#include "pch.h"
#include "CInfotip.h"

CInfoTip::CInfoTip(Texture& texture, CPosition pos, string title, string text)
{
	// Ajuste position 
	pos.x = pos.x + 15;
	pos.y = pos.y - 30;
	this->setTexture(texture);
	this->setPosition(pos);	
	this->SetTitle(title);
	this->SetText(text);
}

string CInfoTip::GetTitle() const
{
	return _Title;
}

string CInfoTip::GetText() const
{
	return _Text;
}

void CInfoTip::SetTitle(string title)
{
	_Title = title;
}

void CInfoTip::SetText(string text)
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