/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** BombUp
*/

#include "BombUp.hpp"

ids::BombUp::BombUp(std::vector<float> pos, Texture texture) : AItem(pos)
{
    _texture = texture;
}

ids::BombUp::~BombUp()
{
}

std::string const ids::BombUp::getType() const
{
    return "bombUp";
}