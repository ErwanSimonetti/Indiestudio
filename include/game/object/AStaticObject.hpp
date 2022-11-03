/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** AStaticObject
*/

#ifndef ASTATICOBJECT_HPP_
#define ASTATICOBJECT_HPP_

#include "IndieStudio.hpp"

#include "AAsset.hpp"

class ids::AStaticObject : public AAsset {
    public:
        AStaticObject(std::vector<float> pos);
        ~AStaticObject();
        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);

    protected:
    private:
};

#endif /* !ASTATICOBJECT_HPP_ */
