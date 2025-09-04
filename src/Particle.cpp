#include "includes/Particle.hpp"
#include "includes/GravitySource.hpp"

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y, float radius) : radius(radius) {
	pos.x = pos_x;
	pos.y = pos_y;
	vel.x = vel_x;
	vel.y = vel_y;
	
	particle.setRadius(radius);
	particle.setPosition(pos);
	particle.setOrigin({ radius, radius });
	particle.setFillColor(sf::Color::Blue);
};

void Particle::render(sf::RenderWindow& window) {
	particle.setPosition(pos);
	window.draw(particle);
}

void Particle::update_physics(const GravitySource &s) {
	float dist_x = s.get_position().x - pos.x;
	float dist_y = s.get_position().y - pos.y;
	float dist = sqrt(dist_x * dist_x + dist_y * dist_y);

	float inverse_dist = 1.f / dist;

	float norm_x = dist_x * inverse_dist;
	float norm_y = dist_y * inverse_dist;

	float inverse_square_dropoff = inverse_dist * inverse_dist;

	float acceler_x = norm_x * s.get_strength() * inverse_square_dropoff;
	float acceler_y = norm_y * s.get_strength() * inverse_square_dropoff;

	vel.x += acceler_x;
	vel.y += acceler_y;

	pos += vel;
}

sf::Vector2f Particle::get_position() const { return pos; }

sf::Vector2f Particle::get_velocity() const { return vel; }