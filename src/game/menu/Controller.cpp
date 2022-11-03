/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Input
*/

#include "Controller.hpp"

ids::Controller::Controller(playerMenu_t &player, ButtonText &textUp, ButtonText &textDown, ButtonText &textLeft,
ButtonText &textRight, ButtonText &textAction, ButtonText &textController) : _player(player), _textUp(textUp), _textDown(textDown),
_textLeft(textLeft), _textRight(textRight), _textAction(textAction), _textController(textController)
{
    _setUpKey = false;
    _setDownKey = false;
    _setRigthKey = false;
    _setLeftKey = false;
    _setActionKey = false;
    _setControllerKey = false;

    std::map<Action, Input> pad;
    pad.insert(std::pair<Action, Input>(Action::MOVE_UP, Input::FACE_UP));
    pad.insert(std::pair<Action, Input>(Action::MOVE_LEFT, Input::FACE_LEFT));
    pad.insert(std::pair<Action, Input>(Action::MOVE_DOWN, Input::FACE_DOWN));
    pad.insert(std::pair<Action, Input>(Action::MOVE_RIGHT, Input::FACE_RIGHT));
    pad.insert(std::pair<Action, Input>(Action::PUT_BOMB, Input::FACE_A));
    _savedControls = pad;
}

ids::Controller::~Controller()
{
}

void ids::Controller::switchUpKey()
{
    _setUpKey = true;
}

void ids::Controller::switchDownKey()
{
    _setDownKey = true;
}

void ids::Controller::switchRightKey()
{
    _setRigthKey = true;
}

void ids::Controller::switchLeftKey()
{
    _setLeftKey = true;
}

void ids::Controller::switchActionKey()
{
    _setActionKey = true;
}

void ids::Controller::switchController()
{
    _setControllerKey = true;
}

void ids::Controller::updateKeyBind(Input input)
{
    if (_setControllerKey) {
        auto tmp = _savedControls;
        _savedControls = _player._bindingKey;
        _player._bindingKey = tmp;
        _textController.getText() != "PAD" ? _textController.setText("PAD") :
        _textController.setText("KEEB");
        _setControllerKey = false;
    }
    if (input == Input::NO_INPUT)
        return;
    if (_setUpKey) {
        _player._bindingKey.find(Action::MOVE_UP)->second = input;
        _textUp.setText(keyboardChar.find(input)->second);
        _setUpKey = false;
    }
    if (_setDownKey) {
        _player._bindingKey.find(Action::MOVE_DOWN)->second = input;
        _textDown.setText(keyboardChar.find(input)->second);
        _setDownKey = false;
    }
    if (_setRigthKey) {
        _player._bindingKey.find(Action::MOVE_RIGHT)->second = input;
        _textRight.setText(keyboardChar.find(input)->second);
        _setRigthKey = false;
    }
    if (_setLeftKey) {
        _player._bindingKey.find(Action::MOVE_LEFT)->second = input;
        _textLeft.setText(keyboardChar.find(input)->second);
        _setLeftKey = false;
    }
    if (_setActionKey) {
        _player._bindingKey.find(Action::PUT_BOMB)->second = input;
        _textAction.setText(keyboardChar.find(input)->second);
        _setActionKey = false;
    }
}
