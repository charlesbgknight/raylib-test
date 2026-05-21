#pragma once
#include <raylib-cpp.hpp>
#include "id/EntityType.hpp"
#include <array>

class Entity {

    private:
    EntityType m_id;
    raylib::Vector2 m_pos;
    public:
        static std::array<raylib::Texture2D, EntityType::NUM_ENTITIES> s_texturecache;
        Entity();
        Entity(EntityType id);
        void Update();
        void Draw();
};