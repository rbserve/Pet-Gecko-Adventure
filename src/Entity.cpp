#include "Entity.hpp"

Entity::Entity(Texture2D sprite):
        m_position({0,0}),
        m_sprite(sprite),
        m_rotation(0),
        m_collisionRect(Rectangle{0,0,(float)sprite.width, (float)sprite.height})
{};

    
void Entity::SetPosition(const Vector2& newVal){
    m_position = newVal;
};

const Vector2& Entity::GetPosition() const {
    return m_position;
};

void Entity::SetRotation(float newVal){
    m_rotation = std::fmodf(newVal, 360.0f);
};

const float& Entity::GetRotation() const {
    return m_rotation;
};

void Entity::SetCollisionRectPosition(const Vector2& newVal){
    m_collisionRect.x = newVal.x - m_sprite.width/2;
    m_collisionRect.y = newVal.y - m_sprite.height/2;
};

const Rectangle& Entity::GetCollisionRect() const{
    return m_collisionRect;
};

// return forward normalised vector based on rotation
const Vector2 Entity::GetForwardVec(float length){
    const Vector2 result =  Vector2{
        (float)std::cos(m_rotation * M_PI/180.0f) * length,
        (float)std::sin(m_rotation * M_PI/180.0f) * length
    };
    return result;
}