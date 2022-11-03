/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Font
*/

#include "ButtonText.hpp"
#include <iostream>

ids::ButtonText::ButtonText(std::vector<float> pos, std::string text, float size, ids::ButtonAction &action, std::vector<ItemType> &choosenItem, playerMenu_t &player) :
AStaticObject(pos), _action(action), _choosenItem(choosenItem), _player(player)
{
    _font = LoadFontEx("resources/font/dohyeon.ttf", 96, 0, 0);
    _text = text;
    _size = size;
    _pos.x = pos.at(0);
    _pos.y = pos.at(1);

    _fps = 90;
    _sound = 50;
    SetTargetFPS(_fps); 

    _fireUp = true;
    _bombUp = true;
    _speedUp = true;
    _WallUp = true;
}

ids::ButtonText::~ButtonText()
{
}

void ids::ButtonText::setText(std::string text)
{
    _text = text;
}
std::string const ids::ButtonText::getText() const
{
    return _text;
}
void ids::ButtonText::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    DrawTextEx(_font, _text.c_str(), _pos, _size, 0, WHITE);
}

void ids::ButtonText::increaseFPS()
{
    if (_fps < 150)
        _fps += 30;
    _text = std::to_string(_fps);
    SetTargetFPS(_fps); 
}

void ids::ButtonText::decreaseFPS()
{
    if (_fps > 60)
        _fps -= 30;
    _text = std::to_string(_fps);
    SetTargetFPS(_fps);
}

void ids::ButtonText::increaseSound()
{
    if (_sound < 100)
        _sound += 1;
    _text = std::to_string(_sound);
    auto audioS = _action.getAudioStruct();
    float volume = _sound/50.0f;
    if (_sound == 69)
        volume = 10;
    SetMusicVolume(audioS.menuMusic, volume);
    SetMusicVolume(audioS.gameMusic, volume);
    SetSoundVolume(audioS.playerDeath, volume);
    SetSoundVolume(audioS.bombExplosion, volume);
}

void ids::ButtonText::decreaseSound()
{
    if (_sound > 1)
        _sound -= 1;
    _text = std::to_string(_sound);
    auto audioS = _action.getAudioStruct();
    float volume = _sound/50.0f;
    if (_sound == 69)
        volume = 10;
    SetMusicVolume(audioS.menuMusic, volume);
    SetMusicVolume(audioS.gameMusic, volume);
    SetSoundVolume(audioS.playerDeath, volume);
    SetSoundVolume(audioS.bombExplosion, volume);
}

void ids::ButtonText::fireUpValue()
{
    if (_fireUp) {
        _fireUp = false;
        _text = "OFF";
        _choosenItem.erase(_choosenItem.begin() + std::distance(_choosenItem.begin(), (std::find(_choosenItem.begin(), _choosenItem.end(), ItemType::FireUp))));
    }
    else {
        _fireUp = true;
        _text = "ON";
        _choosenItem.emplace_back(ItemType::FireUp);
    }
}

void ids::ButtonText::bombUpValue()
{
    if (_bombUp) {
        _bombUp = false;
        _text = "OFF";
        _choosenItem.erase(_choosenItem.begin() + std::distance(_choosenItem.begin(), (std::find(_choosenItem.begin(), _choosenItem.end(), ItemType::BombUp))));
    }
    else {
        _bombUp = true;
        _text = "ON";
        _choosenItem.emplace_back(ItemType::BombUp);
    }
}

void ids::ButtonText::speedUpValue()
{
    if (_speedUp) {
        _speedUp = false;
        _text = "OFF";
        _choosenItem.erase(_choosenItem.begin() + std::distance(_choosenItem.begin(), (std::find(_choosenItem.begin(), _choosenItem.end(), ItemType::SpeedUp))));
    }
    else {
        _speedUp = true;
        _text = "ON";
        _choosenItem.emplace_back(ItemType::SpeedUp);
    }
}

void ids::ButtonText::WallUpValue()
{
    if (_WallUp) {
        _WallUp = false;
        _text = "OFF";
        _choosenItem.erase(_choosenItem.begin() + std::distance(_choosenItem.begin(), (std::find(_choosenItem.begin(), _choosenItem.end(), ItemType::WallUp))));
    }
    else {
        _WallUp = true;
        _text = "ON";
        _choosenItem.emplace_back(ItemType::WallUp);
    }
}

void ids::ButtonText::switchPlayerBot()
{
    if (_player._isBot) {
        _text = "PLAYER";
        _player._isBot = false;
    } else {
        _text = "BOT";
        _player._isBot = true;
    }
}