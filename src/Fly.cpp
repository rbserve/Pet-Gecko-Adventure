#include "Fly.hpp"


Fly::Fly(): 
    Entity(LoadTexture("asset/flySprite.png")){};

Fly::~Fly(){
    UnloadTexture(m_sprite);
}

Texture2D Fly::GetSprite() const{
    return m_sprite;
};

void Fly::Draw(){
    DrawTexturePro(
        GetSprite(), 
        {0,0,(float)m_sprite.width, (float)m_sprite.height},
        {m_position.x, m_position.y,(float)m_sprite.width, (float)m_sprite.height},
        {m_sprite.width / 2.0f, m_sprite.height/2.0f}, 
        m_rotation, 
        WHITE 
    );
    
    // DrawRectangle(m_collisionRect.x, m_collisionRect.y, m_collisionRect.width, m_collisionRect.height, Color{225,0,0,100});
}