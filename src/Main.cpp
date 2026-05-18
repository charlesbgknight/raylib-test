#include "include/Main.hpp"
#include <print>

Main::Main() 
:           window{Main::SCREEN_WIDTH, 
                    Main::SCREEN_HEIGHT,
                     "Raylib C++ Starter Kit Example"},
            world{}
{
    window.SetTargetFPS(60);
}

void Main::Update()
{
    world.Update();
}

void Main::Draw()
{
    world.Draw();
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
