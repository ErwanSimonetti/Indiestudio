/*
** EPITECH PROJECT, 2022
** axel indie sutdio
** File description:
** AAsset
*/

#ifndef AASSET_HPP_
#define AASSET_HPP_

#include "IndieStudio.hpp"
#include "IAsset.hpp"

class ids::AAsset : public IAsset {
    public:
        AAsset(std::vector<float> pos);
        ~AAsset();
        void setPostition(std::string const &vector, float pos);
        float getPosition(std::string const &vector) const;
        std::string const getType() const {return "";};
        std::vector<float> getCoords() const;
    protected:
        float _posX;
        float _posY;
        float _posZ;
    private:
        int _frameCounter;
};

#endif /* !AASSET_HPP_ */
