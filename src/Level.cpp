#include  "Level.hpp"

//level 0 type is home, other is explorable level
Level::Level(const int screenWidth, const int screenHeight, const Texture2D& sprite, const int id):
    m_sprite(sprite),
    m_id(id)
{
    const int fliesCount = rand() % 5;
    for (int i = 0; i<fliesCount; ++i){
        m_flies.emplace_back(std::make_unique<Fly>());
        Vector2 newPos = Vector2{(float)GetRandomValue(10, screenWidth-10), (float)GetRandomValue(10, screenHeight-10)};
        m_flies.back()->SetPosition(newPos);
        m_flies.back()->SetCollisionRectPosition(newPos);
    }
};

// std::vector<std::unique_ptr<Fly>>& Level::GetFlies() const{
//     return m_flies;
// };

int Level::CheckFliesCollision(const Rectangle& other){
    int count = 0; 
    for(auto it = m_flies.begin(); it != m_flies.end();){
            if(CheckCollisionRecs(other, (*it)->GetCollisionRect())){
                it = m_flies.erase(it);
                count += 1;
            }else{
                ++it;
            }
        }
    return count; //flies collided
};

void Level::Draw(){
    DrawTexture(m_sprite, 0, 0, WHITE);
    for (auto& f : m_flies){
                f->Draw();
    }
}

int Level::GetID() const{return m_id;};