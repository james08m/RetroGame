#include "CMonster.h"

CMonster::CMonster(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CPersonnage(texture, pos, nom, vie, attaque, defense, magie)
{
}

bool CMonster::Deplacer(CMap& carte)
{
	int random = rand() % (4) + 1;
	Direction NewDirection;

	if (random == 1)
	{
		NewDirection = Gauche;
	}
	else if (random == 2)
	{
		NewDirection = Droite;
	}
	else if (random == 3)
	{
		NewDirection = Bas;
	}
	else if (random == 4)
	{
		NewDirection = Haut;
	}

	sf::Vector2f M_Left(-3, 0);
	sf::Vector2f M_Right(3, 0);
	sf::Vector2f M_Down(0, 3);
	sf::Vector2f M_Up(0, -3);

	if (GetDirection() == Gauche)
	{
		if (carte.EstPositionValide(getPosition() + M_Left))
		{
			move(M_Left);
		}
		else
		{
			SetDirection(NewDirection);
			Deplacer(carte);
		}
	}
	else if (GetDirection() == Droite)
	{
		if (carte.EstPositionValide(getPosition() + M_Right))
		{
			move(M_Right);
		}
		else
		{
			SetDirection(NewDirection);
			Deplacer(carte);
		}
	}
	else if (GetDirection() == Bas)
	{
		if (carte.EstPositionValide(getPosition() + M_Down))
		{
			move(M_Down);
		}
		else
		{
			SetDirection(NewDirection);
			Deplacer(carte);
		}
	}
	else if (GetDirection() == Haut)
	{
		if (carte.EstPositionValide(getPosition() + M_Up))
		{
			move(M_Up);
		}
		else
		{
			SetDirection(NewDirection);
			Deplacer(carte);
		}
	}

	return true;
}