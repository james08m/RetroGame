#include "pch.h"
#include "CPosition.h"
using namespace std;

bool NearPosition(const CPosition& Pos1, const CPosition& Pos2)
{
	float dx = Pos1.x - Pos2.x;
	float dy = Pos1.y - Pos2.y;
	return (dx*dx + dy*dy) <= NEAR_DISTANCE;
}

int PositionInRange(const CPosition& Pos1, const CPosition& Pos2, float range)
{
	float dx = Pos1.x - Pos2.x;
	float dy = Pos1.y - Pos2.y;
	return (dx*dx + dy * dy) <= range;
}

ostream& operator<<(ostream& os, const CPosition& Position)
{
	os << "(" << Position.x << "," << Position.y << ")";
	return os;
}