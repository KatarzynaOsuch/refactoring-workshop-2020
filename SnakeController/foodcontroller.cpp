#include "foodcontroller.hpp"
#include "IPort.hpp"
#include "SnakeInterface.hpp"
#include "EventT.hpp"

namespace Snake
{

FoodController::FoodController(IPort& display_port, IPort& food_port) : m_displayPort(display_port), m_foodPort(food_port)
{

}

void FoodController::sendClearOldFood()
{
    DisplayInd clearOldFood;
    clearOldFood.x = m_foodPosition.first;
    clearOldFood.y = m_foodPosition.second;
    clearOldFood.value = Cell_FREE;

    m_displayPort.send(std::make_unique<EventT<DisplayInd>>(clearOldFood));
}
}
