#include "pch.h"
#include "UI_Infotip.h"

UI_Infotip::UI_Infotip(Texture& texture, Font& font, CPosition pos, string title, string text) : UI_Component(texture, font)
{
	// Ajuste position 
	pos.x = pos.x + 15;
	pos.y = pos.y - 30;
	this->setPosition(pos);	
	this->SetTitle(title);
	this->SetText(text);
}

string UI_Infotip::GetTitle() const
{
	return _Title.getString();
}

string UI_Infotip::GetText() const
{
	return _Text.getString();
}

void UI_Infotip::SetTitle(string title)
{
	_Title.setString(title);
}

void UI_Infotip::SetText(string text)
{
	_Text.setString(text);
}

/*
CInfoTip::CInfoTip(CPlayer player)
{

}

CInfoTip::CInfoTip(CMonster mob)
{

}*/