//possobly restructure as module?? but later 
#include "include/Entity.hpp"

Entity::Entity() : m_id{},
           m_pos{} {};
Entity::Entity(EntityType id) : m_id{id} {};

void Entity::Update() {
    m_pos += {1,0};
}

void Entity::Draw() {
    Entity::s_texturecache.at(m_id).Draw(m_pos.x, m_pos.y);
}