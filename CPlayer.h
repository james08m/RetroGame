#pragma once

#include <stack>
#include "Personnage.h"
#include <utility>
using namespace std;

class CPlayer : public CPersonnage
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
	bool Deplacer(CMap& carte);
};