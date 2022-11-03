/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AMoveableObject
*/

#include "AMoveableObject.hpp"

ids::AMoveableObject::AMoveableObject(std::vector<float> pos) : AAsset(pos)
{
    _isAnimable = true;
    _frameCounter = 0;
    _direction = 0;
}

ids::AMoveableObject::~AMoveableObject()
{
}

void ids::AMoveableObject::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    if (getType() != "brick") {
        if (updateAnim) updateAnimation(modelMap);
        UpdateModelAnimation(modelMap.find(getType())->second.model, modelMap.find(getType())->second.animation[0], _frameCounter);
    }
    modelMap.find(getType())->second.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = modelMap.find(getType())->second.texture;
    DrawModelEx(modelMap.find(getType())->second.model, {getPosition("x"), getPosition("z"), getPosition("y")}, {0.0f, 1.0f, 0.0f}, getDirection(), modelMap.find(getType())->second.size, WHITE);
}

float ids::AMoveableObject::getDirection() const
{
    return _direction;
}

void ids::AMoveableObject::setDirection(std::string const &direction)
{
    if (direction == "left") _direction = -90;
    if (direction == "right") _direction = 90;
    if (direction == "up") _direction = 180;
    if (direction == "down") _direction = 0;
}

void ids::AMoveableObject::updateAnimation(std::map<std::string, ModelS> modelMap)
{
    _frameCounter++;
    // printf("%s\n", getType().c_str());
    if (_frameCounter >= modelMap.find(getType())->second.animation[0].frameCount) _frameCounter = 0;
}

float ids::AMoveableObject::getFramecounter() const
{
    return _frameCounter;
}