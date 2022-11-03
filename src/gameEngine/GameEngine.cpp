/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

ids::GameEngine::GameEngine() : _menu(_state, _audioS, _choosenItem)
{
    _state = CUTSCENE;
    std::srand(std::time(nullptr));
    
    _render = Renderer();
    _render.createCamera();
    _modelMap = _render.loadModel();
    _audioS.menuMusic = LoadMusicStream("resources/sound/menu.mp3");
    _audioS.gameMusic = LoadMusicStream("resources/sound/music.mp3");
    _audioS.bombExplosion = LoadSound("resources/sound/bomb_explosion.mp3");
    _audioS.playerDeath = LoadSound("resources/sound/death_sound.mp3");
    PlayMusicStream(_audioS.menuMusic);
    PlayMusicStream(_audioS.gameMusic);
    createItemVector();
}

ids::GameEngine::~GameEngine()
{
    StopSoundMulti();
    UnloadMusicStream(_audioS.menuMusic);
    UnloadSound(_audioS.bombExplosion);
    CloseAudioDevice();
    CloseWindow();
}

void ids::GameEngine::run()
{
    while (!WindowShouldClose()) {
        switch (_state) {
            case gameState::MENU:
                menuLoop();
                break;
            case gameState::GAME:
                gameLoop();
                break;
            case gameState::PAUSE:
                menuLoop();
                break;
            case gameState::SETTINGS:
                menuLoop();
                break;
            case gameState::GAMESETTINGS:
                menuLoop();
                break;
            case gameState::CONTROLLER:
                menuLoop();
                break;
            case gameState::CUTSCENE:
                cutscene();
                break;
            case gameState::ENDSCENE:
                endscene();
                break;
            case gameState::EXIT:
                return;
            default:
                break;
        }
    }
	if (_game.isRunning()) {
		_game.save_map();
	}
}

void ids::GameEngine::gameLoop()
{
    Color color = {45, 55, 72};

    std::vector<Input> actions = _render.handleActions();
    if (std::find(actions.begin(), actions.end(), Input::P_KEY) != actions.end() || _state == PAUSE)
        _state = gameState::PAUSE;
    else
        _state = _game.update(actions);
    if (_game.hasBombExplosed())
        PlaySoundMulti(_audioS.bombExplosion);
    if (_game.hasPlayerDied())
        PlaySoundMulti(_audioS.playerDeath);
    UpdateMusicStream(_audioS.gameMusic);
    BeginDrawing();
    ClearBackground(color);
    _render.drawModel(_game.get2DVectorSprite(), _modelMap);
    BeginMode3D(_render._camera);
    
    _render.drawModel(_game.getStaticAssets(), _modelMap);
    _render.drawModel(_game.getMovableAssets(), _modelMap);

    
    if (_state == gameState::PAUSE)
        _render.drawModel(_menu.getVectorSprite(_state), _modelMap);
    if (_state == gameState::ENDSCENE) {
        StopMusicStream(_audioS.gameMusic);
        PlayMusicStream(_audioS.gameMusic);
        _menu.createVectorEndscene(_game.getWinner(), _state);
    }
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
}

void ids::GameEngine::menuLoop()
{
    Color color = {45, 55, 72};

    if (_state == gameState::MENU)
        _game.setIsRunning(false);
    UpdateMusicStream(_audioS.menuMusic);
    BeginDrawing();
    ClearBackground(color);
    ClearBackground(RAYWHITE);
    DrawText("Welcome to the menu", 190, 200, 50, LIGHTGRAY);
    _render.drawModel(_menu.getVectorSprite(_state), _modelMap);
    _menu.checkInputModified();
    EndDrawing();
    if (_state == gameState::GAME && !_game.isRunning()) {
        _game.setMap(_menu.getChoosenItem());
        _game.setCharacters(_menu.getPlayersSettings());
        _game.setIsRunning(true);
    }
}

void ids::GameEngine::cutscene()
{
    Color color = {30, 37, 65};

    UpdateMusicStream(_audioS.menuMusic);
    std::vector<Input> actions = _render.handleActions();
    if (std::find(actions.begin(), actions.end(), Input::SPACE) != actions.end())
        _state = gameState::MENU;
    BeginDrawing();
    ClearBackground(color);
    _render.drawModel(_menu.getCutsceneBackground(), _modelMap);
    BeginMode3D(_render._camera);
    _render.drawModel(_menu.getVectorSprite(_state), _modelMap);
    EndMode3D();
    _render.drawModel(_menu.getVectorSprite2D(_state), _modelMap);

    DrawFPS(10, 10);

    EndDrawing();
}

void ids::GameEngine::endscene()
{
    Color color = {30, 37, 65};

    UpdateMusicStream(_audioS.menuMusic);
    std::vector<Input> actions = _render.handleActions();
    BeginDrawing();
    ClearBackground(color);
    _render.drawModel(_menu.getCutsceneBackground(), _modelMap);
    BeginMode3D(_render._camera);
    _render.drawModel(_menu.getVectorSprite(_state), _modelMap);
    EndMode3D();
    _render.drawModel(_menu.getVectorSprite2D(_state), _modelMap);

    DrawFPS(10, 10);

    EndDrawing();
}

ids::Game const &ids::GameEngine::getGame() const
{
    return _game;
}

void ids::GameEngine::createItemVector()
{
    _choosenItem.emplace_back(ItemType::SpeedUp);
    _choosenItem.emplace_back(ItemType::BombUp);
    _choosenItem.emplace_back(ItemType::WallUp);
    _choosenItem.emplace_back(ItemType::FireUp);
}