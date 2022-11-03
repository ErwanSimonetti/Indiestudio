/*
** EPITECH PROJECT, 2022
** indie_studio
** File description:
** Box.cpp
*/

#include "MapManager.hpp"

void ids::MapManager::initBlockedSpaces() noexcept
{
	int max_size_x = std::get<1>(_size) - 1, max_size_y = std::get<0>(_size) - 1;

	//top left corner
	_blockedSpaces.emplace_back(std::make_pair(1, 1));
	_blockedSpaces.emplace_back(std::make_pair(1, 2));
	_blockedSpaces.emplace_back(std::make_pair(2, 1));

	//top right corner
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 1, 1));
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 1, 2));
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 2, 1));

	// bottom right corner
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 1, max_size_y - 1));
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 2, max_size_y - 1));
	this->_blockedSpaces.emplace_back(std::make_tuple(max_size_x - 1, max_size_y - 2));

	//bottom left corner
	this->_blockedSpaces.emplace_back(std::make_tuple(1, max_size_y - 1));
	this->_blockedSpaces.emplace_back(std::make_tuple(1, max_size_y - 2));
	this->_blockedSpaces.emplace_back(std::make_tuple(2, max_size_y - 1));

}

void ids::MapManager::generateBoxMapFromSave() noexcept
{
	int y = 0, x = 0;

	for (auto &line: _staticMapVector2) {
		for (auto &cases: line) {
			if (cases == StaticMap::Grounds || cases == StaticMap::Walls) {
				x++;
				continue;
			}
			switch (cases) {
				case StaticMap::BoxSave:
					_boxMapVector2[y][x] = BoxMap::Box;
					break;
				 case StaticMap::BombObject:
				 	_boxMapVector2[y][x] = BoxMap::BombObject;
				 	break;
				 case StaticMap::FireUp:
				 	_boxMapVector2[y][x] = BoxMap::FireUp;
				 	break;
				 case StaticMap::SpeedUp:
				 	_boxMapVector2[y][x] = BoxMap::SpeedUp;
				 	break;
				 case StaticMap::WallUp:
				 	_boxMapVector2[y][x] = BoxMap::WallUp;
				 	break;
				default:
					break;
			}
			x++;
		}
		x = 0;
		y += 1;
	}
}

void ids::MapManager::initBoxMap() noexcept
{
	int max_size_x = std::get<1>(_size), max_size_y = std::get<0>(_size);

	for (int col = 0; col <= max_size_y; col++) {
		std::vector<BoxMap> tmp;
		for (int row = 0; row < max_size_x; row++)
			tmp.emplace_back(BoxMap::Unknown);
		_boxMapVector2.emplace_back(tmp);
	}

}

void ids::MapManager::generateBoxMap(std::vector<ItemType> activeHandle) noexcept
{
	int x = 0, y = 0, count = NBR_BLOCK;
	int max_size_x = std::get<1>(_size), max_size_y = std::get<0>(_size);

	_activeHandle = activeHandle;
	this->_boxMapVector2.clear();
	this->initBoxMap();
	this->initBlockedSpaces();
	srand (time(NULL));

	this->initBoxMap();
	this->initBlockedSpaces();
	srand (time(NULL));
	while (count != 0) {
		y = rand() % max_size_y;
		x = rand() % max_size_x;
		if (this->checkIfIsGoodPlace(std::make_pair(x, y))
		    && (x >= 0 && x <= max_size_x) && (y >= 0 && y <= max_size_y)
		    && this->_staticMapVector2[y][x] == StaticMap::Grounds) {
			this->_boxMapVector2[y][x] = BoxMap::Box;
			count -= 1;
			continue;
		}
	}
}

const std::vector<std::vector<ids::BoxMap>> &ids::MapManager::getBoxMap() const noexcept
{
	return _boxMapVector2;
}