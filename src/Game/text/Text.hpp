/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Text
*/

#pragma once

#include "SFML.hpp"

class Text : public sf::Text {
    public:
        Text(std::string, sf::Font *, sf::Color = sf::Color::White, sf::Vector2f = {0, 0}, unsigned int = 30);
        virtual ~Text();

        void draw(sf::RenderTarget *target);
        void setString(std::string &string) { this->_text->setString(string); }

    protected:
    private:
        sf::Font *_font;
        sf::Text *_text;
};
