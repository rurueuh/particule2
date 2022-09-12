/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#pragma once

#include "SFML.hpp"
#include "State.hpp"
#include "Particules.hpp"
#include "Fps.hpp"

#define NB_PARTICULES_10000 20

class GameState : public State {
    public:
        GameState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::stack<State *>>  states);
        virtual ~GameState();

        void update(const float &dt, sf::RenderTarget *target, sf::RenderWindow *window);
        void render(sf::RenderTarget * = nullptr);
        void onWindowResize(sf::RenderTarget *target);
        void updateParticulesTreads(int x);

        void checkQuit();
    protected:
    private:
        std::array<Particules10000 *, NB_PARTICULES_10000> _particules;
        std::array<sf::Thread *, NB_PARTICULES_10000> _threads_updates;
        std::array<sf::Thread *, NB_PARTICULES_10000> _threads_gravity;
        Fps *_fps;
};
