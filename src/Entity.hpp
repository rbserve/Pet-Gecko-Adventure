#pragma once
#include "raylib.h"
#include <cmath>

class Entity {
public:
    Entity(Texture2D sprite);

    virtual ~Entity() = default;

    void SetPosition(const Vector2& newVal);
    const Vector2& GetPosition() const;

    void SetRotation(float newVal);
    const float& GetRotation() const;

    void SetCollisionRectPosition(const Vector2& newVal);
    const Rectangle& GetCollisionRect() const;

    virtual void Draw()=0;

    // return forward normalised vector based on rotation
    const Vector2 GetForwardVec(float length);
    
protected:
    Vector2 m_position;
    Texture2D m_sprite;
    float m_rotation;
    Rectangle m_collisionRect;
};