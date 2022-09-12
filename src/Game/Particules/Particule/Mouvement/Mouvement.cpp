/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Mouvement
*/

#include "Mouvement.hpp"

Mouvement::Mouvement(sf::Vector2f speed)
{
    this->_speed = speed;
}

Mouvement::~Mouvement()
{
}

void Mouvement::gravity(sf::Vertex &vertex, sf::Vector2f mousePos)
{
    const int range = 500;
    const float speed = 1;

    sf::Vector2f distance = mousePos - vertex.position;
    float distanceLength = sqrt(distance.x * distance.x + distance.y * distance.y);
    if (distanceLength < range) {
        distance.x /= distanceLength;
        distance.y /= distanceLength;
        distance.x *= speed;
        distance.y *= speed;
        this->_speed += distance;
    }
    if (abs(this->_speed.x) > 5){
        if (this->_speed.x > 0)
            this->_speed.x = 5;
        else
            this->_speed.x = -5;
    }
    if (abs(this->_speed.y) > 5){
        if (this->_speed.y > 0)
            this->_speed.y = 5;
        else
            this->_speed.y = -5;
    }
}

void Mouvement::update(sf::Vertex &vertex)
{
    vertex.position.x += this->_speed.x;
    vertex.position.y += this->_speed.y;
    if (vertex.position.x > 1920)
        this->_speed.x = -this->_speed.x;
    if (vertex.position.x < 0)
        this->_speed.x = -this->_speed.x;
    if (vertex.position.y > 1080)
        this->_speed.y = -this->_speed.y;
    if (vertex.position.y < 0)
        this->_speed.y = -this->_speed.y;
}
