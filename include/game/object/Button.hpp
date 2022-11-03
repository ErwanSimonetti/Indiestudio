/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "IndieStudio.hpp"
#include "ASpriteObject.hpp"

template < class C, class Tr, class... Args >
class ids::Button : public ids::ASpriteObject {
    public:
    typedef void(C::*eventMethod)(Args...);
        Button(std::vector<float> pos, std::string texture, int frame, C& target, eventMethod method, gameState &state): ASpriteObject (pos, texture, frame), 
        _method(method), _target(target), _gameState(state) { };
        ~Button(){};

        bool operator () ( Args&... args ) const {
        (_target.*(_method))(args...);
        }

        std::string const getType() const {return "button";};

        void checkCollisions() {
        if (CheckCollisionPointRec(GetMousePosition(), _bounds)) {
            _state = HOVERED;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                _state = PRESSED;
                (_target.*_method)();
            }
        } else 
        _state = OFF;
        _sourceRect.y = _state*_frameHeight;
        };

        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim) {
            DrawTextureRec(_texture, _sourceRect,  { _bounds.x, _bounds.y }, WHITE);
            checkCollisions();
        }

    protected:
    private:
        gameState &_gameState;
        eventMethod _method;
        C& _target;
};

#endif /* !BUTTON_HPP_ */
