/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Bot
*/

#ifndef BOT_HPP_
#define BOT_HPP_

#include "IndieStudio.hpp"

#include "ACharacter.hpp"

class ids::Bot : public ACharacter {
    public:
        Bot(std::vector<float> pos, int id, std::string const &texture, std::vector<std::shared_ptr<ids::ACharacter>> &bombermanVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVectorGame);
        ~Bot();

        std::vector<int> handleEvents(std::vector<std::shared_ptr<IAsset>> &assetVector, std::vector<std::shared_ptr<ids::Bomb>> &bombVector, MapManager &mapGen, Input input) override;
        void stopMovement(void);
    private:
        bool isInTheMiddleOfTile(void);
        bool isBotOnLineOrColumnOfPos(std::pair<int, int> coords, int x, int y);
        bool bombCanTouchBot(MapManager &mapGen, int x, int y);
        void avoidBomb(MapManager &mapGen);
        std::vector<std::string> updatePathsAwayFromBomb(int distanceX, int distanceY, std::vector<std::string> &vectorsToGo);
        std::vector<std::pair<int, int>> getBombsCoords(void);
        bool knowsWhatToDo(void);
        std::vector<int> finishMovement(MapManager &mapGen);
        void handlePathFinding(MapManager &mapGen);
        void updateCollisionMap(MapManager &mapGen);
        void moveAtEmptyTile(MapManager &mapGen, std::vector<std::string> directions);
        bool playerAtThisPos(int x, int y);
        void moveTowardsEnnemy(MapManager &mapGen);
        std::pair<int, int> getCloserEnnemyCoords(void);
        void avoidDangerousMovement(MapManager &mapGen, std::vector<std::string> &directions);
        bool stuckAtWall(void);
        void getAway(MapManager &mapGen);

        bool _moving_left;
        bool _moving_right;
        bool _moving_up;
        bool _moving_down;
        bool _chasing_mode;
        std::vector<std::string> _collisionMap;
        const std::vector<std::shared_ptr<ACharacter>> &_bombermanVector;
        std::vector<std::shared_ptr<ids::Bomb>> &_bombVector;
        
};

#endif /* !BOT_HPP_ */
