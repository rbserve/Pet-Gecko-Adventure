#pragma once
#include "raylib.h"

class Entity {
public:
    Entity():m_position({0,0}){};
    virtual ~Entity() = default;

    void SetPosition(Vector2& newVal){m_position = newVal;};
    Vector2 GetPosition() const {return m_position;};
    
protected:
    Vector2 m_position;

};