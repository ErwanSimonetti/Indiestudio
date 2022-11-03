/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#pragma once
#include "IndieStudio.hpp"

#include "Renderer.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "BombUp.hpp"
#include "Brick.hpp"

#include <cstdlib>

class ids::GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        void run();
        void gameLoop();
        void menuLoop();
        void createItemVector();
        void cutscene();
        void endscene();
        Game const &getGame() const;
    protected:
    private:
        Renderer _render;
        gameState _state;
        Game _game;
        Menu _menu;
        std::map<std::string, ModelS> _modelMap;
        AudioS _audioS;
        std::vector<ItemType> _choosenItem;
        std::pair<Renderer, std::map<std::string, ModelS>> _renderModel;
};

#endif /* !GAMEENGINE_HPP_ */
