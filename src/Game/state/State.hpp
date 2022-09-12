/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** State
*/

#pragma once

#include "SFML.hpp"

class State {
    public:
        State(sf::RenderWindow *, sf::Font *, std::shared_ptr<std::stack<State *>> );
        virtual ~State();

        virtual void update(const float &dt, sf::RenderTarget *, sf::RenderWindow *) = 0;
        virtual void render(sf::RenderTarget * = nullptr) = 0;
        virtual void onWindowResize(sf::RenderTarget *) = 0;

        bool const &getQuit() const { return _quit; };
        void QuitState() { _quit = true; };
        virtual void checkQuit();

        sf::RenderWindow *_target;
        sf::Font *_font;
        std::shared_ptr<std::stack<State *>>  _states;
    protected:
    private:

        std::vector<sf::Texture> _textures;
        bool _quit = false;
};
