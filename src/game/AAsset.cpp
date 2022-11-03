/*
** EPITECH PROJECT, 2022
** axel indie sutdio
** File description:
** AAsset
*/

#include "AAsset.hpp"

ids::AAsset::AAsset(std::vector<float> pos)
{
    _posX = pos.at(0);
    _posY = pos.at(1);
    _posZ = pos.at(2);
    _frameCounter = 0;
}

ids::AAsset::~AAsset()
{
}

float ids::AAsset::getPosition(std::string const &vector) const
{
    if (vector == "x") return _posX;
    if (vector == "y") return _posY;
    if (vector == "z") return _posZ;
    return (-1);
}

void ids::AAsset::setPostition(std::string const &vector, float pos)
{
    if (vector == "x") _posX += pos;
    if (vector == "y") _posY += pos;
    if (vector == "z") _posZ += pos;
}

std::vector<float> ids::AAsset::getCoords() const
{
    return {_posX, _posY, _posZ};
}