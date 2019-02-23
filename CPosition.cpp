#include "CPosition.h"
using namespace std;

bool PositionsProches(const CPosition& Pos1, const CPosition& Pos2)  
{ 
	float dx = Pos1.x - Pos2.x;
	float dy = Pos1.y - Pos2.y;
	return (dx*dx + dy*dy) <= DistanceMax;
}

ostream& operator<<(ostream& os, const CPosition& Position)
{
	os << "(" << Position.x << "," << Position.y << ")";
   return os;
}



