/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include <memory>
#include <map>
#include <algorithm>

#include "IndieStudio.hpp"
#include "IAsset.hpp"
#include "MapManager.hpp"
#include "event.hpp"
#include "Player.hpp"
#include "Bomb.hpp"
#include "Fire.hpp"
#include "SpeedUp.hpp"
#include "Bot.hpp"
#include "ImageSprite.hpp"

class ids::Game {
    public:
        Game();
        ~Game();

        std::vector<std::shared_ptr<IAsset>> getMovableAssets() const;
        std::vector<std::shared_ptr<IAsset>> getStaticAssets() const;

        std::string getWinner();
        void setCharacters(std::vector<playerMenu_t> playerS);
        void setMap(std::vector<ItemType> itemTypes);
        gameState update(std::vector<Input> inputs);
        bool hasBombExplosed();
        bool hasPlayerDied();
        bool isRunning();

        void setIsRunning(bool value);
        IAsset &getMovableAsset(int x, int y);
        std::vector<std::shared_ptr<ids::IAsset>> get2DVectorSprite();
		bool save_map();
    private:
        template <typename T>
        std::vector<int> getIAssetIndexesByPosAndType(std::vector<std::shared_ptr<T>> &assetVector, float x, float y, std::vector<std::string> types);
        template <typename T>
        bool deleteFromAssetVector(std::vector<std::shared_ptr<T>> &assetVector, std::vector<int> assetIndexes);
        void bombExplosionCollision(float x, float y, int bombIndex, bool &boolean, std::vector<std::string> types);
        void updateBombTimer();
        void bombDestruction(float x, float y, int bombIndex, std::vector<std::string> types);
        void manageFireDeletion();
        bool isEnd();
        
        std::vector<std::shared_ptr<IAsset>> _moveableAssetVector;
        std::vector<std::shared_ptr<IAsset>> _staticAssetVector;
        MapManager _mapGen;
        std::vector<int> _lastAliveCharactersIndexes;
        bool _hasBombExplosed;
        bool _hasPlayerDied;
        bool _isRunning;

        //Game
        std::vector<std::shared_ptr<ACharacter>> _bombermanVector;
        std::vector<std::shared_ptr<ids::Bomb>> _bombVector;
        std::vector<std::shared_ptr<ids::Fire>> _fireVector;
        std::vector<std::shared_ptr<ids::IAsset>> _2DSprite;
};

#endif /* !GAME_HPP_ */
