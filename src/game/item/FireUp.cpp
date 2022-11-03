/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** FireUp
*/

#include "FireUp.hpp"

ids::FireUp::FireUp(std::vector<float> pos, Texture texture) : AItem(pos)
{
    _texture = texture;
}

ids::FireUp::~FireUp()
{
}

std::string const ids::FireUp::getType() const
{
    return "fireUp";
}