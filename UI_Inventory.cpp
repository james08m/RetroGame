#include "UI_Inventory.h"

////////////////////////////////////////////////////////////
// Constructeur
////////////////////////////////////////////////////////////
UI_Inventory::UI_Inventory(CPosition pos, CPlayer* player)
{
	LoadTexture();
	setTexture(_Texture);
	setPosition(pos);
	SetVisible(true);
	_Player = player;
}

////////////////////////////////////////////////////////////
// Display Objects in inventory
////////////////////////////////////////////////////////////
void UI_Inventory::DisplayObjects(RenderWindow& window)
{
	int width = getPosition().x + 43;
	int height = getPosition().y + 106;
	int columns = 1;


	for (int i = 0; i < _Player->GetInventory()->GetNbObjects(); i++)
	{	
		if (_Player->GetInventory()->GetObject(i) != NULL)
		{
			_Player->GetInventory()->GetObject(i)->setPosition(width, height);
			_Player->GetInventory()->GetObject(i)->Afficher(window);
		}
		
		width += _Player->GetInventory()->GetObject(i)->getTexture()->getSize().x + 10;

		if (columns % 4 == 0 && i != 0)
		{
			width = getPosition().x + 43;
			height = height + _Player->GetInventory()->GetObject(i)->getTexture()->getSize().y + 10;
		}
		columns++;
	}
}

////////////////////////////////////////////////////////////
// GetVisible
////////////////////////////////////////////////////////////
bool UI_Inventory::GetVisible() const
{
	return _Visible;
}

////////////////////////////////////////////////////////////
// SetVisible
////////////////////////////////////////////////////////////
void UI_Inventory::SetVisible(bool visible)
{
	_Visible = visible;
}

////////////////////////////////////////////////////////////
// LoadTexture
////////////////////////////////////////////////////////////
void UI_Inventory::LoadTexture()
{
	if (!_Texture.loadFromFile("res\\ui\\inventory.png"))
	{
		cout << "fail";
	}
}

////////////////////////////////////////////////////////////
// Display UI
////////////////////////////////////////////////////////////
void UI_Inventory::Display(RenderWindow& window)
{
	// UI visible
	if (GetVisible())
	{
		window.draw(*this);
		DisplayObjects(window);
	}
}

////////////////////////////////////////////////////////////
// IsHoverObject
////////////////////////////////////////////////////////////
bool UI_Inventory::IsHoverObject(Vector2f pos)
{
	return false;
}

////////////////////////////////////////////////////////////
// RefreshPosition
////////////////////////////////////////////////////////////
void UI_Inventory::RefreshPosition(RenderWindow& window, CMap& world)
{
	int height, width;

	// width
	if (_Player->getPosition().x <= window.getSize().x / 2)
		width = window.getSize().x - _Texture.getSize().x;
	else if (_Player->getPosition().x + window.getSize().x / 2 > world.getTexture()->getSize().x )
		width = world.getTexture()->getSize().x - _Texture.getSize().x;
	else
		width = _Player->getPosition().x + window.getSize().x / 2 - _Texture.getSize().x;

	// height
	if (_Player->getPosition().y <= window.getSize().y / 2)
		height = window.getSize().y - _Texture.getSize().y;
	else if (_Player->getPosition().y + window.getSize().y / 2 > world.getTexture()->getSize().y)
		height = world.getTexture()->getSize().y - _Texture.getSize().y;
	else
		height = _Player->getPosition().y + window.getSize().y / 2 - _Texture.getSize().y;

	setPosition(width, height);
}