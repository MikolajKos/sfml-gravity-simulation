#ifndef GRAVITY_SOURCE_HPP
#define GRAVITY_SOURCE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class GravitySource {
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::CircleShape circle;
	sf::Clock clock;
	float strength;
	float radius;

public:
	GravitySource(sf::Vector2f vel, float pos_x, float pos_y, float strength, float radius);

	void render(sf::RenderWindow& window);
	void update_physics(const std::vector<GravitySource>& objects);
	sf::Vector2f get_position() const;
	float get_strength() const;

};

#endif