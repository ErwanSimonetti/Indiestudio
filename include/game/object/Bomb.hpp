/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "AMoveableObject.hpp"
#include "Player.hpp"

#include <vector>
#include <memory>

class ids::Bomb : public ids::AMoveableObject {
    public:
        Bomb(std::vector<float> pos, std::string const &texture, ids::ACharacter &owner, int fireUp, bool wallUp);
        ~Bomb();
        std::string const getType() const;

        bool checkAddTimer();
        int getFireUp() const;
        bool getWallUp() const;
        void setFireUp(int newVal);
        void setWallUp(bool newVal);

    protected:
    private:
        ids::ACharacter &_ownerPlayer;
        int _elapsedTimer;
        int _fireUp;
        bool _wallUp;
};


#endif /* !BOMB_HPP_ */
