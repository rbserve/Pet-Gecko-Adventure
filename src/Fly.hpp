#pragma once
#include "Entity.hpp"
#include "raylib.h"

class Fly : public Entity{
public:
    Fly();
    Texture2D GetSprite() const;
private:
    Texture2D m_sprite;
};