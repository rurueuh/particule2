/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(int x, int y, unsigned int width, unsigned int height,
                std::string text, sf::Font *font, unsigned int size,
                sf::Color color, sf::Color hoverColor, sf::Color clickColor)
{
    this->_state = BTN_IDLE;

    this->_shape.setPosition(sf::Vector2f(x, y));
    this->_shape.setSize(sf::Vector2f(width, height));
    this->_shape.setFillColor(color);

    this->_font = font;
    this->_text.setFont(*font);
    this->_text.setString(text);
    this->_text.setFillColor(sf::Color::White);
    this->_text.setCharacterSize(size);
    this->_text.setPosition(
        this->_shape.getPosition().x + this->_shape.getGlobalBounds().width / 2 - this->_text.getGlobalBounds().width / 2,
        this->_shape.getPosition().y + this->_shape.getGlobalBounds().height / 2 - this->_text.getGlobalBounds().height / 2 - size / 3
    );

    this->_color = color;
    this->_hoverColor = hoverColor;
    this->_clickColor = clickColor;
}

Button::~Button()
{
}

bool Button::isPressed() const
{
    if (this->_state == BTN_ACTIVE)
        return true;
    return false;
}

void Button::update(const sf::Vector2f &mousePos)
{
    this->_state = BTN_IDLE;

    if (this->_shape.getGlobalBounds().contains(mousePos)) {
        this->_state = BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            this->_state = BTN_ACTIVE;
    }

    switch (this->_state) {
        case BTN_IDLE:
            this->_shape.setFillColor(this->_color);
            break;
        case BTN_HOVER:
            this->_shape.setFillColor(this->_hoverColor);
            break;
        case BTN_ACTIVE:
            this->_shape.setFillColor(this->_clickColor);
            break;
        default:
            this->_shape.setFillColor(sf::Color::Red);
            break;
    }
}
