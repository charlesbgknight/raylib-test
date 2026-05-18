#pragma once
#include "../../include/raylib/raylib-cpp.hpp"
#include "World.hpp"
class Main
{
public:
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 450;
    static constexpr int SQUARE_SIZE = 40;

    void Update();
    void Draw();

    raylib::Window window;
    World world;
    Main();
private:
    };