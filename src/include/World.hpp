#pragma once
#include <raylib-cpp.hpp>
#include "id/TileType.hpp"
//#include "Main.hpp"

class World
{
    private:
    TileType m_tiles[400][400]{};
    
    public:
    typedef struct {
        TileType id;
        int frame;
        // damage?? or track locally

    } Tile;
    static std::array<raylib::Texture2D, (size_t)TileType::NUM_TILES> s_texturecache;

    World();
    void Update();

    void Draw();
    void drawBoxes();
    
};