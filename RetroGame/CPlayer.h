#pragma once
#include "pch.h"
#include <stack>
#include "CCharacter.h"
#include <utility>
using namespace std;

const CPosition PLAYER_MOVE_LEFT(-5, 0);
const CPosition PLAYER_MOVE_RIGHT(5, 0);
const CPosition PLAYER_MOVE_DOWN(0, 5);
const CPosition PLAYER_MOVE_UP(0, -5);

class CPlayer : public CCharacter
{

	// ---------------- STACK ---------------- //
	stack<pair<Direction, CPosition>> stack_direction;
public:

	////////////////////////////////////////////////////////////
	// CPlayer
	// Constructeur
	//
	// Intrants : Texture, position, nom, attaque et defense
	//
	////////////////////////////////////////////////////////////
	CPlayer(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie);

	////////////////////////////////////////////////////////////
	// CPlayer
	// Deplacer
	//
	// Intrants : CMap
	// Extrant  : bool (ferme le jeux si esc entré)
	// control les deplacements du héros
	//
	////////////////////////////////////////////////////////////
	bool Move(CMap& carte);
};