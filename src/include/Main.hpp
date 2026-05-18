#pragma once
#include <raylib-cpp.hpp>
#include "World.hpp"
#include "Entity.hpp"
#include<array>
class Main
{
public:
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 450;
    static constexpr int SQUARE_SIZE = 40;
    static constexpr int ENTITY_CAP = 40;

    void Update();
    void Draw();

    raylib::Window window;
    World world;
    Main();
private:
    std::array<Entity, ENTITY_CAP> entities;
    };