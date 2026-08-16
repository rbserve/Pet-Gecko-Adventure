#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My First Raylib Game");
    SetTargetFPS(60);

    Vector2 ballPos = { screenWidth / 2.0f, screenHeight / 2.0f };
    float speed = 4.0f;

    while (!WindowShouldClose()) {
        // Update
        if (IsKeyDown(KEY_RIGHT)) ballPos.x += speed;
        if (IsKeyDown(KEY_LEFT))  ballPos.x -= speed;
        if (IsKeyDown(KEY_UP))    ballPos.y -= speed;
        if (IsKeyDown(KEY_DOWN))  ballPos.y += speed;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPos, 20, MAROON);
        DrawText("Move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}