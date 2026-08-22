#include "HomeLevel.hpp"

HomeLevel::HomeLevel(const int screenWidth, const int screenHeight, const Texture2D& sprite, Gecko& gecko, const int id): 
    Level(screenWidth, screenHeight, sprite, id),
    m_geckoRef(gecko),
    m_startSleepTimer(0)
    {};

void HomeLevel::Draw(){
    DrawTexture(m_sprite, 0, 0, WHITE);

    for (auto& f : m_flies){
                f->Draw();
    }
    
    // DrawRectangle(m_homeCollisionBox.x, m_homeCollisionBox.y, m_homeCollisionBox.width, m_homeCollisionBox.height, Color{225,0,0,100});
    
    if (CheckCollisionRecs(m_geckoRef.GetCollisionRect(), m_homeCollisionBox)){

        DrawMenu();

        //start sleep
        if (IsKeyPressed(KEY_E) && m_startSleepTimer == 0){
            if (m_geckoRef.GetHunger() >= 1){
                m_startSleepTimer = GetTime();
                m_geckoRef.SetSpeed(0);
                m_geckoRef.SetHunger(m_geckoRef.GetHunger() - 0.5);
                m_geckoRef.SetDaySurvived(m_geckoRef.GetDaySurvived()+ 1);
                m_geckoRef.StartTiredTimer();
            }else{
                m_popUpTextTimer = GetTime();
                
            }
        }

        //draw pop up text
        if (m_popUpTextTimer != 0){
            if ((GetTime() - m_popUpTextTimer) >= 1){
                m_popUpTextTimer = 0;
            }else{
                Ultilities::DrawOutlinedText(std::string("Gecko is hungry.").c_str(),
                    m_geckoRef.GetPosition().x - 120, m_geckoRef.GetPosition().y + 100, 40, BLUE, 2, LIGHTBLUE);
            }
        }

        //maintain sleeping
        if ( m_startSleepTimer != 0 && (GetTime() - m_startSleepTimer) <= 1){
            //sleeping 
            DrawRectangle(0,0,1920, 1080, BLACK);
            DrawText("Sleeping...", 900, 540, 40, BLUE);
        }else{
            //wake up
            m_startSleepTimer = 0;
            m_geckoRef.SetSpeed(m_geckoRef.GetMaxSpeed());
            
            
        }
    }
};

void HomeLevel::DrawMenu(){
    const Vector2 geckoCurrPos = m_geckoRef.GetPosition();
    const int sidePadding = 200;
    const int outlineSpacing = 2;
    
        Ultilities::DrawOutlinedText("Press Anywhere", 
                    geckoCurrPos.x - 130, geckoCurrPos.y - 300, 40, DARKBLUE, outlineSpacing, LIGHTBLUE); 
        // Ultilities::DrawOutlinedText(std::string("level: " + std::to_string(m_geckoRef.GetDaySurvived())).c_str(),
        //             geckoCurrPos.x - sidePadding, geckoCurrPos.y - 100, 40, DARKBLUE, outlineSpacing, LIGHTBLUE);
        Ultilities::DrawOutlinedText(std::string("Affection: "+ std::to_string(m_geckoRef.GetAffection())).c_str(), 
                    geckoCurrPos.x + sidePadding, geckoCurrPos.y - 100, 40, DARKBLUE, outlineSpacing, LIGHTBLUE);
        Ultilities::DrawOutlinedText(std::string("Secret Found: "+std::to_string(m_geckoRef.GetSecretFound())).c_str(), 
                    geckoCurrPos.x - sidePadding - 250, geckoCurrPos.y - 100, 40, DARKBLUE, outlineSpacing, LIGHTBLUE);
        Ultilities::DrawOutlinedText(std::string("[E] to sleep").c_str(), 
                    geckoCurrPos.x -100, geckoCurrPos.y -200, 40, DARKBLUE, outlineSpacing, LIGHTBLUE);
};