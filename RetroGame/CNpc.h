#pragma once
#include "CCharacter.h"

using namespace std;

// Abstract class 
class CNpc : public CCharacter
{
public:
	CNpc(sf::Texture& texture, const CPosition& pos, string name, int life, int attack, int defense, int magic);

	virtual bool Move(CMap& map, CPosition player_position) = 0;
};