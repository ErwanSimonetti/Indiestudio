/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Namespace
*/

#pragma once
#include <map>
#include <iostream>
#include "event.hpp"
#define PATH_SAVE_FILE "assets/save/save.map"

namespace ids
{
    class Game;
    class IAsset;
    class AAsset;

    class ASpriteObject;
    class ImageSprite;

    class AMoveableObject;
    class AStaticObject;
    class Brick;
    class Bomb;
    class Ground;
    class Wall;

    template < class C, class Tr, class... Args >
    class Button;
    class Fire;

    class ButtonText;
    class Controller;

    class AItem;
    class BombUp;
    class FireUp;
    class SpeedUp;
    class WallUp;

    class ACharacter;
    class Bot;
    class Player;

    class Menu;
    class ButtonAction;

    class GameEngine;

    class MapManager;

    class Renderer;

    class ErrorHandler;

    enum class StaticMap
    {
        Grounds = '0',
        Walls = '1',
	    BoxSave = '2',
	    BombObject = '3',
	    FireUp = '4',
	    BombUp = '5',
	    SpeedUp = '6',
	    WallUp = '7'
    };

    enum class BoxMap
    {
        Unknown = ' ',
        Box = '2',
        BombObject = '3',
	    FireUp = '4',
	    BombUp = '5',
	    SpeedUp = '6',
	    WallUp = '7'
    };

    enum gameState {
        GAME,
        MENU,
        PAUSE,
        EXIT,
        SETTINGS,
        GAMESETTINGS,
        CUTSCENE,
        CONTROLLER,
        ENDSCENE
    };

    enum class ItemType
    {
        None = 0,
        BombUp = 1,
        FireUp = 2,
        SpeedUp = 3,
        WallUp = 4
    };

    typedef struct playerMenu_s {
        std::map<Action, Input> _bindingKey;
        bool _isBot;
        std::string _texture;
    } playerMenu_t;
}
