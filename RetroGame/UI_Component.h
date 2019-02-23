#pragma once

#include "CPlayer.h"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class UI_Component : public sf::Sprite
{
protected:
	// Attribute 
	Font _Font;
	Text _Title;
	Text _Text;
public:

	// Cunstroctor 
	UI_Component(Texture& texture, Font& font);
};