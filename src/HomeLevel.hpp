#pragma once
#include "Level.hpp"
#include "Gecko.hpp"
#include <string>
#include "Ultilities.hpp"

class HomeLevel : public Level{
public:
    HomeLevel(const int screenWidth, const int screenHeight, const Texture2D& sprite, Gecko& gecko, const int id);

    void Draw();

    void DrawMenu();

private:
    Rectangle m_homeCollisionBox = Rectangle{640, 810, 640, 270};
    Gecko& m_geckoRef;
    float m_startSleepTimer;
    float m_popUpTextTimer;
    const Color LIGHTBLUE = Color{173, 216, 230, 225};
};