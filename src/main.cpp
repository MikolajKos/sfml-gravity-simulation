#include <SFML/Graphics.hpp>
#include <thread>



int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1980u, 1240u}), "Gravity Simulation", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

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
        // Draw here
        window.display();
    }
}
