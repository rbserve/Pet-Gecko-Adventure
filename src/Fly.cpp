#include "Fly.hpp"


Fly::Fly(): 
    m_sprite(LoadTexture("asset/flySprite.png")){};

Texture2D Fly::GetSprite() const{
    return m_sprite;
};