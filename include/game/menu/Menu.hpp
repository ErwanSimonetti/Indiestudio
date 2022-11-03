/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#pragma once
#include "IndieStudio.hpp"
#include "Button.hpp"
#include "ButtonText.hpp"
#include "ImageSprite.hpp"
#include "ButtonAction.hpp"
#include "Player.hpp"
#include "Controller.hpp"
#include <memory>


class ids::Menu {
    public:
        Menu(gameState &state, AudioS &audio, std::vector<ItemType> &choosenItem);
        ~Menu();
        std::vector<std::shared_ptr<ids::IAsset>> getVectorSprite(gameState &state);
        std::vector<std::shared_ptr<ids::IAsset>> getVectorSprite2D(gameState &state);
        void createVectorMain(gameState &state);
        void createVectorSettings(gameState &state);
        void createVectorGameSettings(gameState &state);
        void createVectorPause(gameState &state);
        void createVectorCutscene(gameState &state);
        void createVectorController(gameState &state);
        void createVectorEndscene(std::string winner, gameState &state);
        void switchMenu(gameState &state);
        void createInputMap();
        void checkInputModified();
        std::vector<std::shared_ptr<ids::IAsset>> getCutsceneBackground();
        std::vector<ItemType> getChoosenItem();
        std::vector<playerMenu_t> getPlayersSettings();
        Input getInput();

    protected:
    private:
        std::vector<std::shared_ptr<ids::IAsset>> _main;
        std::vector<std::shared_ptr<ids::IAsset>> _settings;
        std::vector<std::shared_ptr<ids::IAsset>> _gameSettings;
        std::vector<std::shared_ptr<ids::IAsset>> _pause;
        std::vector<std::shared_ptr<ids::IAsset>> _cutscene;
        std::vector<std::shared_ptr<ids::IAsset>> _endscene;
        std::vector<std::shared_ptr<ids::IAsset>> _cutsceneBackground;
        std::vector<std::shared_ptr<ids::IAsset>> _cutscene2D;
        std::vector<std::shared_ptr<ids::IAsset>> _endscene2D;
        std::vector<std::shared_ptr<ids::IAsset>> _controllerAssets;

        ButtonAction _action;
        std::vector<ItemType> &_choosenItem;
        std::vector<playerMenu_t> _players;

        std::vector<Controller> _controllers;
};

#endif /* !MENU_HPP_ */
