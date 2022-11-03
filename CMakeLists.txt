cmake_minimum_required(VERSION 3.17)
project(indie_studio)
set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(USE_WAYLAND "ON")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
# find_package(raylib 4.0.0 QUIET)
include(Findraylib)
include_directories(include/ include/gameEngine include/game include/game/menu include/game/character include/game/item include/renderer include/game/object include/map include/errors)

set(SOURCE_FILES src/main.cpp
                src/game/character/ACharacter.cpp
                src/game/AAsset.cpp
                src/game/character/Bot.cpp
                src/game/character/PathFinding.cpp
                src/game/character/Player.cpp
                src/game/item/AItem.cpp
                src/game/item/BombUp.cpp
                src/game/item/FireUp.cpp
                src/game/item/SpeedUp.cpp
                src/game/item/WallUp.cpp
                src/game/object/AStaticObject.cpp
                src/game/object/Wall.cpp
                src/game/object/Bomb.cpp
                src/game/object/Brick.cpp
                src/game/object/Ground.cpp
                src/game/object/AMoveableObject.cpp
                src/map/MapManager.cpp
                src/map/Save.cpp
                src/map/Box.cpp
                src/game/Game.cpp
                src/game/menu/Menu.cpp
                src/game/menu/Controller.cpp
                src/game/menu/ButtonAction.cpp
                src/game/object/ASpriteObject.cpp
                src/game/object/Fire.cpp
                src/game/object/ButtonText.cpp
                src/game/object/ImageSprite.cpp
                src/gameEngine/GameEngine.cpp
                src/renderer/Renderer.cpp
                src/map/Box.cpp)

add_executable(indie_studio ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)

if(DEFINED TEST_ENABLE AND "${TEST_ENABLE}" STREQUAL "yes")
    message(STATUS "Unit testing enabled")
    add_subdirectory("${CMAKE_SOURCE_DIR}/tests")
endif()
