#include "Fly.hpp"


Fly::Fly(): 
    Entity(LoadTexture("asset/flySprite.png")){};

Texture2D Fly::GetSprite() const{
    return m_sprite;
};

void Fly::Draw(){
    DrawTexture(GetSprite(), 0, 0, WHITE);
}