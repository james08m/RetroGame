#pragma once 

#include "Personnage.h"

using namespace std;

class CMonster : public CPersonnage
{
public:

	////////////////////////////////////////////////////////////
	// CMonster
	// Constructeur
	//
	// Intrants : Texture, position, nom, attaque et defense
	//
	////////////////////////////////////////////////////////////
	CMonster(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie);

	////////////////////////////////////////////////////////////
	// CMonster
	// Deplacer
	//
	// Intrants : CMap
	// Extrant  : bool (ferme le jeux si esc entré)
	// Gère les déplacement des monstres
	//
	////////////////////////////////////////////////////////////
	bool Deplacer(CMap& carte);
};