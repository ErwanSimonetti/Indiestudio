/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** ImageSprite
*/

#include "ImageSprite.hpp"

ids::ImageSprite::ImageSprite(std::vector<float> pos, std::string const &texture) : ASpriteObject(pos, texture, 1)
{
}

ids::ImageSprite::~ImageSprite()
{
}

std::string const ids::ImageSprite::getType() const
{
    return "image";
}