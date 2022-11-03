/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Action
*/

#include "ButtonAction.hpp"

ids::ButtonAction::ButtonAction(gameState &state, AudioS &audio) : _state(state), _audio(audio)
{
}

ids::ButtonAction::~ButtonAction()
{
}


AudioS &ids::ButtonAction::getAudioStruct()
{
    return _audio;
}

void ids::ButtonAction::launchGameSettings()
{
    _state = gameState::GAMESETTINGS;
}

void ids::ButtonAction::launchGame()
{
    _state = gameState::GAME;
}

void ids::ButtonAction::launchSettings()
{
    _state = gameState::SETTINGS;
}

void ids::ButtonAction::exitGame()
{
    _state = gameState::EXIT;
}

void ids::ButtonAction::resumeGame()
{
    _state = gameState::GAME;
}

void ids::ButtonAction::launchGameMenu()
{
    _state = gameState::MENU;
    std::remove(PATH_SAVE_FILE);
}

void ids::ButtonAction::launchController()
{
    _state = gameState::CONTROLLER;
}