#pragma once
#include "pch.h"
#include "CPosition.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class CInfoTip : public Sprite
{
	string _Title;
	string _Text;
public:
	CInfoTip(Texture& texture, CPosition pos, string title, string text);
	/*CInfoTip(CPlayer player);
	CInfoTip(CMonster mob);*/

	string GetTitle() const;
	string GetText() const;

	void SetTitle(string title);
	void SetText(string text);
};
