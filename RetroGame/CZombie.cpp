#include "pch.h"
#include "CZombie.h"

CZombie::CZombie(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CNpc(texture, pos, nom, vie, attaque, defense, magie)
{
}

bool CZombie::Move(CMap& carte, CPosition player_pos)
{
	// Pre determine a new direction
	int random = rand() % (4) + 1;
	Direction NewDirection;
	if (random == 1)
	{
		NewDirection = Left;
	}
	else if (random == 2)
	{
		NewDirection = Right;
	}
	else if (random == 3)
	{
		NewDirection = Down;
	}
	else if (random == 4)
	{
		NewDirection = Up;
	}

	// Idle deplacement
	if (this->GetStance() == Idle)
	{
		if (GetDirection() == Left)
		{
			if (carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_LEFT))
			{
				move(ZOMBIE_MOVE_LEFT);
			}
			else
			{
				SetDirection(NewDirection);
				Move(carte, player_pos);
			}
		}
		else if (GetDirection() == Right)
		{
			if (carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_RIGHT))
			{
				move(ZOMBIE_MOVE_RIGHT);
			}
			else
			{
				SetDirection(NewDirection);
				Move(carte, player_pos);
			}
		}
		else if (GetDirection() == Down)
		{
			if (carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_DOWN))
			{
				move(ZOMBIE_MOVE_DOWN);
			}
			else
			{
				SetDirection(NewDirection);
				Move(carte, player_pos);
			}
		}
		else if (GetDirection() == Up)
		{
			if (carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_UP))
			{
				move(ZOMBIE_MOVE_UP);
			}
			else
			{
				SetDirection(NewDirection);
				Move(carte, player_pos);
			}
		}
	}
	else if (GetStance() == Combat)
	{
		SetDirection(DetermineDirection(player_pos));
		float area_range = 10000.0f;
		float animation_range = 1200.0f;

		if (GetDirection() == Left)
		{
			if(PositionInRange(getPosition(), player_pos, animation_range) && carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_RIGHT))
				move(ZOMBIE_MOVE_RIGHT);
			else
				move(ZOMBIE_MOVE_LEFT);
		}
		else if (GetDirection() == Right)
		{
			if (PositionInRange(getPosition(), player_pos, animation_range) && carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_LEFT))
				move(ZOMBIE_MOVE_LEFT);
			else
				move(ZOMBIE_MOVE_RIGHT);
		}
		else if (GetDirection() == Down)
		{
			if (PositionInRange(getPosition(), player_pos, animation_range) && carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_UP))
				move(ZOMBIE_MOVE_UP);
			else
				move(ZOMBIE_MOVE_DOWN);
		}
		else if (this->GetDirection() == Up)
		{
			if (PositionInRange(getPosition(), player_pos, animation_range) && carte.IsValidPosition(getPosition() + ZOMBIE_MOVE_DOWN))
				move(ZOMBIE_MOVE_DOWN);
			else
				move(ZOMBIE_MOVE_UP);
		}

		if(!PositionInRange(getPosition(), player_pos, area_range))
			SetStance(Idle);
	}
	return true;
}