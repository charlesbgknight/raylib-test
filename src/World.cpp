#include "include/World.hpp"
#include "include/Main.hpp"
#include <print>
#include <cmath>
using namespace raylib;
//static constexpr std::array<Util::Coord, 4> CARDINAL_DIRS{{0,1}, {1,0}, {0,-1}, {-1,0}}; 
World::World() : m_tiles{}
{
    //Initialize m_tiles to empty (AIR) blocks 
    for (int y = 0; y < World::WORLD_HEIGHT; ++y)
    {
        for (int x = 0; x < World::WORLD_WIDTH; ++x)
        {
            m_tiles[x][y].id = (y < WORLD_HEIGHT/2) ? TileType::AIR : TileType::DIRT;
            m_tiles[x][y].frame = x + y; //TODO % num frames
        }
    }
    //Generate some random planetoid blobs 
//     for (int bigy = 0; bigy < WORLD_HEIGHT; bigy += 16) {
//         for (int bigx = 0; bigx < WORLD_WIDTH; bigx += 16) {
// 
//         }
//     }
    int x = 15, y = 10;
    int w = 16, h = 16;
    for (int a = - w; a < w; a++) {
        for (int b = -h; b < h; b++) {
            //Manhattan distance bc lazy
            if (abs(a) + abs(b) < 8) {
                m_tiles[x+a][y+b]= {TileType::DIRT,0};
            }
        }
    }
    //Debug-print worldgen to console
    for (int y = 0; y < WORLD_HEIGHT; y++)
    {
        for (int x = 0; x < WORLD_WIDTH; x++)
        {
            putchar(m_tiles[x][y].id == TileType::AIR ? ' ' : '@');
        }
        putchar('\n');
    }
}

void World::Update()
{
}
void World::Draw()
{
    //Draw tilemap:

    // Each tile texture file consists of a center block surrounded by edge blocks. Init a 
    //  texture source to the center block location, then shift it in a cardinal direction if 
    //  a block of the same id touches this blck opposite to that cardinal direction (i.e., 
    //  blocks with similar blocks abovce become bottom edges)
    
    //Textures (will later) also have multiple slightly-changed repetition "frames" to
    // interrupt patterns &  provide visual feedback for block hits etc.

    for (int r = 0; r < WORLD_HEIGHT; r++)
    {
        for (int c = 0; c < WORLD_WIDTH; c++)
        {
            //Initialize texture source to middle tile, located at 1,1.
            ::Rectangle texSource(TILE_WIDTH_PIXELS, TILE_HEIGHT_PIXELS,
                                  TILE_WIDTH_PIXELS, TILE_HEIGHT_PIXELS);
            // If same tile one above, shift sourcerect down. If same tile one left, shift sourcerect right
            Tile t = m_tiles[c][r];
            
            raylib::Vector2 tilePos{c * TILE_WIDTH_PIXELS, r * TILE_HEIGHT_PIXELS};
            World::s_texturecache[t.id].Draw(texSource, tilePos);
        }
    }
}

/*
//TODO uncomment lol     if(t.id == TileType::AIR) continue;
            ::Texture2D tex = s_texturecache[t.id];
            texSource.y += t.frame * TILE_HEIGHT_PIXELS * 3;
            // Cohere lower surface if same blocks below
            if (r+1 < WORLD_HEIGHT && m_tiles[c][r + 1].id == t.id)
            texSource.y -= TILE_HEIGHT_PIXELS;
            // Cohere upper  surface if same blocks above
            if (r > 0 && m_tiles[c][r - 1].id == t.id)
            texSource.y += TILE_HEIGHT_PIXELS;
            //Cohere left surface if same blocks right
            if (c+1 < WORLD_WIDTH && m_tiles[c+1][r].id == t.id)
            texSource.x -= TILE_WIDTH_PIXELS;
            //Cohere right surface if same blocks left
            if (c > 0 && m_tiles[c - 1][r].id == t.id)
            texSource.x += TILE_WIDTH_PIXELS;
            //man i'd love a `for ( x,y in [{0,1},...]) ` type of thing



*/
