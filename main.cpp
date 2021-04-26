#include <iostream>
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

int main()
{
    // Отрисовка окна
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!",sf::Style::Default, settings);
    window.setFramerateLimit(60);

    RectangleShape board(Vector2f(896, 512));
    board.setFillColor(Color::Green);
    board.setPosition(Vector2f(512, 256));

    RectangleShape acrossBoard(Vector2f(1000, 610));
    acrossBoard.setFillColor(Color(150, 75, 0));
    acrossBoard.setPosition(Vector2f(470, 220));

    // Инициализация контроллера игры
    GameController gameController(&window);
    Ball *balls = gameController.balls;

    // Создание спрайта кия
    Image cueImage;
    cueImage.loadFromFile("C:\\Clion Projects\\SFML_Homework\\images\\cue.png");
    Texture cueTexture;
    cueTexture.loadFromImage(cueImage);
    Sprite cueSprite;
    cueSprite.setTexture(cueTexture);
    cueSprite.setScale(0.35, 0.35);
    cueSprite.setOrigin(-20, cueSprite.getTextureRect().height / 2);

    float speed = 0.001;
    bool isTurn = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear(Color(0,128,1));

        float vecX, vecY, rotation;

        Vector2f mousePos(Mouse::getPosition(window));
        Vector2i pixelPos(Mouse::getPosition(window));
        Vector2f pos = window.mapPixelToCoords(pixelPos);

        isTurn = false;

        for (int i = 0; i < gameController.balls_count; ++i) {
            isTurn += balls[i].is_moving;
        }

        for (int i = 0; i < gameController.balls_count; ++i)
        {

            if (balls[i].drawable.getGlobalBounds().contains(mousePos))
            {
                if (Mouse::isButtonPressed(Mouse::Left) && !isTurn)
                {
                    vecX = (pos.x - 512) - (balls[i].position.x - 512);
                    vecY = (pos.y - 256) - (balls[i].position.y - 256);
                    rotation = (atan2(vecX, vecY) * 180 / M_PI);
                    cueSprite.setPosition(balls[i].position.x, balls[i].position.y);
                    cueSprite.setRotation(90 - rotation);

                }
                if (event.type == sf::Event::MouseButtonReleased && !isTurn)
                {
                    balls[i].add_force(Vector2f((balls[i].position.x - mousePos.x) , (balls[i].position.y - mousePos.y )));
                    cueSprite.setPosition(-1000, -1000);
                }


            }
        };

        window.draw(acrossBoard);
        window.draw(board);
        gameController.update();
        window.draw(cueSprite);
        window.display();
    }
        return 0;
}
