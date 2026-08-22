#pragma once
#include "raylib.h"
#include "Entity.hpp"

class Gecko : public Entity{
public:
    Gecko();
    ~Gecko();
    void SetAffection(int val);
    void SetHunger(float val);
    void SetMaxHunger(float val);
    void SetSpeed(int val);
    void SetMaxSpeed(int val);
    void SetDaySurvived(int val);
    void SetSecretFound(int val);
    void StartTiredTimer();

    int GetAffection() const;
    float GetHunger() const;
    float GetMaxHunger() const;
    int GetSpeed() const;
    int GetMaxSpeed() const;
    int GetDaySurvived() const;
    int GetSecretFound() const;

    bool IsTired() const;
    
    Texture2D GetSprite() const;
    void Draw() override;

    void Reset();

private:

    float m_hunger;       //deplet overtime, refill by eating flies
    float m_maxHunger;    
    int m_affection;    //increase by petting on it and simply playing
    int m_speed;        //increase when hunger and affection full
    int m_maxSpeed;     //mutable speed cap
    int m_daySurvived;
    int m_secretFound;
    float m_tiredTimer;
};