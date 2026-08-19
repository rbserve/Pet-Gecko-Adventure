#include "raylib.h"
#include <cmath>
#include <iostream>
#include "Entity.hpp"
#include "Gecko.hpp"
#include "Fly.hpp"
#include "LinearPathFinding.hpp"
#include "LevelGenerator.hpp"
#include <memory> 
#include <vector>

float GetMiddleDegree(const Vector2& v1, const Vector2& v2){
    const float lengthV1 = std::sqrt(v1.x * v1.x + v1.y * v1.y);
    const float lengthV2 = std::sqrt(v2.x * v2.x + v2.y * v2.y);

    const float dotProduct = (v1.x * v2.x) + (v1.y * v2.y);
    const float result = std::acos(dotProduct/(lengthV1 * lengthV2)) * RAD2DEG; 

    // std::cout << "v1 :" + std::to_string(lengthV1) + " v2: " + std::to_string(lengthV2) << std::endl; 
    // std::cout << "dot product: " + std::to_string(dotProduct) << std::endl;
    std::cout << "final result: " + std::to_string(result) << std::endl;
    return result;
}

int main() {
    // const int screenWidth = 1920;
    // const int screenHeight = 1080;
    const int screenWidth = 1280;
    const int screenHeight = 720;
    // const Rectangle screenRec = {0, 0, screenWidth, screenHeight};

    // SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_UNDECORATED);
    InitWindow(screenWidth, screenHeight, "Pet Cicak Adventure");
    SetTargetFPS(60);


    float speed = 4.0f;
    float rotationSpeed = 2.0f;

    //test entity
    LevelGenerator levelGenerator(screenWidth, screenHeight);

    Gecko gecko;

    //pathfinding tools
    LinearPathFinding geckoPathFinder;
    Vector2 mouseTarget;


    while (!WindowShouldClose()) {
        
        levelGenerator.GetCurrentLevel().CheckFliesCollision(gecko.GetCollisionRect());

        //set gecko target
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouseTarget =  GetMousePosition();
            geckoPathFinder.SetTarget(mouseTarget);
        }
        
        //update gecko state
        const Vector2 geckoCurrPos = gecko.GetPosition(); 
        const Vector2 newPos = geckoPathFinder.GetNextPosition(gecko.GetPosition(), speed);
        
        //only update when gecko is moving
        if (newPos.x != geckoCurrPos.x && newPos.y != geckoCurrPos.y){
            gecko.SetPosition(newPos);
            gecko.SetCollisionRectPosition(newPos);
            const Vector2 directionVec = Vector2{mouseTarget.x -gecko.GetPosition().x, mouseTarget.y - gecko.GetPosition().y};

            const float angleToMove = GetMiddleDegree(gecko.GetForwardVec(1), directionVec);
            
            if(abs(angleToMove) > rotationSpeed){
                if (angleToMove > 180){ //counter clockwise rotate
                    gecko.SetRotation(gecko.GetRotation() - rotationSpeed);
                }
                gecko.SetRotation(gecko.GetRotation() + rotationSpeed);
            }
        }
        

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            levelGenerator.DrawCurrentLevel();
            DrawCircle(mouseTarget.x, mouseTarget.y, 15, RED);
            gecko.Draw();
            
            
            std::string hungerBar = "Hunger: " + std::to_string(gecko.GetHunger());
            DrawText(hungerBar.c_str(), 30, 10, 20, DARKBLUE);
            
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}