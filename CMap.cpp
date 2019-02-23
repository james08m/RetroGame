#include "CMap.h"
using namespace sf;
using namespace std;

CMap::CMap(sf::Texture& LaTexture, sf::Image& Obstruction) : Sprite(LaTexture), Obstruction_(Obstruction)
{
}

void CMap::Afficher(RenderWindow& Fenetre) 
{
	Fenetre.draw(*this);
}

bool CMap::EstPositionValide(const CPosition& Position) 
{
   if (Position.x < 0 || Position.x >= Obstruction_.getSize().x ||
      Position.y < 0 || Position.y >= Obstruction_.getSize().y)
   {
      throw string("CMap::EstPositionValide:: position en dehors de la carte!!");
   }
   
   return Obstruction_.getPixel(static_cast<unsigned int>(Position.x), 
                                static_cast<unsigned int>(Position.y)) == Color::Black;
}

