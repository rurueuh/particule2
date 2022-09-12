/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Mouvement
*/

#pragma once

#include "SFML.hpp"

class Mouvement {
    public:
        Mouvement(sf::Vector2f speed);
        ~Mouvement();

        void update(sf::Vertex &vertex);
        void gravity(sf::Vertex &vertex, sf::Vector2f gravity);

        void setSpeed(sf::Vector2f speed) { this->_speed = speed; };

    protected:
    private:
        sf::Vector2f _speed;
};
