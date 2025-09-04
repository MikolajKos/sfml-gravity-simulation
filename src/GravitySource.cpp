#include "includes/GravitySource.hpp"

GravitySource::GravitySource(float pos_x, float pos_y, float strength, float radius) : 
	strength(strength), radius(radius) {
	position.x = pos_x;
	position.y = pos_y;

	circle.setPosition(position);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::White);
	circle.setOrigin({ radius, radius });
}

void GravitySource::render(sf::RenderWindow& window) {
	window.draw(circle);
}

sf::Vector2f GravitySource::get_position() const { return position; }

float GravitySource::get_strength() const { return strength; }