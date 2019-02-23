#include "pch.h"
#include "CNpc.h"

CNpc::CNpc(sf::Texture& texture, const CPosition& pos, string name, int life, int attack, int defense, int magic) : 
	  CCharacter(texture, pos, name, life, attack, defense, magic)
{

}