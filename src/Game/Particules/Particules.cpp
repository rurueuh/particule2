/*
** EPITECH PROJECT, 2022
** particule2
** File description:
** Particules10000
*/

#include "Particules.hpp"

Particules10000::Particules10000()
{
    const int nbParticules = 10000;
    sf::Vector2f pos_diff = sf::Vector2f();
    std::uniform_int_distribution<int> distributionx(0, 960);
    std::uniform_int_distribution<int> distributiony(0, 540);
    std::random_device rd;
    std::mt19937 engine(rd());
    sf::Vector2f speed;

    for (int i = 0; i < nbParticules; i++) {
        pos_diff.x = distributionx(engine);
        pos_diff.y = distributiony(engine);
        sf::Uint8 orange = pos_diff.x / 960 * 255;
        sf::Color color = sf::Color(255, orange, 0, 255);
        speed.x = 0;//(rand() % 100) / 100.0f * (rand() % 2 == 0 ? -1 : 1);
        speed.y = 0;//(rand() % 100) / 100.0f * (rand() % 2 == 0 ? -1 : 1);
        _particules[i] = new Particule(pos_diff + (sf::Vector2f) {1920 / 2, 1080 / 2}, color, speed);
    }
    this->_vertexArray = new sf::VertexArray(sf::Points, nbParticules);
}

Particules10000::~Particules10000()
{
}

void Particules10000::gravity()
{
    for (int i = 0; i < 10000; i++) {
        _particules[i]->_mouvement->gravity(*_particules[i]->getVertex(), this->_mousePosGrav);
    }
}

void Particules10000::update()
{
    for (int i = 0; i < 10000; i++) {
        this->_particules[i]->update();
    }
}

void Particules10000::render(sf::RenderTarget &target)
{
    this->_vertexArray->clear();
    for (int i = 0; i < 10000; i++) {
        this->_vertexArray->append(*this->_particules[i]->getVertex());
    }
    target.draw(*this->_vertexArray);
}