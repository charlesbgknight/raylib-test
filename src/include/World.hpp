#pragma once
#include <raylib-cpp.hpp>
#include "id/TileType.hpp"
#include <array>
// #include "Main.hpp"

class World
{

public:
    World();
    typedef struct
    {
        TileType id;
        int frame;
        // damage?? or track locally

    } Tile;
    static std::array<raylib::Texture2D, (size_t)TileType::NUM_TILES> s_texturecache;
    /** World::Draw : void -> void
     *  @brief Draws the world's tiles and effects to the global screen buffer.
     *  
     *  @param previously float scale, raylib::Vector2 cameraPos? but these are (pending testing) handled by Camera2D beginMode
     */
    void Draw();
    void Update();

private:
    
    static constexpr int WORLD_WIDTH = 80;
    static constexpr int WORLD_HEIGHT = 60;
    std::array<std::array<Tile, WORLD_HEIGHT>, WORLD_WIDTH> m_tiles{};
    static constexpr int TILE_HEIGHT_PIXELS = 32;
    static constexpr int TILE_WIDTH_PIXELS = 32;
};