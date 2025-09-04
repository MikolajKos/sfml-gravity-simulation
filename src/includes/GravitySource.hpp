#ifndef GRAVITY_SOURCE_HPP
#define GRAVITY_SOURCE_HPP

#include <SFML/Graphics.hpp>

class GravitySource {
	sf::Vector2f position;
	sf::CircleShape circle;
	float strength;
	float radius;

public:
	GravitySource(float pos_x, float pos_y, float strength, float radius);

	void render(sf::RenderWindow& window);
	sf::Vector2f get_position();
	float get_strength();

};

#endif