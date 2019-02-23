#pragma once
#include "pch.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include "CCharacter.h"
#include "CMap.h"
#include "CPlayer.h"
#include "UI.h"
#include "CZombie.h"
using namespace std;
using namespace sf;

const string GAME_NAME = "Retro Game";
const int MAX_OBJECT = 15;
const int MAX_MONSTER = 10;


class CGame
{
	// Engin attributs
	bool _Quit = true;
	bool _PlayerAlive = true;
	RenderWindow* _Window;
	View _View;
	CMap* _World;
	CPlayer* _Player;
	multimap<Vector2i, CObject> _Objects;
	set<CZombie*> _Monsters;
	map<Vector2i, CPosition> _Teleporters;
	UI* _UI;
	UI_Inventory* _InventoryUI;

	Music _Music;

	// Textures
	Texture T_World;
	Texture T_Bread;
	Texture T_Sword1;
	Texture T_Shield1;
	Texture T_Shroom;
	Texture T_Player;
	Texture T_Monster;
	Texture T_Dragon;
	Texture T_FireCup;

	Texture T_Infotip;

	// Images
	Image I_WorldMask;

public:

	//////////////////////////////////////////////////////
	// Constructor and Destructor
	//////////////////////////////////////////////////////
	CGame();
	~CGame();

	//////////////////////////////////////////////////////
	// Load ressources
	//////////////////////////////////////////////////////
	void LoadTextures();
	void LoadImages();
	void LoadMusic();

	//////////////////////////////////////////////////////
	// Initialisations
	//////////////////////////////////////////////////////
	void InitObjects();
	void InitMonsters();
	void InitPlayer();
	void InitTeleporters();
	void InitUI();

	//////////////////////////////////////////////////////
	// Actions
	//////////////////////////////////////////////////////
	void MovePlayer();
	void MoveMonsters();
	void TryTakeObject();
	void TryTeleport();
	void PlayerAttackMonsters();
	void MonstersAttackPlayer();

	//////////////////////////////////////////////////////
	// Refresh
	//////////////////////////////////////////////////////
	void RefreshView();

	//////////////////////////////////////////////////////
	// Display
	//////////////////////////////////////////////////////
	void DisplayWorld();
	void DisplayObjects();
	void DisplayMonsters();
	void DisplayPlayer();
	void DisplayUI();
	void DisplayWindow();

	//////////////////////////////////////////////////////
	// Event and time
	//////////////////////////////////////////////////////
	void PollEvent();
	void Wait(int millisec);

	//////////////////////////////////////////////////////
	// Utilities
	//////////////////////////////////////////////////////
	CPosition RandomPosition(CMap & monde);
	Vector2f GetMousePosition();

	//////////////////////////////////////////////////////
	// Game loop
	//////////////////////////////////////////////////////
	void Run();
};

namespace sf
{
	bool operator<(Vector2i pos1, Vector2i pos2);
}
