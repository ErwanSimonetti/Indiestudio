/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include "AStaticObject.hpp"
#include "raylib.h"

class Text : public ids::AStaticObject {
    public:
        Text(std::vector<float> pos, std::string text, float size);
        ~Text();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);

    protected:
    private:
        Font _font;
        std::string _text;
        Vector2 _pos;
        float _size;

};

#endif /* !FONT_HPP_ */
