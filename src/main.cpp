#include "raylib.h"
#include <cmath>
#include <iostream>
#include "Entity.hpp"
#include "Gecko.hpp"
#include "Fly.hpp"
#include "LinearPathFinding.hpp"
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
    // Texture2D backgroundImage = LoadTexture("asset/cicakWall.png");
    Texture2D backgroundImage = LoadTexture("asset/cicakHome.png");


    float speed = 4.0f;
    float rotationSpeed = 2.0f;
    float timer = 2.0f;

    //test entity
    std::vector<std::unique_ptr<Fly>> flies;

    Gecko gecko;

    //pathfinding tools
    LinearPathFinding geckoPathFinder;
    Vector2 mouseTarget;


    while (!WindowShouldClose()) {

        //spawn flies randomly
        timer -= GetFrameTime();
        if(timer <= 0){
            timer = 2.0f;
            // std::unique_ptr<Fly> newFly = 
            flies.emplace_back(std::make_unique<Fly>());
            Vector2 newPos = Vector2{(float)GetRandomValue(10, screenWidth-10), (float)GetRandomValue(10, screenHeight-10)};
            flies.back()->SetPosition(newPos);
            flies.back()->SetCollisionRectPosition(newPos);

        }

        //collision detection
        for(auto it = flies.begin(); it != flies.end();){
            if(CheckCollisionRecs(gecko.GetCollisionRectPosition(), (*it)->GetCollisionRectPosition())){
                it = flies.erase(it);
                gecko.SetHunger(gecko.GetHunger() + 1);
            }else{
                ++it;
            }
        }
        
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
            DrawTexture(backgroundImage, 0, 0, WHITE);
            DrawCircle(mouseTarget.x, mouseTarget.y, 15, RED);
            gecko.Draw();
            
            for (auto& f : flies){
                f->Draw();
            }
            std::string hungerBar = "Hunger: " + std::to_string(gecko.GetHunger());
            DrawText(hungerBar.c_str(), 30, 10, 20, DARKBLUE);
            
        EndDrawing();
    }
    UnloadTexture(backgroundImage);

    CloseWindow();
    return 0;
}