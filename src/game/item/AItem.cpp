/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AItem
*/

#include "AItem.hpp"

ids::AItem::AItem(std::vector<float> pos) : AMoveableObject(pos)
{
}

ids::AItem::~AItem()
{
}

void ids::AItem::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    if (updateAnim) updateAnimation(modelMap);
    UpdateModelAnimation(modelMap.find(getType())->second.model, modelMap.find(getType())->second.animation[0], _frameCounter);
    modelMap.find(getType())->second.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
    DrawModelEx(modelMap.find(getType())->second.model, {getPosition("x"), getPosition("z") - 0.5f, getPosition("y")}, {0.0f, 1.0f, 0.0f}, getDirection(), modelMap.find(getType())->second.size, WHITE);
}