/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** main
*/

#include <memory>

#include "raylib.h"

#include "Renderer.hpp"
#include "Wall.hpp"
#include "Brick.hpp"
#include "IAsset.hpp"
#include "GameEngine.hpp"

void initialization()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    SetTargetFPS(200);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "3d camera mode");
    InitAudioDevice();
}

int main(void)
{
    initialization();
    ids::GameEngine eng;
    eng.run();
    return 0;
}