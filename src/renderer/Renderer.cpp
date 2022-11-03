/*
** EPITECH PROJECT, 2022
** axel indie studio
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include <iostream>

static std::map<KeyboardKey, Input> keyToInputMap = {
    {KeyboardKey::KEY_ENTER, Input::ENTER},
    {KeyboardKey::KEY_BACKSPACE, Input::BACKSPACE},
    {KeyboardKey::KEY_SPACE, Input::SPACE},
    {KeyboardKey::KEY_ESCAPE, Input::ESCAPE},
    {KeyboardKey::KEY_UP, Input::UP_ARROW},
    {KeyboardKey::KEY_DOWN, Input::DOWN_ARROW},
    {KeyboardKey::KEY_LEFT, Input::LEFT_ARROW},
    {KeyboardKey::KEY_RIGHT, Input::RIGHT_ARROW},
    {KeyboardKey::KEY_A, Input::Q_KEY},
    {KeyboardKey::KEY_B, Input::B_KEY},
    {KeyboardKey::KEY_C, Input::C_KEY},
    {KeyboardKey::KEY_D, Input::D_KEY},
    {KeyboardKey::KEY_E, Input::E_KEY},
    {KeyboardKey::KEY_F, Input::F_KEY},
    {KeyboardKey::KEY_G, Input::G_KEY},
    {KeyboardKey::KEY_H, Input::H_KEY},
    {KeyboardKey::KEY_I, Input::I_KEY},
    {KeyboardKey::KEY_J, Input::J_KEY},
    {KeyboardKey::KEY_K, Input::K_KEY},
    {KeyboardKey::KEY_L, Input::L_KEY},
    {KeyboardKey::KEY_M, Input::M_KEY},
    {KeyboardKey::KEY_N, Input::N_KEY},
    {KeyboardKey::KEY_O, Input::O_KEY},
    {KeyboardKey::KEY_P, Input::P_KEY},
    {KeyboardKey::KEY_Q, Input::A_KEY},
    {KeyboardKey::KEY_R, Input::R_KEY},
    {KeyboardKey::KEY_S, Input::S_KEY},
    {KeyboardKey::KEY_T, Input::T_KEY},
    {KeyboardKey::KEY_U, Input::U_KEY},
    {KeyboardKey::KEY_V, Input::V_KEY},
    {KeyboardKey::KEY_W, Input::Z_KEY},
    {KeyboardKey::KEY_X, Input::X_KEY},
    {KeyboardKey::KEY_Y, Input::Y_KEY},
    {KeyboardKey::KEY_Z, Input::W_KEY},
    {KeyboardKey::KEY_ZERO, Input::Num_0},
    {KeyboardKey::KEY_ONE, Input::Num_1},
    {KeyboardKey::KEY_TWO, Input::Num_2},
    {KeyboardKey::KEY_THREE, Input::Num_3},
    {KeyboardKey::KEY_FOUR, Input::Num_4},
    {KeyboardKey::KEY_FIVE, Input::Num_5},
    {KeyboardKey::KEY_SIX, Input::Num_6},
    {KeyboardKey::KEY_SEVEN, Input::Num_7},
    {KeyboardKey::KEY_EIGHT, Input::Num_8},
    {KeyboardKey::KEY_NINE, Input::Num_9},
    {KeyboardKey::KEY_F1, Input::F1},
    {KeyboardKey::KEY_F2, Input::F2},
    {KeyboardKey::KEY_F3, Input::F3},
    {KeyboardKey::KEY_F4, Input::F4},
    {KeyboardKey::KEY_F5, Input::F5},
    {KeyboardKey::KEY_F6, Input::F6},
    {KeyboardKey::KEY_F7, Input::F7},
    {KeyboardKey::KEY_F8, Input::F8},
    {KeyboardKey::KEY_F9, Input::F9},
    {KeyboardKey::KEY_F10, Input::F10},
    {KeyboardKey::KEY_F11, Input::F11},
    {KeyboardKey::KEY_F12, Input::F12},
    {KeyboardKey::KEY_PAGE_UP, Input::PAGE_UP},
    {KeyboardKey::KEY_PAGE_DOWN, Input::PAGE_DOWN},
};

static std::map<GamepadButton, Input> padToInputMap = {
    {GamepadButton::GAMEPAD_BUTTON_LEFT_FACE_UP, Input::FACE_UP},
    {GamepadButton::GAMEPAD_BUTTON_LEFT_FACE_DOWN, Input::FACE_DOWN},
    {GamepadButton::GAMEPAD_BUTTON_LEFT_FACE_LEFT, Input::FACE_LEFT},
    {GamepadButton::GAMEPAD_BUTTON_LEFT_FACE_RIGHT, Input::FACE_RIGHT},
    {GamepadButton::GAMEPAD_BUTTON_RIGHT_FACE_DOWN, Input::FACE_A},
};

ids::Renderer::Renderer()
{
    _elapsedTimer = 0;
    _timeTick = false;
    _inputs.clear();
}

ids::Renderer::~Renderer()
{
}

void ids::Renderer::createWindow()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    SetTargetFPS(30);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "3d camera mode");
}

void ids::Renderer::createCamera()
{
    _camera.position =    {10.0f, 20.0f, 12.0f}; // Camera position
    _camera.target =    {10.0f, 12.0f, 10.0f};   // Camera looking at point
    _camera.up =    {0.0f, 5.0f, 0.0f};          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                              // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;           // Camera mode type
}

std::map<std::string, ModelS> ids::Renderer::loadModel()
{
    std::map<std::string, ModelS> modelMap;

    Shader shader = LoadShader("resources/shader/base_lighting.vs", "resources/shader/fire.fs");

    ModelS wall;
    wall.texture = LoadTexture("resources/wall.png"); // Load model texture
    wall.model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    wall.model.materials[0].shader = shader;
    wall.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = wall.texture;
    wall.size =    {1.0f, 1.0f, 1.0f};

    ModelS plane;
    plane.texture = LoadTexture("resources/grass.png");
    plane.model = LoadModelFromMesh(GenMeshPlane(21.0f, 15.0f, 1.0f, 1.0f));
    plane.model.materials[0].shader = shader;
    plane.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = plane.texture;
    plane.size =    {1.0f, 1.0f, 1.0f};

    ModelS brick;
    brick.texture = LoadTexture("resources/gray_brick.png"); // Load model texture
    brick.model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    brick.model.materials[0].shader = shader;
    brick.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = brick.texture;
    brick.size =    {1.0f, 1.0f, 1.0f};

    ModelS player;
    player.texture = LoadTexture("resources/textures/BombermanPink.png");
    player.model = LoadModel("resources/animation/Bomberman.iqm");
    // player.model.materials[0].shader = fireShader;
    player.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = player.texture;
    player.model.transform = MatrixRotateXYZ(   { 140.0f, 0.0f, 0.0f });
    unsigned int animsPlayer = 0;
    player.animation = LoadModelAnimations("resources/animation/BombermanAnim.iqm", &animsPlayer);
    player.size =    {0.15f, 0.15f, 0.15f};

    ModelS bomb;
    bomb.texture = LoadTexture("resources/textures/textureBomb.png");
    bomb.model = LoadModel("resources/animation/bombok.iqm");
    bomb.model.materials[0].shader = shader;
    bomb.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = bomb.texture;
    bomb.model.transform = MatrixRotateXYZ(   { 140.0f, 0.0f, 0.0f });
    unsigned int animsBomb = 0;
    bomb.animation = LoadModelAnimations("resources/animation/bombokAnim.iqm", &animsBomb);
    bomb.size =    {0.25f, 0.25f, 0.25f};

    ModelS fire;
    fire.texture = LoadTexture("resources/textures/textureFire.png");
    fire.model = LoadModel("resources/animation/fire.iqm");
    fire.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = fire.texture;
    fire.model.materials[0].shader = shader;
    fire.model.transform = MatrixRotateXYZ(   { 140.0f, 0.0f, 0.0f });
    unsigned int animsFire = 0;
    fire.animation = LoadModelAnimations("resources/animation/fireAnim.iqm", &animsFire);
    fire.size =    {0.50f, 0.50f, 0.50f};

    ModelS item;
    item.texture = LoadTexture("resources/textures/itemSpeed.png");
    item.model = LoadModel("resources/animation/item.iqm");
    item.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = item.texture;
    item.model.materials[0].shader = shader;
    item.model.transform = MatrixRotateXYZ(   { 140.0f, 0.0f, 0.0f });
    unsigned int animsItem = 0; 
    item.animation = LoadModelAnimations("resources/animation/itemAnim.iqm", &animsItem);
    item.size =    {0.003f, 0.003f, 0.003f};

    modelMap.insert(std::pair<std::string, ModelS>("wall", wall));
    modelMap.insert(std::pair<std::string, ModelS>("ground", plane));
    modelMap.insert(std::pair<std::string, ModelS>("player", player));
    modelMap.insert(std::pair<std::string, ModelS>("brick", brick));
    modelMap.insert(std::pair<std::string, ModelS>("bomb", bomb));
    modelMap.insert(std::pair<std::string, ModelS>("fire", fire));
    modelMap.insert(std::pair<std::string, ModelS>("fireUp", item));
    modelMap.insert(std::pair<std::string, ModelS>("bombUp", item));
    modelMap.insert(std::pair<std::string, ModelS>("wallUp", item));
    modelMap.insert(std::pair<std::string, ModelS>("speedUp", item));

    return modelMap;
}

void ids::Renderer::drawModel(std::vector<std::shared_ptr<IAsset>> asset, std::map<std::string, ModelS> modelMap)
{
    for (auto &it: asset) {
        it->drawAsset(modelMap, _timeTick);
    }
}

bool ids::Renderer::checkTime()
{
    int sec = std::floor(GetTime() / 0.020);
    if (sec != _elapsedTimer) {
        _elapsedTimer = sec;
        _timeTick = true;
        return true;
    }
    _timeTick = false;
    return false;
}

std::vector<Input> ids::Renderer::handleActions()
{
    _inputs.clear();

    if(checkTime()) {
        _inputs.emplace_back(Input::TIME_TICK);
        for (std::map<KeyboardKey, Input>::const_iterator it = keyToInputMap.begin(); it != keyToInputMap.end(); it++)
            if (IsKeyDown(it->first)) _inputs.emplace_back(it->second);
        for (std::map<GamepadButton, Input>::const_iterator it = padToInputMap.begin(); it != padToInputMap.end(); it++)
            if (IsGamepadButtonDown(0, it->first)) _inputs.emplace_back(it->second);
    }
    return _inputs;
}