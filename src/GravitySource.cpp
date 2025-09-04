#include "includes/GravitySource.hpp"

void GravitySource::render(sf::RenderWindow& window) {
	window.draw(circle);
}

sf::Vector2f GravitySource::get_position() { return position; }

float GravitySource::get_strength() { return strength; }