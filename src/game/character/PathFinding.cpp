/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** PathFinding
*/

#include <cmath>
#include "MapManager.hpp"
#include "Bot.hpp"
#include "Bomb.hpp"

bool ids::Bot::isInTheMiddleOfTile(void)
{
    int x = getPosition("x") * 10;
    int y = getPosition("y") * 10;

    if (_moving_down || _moving_up)
        return (y % 10 == 0);
    return (x % 10 == 0);
}

std::vector<int> ids::Bot::finishMovement(MapManager &mapGen)
{
    std::vector<int> itemPos = {};

    if (isInTheMiddleOfTile() && !bombCanTouchBot(mapGen, std::round(getPosition("x")), std::round(getPosition("y"))) && !_chasing_mode)
        stopMovement();
    if (_moving_down) {
        itemPos = move(Action::MOVE_DOWN, mapGen);
        if (!mapGen.isTileFree(std::round(getPosition("x")), (std::round(getPosition("y") + 0.51))))
            _moving_down = false;
    }
    else if (_moving_up) {
        itemPos = move(Action::MOVE_UP, mapGen);
        if (!mapGen.isTileFree(std::round(getPosition("x")), (std::round(getPosition("y") - 0.51))))
            _moving_up = false;
    }
    else if (_moving_right) {
        itemPos = move(Action::MOVE_RIGHT, mapGen);
        if (!mapGen.isTileFree(std::round(getPosition("x") + 0.51), (std::round(getPosition("y")))))
            _moving_right = false;
    }
    else if (_moving_left) {
        itemPos = move(Action::MOVE_LEFT, mapGen);
        if (!mapGen.isTileFree(std::round(getPosition("x") - 0.51), (std::round(getPosition("y")))))
            _moving_left = false;
    }
    return (itemPos);
}

void ids::Bot::moveAtEmptyTile(MapManager &mapGen, std::vector<std::string> directions)
{
    auto staticMap = mapGen.getStaticMap();
    auto boxMap = mapGen.getBoxMap();

    if (std::find(directions.begin(), directions.end(), "left") != directions.end()
        && boxMap.at(std::round(getPosition("y"))).at(std::round(getPosition("x")) - 1) == ids::BoxMap::Unknown
        && staticMap.at(std::round(getPosition("y"))).at(std::round(getPosition("x")) - 1) == ids::StaticMap::Grounds
        && (std::round(getPosition("x")) - 1) > 0)
        _moving_left = true;
    else if (std::find(directions.begin(), directions.end(), "right") != directions.end()
        && boxMap.at(std::round(getPosition("y"))).at(std::round(getPosition("x")) + 1) == ids::BoxMap::Unknown
        && staticMap.at(std::round(getPosition("y"))).at(std::round(getPosition("x")) + 1) == ids::StaticMap::Grounds
        && (std::round(getPosition("x")) + 1) < staticMap[getPosition("y")].size())
        _moving_right = true;
    else if (std::find(directions.begin(), directions.end(), "down") != directions.end()
        && boxMap.at(std::round(getPosition("y")) + 1).at(std::round(getPosition("x"))) == ids::BoxMap::Unknown
        && staticMap.at(std::round(getPosition("y")) + 1).at(std::round(getPosition("x"))) == ids::StaticMap::Grounds
        && (std::round(getPosition("y")) + 1) < staticMap[getPosition("y")].size())
        _moving_down = true;
    else if (std::find(directions.begin(), directions.end(), "up") != directions.end()
        && boxMap.at(std::round(getPosition("y")) - 1).at(std::round(getPosition("x"))) == ids::BoxMap::Unknown
        && staticMap.at(std::round(getPosition("y")) - 1).at(std::round(getPosition("x"))) == ids::StaticMap::Grounds
        && (std::round(getPosition("y")) - 1) > 0)
        _moving_up = true;
}

bool ids::Bot::playerAtThisPos(int x, int y)
{
    for (int i = 0; i < _bombermanVector.size(); i += 1) {
        if (std::round(_bombermanVector[i].get()->getPosition("x")) == x && std::round(_bombermanVector[i].get()->getPosition("y")) == y)
            return true;
    }
    return false;
}

void ids::Bot::updateCollisionMap(MapManager &mapGen)
{
    auto staticMap = mapGen.getStaticMap();
    auto boxMap = mapGen.getBoxMap();
    std::string currentLine;

    _collisionMap.clear();
    for (int i = 0; i < staticMap.size(); i += 1) {
        for (int j = 0; j < staticMap[i].size(); j += 1) {
            if (staticMap[i][j] == ids::StaticMap::Walls || boxMap[i][j] == ids::BoxMap::Box)
                currentLine.append("X");
            else if (boxMap[i][j] == ids::BoxMap::BombObject)
                currentLine.append("O");
            else if (j == std::round(getPosition("x")) && i == std::round(getPosition("y")))
                currentLine.append("B");
            else if (playerAtThisPos(j, i))
                currentLine.append("P");
            else
                currentLine.append(" ");
        }
        _collisionMap.emplace_back(currentLine);
        currentLine.clear();
    }
}

bool ids::Bot::isBotOnLineOrColumnOfPos(std::pair<int, int> coords, int x, int y)
{
    return (x == coords.first || y == coords.second);
}

static bool bombIsPlaced(const std::vector<std::string> &collisionMap)
{
    for (int i = 0; i < collisionMap.size(); i += 1) {
        if (collisionMap[i].find("O") != std::string::npos)
            return true;
    }
    return false;
}

std::vector<std::pair<int, int>> ids::Bot::getBombsCoords(void)
{
    std::vector<std::pair<int, int>> coordsBombs;
    std::pair<int, int> coordsCurrentBomb;

    for (int y = 0; y < _collisionMap.size(); y += 1) {
        for (int x = _collisionMap[y].find("O"); x != std::string::npos; x = _collisionMap[y].find("O", x + 1)) {
            coordsCurrentBomb.first = x;
            coordsCurrentBomb.second = y;
            coordsBombs.push_back(coordsCurrentBomb);
        }
    }
    return coordsBombs;
}

std::vector<std::string> ids::Bot::updatePathsAwayFromBomb(int distanceX, int distanceY, std::vector<std::string> &vectorsToGo)
{
    if (distanceX >= -3 && distanceX < 0)
        vectorsToGo.erase(std::remove(vectorsToGo.begin(), vectorsToGo.end(), "right"), vectorsToGo.end());
    if (distanceX <= 3 && distanceX > 0)
        vectorsToGo.erase(std::remove(vectorsToGo.begin(), vectorsToGo.end(), "left"), vectorsToGo.end());
    if (distanceY >= -3 && distanceY < 0)
        vectorsToGo.erase(std::remove(vectorsToGo.begin(), vectorsToGo.end(), "down"), vectorsToGo.end());
    if (distanceY <= 3 && distanceY > 0)
        vectorsToGo.erase(std::remove(vectorsToGo.begin(), vectorsToGo.end(), "up"), vectorsToGo.end());
    return vectorsToGo;
}

void ids::Bot::stopMovement(void)
{
    _moving_up = false;
    _moving_down = false;
    _moving_left = false;
    _moving_right = false;
}

void ids::Bot::avoidBomb(MapManager &mapGen)
{
    auto coordsBombs = getBombsCoords();
    int x = std::round(getPosition("x"));
    int y = std::round(getPosition("y"));
    int distanceX = 0;
    int distanceY = 0;
    std::vector<std::string> vectorsToGo = {"up", "down", "left", "right"};

    for (int i = 0; i < coordsBombs.size(); i += 1) {
        distanceX = x - coordsBombs[i].first;
        distanceY = y - coordsBombs[i].second;
        if (std::abs(distanceX) < 3 || std::abs(distanceY) < 3 && isBotOnLineOrColumnOfPos(coordsBombs[i], std::round(getPosition("x")), std::round(getPosition("y"))))
            updatePathsAwayFromBomb(distanceX, distanceY, vectorsToGo);
    }
    moveAtEmptyTile(mapGen, vectorsToGo);
}

static ids::Bomb *getBombAtCoords(const std::vector<std::shared_ptr<ids::Bomb>> &bombVector, int x, int y)
{
    for (int i = 0; i < bombVector.size(); i += 1) {
        if (bombVector.at(i).get()->getPosition("x") == x && bombVector.at(i).get()->getPosition("y") == y)
            return (bombVector.at(i).get());
    }
}

bool ids::Bot::bombCanTouchBot(MapManager &mapGen, int x, int y)
{
    auto coordsBombs = getBombsCoords();
    int distanceX = 0;
    int distanceY = 0;

    for (int i = 0; i < coordsBombs.size(); i += 1) {
        distanceX = x - coordsBombs[i].first;
        distanceY = y - coordsBombs[i].second;
        if (std::abs(distanceX) < 3 && std::abs(distanceY) < 3 && isBotOnLineOrColumnOfPos(coordsBombs[i], x, y))
            return true;
    }
    return false;
}

std::pair<int, int> ids::Bot::getCloserEnnemyCoords(void)
{
    int xBot = std::round(getPosition("x"));
    int yBot = std::round(getPosition("y"));
    int currentCloserAbs = 100;
    int currentDistanceX = 0;
    int currentDistanceY = 0;
    std::pair<int, int> closerEnnemyCoords = {5, 5};

    for (int y = 0; y < _collisionMap.size(); y += 1) {
        for (int x = _collisionMap[y].find("P"); x != std::string::npos; x = _collisionMap[y].find("P", x + 1)) {
            currentDistanceX = std::abs(xBot - x);
            currentDistanceY = std::abs(yBot - y);
            if ((currentDistanceX + currentDistanceY) < currentCloserAbs) {
                closerEnnemyCoords.first = x;
                closerEnnemyCoords.second = y;
            }
        }
    }
    return (closerEnnemyCoords);
}

static void updatePathsCloserToEnnemy(int distanceX, int distanceY, std::vector<std::string> &vectorsToGo)
{
    if (distanceX < 0)
        vectorsToGo.emplace_back("right");
    if (distanceX > 0)
        vectorsToGo.emplace_back("left");
    if (distanceY < 0)
        vectorsToGo.emplace_back("down");
    if (distanceY > 0)
        vectorsToGo.emplace_back("up");
}

void ids::Bot::moveTowardsEnnemy(MapManager &mapGen)
{
    std::pair<int, int> closerEnnemyCoords = getCloserEnnemyCoords();
    int x = std::round(getPosition("x"));
    int y = std::round(getPosition("y"));
    int distanceX = 0;
    int distanceY = 0;
    std::vector<std::string> vectorsToGo;

    distanceX = x - closerEnnemyCoords.first;
    distanceY = y - closerEnnemyCoords.second;
    updatePathsCloserToEnnemy(distanceX, distanceY, vectorsToGo);
    if (bombIsPlaced(_collisionMap) && !vectorsToGo.empty())
        avoidDangerousMovement(mapGen, vectorsToGo);
    moveAtEmptyTile(mapGen, vectorsToGo);
}

void ids::Bot::avoidDangerousMovement(MapManager &mapGen, std::vector<std::string> &directions)
{
    if (directions.empty())
        return;
    if (std::find(directions.begin(), directions.end(), "down") != directions.end() && bombCanTouchBot(mapGen, std::round(getPosition("x")), std::round(getPosition("y")) + 1))
        directions.erase(std::remove(directions.begin(), directions.end(), "down"), directions.end());
    if (std::find(directions.begin(), directions.end(), "up") != directions.end() && bombCanTouchBot(mapGen, std::round(getPosition("x")), std::round(getPosition("y")) - 1))
        directions.erase(std::remove(directions.begin(), directions.end(), "up"), directions.end());
    if (std::find(directions.begin(), directions.end(), "right") != directions.end() && bombCanTouchBot(mapGen, std::round(getPosition("x")) + 1, std::round(getPosition("y"))))
        directions.erase(std::remove(directions.begin(), directions.end(), "right"), directions.end());
    if (std::find(directions.begin(), directions.end(), "left") != directions.end() && bombCanTouchBot(mapGen, std::round(getPosition("x")) - 1, std::round(getPosition("y"))))
        directions.erase(std::remove(directions.begin(), directions.end(), "left"), directions.end());
}

void ids::Bot::handlePathFinding(MapManager &mapGen)
{
    updateCollisionMap(mapGen);

    if (bombIsPlaced(_collisionMap) && bombCanTouchBot(mapGen, std::round(getPosition("x")), std::round(getPosition("y")))) {
        _chasing_mode = false;
        avoidBomb(mapGen);
    }
    else {
        _chasing_mode = true;
        moveTowardsEnnemy(mapGen);
    }
}