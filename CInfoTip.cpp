#include "CInfoTip.h"

CInfoTip::CInfoTip(Vector2f pos)
{
	// Create de convex
	this->setPointCount(6);
	this->setPoint(0, Vector2f(20, 20));
	this->setPoint(1, Vector2f(30, 10));
	this->setPoint(2, Vector2f(150, 10));
	this->setPoint(3, Vector2f(150, 150));
	this->setPoint(4, Vector2f(30, 150));
	this->setPoint(5, Vector2f(30, 30));
	this->setFillColor(sf::Color::White);
	this->setOutlineThickness(1);
	this->setOutlineColor(Color::Black);

	pos.x -= 5;
	pos.y -= 35;

	// Set the position
	this->setPosition(pos);
}
/*
CInfoTip::CInfoTip(CPlayer player)
{

}

CInfoTip::CInfoTip(CMonster mob)
{

}*/