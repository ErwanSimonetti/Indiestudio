/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** FireUp
*/

#ifndef FIREUP_HPP_
#define FIREUP_HPP_

#include "IndieStudio.hpp"
#include "raylib.h"
#include "AItem.hpp"

class ids::FireUp : public AItem {
    public:
        FireUp(std::vector<float> pos, Texture texture);
        ~FireUp();
        std::string const getType() const;

    protected:
    private:
};

#endif /* !FIREUP_HPP_ */
