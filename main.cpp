#include <iostream>
#include "GameController.h"
#include <SFML/Graphics.hpp>

int main()
{
    // Отрисовка окна
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!",sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Инициализация контроллера игры
    GameController gameController;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        GameController::update();
        GameController::draw();

        window.display();

    }
        return 0;
}
