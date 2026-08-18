#include "raylib.h"
#include <iostream>
#include "Entity.hpp"
#include "Gecko.hpp"
#include "Fly.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    // const Rectangle screenRec = {0, 0, screenWidth, screenHeight};

    InitWindow(screenWidth, screenHeight, "Pet Cicak Adventure");
    SetTargetFPS(60);

    float speed = 4.0f;
    float rotationSpeed = 5.0f;

    //test entity
    Fly fly;
    Gecko gecko;



    while (!WindowShouldClose()) {
        int inputX = ((IsKeyDown(KEY_RIGHT))?speed:0 + (IsKeyDown(KEY_LEFT))?-speed:0);
        int inputY = ((IsKeyDown(KEY_UP))?-speed:0 + (IsKeyDown(KEY_DOWN))?speed:0);
        
        // Update position
        Vector2 newPos = (Vector2){
                gecko.GetForwardVec(speed * inputX).x,
                gecko.GetForwardVec(speed * inputY).y
        };
        
        if (inputY != 0) gecko.SetPosition(newPos);
        if (inputX != 0) gecko.SetRotation(gecko.GetRotation() + inputX * rotationSpeed);

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            gecko.Draw();
            fly.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}