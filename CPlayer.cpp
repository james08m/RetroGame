#include "CPlayer.h"

CPlayer::CPlayer(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CPersonnage(texture,pos,nom,vie,attaque,defense,magie)
{
}

bool CPlayer::Deplacer(CMap& carte)
{
	CPosition M_Left(-10, 0);
	CPosition M_Right(10, 0);
	CPosition M_Down(0, 10);
	CPosition M_Up(0, -10);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (carte.EstPositionValide(getPosition() + M_Left))
		{
			SetDirection(Gauche);
			move(M_Left);

			pair<Direction, CPosition> position(Droite, M_Right);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (carte.EstPositionValide(getPosition() + M_Right))
		{
			SetDirection(Droite);
			move(M_Right);
			pair<Direction, CPosition> position(Gauche, M_Left);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (carte.EstPositionValide(getPosition() + M_Up))
		{
			SetDirection(Haut);
			move(M_Up);

			pair<Direction, CPosition> position(Bas, M_Down);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (carte.EstPositionValide(getPosition() + M_Down))
		{
			SetDirection(Bas);
			move(M_Down);

			pair<Direction, CPosition> position(Haut, M_Up);
			stack_direction.push(position);

		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{

		if(stack_direction.size() != 0)
		{
			SetDirection(stack_direction.top().first);
			move(stack_direction.top().second);

			stack_direction.pop();
		}
	}

	cout << "x: " << getPosition().x  << ", y: " << getPosition().y << endl;
	return false;
}