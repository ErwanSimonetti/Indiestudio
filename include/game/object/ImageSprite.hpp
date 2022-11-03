/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "IndieStudio.hpp"
#include "ASpriteObject.hpp"

class ids::ImageSprite : public ASpriteObject {
    public:
        ImageSprite(std::vector<float> pos, std::string const &texture);
        ~ImageSprite();
        std::string const getType() const;

    protected:
    private:
        Image _image;
};

#endif /* !IMAGE_HPP_ */
