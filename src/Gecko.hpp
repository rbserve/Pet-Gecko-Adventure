#pragma once
#include "raylib.h"
#include "Entity.hpp"

class Gecko : public Entity{
public:
    Gecko();
    void SetAffection(int val);
    void SetHunger(int val);
    void SetSpeed(int val);
    void SetMaxSpeed(int val);

    int GetAffection() const;
    int GetHunger() const;
    int GetSpeed() const;
    int GetMaxSpeed() const;
    Texture2D GetSprite() const;
    void Draw() override;

private:

    int m_hunger;       //deplet overtime, refill by eating flies
    int m_affection;    //increase by petting on it and simply playing
    int m_speed;        //increase when hunger and affection full
    int m_maxSpeed;     //mutable speed cap
};