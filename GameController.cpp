#include "GameController.h"

//GameController::GameObject *m_gameObjects = nullptr; //TODO: Как там статики инициализировать?

void GameController::update()
{
    for (int i = 0; i < gameObjectsCount; ++i)
    {
        m_gameObjects[i].update();
//        window->draw(m_gameObjects[i].getDrawable); //TODO: Что рисовать-то?
        m_gameObjects[i].getDrawable();
    }
}

GameController::GameController()
{
    if (m_access_points_created == 0)
    {
        //Constructor




    }
    ++m_access_points_created;
}
