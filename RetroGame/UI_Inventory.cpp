#include "pch.h"
#include "UI_Inventory.h"

////////////////////////////////////////////////////////////
// Constructeur
////////////////////////////////////////////////////////////
UI_Inventory::UI_Inventory(CPlayer* player, Font& font)
{
	LoadTexture();
	setTexture(_TextureBackground);
	SetVisible(true);
	_Font = font;
	_Player = player;

	InitTexts();
}

////////////////////////////////////////////////////////////
// Display Objects in inventory
////////////////////////////////////////////////////////////
void UI_Inventory::DisplayObjects(RenderWindow& window)
{
	int x = getPosition().x + 43;
	int y = getPosition().y + 106;
	int columns = 1;


	for (int i = 0; i < _Player->GetInventory()->GetNbObjects(); i++)
	{
		if (_Player->GetInventory()->GetObject(i) != NULL)
		{
			_Player->GetInventory()->GetObject(i)->setPosition(x, y);
			_Player->GetInventory()->GetObject(i)->Display(window);

			x += _Player->GetInventory()->GetObject(i)->getTexture()->getSize().x + 10; // add 10px to x for next object to be displayed

			if (columns % 4 == 0 && i != 0)
			{
				x = getPosition().x + 43;
				y = y + _Player->GetInventory()->GetObject(i)->getTexture()->getSize().y + 10; // add 10px to y if on another row
			}
			columns++;
		}
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
	if (!_TextureBackground.loadFromFile("res\\ui\\inventory.png"))
	{
		cout << "Failled to load iventory.png";
	}
	if (!_TextureLifeBar.loadFromFile("res\\ui\\life_bar.png"))
	{
		cout << "Failled to load life_bar.png";
	}
	if (!_TextureMagicBar.loadFromFile("res\\ui\\magic_bar.png"))
	{
		cout << "Failled to load magic_bar.png";
	}
}

////////////////////////////////////////////////////////////
// InitTexts
////////////////////////////////////////////////////////////
void UI_Inventory::InitTexts()
{
	//_TextStance.setFont(_Font);
	_TextAttack.setFont(_Font);
	_TextDefense.setFont(_Font);

	//_TextStance.setCharacterSize(10); //px
	_TextAttack.setCharacterSize(15);
	_TextDefense.setCharacterSize(15);
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
		DisplayLifeBar(window);
		DisplayMagicBar(window);
		DisplayTexts(window); 
	}
	
}
void UI_Inventory::DisplayTexts(RenderWindow& window)
{
	CPosition pos = getPosition();
	CPosition p_attack = CPosition(135, 309);
	CPosition p_defense = CPosition(135, 346);

	// Update texts values
	_TextAttack.setString(to_string(_Player->GetAttack()));
	_TextDefense.setString(to_string(_Player->GetDefense()));

	// Update texts positions
	_TextAttack.setPosition(pos + p_attack);
	_TextDefense.setPosition(pos + p_defense);


	// Display texts to screen
	window.draw(_TextAttack);
	window.draw(_TextDefense);
}

void UI_Inventory::DisplayLifeBar(RenderWindow& window)
{
	float purcent = (_Player->GetLife() * 100) / _Player->GetMaxLife();
	unsigned int nbBar = static_cast<int>((purcent*NB_BAR_TO_FILL / 100));

	Sprite lifebar;
	lifebar.setTexture(_TextureLifeBar);

	CPosition pos = getPosition();
	// Position on CIvenventory sprite
	pos.x = pos.x + 201;
	pos.y = pos.y + 325;

	for (int i = 0; i < nbBar; ++i)
	{
		lifebar.setPosition(pos);
		window.draw(lifebar);
		pos.x += _TextureLifeBar.getSize().x;
	}
}

void UI_Inventory::DisplayMagicBar(RenderWindow& window)
{
	float purcent = (_Player->GetMagic() * 100) / _Player->GetMaxMagic();
	unsigned int nbBar = static_cast<int>((purcent*NB_BAR_TO_FILL / 100));

	Sprite magicbar;
	magicbar.setTexture(_TextureMagicBar);

	CPosition pos = getPosition();

	// Position on CIvenventory sprite
	pos.x = pos.x + 201;
	pos.y = pos.y + 348;

	for (int i = 0; i < nbBar; ++i)
	{
		magicbar.setPosition(pos);
		window.draw(magicbar);
		pos.x += _TextureMagicBar.getSize().x;
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
	int x, y;

	// width
	if (_Player->getPosition().x <= window.getSize().x / 2)
		x = window.getSize().x - _TextureBackground.getSize().x;
	else if (_Player->getPosition().x + window.getSize().x / 2 > world.getTexture()->getSize().x)
		x = world.getTexture()->getSize().x - _TextureBackground.getSize().x;
	else
		x = _Player->getPosition().x + window.getSize().x / 2 - _TextureBackground.getSize().x;

	// height
	if (_Player->getPosition().y <= window.getSize().y / 2)
		y = window.getSize().y - _TextureBackground.getSize().y;
	else if (_Player->getPosition().y + window.getSize().y / 2 > world.getTexture()->getSize().y)
		y = world.getTexture()->getSize().y - _TextureBackground.getSize().y;
	else
		y = _Player->getPosition().y + window.getSize().y / 2 - _TextureBackground.getSize().y;

	setPosition(x, y);
}