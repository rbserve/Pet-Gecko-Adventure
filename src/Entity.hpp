#pragma once
#include "raylib.h"
#include <cmath>

class Entity {
public:
    Entity(Texture2D sprite):
        m_position({0,0}),
        m_sprite(sprite),
        m_rotation(0)
    {};

    virtual ~Entity() = default;

    void SetPosition(Vector2& newVal){m_position = newVal;};
    Vector2 GetPosition() const {return m_position;};

    void SetRotation(float newVal){
        m_rotation = std::fmodf(newVal, 360.0f);
    };
    float GetRotation() const {return m_rotation;};

    virtual void Draw()=0;
    // return forward normalised vector based on rotation
    Vector2 GetForwardVec(float length){
        return Vector2{
            m_position.x + (float)std::cos(m_rotation * M_PI/180.0f) * length,
            m_position.y + (float)std::sin(m_rotation * M_PI/180.0f) * length
        };
    }
    
protected:
    Vector2 m_position;
    Texture2D m_sprite;
    float m_rotation;
};