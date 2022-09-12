/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Fps
*/

#include "Fps.hpp"

Fps::Fps(sf::Font *font)
{
    this->_text = new Text("0", font, sf::Color::White, {0, 0}, 30);
}

Fps::~Fps()
{
    delete this->_text;
}

void Fps::update()
{
    this->_time = this->_clock.getElapsedTime();
    std::string s = std::to_string(1 / this->_time.asSeconds());
    this->_text->setString(s);
    this->_clock.restart();
}
