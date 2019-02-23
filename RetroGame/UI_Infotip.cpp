#include "pch.h"
#include "UI_Infotip.h"

UI_Infotip::UI_Infotip(Texture& texture, CPosition pos, string title, string text)
{
	// Ajuste position 
	pos.x = pos.x + 15;
	pos.y = pos.y - 30;
	this->setTexture(texture);
	this->setPosition(pos);	
	this->SetTitle(title);
	this->SetText(text);
}

string UI_Infotip::GetTitle() const
{
	return _Title;
}

string UI_Infotip::GetText() const
{
	return _Text;
}

void UI_Infotip::SetTitle(string title)
{
	_Title = title;
}

void UI_Infotip::SetText(string text)
{
	_Text = text;
}

/*
CInfoTip::CInfoTip(CPlayer player)
{

}

CInfoTip::CInfoTip(CMonster mob)
{

}*/