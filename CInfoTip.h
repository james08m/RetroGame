#pragma once 

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class CInfoTip : public ConvexShape
{
public:
	CInfoTip(Vector2f pos);
	/*CInfoTip(CPlayer player);
	CInfoTip(CMonster mob);*/
};