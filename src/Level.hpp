#pragma once
#include "raylib.h"
#include "Fly.hpp"
#include <vector>
#include <memory>
#include <unordered_map>


class Level {
public:
    //level 0 type is home, other is explorable level
    Level(const int screenWidth, const int screenHeight, const Texture2D& sprite,  const int id);
    int CheckFliesCollision(const Rectangle& other);
    virtual void Draw();
    int GetID() const;
protected:
    std::vector<std::unique_ptr<Fly>> m_flies;
    const Texture2D& m_sprite;
    const int m_id;
};