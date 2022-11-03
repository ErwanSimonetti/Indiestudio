/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** WallUp
*/

#ifndef WallUp_HPP_
#define WallUp_HPP_

#include "IndieStudio.hpp"
#include "AItem.hpp"
#include "raylib.h"

class ids::WallUp : public AItem {
    public:
        WallUp(std::vector<float> pos, Texture texture);
        ~WallUp();
        std::string const getType() const;

    protected:
    private:
};

#endif /* !WallUp_HPP_ */
