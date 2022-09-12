/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::stack<State *>>  states) : State(target, font, states)
{
    for (int i = 0; i < NB_PARTICULES_10000; i++) {
        this->_particules[i] = new Particules10000();
        this->_threads_updates[i] = new sf::Thread(&Particules10000::update, this->_particules[i]);
        this->_threads_gravity[i] = new sf::Thread(&Particules10000::gravity, this->_particules[i]);
    }
    this->_fps = new Fps(font);
}

GameState::~GameState()
{
    std::cout << "Ending GameState" << std::endl;
}

void GameState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}

void GameState::update(const float &dt, sf::RenderTarget *target, sf::RenderWindow *window)
{
    this->checkQuit();

    for (int i = 0; i < NB_PARTICULES_10000; i++) {
        this->_threads_updates[i]->launch();
    }
    for (int i = 0; i < NB_PARTICULES_10000; i++) {
        this->_threads_updates[i]->wait();
    }

    this->_fps->update();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < NB_PARTICULES_10000; i++) {
            this->_particules[i]->gravitySetPoint(sf::Vector2f(target->mapCoordsToPixel((sf::Vector2f) sf::Mouse::getPosition(*dynamic_cast<sf::Window *>(target)))));
            this->_threads_gravity[i]->launch();
        }
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        for (int i = 0; i < NB_PARTICULES_10000; i++) {
            this->_particules[i]->setSpeed({0, 0});
        }
    }
}

void GameState::onWindowResize(sf::RenderTarget *target)
{
}

void GameState::render(sf::RenderTarget *target)
{
    // if (!target)
    //     target = _target;
    // target->draw(this->_text);
    for (int i = 0; i < NB_PARTICULES_10000; i++) {
        this->_particules[i]->render(*target);
    }
    this->_fps->render(target);
}

