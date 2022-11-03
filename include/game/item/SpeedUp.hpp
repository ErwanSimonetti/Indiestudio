/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** SpeedUp
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "IndieStudio.hpp"
#include "raylib.h"
#include "AItem.hpp"

class ids::SpeedUp : public AItem  {
    public:
        SpeedUp(std::vector<float> pos, Texture texture);
        ~SpeedUp();
        std::string const getType() const;

    protected:
    private:
};

#endif /* !SPEEDUP_HPP_ */
