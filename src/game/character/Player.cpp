/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Player
*/

#include <map>
#include "event.hpp"
#include "Player.hpp"

ids::Player::Player(std::vector<float> pos, int id, std::string const &texture,
                    std::map<Action, Input> inputMap) : ACharacter(pos, id, texture)
{
    _isBot = false;
    _inputMap = inputMap;
}

ids::Player::~Player()
{
}

std::vector<int> ids::Player::handleEvents(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen, Input input)
{
    Action event;

    for(auto &it : _inputMap) { 
        if(it.second == input) { 
            event = it.first;
        }
    }
    switch(event) {
            case Action::MOVE_LEFT: case Action::MOVE_RIGHT: case Action::MOVE_UP: case Action::MOVE_DOWN:
                return (move(event, mapGen));
            case Action::PUT_BOMB:
                putBomb(assetVector, bombVector, mapGen);
                break;
            default:
                break;
        }
    return {};
}
