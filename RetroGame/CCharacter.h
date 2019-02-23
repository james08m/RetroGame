#pragma once
#include "pch.h"
#include "CAnimation.h"
#include "CPosition.h"
#include "CMap.h"
#include "CInventory.h"
#include <string>
#include <vector>

using namespace std;

enum Stance
{
	Idle = 0, Combat, Sleep, Charm, Confuse, Busy
};

class CCharacter : public CAnimation
{
	// Attributs
	string _Name;
	Stance _Stance;

	int _Life;
	int _MaxLife;
	int _Attack;
	int _Defense;
	int _Magic;
	int _MaxMagic;
	CInventory* _Inventory;

	// Evert character have a pre-set cooldown of 0.5second and clock to measur time between actions
	Time _Cooldown = milliseconds(500);
	Clock _Clock;

public:
	////////////////////////////////////////////////////////////
	// Constructeur
	////////////////////////////////////////////////////////////
	CCharacter(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie);

	////////////////////////////////////////////////////////////
	// Prendre
	////////////////////////////////////////////////////////////
	bool Take(CObject objet);

	////////////////////////////////////////////////////////////
	// Use the object passed in parameter
	////////////////////////////////////////////////////////////
	bool UseObject(CObject* obj);

	////////////////////////////////////////////////////////////
	// Attack
	////////////////////////////////////////////////////////////
	bool Attack(CCharacter& personnage);

	////////////////////////////////////////////////////////////
	// IsHover
	////////////////////////////////////////////////////////////
	bool IsHover();

	// Accesseurs et mutateurs des attributs
	string GetName() const;
	Stance GetStance() const;
	int GetLife() const;
	int GetMaxLife() const;
	int GetAttack() const;
	int GetDefense() const;
	int GetMagic() const;
	int GetMaxMagic() const;
	Time GetCooldown() const;

	// Can acces the inventory and his methods(not constant)
	CInventory* GetInventory();

	void SetName(string nom);
	void SetStance(Stance s);
	void SetLife(int vie);
	void SetMaxLife(int life);
	void SetAttack(int attaque);
	void SetDefense(int defense);
	void SetMagic(int magic);
	void SetMaxMagic(int magic);
	void SetCooldown(Time time);
};

ostream& operator<<(ostream& os, const CCharacter& Personnage);