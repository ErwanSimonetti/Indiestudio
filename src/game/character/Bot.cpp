/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Bot
*/

#include <iostream>
#include <cmath>
#include "MapManager.hpp"
#include "event.hpp"
#include "Bot.hpp"

ids::Bot::Bot(std::vector<float> pos, int id, std::string const &texture, std::vector<std::shared_ptr<ids::ACharacter>> &bombermanVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVectorGame) : ACharacter(pos, id, texture), _bombermanVector(bombermanVector), _bombVector(bombVectorGame)
{
    _moving_down = false;
    _moving_up = false;
    _moving_right = false;
    _moving_left = false;
    _chasing_mode = false;
}

ids::Bot::~Bot()
{
}

void ids::Bot::getAway(MapManager &mapGen)
{
    std::vector<std::string> vectorsToGo = {"up", "down", "left", "right"};

    avoidDangerousMovement(mapGen, vectorsToGo);
    moveAtEmptyTile(mapGen, vectorsToGo);
}

bool ids::Bot::stuckAtWall(void)
{
    return (!_moving_down && !_moving_up && !_moving_left && !_moving_right);
}

std::vector<int> ids::Bot::handleEvents(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen, Input input)
{
    int distanceXEnnemy = std::abs(std::round(getPosition("x")) - getCloserEnnemyCoords().first);
    int distanceYEnnemy = std::abs(std::round(getPosition("y")) - getCloserEnnemyCoords().second);
    auto staticMap = mapGen.getStaticMap();
    auto boxMap = mapGen.getBoxMap();

    if (input != BOT_INPUT || _isDead)
        return {};
    if (knowsWhatToDo())
        return (finishMovement(mapGen));
    handlePathFinding(mapGen);
    if ((distanceXEnnemy < 3 && distanceYEnnemy < 3) || stuckAtWall()) {
        putBomb(assetVector, bombVector, mapGen);
        getAway(mapGen);
    }
    return (finishMovement(mapGen));
}

bool ids::Bot::knowsWhatToDo(void)
{
    return (!(!_moving_down && !_moving_up && !_moving_left && !_moving_right));
}