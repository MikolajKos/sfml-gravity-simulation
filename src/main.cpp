#include <SFML/Graphics.hpp>
#include "includes/GravitySource.hpp"
#include "includes/Particle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1980u, 1240u}), "Gravity Simulation", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    GravitySource sun(1980 / 2, 1240 / 2, 2000, 30);

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
        
        sun.render(window);

        window.display();
    }
}
