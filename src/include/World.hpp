#pragma once
#include "../../include/raylib/raylib-cpp.hpp"
//#include "Main.hpp"

class World
{
    private:
    static const int SQUARE_SIZE = 40;
    
    static const int RAINBOW_SPEED = 5;
    float m_hue;
    float m_sat;
    float m_val;
    static inline const raylib::Vector2 size{SQUARE_SIZE, SQUARE_SIZE};
    raylib::Vector2 m_pos;
    raylib::Color m_textColor;
    long m_elapsedFrames;
    
    public:
    World();
    void Update();
    
    void Draw();
    void drawBoxes();
    
};