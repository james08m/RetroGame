#pragma once
#include "pch.h"
#include "UI_Component.h"

using namespace std;
using namespace sf;

class UI_Infotip : public UI_Component
{
public:
	UI_Infotip(Texture& texture, Font& font, CPosition pos, string title, string text);
	/*CInfoTip(CPlayer player);
	CInfoTip(CMonster mob);*/

	string GetTitle() const;
	string GetText() const;

	void SetTitle(string title);
	void SetText(string text);
};
