/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** ACharacter
*/

#include "IndieStudio.hpp"
#include "ACharacter.hpp"
#include "MapManager.hpp"
#include "Bomb.hpp"
#include "ACharacter.hpp"

#include <cmath>

ids::ACharacter::ACharacter(std::vector<float> pos, int id, std::string const &texture) : AMoveableObject(pos)
{
    _id = id;
    _speedUp = 0;
    _speed = 0.04f;
    _isAnimable = true;
    _inventory.speedUp = 0;
    _inventory.bombUp = 1;
    _inventory.nbBomb = 1;
    _inventory.fireUp = 1;
    _inventory.wallUp = false;
    _inventory.speed = 0.04f;
    _saveX = 0;
    _saveY = 0;
    _canPutBomb = true;
    _texture = LoadTexture(texture.c_str());
    _isDead = false;
    _isBot = true;
    _iscutscene = false;
    _rotation = {0.0f, 1.0f, 0.0f};
}

ids::ACharacter::~ACharacter()
{
}

Texture ids::ACharacter::getTexture() const
{
    return _texture;
}

std::string const ids::ACharacter::getType() const
{
    return "player";
}

float ids::ACharacter::getSpeed() const
{
    return _speed;
}

int ids::ACharacter::getSpeedUp() const
{
    return _inventory.speedUp;
}

int ids::ACharacter::getId() const
{
    return _id;
}

void ids::ACharacter::incrementSpeedUp()
{
    _inventory.speedUp += 1;
}

bool ids::ACharacter::getisDead() const
{
    return _isDead;
}

void ids::ACharacter::setDirection(std::string direction)
{
    _isAnimable = true;
    if (direction == "left") _direction = -90;
    if (direction == "right") _direction = 90;
    if (direction == "up") _direction = 180;
    if (direction == "down") _direction = 0;
}

void ids::ACharacter::setIsDead(bool isDead)
{
    _isDead = isDead;
}

void ids::ACharacter::setRotation(std::vector<float> rotation, float direction)
{
    _rotation = rotation;
    _direction = direction;
}

void ids::ACharacter::setCutscene()
{
    _iscutscene = true;
}

void ids::ACharacter::drawAsset(std::map<std::string, ModelS> modelMap, bool updateAnim)
{
    if (_isDead)
        return;
    if (_isAnimable && updateAnim) updateAnimation(modelMap);
    UpdateModelAnimation(modelMap.find(getType())->second.model, modelMap.find(getType())->second.animation[0], _frameCounter);
    if (!_iscutscene)
        _isAnimable = false;
    modelMap.find(getType())->second.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
    DrawModelEx(modelMap.find(getType())->second.model, {getPosition("x"), getPosition("z"), getPosition("y")}, {_rotation.at(0), _rotation.at(1), _rotation.at(2)}, _direction, modelMap.find(getType())->second.size, WHITE);
}

void ids::ACharacter::putBomb(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen)
{
    if (_isDead || _inventory.nbBomb <= 0)
        return;
    if (!mapGen.isTileFree(std::round(getPosition("x")), std::round(getPosition("y"))) || !_canPutBomb)
        return;
    _saveX = std::round(getPosition("x"));
    _saveY = std::round(getPosition("y"));
    std::shared_ptr<ids::Bomb> newBomb = std::make_shared<ids::Bomb>(std::vector<float>{_saveX, _saveY, -0.5f}, "resources/textures/textureBomb.png", *this, _inventory.fireUp, _inventory.wallUp);
    _inventory.nbBomb -= 1;
    assetVector.emplace_back(newBomb);
    bombVector.emplace_back(newBomb);
    _canPutBomb = false;
}

void ids::ACharacter::changeTile(MapManager &mapGen)
{
    if (_isDead)
        return;
    mapGen.setBoxMapObject(_saveY, _saveX, BoxMap::BombObject);
    _canPutBomb = true;
    _saveY = 0;
    _saveX = 0;
}

void ids::ACharacter::updateBombNumber(int value)
{
    _inventory.nbBomb += value;
}

std::vector<int> ids::ACharacter::handleMoveCollision(std::vector<std::string> const &directions, MapManager &mapGen, std::vector<float> posInfos)
{
    setDirection(directions.at(0));
    float check = directions.at(1) == "x" ? _posY - static_cast<int>(_posY) : _posX - static_cast<int>(_posX);
    if (!mapGen.isTileFree(posInfos.at(0), posInfos.at(1)) || (check > 0.2 && check < 0.8))
        return {};
    
    bool foundItem = false;

    setPostition(directions.at(1), (_inventory.speed + _inventory.speedUp * _inventory.speed/5) * posInfos.at(3));
    int x = std::round(_posX - 0.1 * posInfos.at(3));
    int y = std::round(_posY - 0.1 * posInfos.at(3));
    auto boxMap = mapGen.getBoxMap();
    if (boxMap.at(y).at(x) == ids::BoxMap::FireUp) {
        _inventory.fireUp++;
        foundItem = true;
    }
    if (boxMap.at(y).at(x) == ids::BoxMap::BombUp) {
        _inventory.bombUp++;
        _inventory.nbBomb++;
        foundItem = true;
    }
    if (boxMap.at(y).at(x) == ids::BoxMap::WallUp) {
        _inventory.wallUp = true;
        foundItem = true;
    }
    if (boxMap.at(y).at(x) == ids::BoxMap::SpeedUp) {
        _inventory.speedUp++;
        foundItem = true;
    }

    if (foundItem) {
        mapGen.setBoxMapObject(y, x, ids::BoxMap::Unknown);
        return std::vector<int>{x, y};
    }
    return {};
}

std::vector<int> ids::ACharacter::move(Action event, MapManager &mapGen)
{
    if (_isDead)
        return {};
    int currentX = std::round(getPosition("x"));
    int currentY = std::round(getPosition("y"));

    if (mapGen.getStaticMap().empty()) {
        std::cout << "Move : Empty static Map" << std::endl;
    }

    std::vector<int> itemPos = {};
    if (event == Action::MOVE_LEFT)
        itemPos = handleMoveCollision(std::vector<std::string>{"left", "x"}, mapGen, std::vector<float>{std::round(getPosition("x") - 0.51f), std::round(getPosition("y")), std::ceil(getPosition("y")) - getPosition("y"), -1});
    if (event == Action::MOVE_RIGHT)
        itemPos = handleMoveCollision(std::vector<std::string>{"right", "x"}, mapGen, std::vector<float>{std::round(getPosition("x") + 0.51f), std::round(getPosition("y")), std::ceil(getPosition("y")) - getPosition("y"), 1});
    if (event == Action::MOVE_UP)
        itemPos = handleMoveCollision(std::vector<std::string>{"up", "y"}, mapGen, std::vector<float>{std::round(getPosition("x")), std::round(getPosition("y") - 0.51f), std::ceil(getPosition("x")) - getPosition("x"), -1});
    if (event == Action::MOVE_DOWN)
        itemPos = handleMoveCollision(std::vector<std::string>{"down", "y"}, mapGen, std::vector<float>{std::round(getPosition("x")), std::round(getPosition("y") + 0.51f), std::ceil(getPosition("x")) - getPosition("x"), 1});
    if ((currentX != std::round(getPosition("x"))) || (currentY != std::round(getPosition("y")))) changeTile(mapGen);

    return itemPos;
}
