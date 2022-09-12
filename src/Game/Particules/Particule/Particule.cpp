/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Particule
*/

#include "Particule.hpp"

Particule::Particule(sf::Vector2f pos, sf::Color color, sf::Vector2f speed)
{
    this->_vertex = new sf::Vertex(pos, color);

    this->_mouvement = new Mouvement(speed);
}

Particule::~Particule()
{
    delete this->_vertex;
}

void Particule::update()
{
    this->_mouvement->update(*this->_vertex);
}
