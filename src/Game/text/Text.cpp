/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(std::string string, sf::Font *font, sf::Color color, sf::Vector2f pos, unsigned int size)
{
    this->_font = font;
    this->_text = new sf::Text(string, *this->_font, size);
    this->_text->setFillColor(color);
    this->_text->setPosition(pos);
}

Text::~Text()
{
    delete this->_text;
}

void Text::draw(sf::RenderTarget *target)
{
    target->draw(*this->_text);
}
