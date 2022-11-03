/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AStaticObject
*/

#include "AStaticObject.hpp"

ids::AStaticObject::AStaticObject(std::vector<float> pos) : AAsset(pos)
{
}

ids::AStaticObject::~AStaticObject()
{
}

void ids::AStaticObject::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    DrawModel(modelMap.find(getType())->second.model, {getPosition("x"), getPosition("z"), getPosition("y")}, 1.0f, WHITE);
}