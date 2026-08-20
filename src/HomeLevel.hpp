#pragma once
#include "Level.hpp"
#include "Gecko.hpp"
#include <string>

class HomeLevel : public Level{
public:
    HomeLevel(const int screenWidth, const int screenHeight, const Texture2D& sprite, Gecko& gecko, const int id): 
        Level(screenWidth, screenHeight, sprite, id),
        m_geckoRef(gecko),
        m_startSleepTime(0)
        {};

    void Draw(){
        DrawTexture(m_sprite, 0, 0, WHITE);

        for (auto& f : m_flies){
                    f->Draw();
        }
        
        // DrawRectangle(m_homeCollisionBox.x, m_homeCollisionBox.y, m_homeCollisionBox.width, m_homeCollisionBox.height, Color{225,0,0,100});
        
        if (CheckCollisionRecs(m_geckoRef.GetCollisionRect(), m_homeCollisionBox)){

            DrawMenu();

            if (IsKeyPressed(KEY_E) && m_startSleepTime == 0){
                m_startSleepTime = GetTime();
                m_geckoRef.SetSpeed(0);
                m_geckoRef.SetHunger(m_geckoRef.GetHunger() - 1);
                m_geckoRef.SetLevel(m_geckoRef.GetLevel()+ 1);
            }

            if ( m_startSleepTime != 0 && (GetTime() - m_startSleepTime) <= 1){
                //sleeping 
                DrawRectangle(0,0,1920, 1080, BLACK);
                DrawText("Sleeping...", 900, 540, 40, BLUE);
            }else{
                m_startSleepTime = 0;
                m_geckoRef.SetSpeed(m_geckoRef.GetMaxHunger());
                
            }
        }
    };

    void DrawMenu(){
        const Vector2 geckoCurrPos = m_geckoRef.GetPosition();
        const int sidePadding = 200;
            DrawText("Press Anywhere", 
                        geckoCurrPos.x - 100, geckoCurrPos.y - 300, 40, DARKBLUE); 
            DrawText(std::string("level: " + std::to_string(m_geckoRef.GetLevel())).c_str(),
                        geckoCurrPos.x - sidePadding, geckoCurrPos.y - 100, 40, DARKBLUE);
            DrawText(std::string("Affection: "+ std::to_string(m_geckoRef.GetAffection())).c_str(), 
                        geckoCurrPos.x + sidePadding, geckoCurrPos.y - 100, 40, DARKBLUE);
            DrawText(std::string("Secret Found: "+std::to_string(m_geckoRef.GetSecretFound())).c_str(), 
                        geckoCurrPos.x - sidePadding - 100, geckoCurrPos.y + 100, 40, DARKBLUE);
            DrawText(std::string("[E] to sleep").c_str(), 
                        geckoCurrPos.x + sidePadding, geckoCurrPos.y + 100, 40, DARKBLUE);
    };

private:
    Rectangle m_homeCollisionBox = Rectangle{640, 810, 640, 270};
    Gecko& m_geckoRef;
    float m_startSleepTime;
};