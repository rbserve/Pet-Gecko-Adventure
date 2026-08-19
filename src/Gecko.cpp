#include "Gecko.hpp"
#include <algorithm>

Gecko::Gecko():
    Entity(LoadTexture("asset/geckoSprite.png")),
    m_hunger(0), 
    m_affection(0), 
    m_speed(0),
    m_maxSpeed(5)
{};

Gecko::~Gecko(){
    UnloadTexture(m_sprite);
}

void Gecko::Draw() {
    // DrawCircle(m_position.x,m_position.y, 2, RED);
    DrawTexturePro(
        GetSprite(), 
        {0,0,(float)m_sprite.width, (float)m_sprite.height},
        {m_position.x, m_position.y,(float)m_sprite.width, (float)m_sprite.height},
        {m_sprite.width / 2.0f, m_sprite.height/2.0f}, 
        m_rotation, 
        WHITE 
            );
    // DrawRectangle(m_collisionRect.x, m_collisionRect.y, m_collisionRect.width, m_collisionRect.height, Color{225,0,0,100});
    const int lineLength = 100;
    DrawLine(m_position.x, m_position.y,m_position.x + GetForwardVec(lineLength).x, m_position.y + GetForwardVec(lineLength).y, RED);
};

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