/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Brick
*/

#ifndef BRICK_HPP_
#define BRICK_HPP_

#include "IndieStudio.hpp"

#include "AMoveableObject.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class ids::Brick : public AMoveableObject {
    public:
        Brick(std::vector<float> pos, std::string const &texture);
        ~Brick();
        std::string const getType() const;

        const ItemType &getItemType() const;

    protected:
    private:

        void setItemType();

        ItemType _itemType;
};

#endif /* !BRICK_HPP_ */
