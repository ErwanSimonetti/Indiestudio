/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include "raylib.h"

struct ModelS {
    Model model;
    ModelAnimation *animation;
    Vector3 size;
    Texture texture;
};

struct PlayerS {
    int speedUp;
    int bombUp;
    int fireUp;
    bool wallUp;
    float speed;
    int nbBomb;
};


#endif /* !CONFIG_HPP_ */
