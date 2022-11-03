/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include "IndieStudio.hpp"
#include "AStaticObject.hpp"
#include "ButtonAction.hpp"
#include "raylib.h"

class ids::ButtonText : public ids::AStaticObject {
    public:
        ButtonText(std::vector<float> pos, std::string text, float size, ids::ButtonAction &action, std::vector<ItemType> &choosenItem, playerMenu_t &player);
        ~ButtonText();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);
        void print();
        void increaseFPS();
        void decreaseFPS();
        void increaseSound();
        void decreaseSound();
        void fireUpValue();
        void bombUpValue();
        void speedUpValue();
        void WallUpValue();
        void switchPlayerBot();
        void setText(std::string text);
        std::string const getText() const;
    protected:
    private:
        Font _font;
        std::string _text;
        Vector2 _pos;
        float _size;
        ButtonAction &_action;
        std::vector<ItemType> &_choosenItem;
        playerMenu_t &_player;

        int _fps;
        int _sound;
        bool _fireUp;
        bool _bombUp;
        bool _speedUp;
        bool _WallUp;

};

#endif /* !FONT_HPP_ */
