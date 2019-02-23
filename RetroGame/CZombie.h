#pragma once
#include "pch.h"
#include "CNpc.h"
using namespace std;

// Deplacement vectors
const CPosition ZOMBIE_MOVE_NULL(0, 0);
const CPosition ZOMBIE_MOVE_LEFT(-1, 0);
const CPosition ZOMBIE_MOVE_RIGHT(1, 0);
const CPosition ZOMBIE_MOVE_DOWN(0, 1);
const CPosition ZOMBIE_MOVE_UP(0, -1);

class CZombie : public CNpc
{
public:

	////////////////////////////////////////////////////////////
	// CZombie
	// Constructor
	////////////////////////////////////////////////////////////
	CZombie(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie);

	////////////////////////////////////////////////////////////
	// CMonster
	// Deplace
	////////////////////////////////////////////////////////////
	bool Move(CMap& carte, CPosition player_pos);
};