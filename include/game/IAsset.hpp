/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** IAsset
*/

#ifndef IASSET_HPP_
#define IASSET_HPP_

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <raylib.h>

#include "IndieStudio.hpp"

#include "config.hpp"

class ids::IAsset {
    public:
        IAsset() = default;
        ~IAsset() = default;
        virtual float getPosition(std::string const &vector) const = 0;
        virtual std::string const getType() const = 0;
        virtual void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim) = 0;
};

#endif /* !IASSET_HPP_ */