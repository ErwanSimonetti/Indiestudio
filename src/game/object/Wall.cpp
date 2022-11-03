/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Wall
*/

#include "Wall.hpp"

ids::Wall::Wall(std::vector<float> pos) : AStaticObject(pos)
{

}


ids::Wall::~Wall()
{
}

std::string const ids::Wall::getType() const
{
    return "wall";
}