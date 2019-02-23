#include "CGame.h"


//////////////////////////////////////////////////////
// Constructor and Destructor
//////////////////////////////////////////////////////
CGame::CGame()
{
	this->LoadTextures();
	this->LoadImages();
	this->LoadMusic();

	// Antialiased shapes
	ContextSettings Settings;
	Settings.antialiasingLevel = 8;

	_Window = new RenderWindow(VideoMode::getDesktopMode(), GAME_NAME, sf::Style::Fullscreen, Settings); // Init Window
	_Window->setFramerateLimit(60);
	_World = new CMap(T_World, I_WorldMask); // Init word map

	this->InitObjects();
	this->InitTeleporters();
	this->InitMonsters();
	this->InitPlayer();
	this->InitUI();
}

CGame::~CGame()
{
	// Destroy all dynamic pointer of monsters
	for (auto i = _Monsters.begin(); i != _Monsters.end(); i++)
	{
		delete (*i);
	}
}



//////////////////////////////////////////////////////
// Load ressources
//////////////////////////////////////////////////////
void CGame::LoadTextures()
{
	T_World.loadFromFile("res\\lemonde.bmp");
	T_Bread.loadFromFile("res\\pain.png");
	T_Sword.loadFromFile("res\\epee.png");
	T_Triforce.loadFromFile("res\\objets\\Triforce.png");
	T_Player.loadFromFile("res\\characters\\agent.png");
	T_Monster.loadFromFile("res\\characters\\warewolf.png");
	T_BloodAxe.loadFromFile("res\\objets\\BloodAxe.png");
}

void CGame::LoadImages()
{
	I_WorldMask.loadFromFile("res\\MasqueDuMonde.bmp");
}

void CGame::LoadMusic()
{
	_Music.openFromFile("res\\song.wav");
	_Music.setLoop(true);
}



//////////////////////////////////////////////////////
// Initialisations
//////////////////////////////////////////////////////
void CGame::InitObjects()
{
	// Randomly placed objects
	int random;
	for (int i = 0; i < MAX_OBJECT; i++)
	{
		// Défini aléatoirement le nombre de pains et d'épées
		random = rand() % (2) + 1;

		CPosition Position = PositionHasard(*_World);
		Vector2i Case(Position.x / 32, Position.y / 32);

		if (random == 1)
		{
			_Objects.insert(make_pair(Case, CObject(T_Bread, Position, CONSOMMABLE,"Bread", "Eat it for 20pv",20,0,0,0)));
		}
		else if (random == 2)
		{
			_Objects.insert(make_pair(Case, CObject(T_Sword, Position, WEAPON, "Sword", "Common sword of the milicia",0, 10, 0, 0)));
		}
	}


	// Triforce
	CPosition Pos1;
	Pos1.x = 3012;
	Pos1.y = 221;
	Vector2i Case1;
	Case1.x = Pos1.x / 32;
	Case1.y = Pos1.y / 32;
	_Objects.insert(make_pair(Case1, CObject(T_Triforce, Pos1, TRINKET, "Triforce", "Sacred relic, representing the essence of the Golden Goddesses.", 888,888, 888, 888)));

	// Blood Axe
	CPosition Pos2;
	Pos2.x = 178;
	Pos2.y = 3419;
	Vector2i Case2;
	Case2.x = Pos2.x / 32;
	Case2.y = Pos2.y / 32;
	_Objects.insert(make_pair(Case2, CObject(T_BloodAxe, Pos2, WEAPON, "Blood Axe", "Axe of the bleeding men", 0, 250, 400, 100)));
}

void CGame::InitMonsters()
{
	for (int i = 0; i < MAX_MONSTER; i++)
	{
		_Monsters.insert(new CMonster(T_Monster, PositionHasard(*_World), "Monster", 100, 10, 10, 10));
	}
}

void CGame::InitPlayer()
{
	_Player = new CPlayer(T_Player, CPosition(848, 1989), "Player 1", 10, 10, 10, 10);
}

void CGame::InitTeleporters()
{
	Vector2i T1_Start(3, 54);
	CPosition T1_End(2296, 137);
	_Teleporters[T1_Start] = T1_End;
}

void CGame::InitUI()
{
	_InventoryUI = new UI_Inventory(CPosition(848, 1989), _Player);
}


//////////////////////////////////////////////////////
// Actions
//////////////////////////////////////////////////////
void CGame::MovePlayer()
{
	_Quit = _Player->Deplacer(*_World);
}

void CGame::MoveMonsters()
{
	for (auto i = _Monsters.begin(); i != _Monsters.end(); i++)
	{
		(*i)->Deplacer(*_World);
	}
}

void CGame::TryTakeObject()
{
	// Finding player case
	Vector2i PlayerCase(0, 0);
	PlayerCase.x = _Player->getPosition().x / 32;
	PlayerCase.y = _Player->getPosition().y / 32;

	// Search if there is an object at this case
	auto j = _Objects.equal_range(PlayerCase);

	// Take the object if not empty
	if (j.first != j.second)
	{
		if(_Player->Prendre(j.first->second))
			_Objects.erase(j.first);
	}

}

void CGame::TryTeleport()
{
	// Finding player case
	Vector2i PlayerCase(0, 0);
	PlayerCase.x = _Player->getPosition().x / 32;
	PlayerCase.y = _Player->getPosition().y / 32;

	// Try to teleport
	auto e = _Teleporters.find(PlayerCase);
	if (e != _Teleporters.end())
	{
		_Player->setPosition(e->second);
	}
}

void CGame::PlayerAttackMonsters()
{
	// Player try to attack every monsters
	for (auto i = _Monsters.begin(); i != _Monsters.end(); i++)
	{
		if (_PlayerAlive)
		{
			if (!_Player->Attack(**i))
			{
				delete (*i);
				_Monsters.erase(*i);
				break;
			}
		}
	}
}

void CGame::MonstersAttackPlayer()
{
	// Monsters try to attack player
	for (auto i = _Monsters.begin(); i != _Monsters.end(); i++)
	{
		if (_PlayerAlive)
			_PlayerAlive = (*i)->Attack(*_Player);
	}
}


//////////////////////////////////////////////////////
// Refresh
//////////////////////////////////////////////////////
void CGame::RefreshView()
{
	// Center the view on the player
	View Vue = _Window->getView();

	if (_Player->getPosition().y >= T_World.getSize().y - _Window->getSize().y / 2 && _Player->getPosition().x < _Window->getSize().x / 2) // Stop view bottom left
		Vue.setCenter(_Window->getSize().x / 2, T_World.getSize().y - _Window->getSize().y / 2);

	else if (_Player->getPosition().y < _Window->getSize().y / 2 && _Player->getPosition().x < _Window->getSize().x / 2) // Stop view top left
		Vue.setCenter(_Window->getSize().x / 2, _Window->getSize().y / 2);

	else if (_Player->getPosition().y < _Window->getSize().y / 2 && _Player->getPosition().x >= T_World.getSize().x - _Window->getSize().x / 2) // Stop view top right
		Vue.setCenter(T_World.getSize().x - _Window->getSize().x / 2, _Window->getSize().y / 2);

	else if (_Player->getPosition().y >= T_World.getSize().y - _Window->getSize().y / 2 && _Player->getPosition().x < _Window->getSize().x / 2) // Stop view bottom right
		Vue.setCenter(_Window->getSize().x / 2, T_World.getSize().y - _Window->getSize().y / 2);

	else if (_Player->getPosition().x < _Window->getSize().x / 2) // Stop view left
		Vue.setCenter(_Window->getSize().x / 2, _Player->getPosition().y);

	else if (_Player->getPosition().x >= T_World.getSize().x - _Window->getSize().x / 2) // Stop view right
		Vue.setCenter(T_World.getSize().x - _Window->getSize().x / 2, _Player->getPosition().y);

	else if (_Player->getPosition().y < _Window->getSize().y / 2) // Stop view top
		Vue.setCenter(_Player->getPosition().x, _Window->getSize().y / 2);

	else if (_Player->getPosition().y >= T_World.getSize().y - _Window->getSize().y / 2) // Stop view bottom
		Vue.setCenter(_Player->getPosition().x, T_World.getSize().y - _Window->getSize().y / 2);

	else
		Vue.setCenter(_Player->getPosition());

	_Window->setView(Vue);
}



//////////////////////////////////////////////////////
// Display
//////////////////////////////////////////////////////
void CGame::DisplayWorld()
{
	_World->Afficher(*_Window);
}

void CGame::DisplayObjects()
{
	// Display objects
	for (auto i = _Objects.begin(); i != _Objects.end(); i++)
	{
		i->second.Afficher(*_Window);
	}
}

void CGame::DisplayMonsters()
{
	// Display monsters
	for (auto i = _Monsters.begin(); i != _Monsters.end(); i++)
	{
		(*i)->Afficher(*_Window);
	}
}

void CGame::DisplayPlayer()
{
	// Display player
	if (_PlayerAlive)
		_Player->Afficher(*_Window);
}

void CGame::DisplayUI()
{

	// Display UI inventory bottom right
	_InventoryUI->RefreshPosition(*_Window, *_World);
	_InventoryUI->Display(*_Window);

	// Display popup
	for (auto i = _Objects.begin(); i != _Objects.end(); i++)
	{
		if (i->second.IsHover(GetMousePosition()))
		{
			CInfoTip tip(i->second.getPosition());
			_Window->draw(tip);
		}
	}

	// Inventory pop up
	for (int i = 0; i < _Player->GetInventory()->GetNbObjects(); i++)
	{
		if (_Player->GetInventory()->GetObject(i)->IsHover(GetMousePosition()))
		{
			CInfoTip tip(_Player->GetInventory()->GetObject(i)->getPosition());
			_Window->draw(tip);
		}
	}
}

void CGame::DisplayWindow()
{
	_Window->display();
}

//////////////////////////////////////////////////////
// Event and time
//////////////////////////////////////////////////////
void CGame::PollEvent()
{
	Event event;
	while (_Window->pollEvent(event))
	{
		// évènement fermeture
		if (event.type == Event::Closed)
			_Window->close();
	}
}

void CGame::Wait(int millisec)
{
	sleep(milliseconds(millisec));
}


//////////////////////////////////////////////////////
// Utilities
//////////////////////////////////////////////////////
CPosition CGame::PositionHasard(CMap & monde)
{
	bool bPos;
	CPosition Pos;
	do
	{
		Pos.x = rand() % 4000;
		Pos.y = rand() % 4000;

		bPos = monde.EstPositionValide(Pos);
	} while (!bPos);

	return Pos;
}

Vector2f CGame::GetMousePosition()
{
	// Get mouse postion from window
	Vector2u winSize = _Window->getSize();
	Vector2i mousePos = Mouse::getPosition(*_Window);
	Vector2f playerPos = _Player->getPosition();
	
	int x;
	int y;

	if (playerPos.x < winSize.x / 2)
		x = mousePos.x;
	else
		x = playerPos.x - (winSize.x / 2) + mousePos.x;

	if (playerPos.y < winSize.y / 2)
		y = mousePos.y;
	else
		y = playerPos.y - (winSize.y / 2) + mousePos.y;

	return Vector2f(x, y);
}

//////////////////////////////////////////////////////
// Game loop
//////////////////////////////////////////////////////
void CGame::Run()
{
	_Music.play();

	do
	{
		MovePlayer();
		MoveMonsters();

		TryTakeObject();
		TryTeleport();

		PlayerAttackMonsters();
		MonstersAttackPlayer();

		RefreshView();

		DisplayWorld();
		DisplayObjects();
		DisplayMonsters();
		DisplayPlayer();
		DisplayUI();
		DisplayWindow();

		PollEvent();

		Wait(30);

	} while (!_Quit && _PlayerAlive && _Window->isOpen());

	if (!_PlayerAlive)
		cout << "You are dead" << endl;

}

namespace sf
{
	bool operator<(Vector2i pos1, Vector2i pos2)
	{
		return (1000 * pos1.y + pos1.x) < (1000 * pos2.y + pos2.x);
	}
}