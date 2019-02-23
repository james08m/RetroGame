#include "pch.h"
#include "CMap.h"
using namespace sf;
using namespace std;

CMap::CMap(sf::Texture& LaTexture, sf::Image& Obstruction) : Sprite(LaTexture), Obstruction_(Obstruction)
{
}

void CMap::Display(RenderWindow& Fenetre)
{
	Fenetre.draw(*this);
}

bool CMap::IsValidPosition(const CPosition& Position)
{
	if (Position.x < 0 || Position.x >= Obstruction_.getSize().x ||
		Position.y < 0 || Position.y >= Obstruction_.getSize().y)
	{
		throw string("CMap::IsValidPoSition::OutOfMap");
	}

	Color mask = Obstruction_.getPixel(static_cast<unsigned int>(Position.x), static_cast<unsigned int>(Position.y));

	if (mask == Color::Black || mask == Color::Blue)
		return true;
	else
		return false;
}