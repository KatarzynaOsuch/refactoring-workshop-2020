#pragma once
#include <functional>

class IPort;

namespace Snake
{

class FoodController
{
public:
    FoodController(IPort&, IPort&);

    void updateFoodPosition(int x, int y, std::function<void()> clearPolicy);
    void sendClearOldFood();
    void sendPlaceNewFood(int x, int y);

private:
    IPort& m_displayPort;
    IPort& m_foodPort;
    std::pair<int, int> m_foodPosition;
};
}
