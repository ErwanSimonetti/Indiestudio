/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** ASpriteObject
*/

#ifndef ASPRITEOBJECT_HPP_
#define ASPRITEOBJECT_HPP_

#include "AAsset.hpp"

enum ButtonState {
    OFF,
    HOVERED,
    PRESSED
};

class ids::ASpriteObject : public ids::AAsset {
    public:
        ASpriteObject(std::vector<float> pos, std::string const &texture, int frame);
        ~ASpriteObject();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);
        void checkCollisions();

    protected:
        Texture2D _texture;
        float _frameHeight;
        Rectangle _sourceRect;
        Rectangle _bounds;
        int _state;
    private:
};

#endif /* !ASPRITEOBJECT_HPP_ */
