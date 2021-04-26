#include "GameController.h"

size_t GameController::points_created = 0;
Ball* GameController::balls = nullptr;
size_t GameController::balls_count = 4;
Wall* GameController::walls = nullptr;
size_t GameController::walls_count = 4;
sf::RenderWindow* GameController::window = nullptr;

void GameController::update()
{
    for (int i = 0; i < balls_count; ++i)
    {
        balls[i].update();
        window->draw(balls[i].drawable);
    }
    for (int i = 0; i < walls_count; ++i)
    {
        walls[i].update();
        window->draw(walls[i].drawable);
    }
    balls[0].hit_check();
}

GameController::GameController(sf::RenderWindow *_window)
{
    if (points_created == 0)
    {
        //Constructor
        balls_count = 4;
        balls = new Ball[balls_count];
        walls = new Wall[walls_count];

        walls[0].position.x = 512; walls[0].position.y = 256;
        walls[1].position.x = 512; walls[1].position.y = 256;
        walls[2].position.x = 1408; walls[2].position.y = 256;
        walls[3].position.x = 512; walls[3].position.y = 768;

        walls[1].size.x = 896, walls[1].size.y = 20;
        walls[0].size.x = 20, walls[0].size.y = 512;
        walls[3].size.x = 896, walls[3].size.y = 20;
        walls[2].size.x = 20, walls[2].size.y = 532;

        balls[0].position.x = 960, balls[0].position.y = 540;
        balls[1].position.x = 1020, balls[1].position.y = 600;

        balls[2].position = sf::Vector2f(1050,500);
        balls[3].position = sf::Vector2f(1250,500);
        window = _window;
    }
    ++points_created;
}

GameController::GameController()
{

}
