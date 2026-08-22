#include "Gecko.hpp"
#include <algorithm>
#include <string>

Gecko::Gecko():
    Entity(LoadTexture("asset/geckoSprite.png")),
    m_hunger(1), 
    m_maxHunger(3),
    m_affection(0), 
    m_speed(5),
    m_maxSpeed(5),
    m_daySurvived(1),
    m_secretFound(0),
    m_tiredTimer(GetTime())
{};

Gecko::~Gecko(){
    UnloadTexture(m_sprite);
}

void Gecko::Reset(){
    m_hunger = 1;
    m_maxHunger = 3;
    m_affection = 0;
    m_speed = 5;
    m_maxSpeed = 5;
    m_daySurvived = 1;
    m_secretFound = 0;
    StartTiredTimer();
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
    if (IsTired()){
        DrawText(std::string("I am tired. I want to go home.").c_str(),
        m_position.x - 150, m_position.y + 100, 20, DARKBLUE);
    }
    // DrawRectangle(m_collisionRect.x, m_collisionRect.y, m_collisionRect.width, m_collisionRect.height, Color{225,0,0,100});
    // const int lineLength = 100;
    // DrawLine(m_position.x, m_position.y,m_position.x + GetForwardVec(lineLength).x, m_position.y + GetForwardVec(lineLength).y, RED);
};

//setter
void Gecko::SetAffection(int newVal){
    m_affection = std::clamp(newVal, 0, 5);
};

void Gecko::SetHunger(float newVal){
    m_hunger = std::clamp(newVal, 0.0f, m_maxHunger);
};

void Gecko::SetMaxHunger(float val){
    m_maxHunger = val;
};

void Gecko::SetSpeed(int newVal){
    m_speed = std::clamp(newVal, 0, GetMaxSpeed());
};

void Gecko::SetMaxSpeed(int newVal){
    m_maxSpeed = std::clamp(newVal, 0, 10);
};

void Gecko::SetDaySurvived(int val){
    if (val > 0){
        m_affection += 1;
        m_maxSpeed += 1;
        m_speed = m_maxSpeed;
        m_maxHunger += 1;
    }
    m_daySurvived = val;
};

void Gecko::SetSecretFound(int val){
    m_secretFound = val;
}

void Gecko::StartTiredTimer(){
    m_tiredTimer = GetTime();
}


//getter
int Gecko::GetAffection() const{
    return m_affection;
};
float Gecko::GetHunger() const{
    return m_hunger;
};
float Gecko::GetMaxHunger() const{
    return m_maxHunger;
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
int Gecko::GetDaySurvived() const{
    return m_daySurvived;
};
int Gecko::GetSecretFound() const{
    return m_secretFound;
};
bool Gecko::IsTired() const{
    // check if minutes is pass
    return ((GetTime() - m_tiredTimer ) >= ( 1+ m_daySurvived) * 60.0f); 
};