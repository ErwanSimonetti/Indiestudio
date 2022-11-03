/*
** EPITECH PROJECT, 2022
** Indie Studio
** File description:
** Map Generator
*/

#pragma once

#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <functional>

#include "raylib.h"
#include "IndieStudio.hpp"
#include "ErrorHandler.hpp"
#include "IAsset.hpp"
#include "Wall.hpp"
#include "Brick.hpp"
#include "Ground.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "SpeedUp.hpp"
#include "WallUp.hpp"

#define NBR_BLOCK 300

class ids::MapManager {
    public:
        MapManager();
        ~MapManager();

		void initBlockedSpaces() noexcept;

        const std::vector<std::vector<StaticMap>> &getStaticMap() const;
        std::vector<std::vector<StaticMap>> &getStaticMapFromFile(const std::string&filePath, bool save);
        const std::vector<std::vector<BoxMap>> &getBoxMap() const noexcept;

        void setBoxMapObject(float y, float x, BoxMap);
		void generateBoxMap(std::vector<ItemType> vector) noexcept;

		bool checkIfIsGoodPlace(std::tuple<int, int> temp) noexcept;
        bool isTileFree(int x, int y) const;

        void loadItemTexture();

		std::map<std::string, std::vector<std::shared_ptr<IAsset>>>  &transformIAsset();

        bool save(const std::string &filename) noexcept;

        std::shared_ptr<IAsset> breakBrick(const Brick &brick);
        std::shared_ptr<IAsset> breakBrick(std::shared_ptr<IAsset> asset);


    protected:
    private:
		void initBoxMap() noexcept;
		void generateBoxMapFromSave() noexcept;

		std::vector<StaticMap> stringToStaticMap(const std::string& line);
        std::vector<std::vector<StaticMap>> _staticMapVector2;
        std::vector<std::vector<BoxMap>> _boxMapVector2;
        std::vector<std::tuple<int, int>> _blockedSpaces;
        std::tuple<int, int> _size;
        std::map<std::string, std::vector<std::shared_ptr<IAsset>>> _map;
		std::vector<ItemType> _activeHandle;
        std::vector<Texture> _itemTexture;
};
