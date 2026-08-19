#pragma once
#include "raylib.h"
#include <memory>
#include <unordered_map>
#include <vector>
#include "Level.hpp"

class LevelGenerator {
public:
    LevelGenerator(const int screenWidth, const int screenHeight);
    ~LevelGenerator();
    void CreateNewLevel(const int screenWidth, const int screenHeight);
    Level& GetCurrentLevel() const;
    void SwitchLevel(const unsigned int levelID);
    unsigned int GetCurrLevelID() const ;
    void DrawCurrentLevel();
private:
    std::vector<std::unique_ptr<Level>> m_levels;
    unsigned int m_currLevelID;
    const std::unordered_map<int, Texture2D> m_textureMap = {
            {0, LoadTexture("asset/cicakHome.png")},
            {1, LoadTexture("asset/cicakHome.png")}
    };

};