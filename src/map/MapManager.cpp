/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Map Generator
*/

#include "MapManager.hpp"
#include <iostream>

ids::MapManager::MapManager()
{
	loadItemTexture();
}

ids::MapManager::~MapManager()
{
}

void ids::MapManager::loadItemTexture()
{
	_itemTexture.emplace_back(LoadTexture("resources/textures/itemBomb.png"));
	_itemTexture.emplace_back(LoadTexture("resources/textures/itemSpeed.png"));
	_itemTexture.emplace_back(LoadTexture("resources/textures/itemFire.png"));
	_itemTexture.emplace_back(LoadTexture("resources/textures/itemWall.png"));
}

const std::vector<std::vector<ids::StaticMap>> &ids::MapManager::getStaticMap() const
{
    return _staticMapVector2;
}

std::vector<std::vector<ids::StaticMap>> &ids::MapManager::getStaticMapFromFile(const std::string &path, bool save)
{
	std::ifstream inputFile(path);
	std::string line;
	bool first = false;
	int y = 0;
	int x = 0;

	_staticMapVector2.clear();
    if (!inputFile.is_open()) {
        std::cerr << "Error: " << path << " does not exists." <<  std::endl;
        return getStaticMapFromFile("assets/map/default.map", save);
    }

    while (std::getline(inputFile, line)) {
		y++;
		if (!first) {
			x = line.length();
			first = true;
		}
        _staticMapVector2.emplace_back(stringToStaticMap(line));
    }
	_size = std::make_tuple(y, x);
	if (save) {
		this->initBoxMap();
		this->initBlockedSpaces();
		this->generateBoxMapFromSave();
	}
    return _staticMapVector2;
}


std::vector<ids::StaticMap> ids::MapManager::stringToStaticMap(const std::string &line)
{
    std::vector<StaticMap> result;

    for (auto const &c: line) {
        result.emplace_back(static_cast<StaticMap>(c));
    }
    return result;
}

bool ids::MapManager::checkIfIsGoodPlace(std::tuple<int, int> temp) noexcept
{
	for (auto vec: _blockedSpaces) {
		if (vec == temp) {
			return false;
		}
	}
	return true;
}

std::map<std::string, std::vector<std::shared_ptr<ids::IAsset>>> &ids::MapManager::transformIAsset()
{
	std::vector<std::shared_ptr<IAsset>> moveable;
	std::vector<std::shared_ptr<IAsset>> bonus_wall;
	float x = 0;
	float y = 0;
	float z = 0;

	for (auto vec : _staticMapVector2) {
		for (auto item: vec) {
			if (item == StaticMap::Walls)
				moveable.emplace_back(std::make_shared<Wall>(std::vector<float>{x, y, z}));
			x += 1;
		}
		x = 0;
		y += 1;
	}
	y = 0;
	x = 0;

	_map["static"] = moveable;

	for (auto vec : _boxMapVector2) {
		for (auto item: vec) {
			if (item == BoxMap::Box) {
				bonus_wall.emplace_back(std::make_shared<Brick>(std::vector<float>{x, y, z}, "resources/gray_brick.png"));
			}
			x += 1;
		}
		x = 0;
		y += 1;
	}
	_map["moveable"] = bonus_wall;
	return _map;
}

bool ids::MapManager::isTileFree(int x, int y) const
{
	bool res = true;

	if (this->_staticMapVector2[y][x] == StaticMap::Walls ||
		this->_boxMapVector2[y][x] == BoxMap::Box ||
		this->_boxMapVector2[y][x] == BoxMap::BombObject)

		res = false;
	return res;
}

std::shared_ptr<ids::IAsset> ids::MapManager::breakBrick(const ids::Brick &b)
{
	std::map<ItemType, std::function<std::shared_ptr<IAsset>(std::vector<float>)>>
        factory;
	_itemTexture;
	for (auto &it: _activeHandle) {
		switch (it) {
			case ItemType::None:
				factory[ItemType::None] =  [](const std::vector<float> &p){return nullptr;};
				break;
			case ItemType::WallUp:
				factory[ItemType::WallUp] = [=](const std::vector<float> &p){return std::make_shared<WallUp>(p, _itemTexture.at(3));};
				break;
			case ItemType::SpeedUp:
				factory[ItemType::SpeedUp] = [=](const std::vector<float> &p){return std::make_shared<SpeedUp>(p, _itemTexture.at(1));};
			case ItemType::BombUp:
				factory[ItemType::BombUp] = [=](const std::vector<float> &p){return std::make_shared<BombUp>(p, _itemTexture.at(0));};
				break;
			case ItemType::FireUp:
				factory[ItemType::FireUp] = [=](const std::vector<float>& p){return std::make_shared<FireUp>(p, _itemTexture.at(2));};
				break;
			default:
				break;
		}
	}
	auto it = factory[b.getItemType()];
	if (!it) {
		return nullptr;
	}
	return it(b.getCoords());
}

std::shared_ptr<ids::IAsset> ids::MapManager::breakBrick(std::shared_ptr<ids::IAsset> asset)
{
	if (asset->getType() != "brick") return nullptr;

	std::shared_ptr<ids::Brick> brick_ptr = std::dynamic_pointer_cast<ids::Brick>(asset);

	if (brick_ptr == nullptr) return nullptr;

	return breakBrick(*brick_ptr.get());
}

void ids::MapManager::setBoxMapObject(float y, float x, BoxMap boxMap)
{
	if (_boxMapVector2.size() >= y && _boxMapVector2.at(y).size() >= x) {
		_boxMapVector2.at(y).at(x) = boxMap;
	}
}