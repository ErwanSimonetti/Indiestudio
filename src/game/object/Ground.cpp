/*
** EPITECH PROJECT, 2022
** indie_studio
** File description:
** Ground.cpp
*/

#include "Ground.hpp"

ids::Ground::Ground(std::vector<float> pos) : AStaticObject(pos)
{
}

ids::Ground::~Ground()
{
}

std::string const ids::Ground::getType() const
{
    return "ground";
}