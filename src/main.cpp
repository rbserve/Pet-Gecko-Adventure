#include "raylib.h"
#include <cmath>
#include <iostream>
#include "Entity.hpp"
#include "Gecko.hpp"
#include "Fly.hpp"
#include "LinearPathFinding.hpp"
#include "LevelGenerator.hpp"
#include "HomeLevel.hpp"
#include <memory> 
#include <vector>





int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    // const int screenWidth = 1280;
    // const int screenHeight = 720;
    // const Rectangle screenRec = {0, 0, screenWidth, screenHeight};

    SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_UNDECORATED);
    InitWindow(screenWidth, screenHeight, "Pet Cicak Adventure");
    SetTargetFPS(60);

    float rotationSpeed = 2.0f;
    float startGameOverTime = 0;

    
    Gecko gecko;
    gecko.SetPosition(Vector2{screenWidth/2, 0.8 *screenHeight});
    
    //test entity
    LevelGenerator levelGenerator(screenWidth, screenHeight, gecko);
    bool isOnRightEdge = false;
    bool isOnLeftEdge = false;
    // dynamic_cast<HomeLevel*>(&levelGenerator.GetCurrentLevel())->DrawMenu();

    //pathfinding tools
    LinearPathFinding geckoPathFinder;
    Vector2 mouseTarget = Vector2{gecko.GetPosition().x + 10, gecko.GetPosition().y + 10};
    geckoPathFinder.SetTarget(mouseTarget);

    //background music
    // InitAudioDevice();
    // Music music = LoadMusicStream("asset/soundore-cartoon-366903.ogg");
    // music.looping = true;
    // PlayMusicStream(music);


    while (!WindowShouldClose()) {
        
        // UpdateMusicStream(music); 

        //collision check to every flies in the current level
        if (levelGenerator.GetCurrentLevel().CheckFliesCollision(gecko.GetCollisionRect())){
            gecko.SetHunger(gecko.GetHunger() + 1);
        };

        //set gecko target
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouseTarget =  GetMousePosition();
            geckoPathFinder.SetTarget(mouseTarget);
        }
        
        //update gecko state
        const Vector2 geckoCurrPos = gecko.GetPosition(); 
        const Vector2 newPos = geckoPathFinder.GetNextPosition(gecko.GetPosition(), gecko.GetSpeed());
        
        //only update when gecko is moving
        if (newPos.x != geckoCurrPos.x && newPos.y != geckoCurrPos.y){
            gecko.SetPosition(newPos);
            gecko.SetCollisionRectPosition(newPos);
            const Vector2 directionVec = Vector2{mouseTarget.x -gecko.GetPosition().x, mouseTarget.y - gecko.GetPosition().y};

            //deplet hunger
            gecko.SetHunger(gecko.GetHunger() - 0.05 * GetFrameTime());

            const float angleToMove = Ultilities::GetMiddleDegree(gecko.GetForwardVec(1), directionVec);
            
            if(abs(angleToMove) > rotationSpeed){
                if (angleToMove > 180){ //counter clockwise rotate
                    gecko.SetRotation(gecko.GetRotation() - rotationSpeed);
                }
                gecko.SetRotation(gecko.GetRotation() + rotationSpeed);
            }
        }

        //gecko hunger debuff
        if (gecko.GetHunger() < 0.2*gecko.GetMaxHunger()){
            gecko.SetSpeed(0.5 * gecko.GetMaxSpeed());
        }else {
            gecko.SetSpeed(gecko.GetMaxSpeed());
        }
        
        //game over
        if(gecko.GetHunger() <= 0.05 && startGameOverTime == 0){
            startGameOverTime = GetTime();
            gecko.SetPosition(Vector2{screenWidth/2, 0.8 *screenHeight});
            gecko.Reset();
            levelGenerator.Reset();
            Vector2 mouseTarget = Vector2{gecko.GetPosition().x + 10, gecko.GetPosition().y + 10};
            geckoPathFinder.SetTarget(mouseTarget);
        }

        

        //move to next level by clicking [SPACE] on the right bound
        const int bound = 200;
        if (geckoCurrPos.x >= screenWidth - bound){
            isOnRightEdge = true;
        }else{
            isOnRightEdge = false;
        }

        //check left to go back to previous leve
        if (geckoCurrPos.x <= bound && levelGenerator.GetCurrLevelID() != 0){
            isOnLeftEdge = true;
        }else{
            isOnLeftEdge = false;
        }
        
        //clicking [SPACE] to switch level
        if (IsKeyPressed(KEY_SPACE) ){
            if (isOnRightEdge){
                levelGenerator.CreateNewLevel(screenWidth, screenHeight);
                levelGenerator.SwitchLevel(levelGenerator.GetCurrLevelID() + 1);
                
                //update gecko position
                gecko.SetPosition(Vector2{bound, geckoCurrPos.y});
                isOnRightEdge = false;

                //update mouse target
                mouseTarget = gecko.GetPosition();
                geckoPathFinder.SetTarget(mouseTarget);

            }else if (isOnLeftEdge){ //first home level cannot go left
                levelGenerator.SwitchLevel(levelGenerator.GetCurrLevelID() - 1);

                //update gecko position
                gecko.SetPosition(Vector2{screenWidth - bound, geckoCurrPos.y});
                isOnLeftEdge = false;

                //update mouse target
                mouseTarget = gecko.GetPosition();
                geckoPathFinder.SetTarget(mouseTarget);
            }
        }

        
        
        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            levelGenerator.DrawCurrentLevel();
            DrawCircle(mouseTarget.x, mouseTarget.y, 15, RED);
            gecko.Draw();
            
            //gecko hunger bar
            std::string hungerBar = "Hunger: ";
            Ultilities::DrawOutlinedText(hungerBar.c_str(), 30, 10, 50, DARKBLUE, 2, WHITE);
            DrawRectangle(30, 80, 500, 50, GRAY);
            DrawRectangle(30, 80,(500* gecko.GetHunger()/gecko.GetMaxHunger()), 50, GREEN);

            //boundary hint
            if (isOnRightEdge){
                std::string rightEdgeHint = "[SPACE] to next level";
                DrawText(rightEdgeHint.c_str(), geckoCurrPos.x-200, geckoCurrPos.y + 40, 30, DARKBLUE);
            }
            if (isOnLeftEdge){
                std::string leftEdgeHint = "[SPACE] to go back";
                DrawText(leftEdgeHint.c_str(), geckoCurrPos.x-150, geckoCurrPos.y + 40, 30, DARKBLUE);
            }

            //game over screen
        if ( startGameOverTime != 0 && (GetTime() - startGameOverTime) <= 2){
                //sleeping 
                DrawRectangle(0,0,1920, 1080, BLACK);
                DrawText("Pet Cicak starve to death :(", 650, 540, 40, BLUE);
            }else{
                startGameOverTime = 0;
            }
            
        EndDrawing();
    }
    
    // UnloadMusicStream(music);
    // CloseAudioDevice();
    CloseWindow();
    return 0;
}