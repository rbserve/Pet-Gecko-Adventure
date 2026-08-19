#include "LinearPathFinding.hpp"
#include <cmath>

LinearPathFinding::LinearPathFinding(){};


Vector2 LinearPathFinding::GetNextPosition(const Vector2& currPos, const float speed) const {
    const float distance = std::hypot(m_target.x-currPos.x, m_target.y - currPos.y);

    if (distance < speed ){ //within walking distance
        return currPos;
    }else{ // not within 
        return Vector2{
            //normalise then applied speed constant
            currPos.x + (m_target.x-currPos.x)/distance * speed,
            currPos.y + (m_target.y-currPos.y)/distance * speed
        };
    }

};

