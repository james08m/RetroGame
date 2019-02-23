#pragma once
#include "pch.h"
#include "CPosition.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class UI_Infotip : public Sprite
{
	string _Title;
	string _Text;
public:
	UI_Infotip(Texture& texture, CPosition pos, string title, string text);
	/*CInfoTip(CPlayer player);
	CInfoTip(CMonster mob);*/

	string GetTitle() const;
	string GetText() const;

	void SetTitle(string title);
	void SetText(string text);
};
