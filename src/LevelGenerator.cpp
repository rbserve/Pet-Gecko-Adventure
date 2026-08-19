#include "LevelGenerator.hpp"

LevelGenerator::LevelGenerator(const int screenWidth, const int screenHeight):m_levels(), m_currLevelID(0){
    m_levels.emplace_back(std::make_unique<Level>(screenWidth, screenHeight, m_textureMap.at(0)));
};

LevelGenerator::~LevelGenerator(){
    for (auto texture : m_textureMap){
        UnloadTexture(texture.second);
    }
}

void LevelGenerator::CreateNewLevel(const int screenWidth, const int screenHeight){
    const int levelType = (rand() % m_textureMap.size()-1)+1;
    m_levels.emplace_back(std::make_unique<Level>(screenWidth, screenHeight, m_textureMap.at(levelType)));
};

Level& LevelGenerator::GetCurrentLevel() const{
    return *(m_levels.at(m_currLevelID).get());
};

void LevelGenerator::SwitchLevel(const unsigned int levelID){
    if (levelID < m_levels.size()) {
        m_currLevelID = levelID;
    }
};
 
unsigned int LevelGenerator::GetCurrLevelID() const {
    return m_currLevelID;
};

void LevelGenerator::DrawCurrentLevel(){
    GetCurrentLevel().Draw();
};