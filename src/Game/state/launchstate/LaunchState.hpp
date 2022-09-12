/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#pragma once

#include "SFML.hpp"
#include "State.hpp"

class LaunchState : public State {
    public:
        LaunchState(sf::RenderWindow *, sf::Font *, std::shared_ptr<std::stack<State *>> );
        virtual ~LaunchState();

        void update(const float &dt, sf::RenderTarget *target, sf::RenderWindow *window);
        void render(sf::RenderTarget * = nullptr);
        void onWindowResize(sf::RenderTarget *target) {};

        void button_action_exit();
        void button_action_start();

        void checkQuit();
    protected:
    private:
        Text *_text;
        std::pair<Button *, void (LaunchState::*)()> _button;
        std::pair<Button *, void (LaunchState::*)()> _button_start;
};
