#include "include/World.hpp"
#include "include/Main.hpp"
#include <print>
#include <cmath>
using namespace raylib;
//static constexpr std::array<Util::Coord, 4> CARDINAL_DIRS{{0,1}, {1,0}, {0,-1}, {-1,0}}; 
World::World() : m_tiles{}
{
    //m_tiles: 2D std::array. Indexed [x][y], [0][0] is the top-left corner.
    for (int y = 0; y < World::WORLD_HEIGHT; ++y)
    {
        for (int x = 0; x < World::WORLD_WIDTH; ++x)
        {
            m_tiles[x][y].id = (y < 20) ? TileType::AIR : TileType::DIRT;
            m_tiles[x][y].frame = x + y; //TODO % num frames
        }
    }
}

void World::Update()
{
}
void World::Draw()
{ 
    for (int r = 0; r < WORLD_HEIGHT; r++)
    {
        for (int c = 0; c < WORLD_WIDTH; c++)
        {
            ::Vector2 tilePos{c * TILE_WIDTH_PIXELS, r * TILE_HEIGHT_PIXELS};
            ::Rectangle tSource{0,0,TILE_WIDTH_PIXELS, TILE_HEIGHT_PIXELS};
            // If same tile one above, shift sourcerect down.
            // If same tile one left, shift sourcerect right
            Tile t = m_tiles[c][r];
            // TODO uncomment lol     if(t.id == TileType::AIR) continue;
            tSource.y += t.frame * TILE_HEIGHT_PIXELS * 3;
            // Cohere lower surface if same blocks below
            if (r + 1 < WORLD_HEIGHT && m_tiles[c][r + 1].id == t.id)
            tSource.y -= TILE_HEIGHT_PIXELS;
            // Cohere upper  surface if same blocks above
            if (r > 0 && m_tiles[c][r - 1].id == t.id)
            tSource.y += TILE_HEIGHT_PIXELS;
            // Cohere left surface if same blocks right
            if (c + 1 < WORLD_WIDTH && m_tiles[c + 1][r].id == t.id)
            tSource.x -= TILE_WIDTH_PIXELS;
            // Cohere right surface if same blocks left
            if (c > 0 && m_tiles[c - 1][r].id == t.id)
            tSource.x -= TILE_WIDTH_PIXELS;
            // man i'd love a `for ( x,y in [{0,1},...]) ` type of thing
            
            World::s_texturecache[t.id].Draw(tSource, tilePos);
        }
    }
}
