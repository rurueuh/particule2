/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Game
*/

#include "Game.hpp"

void Game::initWindow()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    this->_window->setFramerateLimit(144);
}

void Game::initStates()
{
    this->_states = std::make_shared<std::stack<State *>>();
    this->_states.get()->push(new LaunchState(this->_window, this->_font, _states));
}

Game::Game()
{
    this->initWindow();
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/font.ttf");
    this->initStates();
}

Game::~Game()
{
    delete this->_window;
    while (!this->_states.get()->empty()) {
        delete this->_states.get()->top();
        this->_states.get()->pop();
    }
    delete this->_font;
}

void Game::handleEvent()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        if (this->_event.type == sf::Event::KeyPressed && this->_event.key.code == sf::Keyboard::Escape)
            this->_window->close();
        if (this->_event.type == sf::Event::Resized)
            this->_states.get()->top()->onWindowResize(this->_window);
    }
}

void Game::update()
{
    this->updateDt();
    if (!this->_window->hasFocus()){
        return;
    }
    this->handleEvent();
    if (!this->_states.get()->empty()){
        this->_states.get()->top()->update(this->_deltaTime, this->_window, this->_window);
        if (this->_states.get()->top()->getQuit()){
            delete this->_states.get()->top();
            this->_states.get()->pop();
            sf::sleep(sf::milliseconds(300));
        }
    } else {
        this->_window->close();
    }
}

void Game::render()
{
    this->_window->clear();

    // render items
    if (!this->_states.get()->empty())
        this->_states.get()->top()->render(this->_window);

    this->_window->display();
}

void Game::run()
{
    while (this->_window->isOpen()) {
        this->handleEvent();
        this->update();
        this->render();
    }
}
