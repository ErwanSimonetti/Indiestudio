/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Fire
*/

#include "Fire.hpp"

ids::Fire::Fire(std::vector<float> pos, std::string const &texture) : AMoveableObject(pos)
{
    _elapsedTimer = 0;
}

ids::Fire::~Fire()
{
}

std::string const ids::Fire::getType() const
{
    return "fire";
}

bool ids::Fire::checkAddTimer()
{
    _elapsedTimer++;
    if (_elapsedTimer >= 10)
        return true;
    return false;
}