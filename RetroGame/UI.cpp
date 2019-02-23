#include "pch.h"
#include "UI.h"


//////////////////////////////////////////////////////
// Constructor and Destructor
//////////////////////////////////////////////////////

UI::UI(RenderWindow* windows, CMap* world, CPlayer* player, multimap<Vector2i, CObject>* objects)
{
	LoadTextures();
	LoadFonts();

	_Window = windows;
	_World = world;
	_Player = player;
	_Inventory = new UI_Inventory(player, _Font);
	_Objects = objects;
}

UI::~UI()
{
}

//////////////////////////////////////////////////////
// Public Methods
//////////////////////////////////////////////////////
void UI::Display()
{
	DisplayInventory();
	DisplayInfotip();
}

UI_Inventory* UI::GetInventory()
{
	return _Inventory;
}

//////////////////////////////////////////////////////
// Private Methods
//////////////////////////////////////////////////////
void UI::LoadTextures()
{
	T_Infotip.loadFromFile("res\\ui\\infotip.png");
}

void UI::LoadFonts()
{
	if (!_Font.loadFromFile("Res\\Fonts\\oblivion.ttf"))
	{
		cout << "Couldn't load font!" << endl;
	}
}

void UI::DisplayInventory()
{
	_Inventory->RefreshPosition(*_Window, *_World);
	_Inventory->Display(*_Window);
}

void UI::DisplayInfotip()
{
	// Go thru all objects on the map
	for (auto i = _Objects->begin(); i != _Objects->end(); i++) // Go through all world objects
	{
		// If mouse is hover
		if (i->second.IsHover(GetMousePosition()))
		{
			// Display object infotip
			CInfoTip tip(T_Infotip, i->second.getPosition(), i->second.GetName(), "text");
			_Window->draw(tip);
		}
		
	}

	// If Inventory is visible
	if (_Inventory->GetVisible())
	{
		// Go thru all inventory objects
		for (int i = 0; i < _Player->GetInventory()->GetNbObjects(); i++)
		{
			// If player inventory is not null
			if (_Player->GetInventory()->GetObject(i) != NULL)
			{
				CObject* obj = _Player->GetInventory()->GetObject(i);

				// If mouse is hover
				if (obj->IsHover(GetMousePosition()))
				{
					// Display object info tip
					CInfoTip tip(T_Infotip, obj->getPosition(), obj->GetName(), "text");
					_Window->draw(tip);
				}
			}
		}
	}
}

Vector2f UI::GetMousePosition()
{
	// Get mouse postion from window
	Vector2u winSize = _Window->getSize();
	Vector2i mousePos = Mouse::getPosition(*_Window);
	Vector2f playerPos = _Player->getPosition();

	int x = 0;
	int y = 0;

	if (playerPos.x < winSize.x / 2)
		x = mousePos.x;
	else if (playerPos.x + winSize.x / 2 >= _World->getTexture()->getSize().x)
		x = _World->getTexture()->getSize().x - winSize.x + mousePos.x;
	else
		x = playerPos.x - (winSize.x / 2) + mousePos.x;

	if (playerPos.y < winSize.y / 2)
		y = mousePos.y;
	else if (playerPos.y + winSize.y / 2 >= _World->getTexture()->getSize().y)
		y = _World->getTexture()->getSize().y - winSize.y + mousePos.y;
	else
		y = playerPos.y - (winSize.y / 2) + mousePos.y;

	return Vector2f(x, y);
}