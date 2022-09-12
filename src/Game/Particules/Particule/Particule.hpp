/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Particule
*/

#pragma once

#include "SFML.hpp"
#include "Mouvement.hpp"

class Particule {
    public:
        Particule(sf::Vector2f pos, sf::Color color, sf::Vector2f speed);
        virtual ~Particule();

        void update();

        sf::Vertex *getVertex() const { return this->_vertex; };
        void setSpeed(sf::Vector2f speed) { this->_mouvement->setSpeed(speed); };

        Mouvement *_mouvement;
    protected:
    private:
        sf::Vertex *_vertex;
};
