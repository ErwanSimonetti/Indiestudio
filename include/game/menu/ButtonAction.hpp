/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Action
*/

#ifndef BUTTONACTION_HPP_
#define BUTTONACTION_HPP_

#pragma once
#include <algorithm>
#include <iterator>
#include <cstdio>

#include "raylib.h"
#include "IndieStudio.hpp"
#include "MapManager.hpp"
#include "ButtonText.hpp"

struct AudioS
{
	Music menuMusic;
	Music gameMusic;
    Sound bombExplosion;
    Sound playerDeath;
};

class ids::ButtonAction {
    public:
        ButtonAction(gameState &state, AudioS &audio);
        ~ButtonAction();

        AudioS &getAudioStruct();

        void launchGame();
        void launchGameMenu();
        void launchSettings();
        void exitGame();
        void launchGameSettings();
        void resumeGame();
        void launchController();

    protected:
    private:
        AudioS &_audio;
        gameState &_state;
};

#endif /* !BUTTONACTION_HPP_ */
