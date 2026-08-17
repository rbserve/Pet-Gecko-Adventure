#include "raylib.h"
#include <iostream>
#include "Entity.hpp"
#include "Gecko.hpp"
#include "Fly.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My First Raylib Game");
    SetTargetFPS(60);

    // Vector2 ballPos = { screenWidth / 2.0f, screenHeight / 2.0f };
    float speed = 4.0f;

    //test entity
    Fly fly;
    Gecko gecko;

    //camera
    Camera2D camera;
    camera.target = gecko.GetPosition();
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    while (!WindowShouldClose()) {
        // Update position
        Vector2 newPos = (Vector2){
                gecko.GetPosition().x + ((IsKeyDown(KEY_RIGHT))?speed:0 + (IsKeyDown(KEY_LEFT))?-speed:0),
                gecko.GetPosition().y + ((IsKeyDown(KEY_UP))?-speed:0 + (IsKeyDown(KEY_DOWN))?speed:0)
        };
        gecko.SetPosition(newPos);

        //camera follow
        camera.target = gecko.GetPosition();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawCircleV(ballPos, 20, MAROON);
            DrawTexture(gecko.GetSprite(),gecko.GetPosition().x, gecko.GetPosition().y, WHITE);
            DrawTexture(fly.GetSprite(), 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}