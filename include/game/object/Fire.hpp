/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include "AMoveableObject.hpp"

class ids::Fire : public ids::AMoveableObject {
    public:
        Fire(std::vector<float> pos, std::string const &texture);
        ~Fire();
        std::string const getType() const;
        bool checkAddTimer();

    private:
        int _elapsedTimer;

};

#endif /* !FIRE_HPP_ */
