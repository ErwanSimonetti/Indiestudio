/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Bomb
*/

#include "Bomb.hpp"

ids::Bomb::Bomb(std::vector<float> pos, std::string const &texture, ids::ACharacter &owner, int fireUp, bool wallUp) : AMoveableObject(pos), _ownerPlayer(owner)
{
    _elapsedTimer = 0;
    _fireUp = fireUp;
    _wallUp = wallUp;
}

ids::Bomb::~Bomb()
{
}

std::string const ids::Bomb::getType() const
{
    return "bomb";
}

bool ids::Bomb::checkAddTimer()
{
    _elapsedTimer++;
    if (_elapsedTimer >= 100) {
        _ownerPlayer.updateBombNumber(1);
        return true;
    }
    return false;
}

int ids::Bomb::getFireUp() const
{
    return _fireUp;
}

bool ids::Bomb::getWallUp() const
{
    return _wallUp;
}

void ids::Bomb::setFireUp(int newVal)
{
    _fireUp = newVal;
}

void ids::Bomb::setWallUp(bool newVal)
{
    _wallUp = newVal;
}