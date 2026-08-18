#pragma once
#include "PathFinding.hpp"

class LinearPathFinding : public PathFinding {
public:
    LinearPathFinding();
    Vector2 GetNextPosition(const Vector2& currPos, const float speed) const override;
private: 

};