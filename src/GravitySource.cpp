#include "includes/GravitySource.hpp"

GravitySource::GravitySource(sf::Vector2f vel, float pos_x, float pos_y, float strength, float radius) :
	strength(strength), radius(radius) {
	position.x = pos_x;
	position.y = pos_y;

	velocity = vel;

	clock.start();

	circle.setPosition(position);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::White);
	circle.setOrigin({ radius, radius });
}

void GravitySource::render(sf::RenderWindow& window) {
	circle.setPosition(position);
	window.draw(circle);
}

void GravitySource::update_physics(const std::vector<GravitySource>& objects) {
	sf::Vector2f total_accel(0.f, 0.f);

	for (const auto& other : objects) {
		if (&other == this) continue; // Skip yourself
		
		sf::Vector2f dir = other.get_position() - position;
		float dist = sqrt(dir.x * dir.x + dir.y * dir.y);
		if (dist == 0.f) continue; // Skip division by 0

		dir /= dist; // Normalize direction
		float accel_obj = other.get_strength() / (dist * dist); // (dist * dist) -- pow(x, -2) dependency between gravity strength and distance
		total_accel += dir * accel_obj;
	}
	
	float dt = clock.restart().asSeconds() * 100.f;
	velocity += total_accel * dt;
	position += velocity * dt;
}

sf::Vector2f GravitySource::get_position() const { return position; }

float GravitySource::get_strength() const { return strength; }