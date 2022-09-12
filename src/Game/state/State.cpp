/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** State
*/

#include "State.hpp"

State::State(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::stack<State *>>  states)
{
    this->_target = target;
    this->_font = font;
    this->_states = states;
    this->_target = target;
}

State::~State()
{
}

void State::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->_quit = true;
}
