#ifndef UISDUEL_HPP_
#define UISDUEL_HPP_

#include "UISEscapeMenu.hpp"

class UISDuel final : public UISEscapeMenu
{
public:
    UISDuel(std::shared_ptr<State>, const sf::VideoMode&);
};

#endif // UISDUEL_HPP_
