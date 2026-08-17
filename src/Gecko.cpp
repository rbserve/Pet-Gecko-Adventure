#include "Gecko.hpp"
#include <algorithm>

Gecko::Gecko():
    m_sprite(LoadTexture("asset/geckoSprite.png")),
    m_hunger(3), 
    m_affection(0), 
    m_speed(0),
    m_maxSpeed(5)
{};

//setter
void Gecko::SetAffection(int newVal){
    m_affection = std::clamp(newVal, 0, 5);
};

void Gecko::SetHunger(int newVal){
    m_hunger = std::clamp(newVal, 0, 3);
};

void Gecko::SetSpeed(int newVal){
    m_speed = std::clamp(newVal, 0, GetMaxSpeed());
};

void Gecko::SetMaxSpeed(int newVal){
    m_maxSpeed = std::clamp(newVal, 0, 10);
};



//getter
int Gecko::GetAffection() const{
    return m_affection;
};
int Gecko::GetHunger() const{
    return m_hunger;
};
int Gecko::GetSpeed() const{
    return m_speed;
};
int Gecko::GetMaxSpeed() const{
    return m_maxSpeed;
};
Texture2D Gecko::GetSprite() const{
    return m_sprite;
};