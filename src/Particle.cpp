#include "includes/Particle.hpp"

void Particle::render(sf::RenderWindow& window) {
	window.draw(particle);
}

void Particle::update_gravity() {
	
}

sf::Vector2f Particle::get_position() { return pos; }

sf::Vector2f Particle::get_velocity() { return vel; }