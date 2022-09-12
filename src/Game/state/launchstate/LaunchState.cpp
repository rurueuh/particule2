/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** LaunchState
*/

#include "LaunchState.hpp"
#include "GameState.hpp"

LaunchState::LaunchState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::stack<State *>>  states) : State(target, font, states)
{
    this->_text = new Text("Press Space to start", font, sf::Color::White, sf::Vector2f(100, 100), 50);
    this->_button = std::make_pair(new Button(200, 400, 140, 40, "exit", font, 40, sf::Color(100, 100, 100, 255), sf::Color(80, 80, 80, 255), sf::Color(50, 50, 50, 255)), &LaunchState::button_action_exit);
    this->_button_start = std::make_pair(new Button(200, 300, 140, 40, "start", font, 40, sf::Color(100, 100, 100, 255), sf::Color(80, 80, 80, 255), sf::Color(50, 50, 50, 255)), &LaunchState::button_action_start);
}

LaunchState::~LaunchState()
{
    delete this->_text;
    delete this->_button.first;
    delete this->_button_start.first;
    std::cout << "Ending LaunchState" << std::endl;
}

void LaunchState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}


// button action
void LaunchState::button_action_exit()
{
    this->QuitState();
}

void LaunchState::button_action_start()
{
    // this->QuitState();
    this->_states->push(new GameState(this->_target, this->_font, this->_states));
}

// function

void LaunchState::update(const float &dt, sf::RenderTarget *target, sf::RenderWindow *window)
{
    this->checkQuit();
    this->_button.first->update(sf::Vector2f(target->mapCoordsToPixel((sf::Vector2f) sf::Mouse::getPosition(*dynamic_cast<sf::Window *>(target)))));
    if (this->_button.first->isPressed() && this->_button.second != nullptr)
        (this->*_button.second)();
    this->_button_start.first->update(sf::Vector2f(target->mapCoordsToPixel((sf::Vector2f) sf::Mouse::getPosition(*dynamic_cast<sf::Window *>(target)))));
    if (this->_button_start.first->isPressed() && this->_button_start.second != nullptr)
        (this->*_button_start.second)();
}

void LaunchState::render(sf::RenderTarget *target)
{
    // if (!target)
    //     target = _target;
    this->_text->draw(target);
    this->_button.first->draw(target);
    this->_button_start.first->draw(target);
}

