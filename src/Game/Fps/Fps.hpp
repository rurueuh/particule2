/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Fps
*/

#pragma once

#include "SFML.hpp"
#include "Text.hpp"

class Fps {
    public:
        Fps(sf::Font *);
        ~Fps();

        void update();
        void render(sf::RenderTarget *target) { this->_text->draw(target); }

    protected:
    private:
        sf::Clock _clock;
        sf::Time _time;
        Text *_text;
};
