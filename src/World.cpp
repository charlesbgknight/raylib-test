#include "include/World.hpp"
#include "include/Main.hpp"
#include <print>
#include <cmath>
World::World() : m_tiles{}
{

}

void World::Update()
{
}
void World::drawBoxes()
{
}
void World::Draw()
{
    World::s_texturecache[1].Draw(80, 80);
}
