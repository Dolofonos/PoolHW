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

    // Инициализация контроллера игры
    GameController gameController(&window);
    Ball *balls = gameController.balls;


    Image cueImage;
    cueImage.loadFromFile("/home/kefrnik/cue.png");
    Texture cueTexture;
    cueTexture.loadFromImage(cueImage);
    Sprite cueSprite;
    cueSprite.setTexture(cueTexture);
    cueSprite.setScale(0.35, 0.35);
    cueSprite.setOrigin(-20, cueSprite.getTextureRect().height / 2);




//    CircleShape holes[6];
//    for (int i = 0; i < 6; i++) {
//        float positionX, positionY;
//        if (i < 3){
//            positionX = 482 * (i + 1);
//            positionY = 226;
//        } else {
//            positionX = 482 * (i - 2);
//            positionY = 766;
//        }
//        holes[i].setRadius(30);
//        holes[i].setPosition(positionX, positionY);
//        holes[i].setFillColor(Color::Black);
//    }


    float speed = 0.001;
    bool isTurn = false;

//    Ball *Balls = gameController.balls;
//    balls[0].add_force(sf::Vector2f( 5,9));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(80, 140, 80));

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
//                    Balls[i]->startCoordinates = Balls[i]->getPosition();
//                    Balls[i]->endCoordinates = Balls[i]->getEndBallCoordinates({mousePos.x, mousePos.y}, force);
                }


            }
        };




        gameController.update();
//        GameController::draw();
        window.draw(cueSprite);
        window.display();
    }
        return 0;
}
