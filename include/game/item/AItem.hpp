/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AItem
*/

#ifndef AITEM_HPP_
#define AITEM_HPP_

#include "IndieStudio.hpp"

#include "AMoveableObject.hpp"

class ids::AItem : public AMoveableObject {
    public:
        AItem(std::vector<float> pos);
        ~AItem();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);

    protected:
        Texture _texture;
    private:
};

#endif /* !AITEM_HPP_ */
