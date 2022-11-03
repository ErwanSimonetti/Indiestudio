/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** Menu
*/

#include "Menu.hpp"

ids::Menu::Menu(gameState &state, AudioS &audio, std::vector<ItemType> &choosenItem) : _action(state, audio), _choosenItem(choosenItem)
{
    
    createInputMap();
    createVectorMain(state);
    createVectorSettings(state);
    createVectorGameSettings(state);
    createVectorPause(state);
    createVectorCutscene(state);
    createVectorController(state);
}

ids::Menu::~Menu()
{
}

std::vector<std::shared_ptr<ids::IAsset>> ids::Menu::getCutsceneBackground()
{
    return _cutsceneBackground;
}

void ids::Menu::createInputMap()
{
    std::map<Action, Input> inputP1;
    inputP1.insert(std::pair<Action, Input>(Action::MOVE_UP, Input::Z_KEY));
    inputP1.insert(std::pair<Action, Input>(Action::MOVE_LEFT, Input::Q_KEY));
    inputP1.insert(std::pair<Action, Input>(Action::MOVE_DOWN, Input::S_KEY));
    inputP1.insert(std::pair<Action, Input>(Action::MOVE_RIGHT, Input::D_KEY));
    inputP1.insert(std::pair<Action, Input>(Action::PUT_BOMB, Input::A_KEY));

    std::map<Action, Input> inputP2;
    inputP2.insert(std::pair<Action, Input>(Action::MOVE_UP, Input::T_KEY));
    inputP2.insert(std::pair<Action, Input>(Action::MOVE_LEFT, Input::F_KEY));
    inputP2.insert(std::pair<Action, Input>(Action::MOVE_DOWN, Input::G_KEY));
    inputP2.insert(std::pair<Action, Input>(Action::MOVE_RIGHT, Input::H_KEY));
    inputP2.insert(std::pair<Action, Input>(Action::PUT_BOMB, Input::R_KEY));

    std::map<Action, Input> inputP3;
    inputP3.insert(std::pair<Action, Input>(Action::MOVE_UP, Input::I_KEY));
    inputP3.insert(std::pair<Action, Input>(Action::MOVE_LEFT, Input::J_KEY));
    inputP3.insert(std::pair<Action, Input>(Action::MOVE_DOWN, Input::K_KEY));
    inputP3.insert(std::pair<Action, Input>(Action::MOVE_RIGHT, Input::L_KEY));
    inputP3.insert(std::pair<Action, Input>(Action::PUT_BOMB, Input::U_KEY));

    std::map<Action, Input> inputP4;
    inputP4.insert(std::pair<Action, Input>(Action::MOVE_UP, Input::UP_ARROW));
    inputP4.insert(std::pair<Action, Input>(Action::MOVE_LEFT, Input::LEFT_ARROW));
    inputP4.insert(std::pair<Action, Input>(Action::MOVE_DOWN, Input::DOWN_ARROW));
    inputP4.insert(std::pair<Action, Input>(Action::MOVE_RIGHT, Input::RIGHT_ARROW));
    inputP4.insert(std::pair<Action, Input>(Action::PUT_BOMB, Input::PAGE_UP));

    playerMenu_t player1 = {inputP1, false, ""};
    playerMenu_t player2 = {inputP2, false, ""};
    playerMenu_t player3 = {inputP3, false, ""};
    playerMenu_t player4 = {inputP4, false, ""};

    _players.emplace_back(player1);
    _players.emplace_back(player2);
    _players.emplace_back(player3);
    _players.emplace_back(player4);
}

void ids::Menu::createVectorController(gameState &state)
{
    std::shared_ptr<ButtonText> P1LEFT = std::make_shared<ButtonText>(std::vector<float>{220.0f, 470.0f, 1.0f}, "Q", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P1BOT = std::make_shared<ButtonText>(std::vector<float>{320.0f, 470.0f, 1.0f}, "S", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P1RIGHT = std::make_shared<ButtonText>(std::vector<float>{420.0f, 470.0f, 1.0f}, "D", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P1UP = std::make_shared<ButtonText>(std::vector<float>{320.0f, 370.0f, 1.0f}, "Z", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P1ACTION = std::make_shared<ButtonText>(std::vector<float>{540.0f, 470.0f, 1.0f}, "A", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P1CONTROLLER = std::make_shared<ButtonText>(std::vector<float>{457.0f, 350.0f, 1.0f}, "KEEB", 70.0f, _action, _choosenItem, _players.at(0));

    std::shared_ptr<ButtonText> P2LEFT = std::make_shared<ButtonText>(std::vector<float>{220.0f, 880.0f, 1.0f}, "F", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P2BOT = std::make_shared<ButtonText>(std::vector<float>{320.0f, 880.0f, 1.0f}, "G", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P2RIGHT = std::make_shared<ButtonText>(std::vector<float>{420.0f, 880.0f, 1.0f}, "H", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P2UP = std::make_shared<ButtonText>(std::vector<float>{320.0f, 780.0f, 1.0f}, "T", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P2ACTION = std::make_shared<ButtonText>(std::vector<float>{540.0f, 880.0f, 1.0f}, "R", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P2CONTROLLER = std::make_shared<ButtonText>(std::vector<float>{457.0f, 760.0f, 1.0f}, "KEEB", 70.0f, _action, _choosenItem, _players.at(0));

    std::shared_ptr<ButtonText> P3LEFT = std::make_shared<ButtonText>(std::vector<float>{1340.0f, 470.0f, 1.0f}, "J", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P3BOT = std::make_shared<ButtonText>(std::vector<float>{1440.0f, 470.0f, 1.0f}, "K", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P3RIGHT = std::make_shared<ButtonText>(std::vector<float>{1540.0f, 470.0f, 1.0f}, "L", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P3UP = std::make_shared<ButtonText>(std::vector<float>{1440.0f, 370.0f, 1.0f}, "I", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P3ACTION = std::make_shared<ButtonText>(std::vector<float>{1660.0f, 470.0f, 1.0f}, "U", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P3CONTROLLER = std::make_shared<ButtonText>(std::vector<float>{1576.0f, 350.0f, 1.0f}, "KEEB", 70.0f, _action, _choosenItem, _players.at(0));

    std::shared_ptr<ButtonText> P4LEFT = std::make_shared<ButtonText>(std::vector<float>{1340.0f, 880.0f, 1.0f}, "<-", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P4BOT = std::make_shared<ButtonText>(std::vector<float>{1440.0f, 880.0f, 1.0f}, "v", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P4RIGHT = std::make_shared<ButtonText>(std::vector<float>{1540.0f, 880.0f, 1.0f}, "->", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P4UP = std::make_shared<ButtonText>(std::vector<float>{1440.0f, 780.0f, 1.0f}, "^", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P4ACTION = std::make_shared<ButtonText>(std::vector<float>{1660.0f, 880.0f, 1.0f}, "P_UP", 70.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> P4CONTROLLER = std::make_shared<ButtonText>(std::vector<float>{1576.0f, 760.0f, 1.0f}, "KEEB", 70.0f, _action, _choosenItem, _players.at(0));

    _controllers.emplace_back(Controller(_players.at(0), *P1UP.get(), *P1BOT.get(), *P1LEFT.get(), *P1RIGHT.get(), *P1ACTION.get(), *P1CONTROLLER.get()));
    _controllers.emplace_back(Controller(_players.at(1), *P2UP.get(), *P2BOT.get(), *P2LEFT.get(), *P2RIGHT.get(), *P2ACTION.get(), *P2CONTROLLER.get()));
    _controllers.emplace_back(Controller(_players.at(2), *P3UP.get(), *P3BOT.get(), *P3LEFT.get(), *P3RIGHT.get(), *P3ACTION.get(), *P3CONTROLLER.get()));
    _controllers.emplace_back(Controller(_players.at(3), *P4UP.get(), *P4BOT.get(), *P4LEFT.get(), *P4RIGHT.get(), *P4ACTION.get(), *P4CONTROLLER.get()));
    _controllerAssets.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/controller.png"));
    _controllerAssets.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{20.0f, 2800.0f, 1.0f}, "resources/textures/return.png", 3, _action, &ButtonAction::launchGameMenu, state));
    _controllerAssets.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{20.0f, 2800.0f, 1.0f}, "resources/textures/return.png", 3, _action, &ButtonAction::launchSettings, state));

    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{200.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(0), &Controller::switchLeftKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{300.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(0), &Controller::switchDownKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{400.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(0), &Controller::switchRightKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{300.0f, 1100.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(0), &Controller::switchUpKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{500.0f, 1400.0f, 1.0f}, "resources/textures/buttonAction.png", 3, _controllers.at(0), &Controller::switchActionKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{450.0f, 1000.0f, 1.0f}, "resources/textures/buttonManette.png", 3, _controllers.at(0), &Controller::switchController, state));

    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1320.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(2), &Controller::switchLeftKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1420.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(2), &Controller::switchDownKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1520.0f, 1400.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(2), &Controller::switchRightKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1420.0f, 1100.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(2), &Controller::switchUpKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1620.0f, 1400.0f, 1.0f}, "resources/textures/buttonAction.png", 3, _controllers.at(2), &Controller::switchActionKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1570.0f, 1000.0f, 1.0f}, "resources/textures/buttonManette.png", 3, _controllers.at(2), &Controller::switchController, state));

    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{200.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(1), &Controller::switchLeftKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{300.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(1), &Controller::switchDownKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{400.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(1), &Controller::switchRightKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{300.0f, 2320.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(1), &Controller::switchUpKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{500.0f, 2620.0f, 1.0f}, "resources/textures/buttonAction.png", 3, _controllers.at(1), &Controller::switchActionKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{450.0f, 2220.0f, 1.0f}, "resources/textures/buttonManette.png", 3, _controllers.at(1), &Controller::switchController, state));

    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1320.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(3), &Controller::switchLeftKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1420.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(3), &Controller::switchDownKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1520.0f, 2620.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(3), &Controller::switchRightKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1420.0f, 2320.0f, 1.0f}, "resources/textures/buttonKey.png", 3, _controllers.at(3), &Controller::switchUpKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1620.0f, 2620.0f, 1.0f}, "resources/textures/buttonAction.png", 3, _controllers.at(3), &Controller::switchActionKey, state));
    _controllerAssets.emplace_back(std::make_shared<Button<Controller, void>>(std::vector<float>{1570.0f, 2220.0f, 1.0f}, "resources/textures/buttonManette.png", 3, _controllers.at(3), &Controller::switchController, state));


    _controllerAssets.emplace_back(P1UP);
    _controllerAssets.emplace_back(P1LEFT);
    _controllerAssets.emplace_back(P1BOT);
    _controllerAssets.emplace_back(P1RIGHT);
    _controllerAssets.emplace_back(P1ACTION);
    _controllerAssets.emplace_back(P1CONTROLLER);

    _controllerAssets.emplace_back(P2UP);
    _controllerAssets.emplace_back(P2LEFT);
    _controllerAssets.emplace_back(P2BOT);
    _controllerAssets.emplace_back(P2RIGHT);
    _controllerAssets.emplace_back(P2ACTION);
    _controllerAssets.emplace_back(P2CONTROLLER);

    _controllerAssets.emplace_back(P3UP);
    _controllerAssets.emplace_back(P3LEFT);
    _controllerAssets.emplace_back(P3BOT);
    _controllerAssets.emplace_back(P3RIGHT);
    _controllerAssets.emplace_back(P3ACTION);
    _controllerAssets.emplace_back(P3CONTROLLER);

    _controllerAssets.emplace_back(P4UP);
    _controllerAssets.emplace_back(P4LEFT);
    _controllerAssets.emplace_back(P4BOT);
    _controllerAssets.emplace_back(P4RIGHT);
    _controllerAssets.emplace_back(P4ACTION);
    _controllerAssets.emplace_back(P4CONTROLLER);
}

void ids::Menu::createVectorCutscene(gameState &state)
{
    _cutsceneBackground.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/cutscene_bg.png"));
    _cutscene2D.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/title.png"));
    std::shared_ptr<Player> model = std::make_shared<Player>(std::vector<float>{10.0f, 11.8f, 17.0f}, 1, "resources/textures/BombermanPink.png");
    model->setRotation({1.0f, 0.0f, 0.0f}, -55.0f);
    model->setCutscene();
    _cutscene.emplace_back(model);
    _cutscene2D.emplace_back(std::make_shared<ButtonText>(std::vector<float>{350.0f, 820.0f, 0.0f}, "Press SPACE to continue", 100.0f, _action, _choosenItem, _players.at(0)));

}

void ids::Menu::createVectorEndscene(std::string winner, gameState &state)
{
    _endscene2D.clear();
    _endscene.clear();
    if (winner == "") 
        _endscene2D.emplace_back(std::make_shared<ButtonText>(std::vector<float>{650.0f, 350.0f, 0.0f}, "DRAW", 250.0f, _action, _choosenItem, _players.at(0)));
    else {
        _endscene2D.emplace_back(std::make_shared<ButtonText>(std::vector<float>{520.0f, 100.0f, 0.0f}, "THE WINNER IS", 100.0f, _action, _choosenItem, _players.at(0)));
        std::shared_ptr<Player> model = std::make_shared<Player>(std::vector<float>{10.0f, 12.2f, 17.0f}, 1, winner);
        model->setRotation({1.0f, 0.0f, 0.0f}, -55.0f);
        model->setCutscene();
        _endscene.emplace_back(model);
    }
    _endscene2D.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{1200.0f, 2000.0f, 1.0f}, "resources/textures/buttonMenu.png", 3, _action, &ButtonAction::launchGameMenu, state));
    _endscene2D.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{500.0f, 2000.0f, 1.0f}, "resources/textures/quitEndscene.png", 3, _action, &ButtonAction::exitGame, state));
}

void ids::Menu::createVectorMain(gameState &state)
{
    _main.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/background.png"));
    _main.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/title.png"));
    _main.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{0.0f, 1000.0f, 1.0f}, "resources/play.png", 3, _action, &ButtonAction::launchGameSettings, state));
    _main.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{0.0f, 1500.0f, 1.0f}, "resources/settings.png", 3, _action, &ButtonAction::launchSettings, state));
    _main.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{0.0f, 2000.0f, 1.0f}, "resources/quit.png", 3, _action, &ButtonAction::exitGame, state));

}

void ids::Menu::createVectorPause(gameState &state)
{
    std::shared_ptr<ButtonText> textSound = std::make_shared<ButtonText>(std::vector<float>{1000.0f, 350.0f, 0.0f}, "50", 100.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textFPS = std::make_shared<ButtonText>(std::vector<float>{1000.0f, 550.0f, 0.0f}, "90", 100.0f, _action, _choosenItem, _players.at(0));

    _pause.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/settings.png"));
    _pause.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1300.0f, 1050.0f, 1.0f}, "resources/textures/plus.png", 3, *textSound.get(), &ButtonText::increaseSound, state));
    _pause.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{700.0f, 1150.0f, 1.0f}, "resources/textures/minus.png", 3, *textSound.get(), &ButtonText::decreaseSound, state));
    _pause.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1300.0f, 1650.0f, 1.0f}, "resources/textures/plus.png", 3, *textFPS.get(), &ButtonText::increaseFPS, state));
    _pause.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{700.0f, 1750.0f, 1.0f}, "resources/textures/minus.png", 3, *textFPS.get(), &ButtonText::decreaseFPS, state));
    _pause.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{700.0f, 2350.0f, 1.0f}, "resources/textures/buttonResume.png", 3, _action, &ButtonAction::resumeGame, state));
    _pause.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{1000.0f, 2350.0f, 1.0f}, "resources/textures/buttonMenu.png", 3, _action, &ButtonAction::launchGameMenu, state));
    _pause.emplace_back(textSound);
    _pause.emplace_back(textFPS);
}

void ids::Menu::createVectorSettings(gameState &state)
{

    std::shared_ptr<ButtonText> textSound = std::make_shared<ButtonText>(std::vector<float>{1000.0f, 350.0f, 0.0f}, "50", 100.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textFPS = std::make_shared<ButtonText>(std::vector<float>{1000.0f, 550.0f, 0.0f}, "90", 100.0f, _action, _choosenItem, _players.at(0));

    _settings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/settings.png"));
    _settings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1300.0f, 1050.0f, 1.0f}, "resources/textures/plus.png", 3, *textSound.get(), &ButtonText::increaseSound, state));
    _settings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{700.0f, 1150.0f, 1.0f}, "resources/textures/minus.png", 3, *textSound.get(), &ButtonText::decreaseSound, state));
    _settings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1300.0f, 1650.0f, 1.0f}, "resources/textures/plus.png", 3, *textFPS.get(), &ButtonText::increaseFPS, state));
    _settings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{700.0f, 1750.0f, 1.0f}, "resources/textures/minus.png", 3, *textFPS.get(), &ButtonText::decreaseFPS, state));
    _settings.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{20.0f, 2800.0f, 1.0f}, "resources/textures/return.png", 3, _action, &ButtonAction::launchGameMenu, state));
    _settings.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{550.0f, 2280.0f, 1.0f}, "resources/textures/assignButton.png", 3, _action, &ButtonAction::launchController, state));
    _settings.emplace_back(textSound);
    _settings.emplace_back(textFPS);
}

void ids::Menu::createVectorGameSettings(gameState &state)
{
    std::shared_ptr<ButtonText> textFire = std::make_shared<ButtonText>(std::vector<float>{1700.0f, 430.0f, 0.0f}, "ON", 50.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textSpeed = std::make_shared<ButtonText>(std::vector<float>{1700.0f, 560.0f, 0.0f}, "ON", 50.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textBomb = std::make_shared<ButtonText>(std::vector<float>{1700.0f, 690.0f, 0.0f}, "ON", 50.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textWall = std::make_shared<ButtonText>(std::vector<float>{1700.0f, 820.0f, 0.0f}, "ON", 50.0f, _action, _choosenItem, _players.at(0));

    std::shared_ptr<ButtonText> textP1 = std::make_shared<ButtonText>(std::vector<float>{130.0f, 885.0f, 1.0f}, "PLAYER", 50.0f, _action, _choosenItem, _players.at(0));
    std::shared_ptr<ButtonText> textP2 = std::make_shared<ButtonText>(std::vector<float>{490.0f, 885.0f, 0.0f}, "PLAYER", 50.0f, _action, _choosenItem, _players.at(1));
    std::shared_ptr<ButtonText> textP3 = std::make_shared<ButtonText>(std::vector<float>{830.0f, 885.0f, 0.0f}, "PLAYER", 50.0f, _action, _choosenItem, _players.at(2));
    std::shared_ptr<ButtonText> textP4 = std::make_shared<ButtonText>(std::vector<float>{1190.0f, 885.0f, 0.0f}, "PLAYER", 50.0f, _action, _choosenItem, _players.at(3));

    _gameSettings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1.0f, 1.0f, 1.0f}, "resources/textures/playerchoose.png"));
    _gameSettings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{50.0f, 250.0f, 1.0f}, "resources/textures/white.png"));
    _gameSettings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{400.0f, 250.0f, 1.0f}, "resources/textures/blue.png"));
    _gameSettings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{750.0f, 250.0f, 1.0f}, "resources/textures/pink.png"));
    _gameSettings.emplace_back(std::make_shared<ImageSprite>(std::vector<float>{1100.0f, 250.0f, 1.0f}, "resources/textures/green.png"));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1600.0f, 850.0f, 1.0f}, "resources/textures/buttonOnOff.png", 2, *textFire.get(), &ButtonText::fireUpValue, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1600.0f, 1100.0f, 1.0f}, "resources/textures/buttonOnOff.png", 2, *textSpeed.get(), &ButtonText::speedUpValue, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1600.0f, 1380.0f, 1.0f}, "resources/textures/buttonOnOff.png", 2, *textBomb.get(), &ButtonText::bombUpValue, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1600.0f, 1640.0f, 1.0f}, "resources/textures/buttonOnOff.png", 2, *textWall.get(), &ButtonText::WallUpValue, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{1550.0f, 80.0f, 1.0f}, "resources/textures/start.png", 3, _action, &ButtonAction::launchGame, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonAction, void>>(std::vector<float>{20.0f, 2900.0f, 1.0f}, "resources/textures/return.png", 3, _action, &ButtonAction::launchGameMenu, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{100.0f, 2600.0f, 1.0f}, "resources/textures/buttonPlayer.png", 3, *textP1.get(), &ButtonText::switchPlayerBot, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{450.0f, 2600.0f, 1.0f}, "resources/textures/buttonPlayer.png", 3, *textP2.get(), &ButtonText::switchPlayerBot, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{800.0f, 2600.0f, 1.0f}, "resources/textures/buttonPlayer.png", 3, *textP3.get(), &ButtonText::switchPlayerBot, state));
    _gameSettings.emplace_back(std::make_shared<Button<ButtonText, void>>(std::vector<float>{1150.0f, 2600.0f, 1.0f}, "resources/textures/buttonPlayer.png", 3, *textP4.get(), &ButtonText::switchPlayerBot, state));

    _gameSettings.emplace_back(textFire);
    _gameSettings.emplace_back(textBomb);
    _gameSettings.emplace_back(textSpeed);
    _gameSettings.emplace_back(textWall);

    _gameSettings.emplace_back(textP1);
    _gameSettings.emplace_back(textP2);
    _gameSettings.emplace_back(textP3);
    _gameSettings.emplace_back(textP4);
}

Input ids::Menu::getInput()
{
    auto keyPressed = GetKeyPressed();
    return static_cast<Input>(keyPressed);
}

void ids::Menu::checkInputModified()
{
    auto input = getInput();
    for (auto &controller: _controllers) {
        controller.updateKeyBind(input);
    }
}

std::vector<std::shared_ptr<ids::IAsset>> ids::Menu::getVectorSprite2D(gameState &state)
{
    switch (state) {
    case gameState::CUTSCENE:
        return _cutscene2D;
        break;
    case gameState::ENDSCENE:
        return _endscene2D;
        break;
    default:
        return _cutscene2D;
        break;
    }
}

std::vector<ids::ItemType> ids::Menu::getChoosenItem()
{
    return _choosenItem;
}

std::vector<ids::playerMenu_t> ids::Menu::getPlayersSettings()
{
    return _players;
}

std::vector<std::shared_ptr<ids::IAsset>> ids::Menu::getVectorSprite(gameState &state)
{
    switch (state) {
    case gameState::MENU:
        return _main;
        break;
    case gameState::SETTINGS:
        return _settings;
        break;
    case gameState::GAMESETTINGS:
        return _gameSettings;
        break;
    case gameState::PAUSE:
        return _pause;
        break;
    case gameState::CUTSCENE:
        return _cutscene;
        break;
    case gameState::ENDSCENE:
        return _endscene;
        break;
    case gameState::CONTROLLER:
        return _controllerAssets;
        break;
    default:
        break;
    }
    //  return _main;
}