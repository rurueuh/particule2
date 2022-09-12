/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Particules10000
*/

#pragma once

#include "SFML.hpp"
#include "Particule.hpp"

class Particules10000 {
    public:
        Particules10000();
        virtual ~Particules10000();

        void update();
        void render(sf::RenderTarget &);

        void gravity();
        void gravitySetPoint(sf::Vector2f MousePos) { _mousePosGrav = MousePos; };
        void setSpeed(sf::Vector2f speed) { for (auto &particule : this->_particules) particule->setSpeed(speed); };

        std::array<Particule *, 10000> _particules;
    protected:
    private:
        sf::VertexArray *_vertexArray;
        sf::Vector2f _mousePosGrav;
};
