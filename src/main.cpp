#include <SFML/Graphics.hpp>
#include "includes/GravitySource.hpp"
#include "includes/Particle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1980u, 1240u}), "Gravity Simulation", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    GravitySource star(1980 / 2, 1240 / 2, 4000, 50);
    Particle planet(1980 / 2, 200, 3, 0, 20);
    Particle planet2(200, 300, 1, -1, 20);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        star.render(window);
        planet.render(window);
        planet2.render(window);

        planet.update_physics(star);
        planet2.update_physics(star);

        window.display();
    }
}
