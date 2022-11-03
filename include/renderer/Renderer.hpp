/*
** EPITECH PROJECT, 2022
** axel indie sutdio
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "IndieStudio.hpp"
#include "raylib.h"
#include "raymath.h"
#include "vector"
#include "IAsset.hpp"
#include "Brick.hpp"
#include "Player.hpp"
#include "event.hpp"

#include <memory>
#include <map>

class ids::Renderer {
    public:
        Renderer();
        ~Renderer();
        void createWindow();
        void createCamera();

        std::map<std::string, ModelS> loadModel();

        void drawModel(std::vector<std::shared_ptr<IAsset>> asset, std::map<std::string, ModelS> modelMap);

        void updateAnimation(std::shared_ptr<IAsset> asset);

        std::vector<Input> handleActions();
        bool checkTime();
        Camera3D _camera;

    protected:
    private:
        std::vector<Input> _inputs;
        int _elapsedTimer;
        int _timeTickCounter;
        bool _timeTick;

};

#endif /* !RENDERER_HPP_ */
