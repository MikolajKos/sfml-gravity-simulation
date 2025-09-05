#include <SFML/Graphics.hpp>
#include "includes/GravitySource.hpp"
#include "includes/Particle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1980u, 1240u}), "Gravity Simulation", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    // Creating objects for simulation
    std::vector<GravitySource> stars;
    stars.emplace_back(sf::Vector2f(0, -1), 1980 / 2, 1240 / 2, 4000, 50);
    stars.emplace_back(sf::Vector2f(-1, 2), (1980 / 2) + 500, (1240 / 2) - 200, 4000, 50);

    std::vector<Particle> planets;
    //planets.emplace_back(1980 / 2, 200, 3, 0, 10);
    //planets.emplace_back(200, 300, 1, -1, 5);
    //planets.emplace_back(500, 500, 1, -2, 20);

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

        for (auto& star : stars) {
            star.update_physics();
            star.render(window);
        }

        for (auto& particle : planets) {
            particle.update_physics(stars[0]); // Temporary stars[0]
            particle.render(window);
        }

        window.display();
    }
}
