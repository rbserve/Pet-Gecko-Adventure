#pragma once
#include "raylib.h"

class Ultilities{
public:
    static void DrawOutlinedText(const char *text, int posX, int posY, int fontSize, Color color, int outlineSize, Color outlineColor){
        DrawText(text, posX-outlineSize, posY-outlineSize, fontSize, outlineColor);
        DrawText(text, posX+outlineSize, posY+outlineSize, fontSize, outlineColor);
        DrawText(text, posX-outlineSize, posY+outlineSize, fontSize, outlineColor);
        DrawText(text, posX+outlineSize, posY-outlineSize, fontSize, outlineColor);
        DrawText(text, posX, posY, fontSize, color);
    };
    
    static float GetMiddleDegree(const Vector2& v1, const Vector2& v2){
        const float lengthV1 = std::sqrt(v1.x * v1.x + v1.y * v1.y);
        const float lengthV2 = std::sqrt(v2.x * v2.x + v2.y * v2.y);

        const float dotProduct = (v1.x * v2.x) + (v1.y * v2.y);
        const float result = std::acos(dotProduct/(lengthV1 * lengthV2)) * RAD2DEG; 

        // std::cout << "v1 :" + std::to_string(lengthV1) + " v2: " + std::to_string(lengthV2) << std::endl; 
        // std::cout << "dot product: " + std::to_string(dotProduct) << std::endl;
        // std::cout << "final result: " + std::to_string(result) << std::endl;
        return result;
    }


    static bool IsMouseClicked(const Rectangle& clickedRect){
        return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), clickedRect);
    }

private:
    Ultilities() = default;
};