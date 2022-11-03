/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AMoveableObject
*/

#ifndef AMOVEABLEOBJECT_HPP_
#define AMOVEABLEOBJECT_HPP_

#include "IndieStudio.hpp"

#include "AAsset.hpp"

class ids::AMoveableObject: public AAsset {
    public:
        AMoveableObject(std::vector<float> pos);
        ~AMoveableObject();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);
        void updateAnimation(std::map<std::string, ModelS> modelMap);
        void setDirection(std::string const &direction);
        float getDirection() const;
        float getFramecounter() const;

    protected:
        float _direction;
        int _frameCounter;
    private:
        bool _isAnimable;
        PlayerS _inventory;
};

#endif /* !AMOVEABLEOBJECT_HPP_ */
