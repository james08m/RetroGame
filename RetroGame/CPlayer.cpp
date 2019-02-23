#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CCharacter(texture, pos, nom, vie, attaque, defense, magie)
{
}

bool CPlayer::Move(CMap& carte)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (carte.IsValidPosition(getPosition() + PLAYER_MOVE_LEFT))
		{
			SetDirection(Left);
			move(PLAYER_MOVE_LEFT);

			pair<Direction, CPosition> position(Right, PLAYER_MOVE_RIGHT);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (carte.IsValidPosition(getPosition() + PLAYER_MOVE_RIGHT))
		{
			SetDirection(Right);
			move(PLAYER_MOVE_RIGHT);
			pair<Direction, CPosition> position(Left, PLAYER_MOVE_LEFT);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (carte.IsValidPosition(getPosition() + PLAYER_MOVE_UP))
		{
			SetDirection(Up);
			move(PLAYER_MOVE_UP);

			pair<Direction, CPosition> position(Down, PLAYER_MOVE_DOWN);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (carte.IsValidPosition(getPosition() + PLAYER_MOVE_DOWN))
		{
			SetDirection(Down);
			move(PLAYER_MOVE_DOWN);

			pair<Direction, CPosition> position(Up, PLAYER_MOVE_UP);
			stack_direction.push(position);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (stack_direction.size() != 0)
		{
			SetDirection(stack_direction.top().first);
			move(stack_direction.top().second);

			stack_direction.pop();
		}
	}
	return false;
}