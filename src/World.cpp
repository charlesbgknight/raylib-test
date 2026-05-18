#include "include/World.hpp"
#include "include/Main.hpp"
#include <print>
#include <cmath>
World::World() : m_hue(0.0),
                 m_sat(1.0),
                 m_val(1.0),
                 m_pos{0, 255},           // Main::SCREEN_HEIGHT / 2};
                 m_textColor{0, 255, 255}, // HSV = 011, bright red
                 m_elapsedFrames{0},
                 m_tiles{}
{
    
}

void World::Update()
{
    m_elapsedFrames++;
        m_hue++;
    if (m_hue == 256 * RAINBOW_SPEED)
    {
        m_hue = 0;
    }
    m_textColor = raylib::Color::FromHSV(m_hue / RAINBOW_SPEED, m_sat, m_val);
}
void World::drawBoxes()
{

    int numBoxes = 800 / SQUARE_SIZE;
    for (int i = 0; 
        i <= numBoxes;
         ++i) {

        raylib::Color c = raylib::Color::FromHSV((float)(i * 10.0), 1.0, 1.0);
        m_pos.SetX((float)(i * SQUARE_SIZE));
        c.DrawRectangle(m_pos, size);
    }
}
void World::Draw()
{
    drawBoxes();
    World::texturecache_tiles[1].Draw(80, 80);
}
