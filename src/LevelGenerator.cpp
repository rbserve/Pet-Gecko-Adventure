#include "LevelGenerator.hpp"
#include <algorithm>

LevelGenerator::LevelGenerator(const int screenWidth, const int screenHeight, Gecko& gecko):m_levels(), m_currLevelID(0){
    //the one and only home level  ( might do inheritance later)
    m_levels.emplace_back(std::make_unique<HomeLevel>(screenWidth, screenHeight, m_textureMap.at(0), gecko, 0));
};

void LevelGenerator::Reset(){
    SwitchLevel(0);
    for (auto it = m_levels.begin(); it != m_levels.end();){
        if ((*it)->GetID() == 0) {
            ++it;
        }else{
            it = m_levels.erase(it);
        }
    }

};

LevelGenerator::~LevelGenerator(){
    for (auto texture : m_textureMap){
        UnloadTexture(texture.second);
    }
}

void LevelGenerator::CreateNewLevel(const int screenWidth, const int screenHeight){
    const int levelType = std::max((rand() % m_textureMap.size() +1 ), static_cast<unsigned long>(1)); // always skip 0 home level,  
    m_levels.emplace_back(std::make_unique<Level>(screenWidth, screenHeight, m_textureMap.at(levelType), 1));
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