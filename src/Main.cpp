#include "include/Main.hpp"
#include <print>
#include <ranges>
#include <format>

std::array<raylib::Texture2D, (size_t)TileType::NUM_TILES> World::s_texturecache;
std::array<raylib::Texture2D, 1> Entity::s_texturecache;
Main::Main()
    : window{Main::SCREEN_WIDTH,
             Main::SCREEN_HEIGHT,
             "Raylib C++ Starter Kit Example"},
      world{},
      goalZoom{1.2f},
      cam { {0, 0},{0, 0},0.0f,goalZoom },
      cameraGoal{0,0}

{
    window.SetTargetFPS(60);

    for (int i = 0; i < TileType::NUM_TILES; i++)
    {
        World::s_texturecache[i] = raylib::LoadImage(std::format("res/tile-{}.png", i));
    }
    for (int i = 0; i < EntityType::NUM_ENTITIES; i++)
    {
        Entity::s_texturecache[i] = raylib::LoadImage(std::format("res/entity-{}.png", i));
    }
}

void Main::Update()
{
    world.Update();
    //GetWheelMove gives a +1 or -1 if wheel scrolled, 
    //cam.SetZoom(cam.GetZoom() + (raylib::Mouse::GetWheelMove() / 10.0));


    // GetWheelMove gives a +1 or -1 if wheel scrolled,
     goalZoom += (raylib::Mouse::GetWheelMove() / 10.0);
     float delZoom = (goalZoom - cam.GetZoom()) / 20.0;
     cam.SetZoom( cam.GetZoom() + delZoom);

    if (raylib::Mouse::IsButtonDown(MOUSE_BUTTON_LEFT)) {
        raylib::Vector2 mov = raylib::Mouse::GetDelta();
        cameraGoal += mov;
        raylib::Vector2 delPos = (cameraGoal - cam.GetOffset())/ 5.0;
        cam.SetOffset(raylib::Vector2(cam.GetOffset()) + delPos);

    }
}

void Main::Draw()
{
    BeginDrawing();
    ClearBackground(raylib::Color{0x00aaffff});
    cam.BeginMode();
    world.Draw();
    cam.EndMode();
    EndDrawing();
}

int main()
{

    Main m{};

    // Main game loop
    while (!m.window.ShouldClose()) // Detect window close button or ESC key
    {
        m.Update();
        m.Draw();
    }
    return EXIT_SUCCESS;
}
