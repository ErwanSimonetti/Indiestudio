/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** BombUp
*/

#ifndef BOMBUP_HPP_
#define BOMBUP_HPP_

#include "IndieStudio.hpp"
#include "AItem.hpp"
#include "raylib.h"

class ids::BombUp : public AItem {
    public:
        BombUp(std::vector<float> pos, Texture texture);
        ~BombUp();
        std::string const getType() const;

    protected:
    private:
};

#endif /* !BOMBUP_HPP_ */
