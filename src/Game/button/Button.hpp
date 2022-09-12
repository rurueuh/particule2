/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Button
*/

#pragma once

#include "SFML.hpp"

enum ButtonState {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_ACTIVE
};

class Button {
    public:
        Button(int x, int y, unsigned int width, unsigned int height,
                std::string text, sf::Font *font, unsigned int size,
                sf::Color color, sf::Color hoverColor, sf::Color clickColor);
        ~Button();

        bool isPressed() const;
        void update(const sf::Vector2f &mousePos);

        void draw(sf::RenderTarget *target) {
            target->draw(this->_shape);
            target->draw(this->_text);
        }

    protected:
    private:
        ButtonState _state;

        sf::RectangleShape _shape;

        sf::Font *_font;
        sf::Text _text;

        sf::Color _color;
        sf::Color _hoverColor;
        sf::Color _clickColor;

};
