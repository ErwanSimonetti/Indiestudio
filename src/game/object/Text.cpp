/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Font
*/

#include "Text.hpp"

Text::Text(std::vector<float> pos, std::string text, float size) : AStaticObject(pos)
{
    _font = LoadFontEx("resources/font/dohyeon.ttf", 96, 0, 0);
    _text = text;
    _size = size;
    // _pos.x = pos.at(0);
    // _pos.y = pos.at(1);
}

Text::~Text()
{
}

void Text::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    DrawTextEx(_font, _text.c_str(), _pos, _size, 0, BLACK);
}