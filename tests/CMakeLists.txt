# run tests : cmake ../ -DTEST_ENABLE=yes

cmake_minimum_required(VERSION 3.17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

project(indie_studio)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(SOURCE_FILES ../src/main.cpp
                ../src/game/character/ACharacter.cpp
                ../src/game/AAsset.cpp
                ../src/game/character/Bot.cpp
                ../src/game/character/Player.cpp
                ../src/game/item/AItem.cpp
                ../src/game/item/BombUp.cpp
                ../src/game/item/FireUp.cpp
                ../src/game/item/SpeedUp.cpp
                ../src/game/item/WallUp.cpp
                ../src/game/object/AStaticObject.cpp
                ../src/game/object/Wall.cpp
                ../src/game/object/Bomb.cpp
                ../src/game/object/Brick.cpp
                ../src/game/object/Ground.cpp
                ../src/game/object/AMoveableObject.cpp
                ../src/map/MapManager.cpp
                ../src/map/Save.cpp
                ../src/map/Box.cpp
                ../src/game/Game.cpp
                ../src/game/menu/Menu.cpp
                ../src/game/object/ASpriteObject.cpp
                ../src/game/object/Button.cpp
                ../src/game/object/ImageSprite.cpp
                ../src/game/object/Fire.cpp
                ../src/gameEngine/GameEngine.cpp
                ../src/renderer/Renderer.cpp
        ../src/map/Box.cpp)

set(TEST_SRC
    map/fileToVectorEnum.cpp
    ${SOURCE_FILES})

if (NOT Catch2_found)
    include(FetchContent)

    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v3.0.0-preview4
    )
    message(STATUS "Cloning Catch2")
    FetchContent_MakeAvailable(Catch2)
    set(Catch2_found)
endif()
add_executable(unit_tests ${TEST_SRC} ${PROJECT_DIR})

target_include_directories(unit_tests PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/game
        ${INCLUDE_DIR}/game/character
        ${INCLUDE_DIR}/game/Item
        ${INCLUDE_DIR}/game/object
        ${INCLUDE_DIR}/map)




target_compile_options(unit_tests PRIVATE
    -Wall
    -Wextra
    --coverage)

target_link_libraries(unit_tests PRIVATE
    Catch2::Catch2WithMain
    gcov
    raylib)

