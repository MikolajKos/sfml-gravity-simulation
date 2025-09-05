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

void GravitySource::update_physics() {
	float dt = clock.restart().asSeconds() * 100;
	position += velocity * dt;
}

sf::Vector2f GravitySource::get_position() const { return position; }

float GravitySource::get_strength() const { return strength; }