#include "Ball.h"
#include "GameController.h"
#include "Hole.h"
#include <cmath>

void Ball::add_force(sf::Vector2f force)
{
    speed = sf::Vector2f(force.x,force.y);
    is_moving = true;
}

void Ball::update()
{
    if (is_moving)
    {
        position.x += speed.x;
        position.y += speed.y;
    }
    sf::Vector2f __speed = sf::Vector2f(speed.x * deceleration, speed.y * deceleration);
    speed = __speed;
    float abs_speed = sqrt(speed.x * speed.x + speed.y * speed.y);
    if (abs_speed < 0.2)
    {
        speed.y = 0; speed.x = 0;
        is_moving = false;
    }
    drawable.setPosition(position);
    drawable.setRadius(radius);
}

void Ball::hit_check()
{
    GameController controller;
    Wall *walls = controller.walls;
    Ball *balls = controller.balls;
    Hole *holes = controller.holes;

    sf::Text scoreText;
    sf::Text scoreNumber;
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
    scoreText.setFont(font);
    scoreNumber.setFont(font);
    scoreText.setCharacterSize(20);
    scoreNumber.setCharacterSize(20);
    scoreText.setString("Score: ");
    char inNum = printScoreNumber + '0';
    scoreNumber.setString(inNum);
    scoreText.setFillColor(sf::Color::Black);
    scoreNumber.setFillColor(sf::Color::Black);
    scoreText.setPosition(1000, 100);
    scoreNumber.setPosition(1060, 100);
    GameController::window->draw(scoreText);
    GameController::window->draw(scoreNumber);

    // Столкновения
    for (int i = 0; i < controller.balls_count; ++i)
    {
        for (int j = 0; j < controller.walls_count; ++j)
        {
            switch (j)
            {
                case 0:
                if (balls[i].position.x + balls[i].speed.x < walls[j].position.x + balls[i].radius + walls[j].size.x)
                    balls[i].speed.x *= -balls[i].elasticValue;
                    break;
                case 1:
                    if (balls[i].position.y + balls[i].speed.y < walls[j].position.y + balls[i].radius + walls[j].size.y)
                        balls[i].speed.y *= -balls[i].elasticValue;
                    break;
                case 2:
                if (balls[i].position.x + balls[i].speed.x > walls[j].position.x - balls[i].radius)
                    balls[i].speed.x *= -balls[i].elasticValue;
                    break;
                case 3:
                    if (balls[i].position.y + balls[i].speed.y > walls[j].position.y - balls[i].radius)
                        balls[i].speed.y *= -balls[i].elasticValue;
                    break;
            }
        }

        for (int j = 0; j < controller.balls_count; ++j)
        {
            double a = balls[i].position.x - balls[j].position.x;
            double b = balls[i].position.y - balls[j].position.y;
            double dist = sqrt(a*a + b*b);
            if (i != j && dist<= 2*balls[i].radius)
            {
                        double bet = atan2(balls[j].position.y - balls[i].position.y, balls[j].position.x - balls[i].position.x);
                        double x1 = balls[i].speed.x * cos(-bet) - balls[i].speed.y * sin(-bet);
                        double y1 = balls[i].speed.x * sin(-bet) + balls[i].speed.y * cos(-bet);
                        double x2 = balls[j].speed.x * cos(-bet) - balls[j].speed.y * sin(-bet);
                        double y2 = balls[j].speed.x * sin(-bet) + balls[j].speed.y * cos(-bet);
                        balls[i].speed.x = x2 * cos(bet) - y1 * sin(bet);
                        balls[i].speed.y = x2 * sin(bet) + y1 * cos(bet);
                        balls[j].speed.x = x1 * cos(bet) - y2 * sin(bet);
                        balls[j].speed.y = x1 * sin(bet) + y2 * cos(bet);

                        int kk = 1;
                        while (dist < 2*balls[0].radius && kk < 100)
                        {

                            a = balls[i].position.x - balls[j].position.x;
                            b = balls[i].position.y - balls[j].position.y;

                            balls[i].position.x = balls[i].position.x + balls[i].speed.x;
                            balls[i].position.y = balls[i].position.y + balls[i].speed.y;

                            balls[j].position.x = balls[j].position.x + balls[j].speed.x;
                            balls[j].position.y = balls[j].position.y + balls[j].speed.y;

                            dist = sqrt(a*a + b*b);

                            if (balls[j].speed.x != 0 || balls[j].speed.y != 0)
                                balls[j].is_moving = true;
                            if (balls[i].speed.x != 0 || balls[i].speed.y != 0)
                                balls[i].is_moving = true;
                            ++kk;
                        }
            }
        }

        for (int j = 0; j < controller.holes_count; ++j) {
            if (abs(balls[i].position.x - holes[j].position.x) + abs(balls[i].position.y - holes[j].position.y) < holes[j].holeRadius * 1.8){
                sf::Vector2f postionOffset = {0,0};
                postionOffset.x = 532 + (i * 100);
                postionOffset.y = 200;
                balls[i].position = postionOffset;
                balls[i].speed = {0, 0};
                printScoreNumber++;
                balls[i].is_goal = true;
            }
        }
    }
}

Ball::Ball(sf::Vector2f _position, float _radius)
{
    position = _position;
    radius = _radius;
    drawable.setRadius(radius);
    drawable.setOrigin(radius,radius);
    drawable.setPosition(position);
    drawable.setFillColor(sf::Color::Yellow);

    is_moving = false;
}

Ball::Ball() : Ball(sf::Vector2f (0, 0), 20)
{

}



