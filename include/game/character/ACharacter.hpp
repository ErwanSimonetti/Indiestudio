/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** ACharacter
*/

#ifndef ACHARACTER_HPP_
#define ACHARACTER_HPP_

#include <memory>

#include "event.hpp"
#include "IndieStudio.hpp"
#include "AMoveableObject.hpp"
#include "MapManager.hpp"

class ids::ACharacter : public AMoveableObject {
    public:
        ACharacter(std::vector<float> pos, int id, std::string const &texture);
        ~ACharacter();
        int getId() const;
        int getSpeedUp() const;
        float getSpeed() const;
        Texture getTexture() const;
        std::string const getType() const;
        bool getisDead() const;

        void setDirection(std::string direction);
        void setIsDead(bool isDead);
        void setRotation(std::vector<float> roation, float direction);
        void setCutscene();

        void drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim);
        void incrementSpeedUp();
        void putBomb(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen);
        std::vector<int> handleMoveCollision(std::vector<std::string> const &directions, MapManager &mapGen, std::vector<float> posInfos);
        std::vector<int> move(Action event, MapManager &mapGen);
        void updateBombNumber(int value);
        void changeTile(MapManager &mapGen);

        virtual std::vector<int> handleEvents(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen, Input input) = 0;

    protected:
        int _id;
        int _speedUp;
        float _speed;
        float _currentSpeed;
        bool _isAnimable;
        PlayerS _inventory;
        float _saveX;
        float _saveY;
        bool _canPutBomb;
        bool _isDead;
        bool _isBot;
        Texture _texture;
        float _direction;
        bool _iscutscene;
        std::vector<float> _rotation;
};

#endif /* !ACHARACTER_HPP_ */
