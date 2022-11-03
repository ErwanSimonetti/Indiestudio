/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"

ids::SpeedUp::SpeedUp(std::vector<float> pos , Texture texture) : AItem(pos)
{
    _texture = texture;
}

ids::SpeedUp::~SpeedUp()
{
}

std::string const ids::SpeedUp::getType() const
{
    return "speedUp";
}