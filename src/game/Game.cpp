/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Game
*/

#include "Game.hpp"

ids::Game::Game()
{
    _lastAliveCharactersIndexes = {0, 1, 2, 3};
    _hasBombExplosed = false;
    _hasPlayerDied = false;
    _isRunning = false;
}

void ids::Game::setCharacters(std::vector<playerMenu_t> playerS)
{
    _bombermanVector.clear();
    !playerS.at(0)._isBot ?
        _bombermanVector.emplace_back(std::make_shared<Player>(std::vector<float>{1.0f, 1.0f, -0.5f}, 1, "resources/textures/BombermanPink.png", playerS.at(0)._bindingKey))
        :_bombermanVector.emplace_back(std::make_shared<Bot>(std::vector<float>{1.0f, 1.0f, -0.5f}, 1, "resources/textures/BombermanPink.png", _bombermanVector, _bombVector));

    !playerS.at(1)._isBot ?
        _bombermanVector.emplace_back(std::make_shared<Player>(std::vector<float>{1.0f, 13.0f, -0.5f}, 1, "resources/textures/BombermanBlue.png", playerS.at(1)._bindingKey))
        :_bombermanVector.emplace_back(std::make_shared<Bot>(std::vector<float>{1.0f, 13.0f, -0.5f}, 1, "resources/textures/BombermanBlue.png", _bombermanVector, _bombVector));

    !playerS.at(2)._isBot ?
        _bombermanVector.emplace_back(std::make_shared<Player>(std::vector<float>{19.0f, 1.0f, -0.5f}, 1, "resources/textures/BombermanRed.png", playerS.at(2)._bindingKey))
        :_bombermanVector.emplace_back(std::make_shared<Bot>(std::vector<float>{19.0f, 1.0f, -0.5f}, 1, "resources/textures/BombermanRed.png", _bombermanVector, _bombVector));

    !playerS.at(3)._isBot ?
        _bombermanVector.emplace_back(std::make_shared<Player>(std::vector<float>{19.0f, 13.0f, -0.5f}, 1, "resources/textures/BombermanGreen.png", playerS.at(3)._bindingKey))
        :_bombermanVector.emplace_back(std::make_shared<Bot>(std::vector<float>{19.0f, 13.0f, -0.5f}, 1, "resources/textures/BombermanGreen.png", _bombermanVector, _bombVector));

    _moveableAssetVector.insert(_moveableAssetVector.end(), _bombermanVector.begin(), _bombermanVector.end());
}

void ids::Game::setMap(std::vector<ItemType> itemTypes)
{
	std::ifstream inputFile(PATH_SAVE_FILE);

	_moveableAssetVector.clear();
    _staticAssetVector.clear();
    _2DSprite.clear();
    _fireVector.clear();


	if (inputFile.is_open()) {
		_mapGen.getStaticMapFromFile(PATH_SAVE_FILE, true);
	} else {
		_mapGen.getStaticMapFromFile("tests/map/5by5.map", false);
		_mapGen.generateBoxMap(itemTypes);
	}
	auto map = _mapGen.transformIAsset();
    _staticAssetVector =  map["static"];
    _moveableAssetVector =  map["moveable"];

    _2DSprite.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/backgroundGame.png"));

    _staticAssetVector.emplace_back(std::make_shared<Ground>(std::vector<float>{10.0f, 7.0f, -0.5f}));
}


std::vector<std::shared_ptr<ids::IAsset>> ids::Game::get2DVectorSprite()
{
    return _2DSprite;
}

ids::Game::~Game()
{
}

std::vector<std::shared_ptr<ids::IAsset>> ids::Game::getMovableAssets() const
{
    return _moveableAssetVector;
}

std::vector<std::shared_ptr<ids::IAsset>> ids::Game::getStaticAssets() const
{
    return _staticAssetVector;
}

template <typename T>
std::vector<int> ids::Game::getIAssetIndexesByPosAndType(std::vector<std::shared_ptr<T>> &assetVector, float x, float y, std::vector<std::string> types)
{
   int savedIndex = 0;
    std::vector<int> assetIndexes = {};
    for (auto &it: assetVector) {
        if (std::find(types.begin(), types.end(), it->getType()) != types.end()
            && static_cast<int>(std::round(it->getPosition("x"))) == static_cast<int>(std::round(x)) 
            && static_cast<int>(std::round(it->getPosition("y"))) == static_cast<int>(std::round(y))) {
            assetIndexes.emplace_back(savedIndex);
            }
        savedIndex++;
    }
    return assetIndexes;
}

template <typename T>
bool ids::Game::deleteFromAssetVector(std::vector<std::shared_ptr<T>> &assetVector, std::vector<int> assetIndexes)
{
    if (!assetIndexes.empty()) {
        std::reverse(assetIndexes.begin(), assetIndexes.end());
        for (auto &index: assetIndexes)
            assetVector.erase(assetVector.begin()+index);
        return true;
    }
    return false;
}

void ids::Game::bombExplosionCollision(float x, float y, int bombIndex, bool &boolean, std::vector<std::string> types)
{
    bool canPassWalls = _bombVector.at(bombIndex)->getWallUp();

    _mapGen.setBoxMapObject(y, x, BoxMap::Unknown);
    auto assetIndexes = getIAssetIndexesByPosAndType(_moveableAssetVector, x, y, types);
    if (!canPassWalls && !assetIndexes.empty()) {
        boolean = true;
    }
    auto playerIndexes = getIAssetIndexesByPosAndType(_bombermanVector, x, y, std::vector<std::string>{"player"});

    if (!playerIndexes.empty()) {
        for (auto &it: playerIndexes) {
            if (!_bombermanVector.at(it)->getisDead()) _hasPlayerDied = true;
            _bombermanVector.at(it)->setIsDead(true);
        }
    }
    if (!assetIndexes.empty() && _moveableAssetVector.at(assetIndexes.at(0))->getType() == "brick") {
        std::shared_ptr<ids::IAsset> item = _mapGen.breakBrick(_moveableAssetVector.at(assetIndexes.at(0)));
        if (item != nullptr) {
            _moveableAssetVector.emplace_back(item);
            if (item->getType() == "fireUp") _mapGen.setBoxMapObject(item->getPosition("y"), item->getPosition("x"), ids::BoxMap::FireUp);
            if (item->getType() == "wallUp") _mapGen.setBoxMapObject(item->getPosition("y"), item->getPosition("x"), ids::BoxMap::WallUp);
            if (item->getType() == "bombUp") _mapGen.setBoxMapObject(item->getPosition("y"), item->getPosition("x"), ids::BoxMap::BombUp);
            if (item->getType() == "speedUp") _mapGen.setBoxMapObject(item->getPosition("y"), item->getPosition("x"), ids::BoxMap::SpeedUp);
        }
    }
    deleteFromAssetVector(_moveableAssetVector, assetIndexes);
    std::shared_ptr<ids::Fire> newFire = std::make_shared<ids::Fire>(std::vector<float>{x, y, -0.5f}, "resources/textures/textureFire.png");
    _moveableAssetVector.emplace_back(newFire);
    _fireVector.emplace_back(newFire);
}

void ids::Game::bombDestruction(float x, float y, int bombIndex, std::vector<std::string> types)
{
    bool stopUp = false;
    bool stopDown = false;
    bool stopLeft = false;
    bool stopRight = false;

        bombExplosionCollision(x, y, bombIndex, stopUp, types);
        for (int fireCount = 1; fireCount <= _bombVector.at(bombIndex)->getFireUp(); fireCount++) {
        if (y - fireCount >= 0 && _mapGen.getStaticMap()[y - fireCount][x] == StaticMap::Walls) stopUp = true;
        if (y + fireCount < _mapGen.getStaticMap().size() && _mapGen.getStaticMap()[y + fireCount][x] == StaticMap::Walls) stopDown = true;
        if (x - fireCount >= 0 && _mapGen.getStaticMap()[y][x - fireCount] == StaticMap::Walls) stopLeft = true;
        if (x + fireCount < _mapGen.getStaticMap()[y].size() && _mapGen.getStaticMap()[y][x + fireCount] == StaticMap::Walls) stopRight = true;

        if (!stopUp)
            bombExplosionCollision(x, y - fireCount, bombIndex, stopUp, types);
        if (!stopDown)
            bombExplosionCollision(x, y + fireCount, bombIndex, stopDown, types);
        if (!stopLeft)
            bombExplosionCollision(x - fireCount, y, bombIndex, stopLeft, types);
        if (!stopRight)
            bombExplosionCollision(x + fireCount, y, bombIndex, stopRight, types);
    }
    _hasBombExplosed = true;
}

void ids::Game::manageFireDeletion()
{
    std::vector<int> assetToRemoveIndex = {};
    std::vector<int> fireToRemoveIndex = {};
    int x = 0;
    int y = 0;
    std::vector<std::string> type = std::vector<std::string>{"fire"};

    for (int fireIndex = 0; fireIndex < _fireVector.size(); fireIndex++) {
        if (!_fireVector.at(fireIndex)->checkAddTimer())
            continue;
        x =  _fireVector.at(fireIndex)->getPosition("x");
        y =  _fireVector.at(fireIndex)->getPosition("y");
        assetToRemoveIndex = getIAssetIndexesByPosAndType(_moveableAssetVector, x, y, type);
        fireToRemoveIndex = getIAssetIndexesByPosAndType(_fireVector, x, y, type);
        deleteFromAssetVector(_moveableAssetVector, assetToRemoveIndex);
        deleteFromAssetVector(_fireVector, fireToRemoveIndex);
        fireIndex--;
    }
}

void ids::Game::updateBombTimer()
{
    float x = 0.0f;
    float y = 0.0f;
    std::string bombType = "";
    std::vector<std::string> types = {"player", "brick", "bombUp", "fireUp", "speedUp", "wallUp"};

    for (int i = 0; i < _bombVector.size(); i++) {
        if (!_bombVector.at(i)->checkAddTimer())
            continue;
        x = _bombVector.at(i)->getPosition("x");
        y = _bombVector.at(i)->getPosition("y");
        bombType = _bombVector.at(i)->getType();
        _mapGen.setBoxMapObject(y, x, BoxMap::Unknown);
        deleteFromAssetVector(_moveableAssetVector, getIAssetIndexesByPosAndType(_moveableAssetVector, x, y, std::vector<std::string>{bombType}));
        bombDestruction(x, y, i, types);
        _bombVector.erase(_bombVector.begin()+i);
    }
}

bool ids::Game::hasPlayerDied()
{
    return _hasPlayerDied;
}

bool ids::Game::hasBombExplosed()
{
    return _hasBombExplosed;
}

bool ids::Game::isRunning()
{
    return _isRunning;
}

void ids::Game::setIsRunning(bool value)
{
    _isRunning = value;
}

std::string ids::Game::getWinner()
{

    if (_lastAliveCharactersIndexes.size() != 1)
        return "";
    auto index = _lastAliveCharactersIndexes.at(0);
    if (index == 0) return "resources/textures/BombermanPink.png";
    if (index == 1) return "resources/textures/BombermanBlue.png";
    if (index == 2) return "resources/textures/BombermanRed.png";
    if (index == 3) return "resources/textures/BombermanGreen.png";
}

bool ids::Game::isEnd()
{
    std::vector<int> indexes = {};
    for (int index = _bombermanVector.size(); index > 0; index--) {
        if (!_bombermanVector.at(index - 1)->getisDead()) {
            indexes.emplace_back(index - 1);
        }
    }
    if (indexes.empty())
        return true;
    _lastAliveCharactersIndexes = indexes;
    if (indexes.size() == 1)
        return true;
    return false;
}

ids::gameState ids::Game::update(std::vector<Input> inputs)
{
    std::vector<int> itemPos = {};

    _hasBombExplosed = false;
    _hasPlayerDied = false;
    for (auto const &bomberman : _bombermanVector) {
        itemPos = bomberman.get()->handleEvents(_moveableAssetVector, _bombVector, _mapGen, BOT_INPUT);
        if (!itemPos.empty()) {
            std::vector<int> index = getIAssetIndexesByPosAndType(_moveableAssetVector, itemPos.at(0), itemPos.at(1), std::vector<std::string>{"fireUp", "wallUp", "bombUp", "speedUp"});
            deleteFromAssetVector(_moveableAssetVector, index);
        }
    }
    for (auto const &input : inputs) {
        if (input == TIME_TICK) {
            updateBombTimer();
            manageFireDeletion();
        }
        for (std::vector<std::shared_ptr<ACharacter>>::iterator itMan = _bombermanVector.begin(); itMan < _bombermanVector.end(); itMan ++) {
            itemPos = (*itMan).get()->handleEvents(_moveableAssetVector, _bombVector, _mapGen, input);
            if (!itemPos.empty()) {
                std::vector<int> index = getIAssetIndexesByPosAndType(_moveableAssetVector, itemPos.at(0), itemPos.at(1), std::vector<std::string>{"fireUp", "wallUp", "bombUp", "speedUp"});
                deleteFromAssetVector(_moveableAssetVector, index);
            }
        }
    }
    if (isEnd())
        return gameState::ENDSCENE;
    return gameState::GAME;
}

bool ids::Game::save_map()
{
	return this->_mapGen.save("");
}
