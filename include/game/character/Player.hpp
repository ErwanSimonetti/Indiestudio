/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IndieStudio.hpp"
#include "ACharacter.hpp"
#include "MapManager.hpp"
#include "Bomb.hpp"

#include <map>
#include <cmath>

class ids::Player : public ACharacter {
    public:
        Player(std::vector<float> pos, int id, std::string const &texture,
                std::map<Action, Input> inputMap =
                {{Action::MOVE_UP, NO_INPUT}, {Action::MOVE_DOWN, NO_INPUT},
                {Action::MOVE_RIGHT, NO_INPUT}, {Action::MOVE_LEFT, NO_INPUT},
                {Action::PUT_BOMB, NO_INPUT}});
        ~Player();
        std::vector<int> handleEvents(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen, Input input) override;
    
    private:
        std::map<Action, Input> _inputMap;


};

#endif /* !PLAYER_HPP_ */
