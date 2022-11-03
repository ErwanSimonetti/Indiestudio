/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** WallUp
*/

#include "WallUp.hpp"

ids::WallUp::WallUp(std::vector<float> pos, Texture texture) : AItem(pos)
{
    _texture = texture;
}

ids::WallUp::~WallUp()
{
}

std::string const ids::WallUp::getType() const
{
    return "wallUp";
}