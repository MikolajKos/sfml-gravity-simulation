#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include <thread>
#include "GravitySource.hpp"

class Particle {
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::CircleShape particle;
	sf::Clock clock;
	float radius;
public:
	Particle(float pos_x, float pos_y, float vel_x, float vel_y, float radius);

	void render(sf::RenderWindow& window);
	void update_physics(const GravitySource& s);
	sf::Vector2f get_position() const;
	sf::Vector2f get_velocity() const;
};

#endif