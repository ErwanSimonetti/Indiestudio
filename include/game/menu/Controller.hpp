/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Input
*/

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "IndieStudio.hpp"
#include "raylib.h"
#include "ButtonText.hpp"

#include <utility>
#include <vector>
#include <iostream>
#include <memory>

static std::map<Input, std::string> keyboardChar = {
    {Input::ENTER, "ENTER"},
    {Input::BACKSPACE, "<-"},
    {Input::SPACE, "_"},
    {Input::ESCAPE, "ESP"},
    {Input::UP_ARROW, "^"},
    {Input::DOWN_ARROW, "v"},
    {Input::LEFT_ARROW, "<-"},
    {Input::RIGHT_ARROW, "->"},
    {Input::Q_KEY, "Q"},
    {Input::B_KEY, "B"},
    {Input::C_KEY, "C"},
    {Input::D_KEY, "D"},
    {Input::E_KEY, "E"},
    {Input::F_KEY, "F"},
    {Input::G_KEY, "G"},
    {Input::H_KEY, "H"},
    {Input::I_KEY, "I"},
    {Input::J_KEY, "J"},
    {Input::K_KEY, "K"},
    {Input::L_KEY, "L"},
    {Input::M_KEY, "M"},
    {Input::N_KEY, "N"},
    {Input::O_KEY, "O"},
    {Input::P_KEY, "P"},
    {Input::A_KEY, "A"},
    {Input::R_KEY, "R"},
    {Input::S_KEY, "S"},
    {Input::T_KEY, "T"},
    {Input::U_KEY, "U"},
    {Input::V_KEY, "V"},
    {Input::Z_KEY, "Z"},
    {Input::X_KEY, "X"},
    {Input::Y_KEY, "Y"},
    {Input::W_KEY, "W"},
    {Input::Num_0, "0"},
    {Input::Num_1, "1"},
    {Input::Num_2, "2"},
    {Input::Num_3, "3"},
    {Input::Num_4, "4"},
    {Input::Num_5, "5"},
    {Input::Num_6, "6"},
    {Input::Num_7, "7"},
    {Input::Num_8, "8"},
    {Input::Num_9, "9"},
    {Input::F1, "F1"},
    {Input::F2, "F2"},
    {Input::F3, "F3"},
    {Input::F4, "F4"},
    {Input::F5, "F5"},
    {Input::F6, "F6"},
    {Input::F7, "F7"},
    {Input::F8, "F8"},
    {Input::F9, "F9"},
    {Input::F10, "F10"},
    {Input::F11, "F11"},
    {Input::F12, "F12"},
    {Input::PAGE_UP, "P_UP"},
    {Input::PAGE_DOWN, "P_DOWN"},
};

class ids::Controller {
    public:
        Controller(playerMenu_t &player, ButtonText &textUp, ButtonText &textDown, ButtonText &textLeft,
        ButtonText &textRight, ButtonText &textAction, ButtonText &textController);
        ~Controller();
        void switchUpKey();
        void switchDownKey();
        void switchRightKey();
        void switchLeftKey();
        void switchActionKey();
        void switchController();
        
        void updateKeyBind(Input input);

    protected:
    private:
        playerMenu_t &_player;
        bool _setUpKey;
        bool _setDownKey;
        bool _setRigthKey;
        bool _setLeftKey;
        bool _setActionKey;
        bool _setControllerKey;

        std::map<Action, Input> _savedControls;
        ButtonText &_textUp;
        ButtonText &_textDown;
        ButtonText &_textLeft;
        ButtonText &_textRight;
        ButtonText &_textAction;
        ButtonText &_textController;

};

#endif /* !INPUT_HPP_ */