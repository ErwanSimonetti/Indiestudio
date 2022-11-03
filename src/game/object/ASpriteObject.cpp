/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** ASpriteObject
*/

#include "ASpriteObject.hpp"

ids::ASpriteObject::ASpriteObject(std::vector<float> pos, std::string const &texture, int frame) : AAsset(pos)
{
    _state = 0;
    _texture = LoadTexture(texture.c_str());
    _frameHeight = (float)_texture.height/frame;
    _sourceRect = {0, 0, (float)_texture.width, _frameHeight};
    _bounds = { pos.at(0) - 1, pos.at(1)/frame - 1, (float)_texture.width, _frameHeight};
}

ids::ASpriteObject::~ASpriteObject()
{
}

void ids::ASpriteObject::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    DrawTextureRec(_texture, _sourceRect,  { _bounds.x, _bounds.y }, WHITE);
}