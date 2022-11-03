/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Brick
*/

#include "Brick.hpp"

ids::Brick::Brick(std::vector<float> pos, std::string const &texture) : AMoveableObject(pos)
{
    setItemType();
}

ids::Brick::~Brick()
{
}

std::string const ids::Brick::getType() const
{
    return "brick";
}

const ids::ItemType &ids::Brick::getItemType() const
{
    return _itemType;
}

void ids::Brick::setItemType()
{
    bool hasItem = (std::rand() % 100) < 50;

    if (!hasItem)
    {
        _itemType = ItemType::None;
        return;
    }

    short num = std::rand() % 4;

    switch (num)
    {
    case 0:
        _itemType = ItemType::BombUp;
        break;

    case 1:
        _itemType = ItemType::FireUp;
        break;

    case 2:
        _itemType = ItemType::SpeedUp;
        break;

    default:
        _itemType = ItemType::WallUp;
        break;
    }
}