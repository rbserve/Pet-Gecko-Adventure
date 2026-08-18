#pragma once
#include "raylib.h"

class PathFinding{
public:
    PathFinding(): m_target(Vector2{0,0}){};
    virtual Vector2 GetNextPosition(const Vector2& currPos,const float speed) const = 0;
    void SetTarget(const Vector2& target){m_target = target;};
    
protected:
    Vector2 m_target;
    
};

