/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "IndieStudio.hpp"

#include "AStaticObject.hpp"
#include <vector>

class ids::Wall : public AStaticObject {
    public:
        Wall(std::vector<float> pos);
        ~Wall();
        std::string const getType() const;
    protected:
    private:
};

#endif /* !WALL_HPP_ */
