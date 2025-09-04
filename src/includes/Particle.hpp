#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

class Particle {
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::CircleShape particle;
	float radius;
public:
	Particle(float pos_x, float pos_y, float vel_x, float vel_y, float radius) : radius(radius) {
		pos.x = pos_x;
		pos.y = pos_y;
		vel.x = vel_x;
		vel.y = vel_y;
	};

	void render(sf::RenderWindow& window);
	void update_gravity();
	sf::Vector2f get_position();
	sf::Vector2f get_velocity();
};

#endif