#pragma once
#include "pch.h"
#include "CPosition.h"
#include "UI_Infotip.h"
#include <string>


using namespace std;

enum ObjectType { HEAD, CHEST, LEG, WEAPON, SHIELD, TRINKET, CONSOMMABLE };

class CObject : public sf::Sprite
{
	// Attributs
	Texture* _Texture;
	ObjectType Type_;
	string Name_;
	string Description_;
	int Heal_;
	int Attaque_;
	int Defense_;
	int Magic_;

public:

	////////////////////////////////////////////////////////////
	// Constructeur
	////////////////////////////////////////////////////////////
	CObject(sf::Texture& texture, CPosition pos, ObjectType type, string name, string description, int life, int attaque, int defense, int magic);

	////////////////////////////////////////////////////////////
	// Display
	////////////////////////////////////////////////////////////
	void Display(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// IsHover
	////////////////////////////////////////////////////////////
	bool IsHover(Vector2f pos);

	// Accesseurs et Mutateurs des attributs
	ObjectType GetType() const;
	string GetName() const;
	string GetDescription() const;
	int GetHeal() const;
	int GetAttack() const;
	int GetDefense() const;
	int GetMagic() const;
	Texture* GetTexture();

	void SetType(ObjectType type);
	void SetName(string name);
	void SetDescription(string description);
	void SetHeal(int vie);
	void SetAttack(int attaque);
	void SetDefense(int defense);
	void SetMagic(int magic);
};

ostream& operator<<(ostream& os, const CObject& objet);