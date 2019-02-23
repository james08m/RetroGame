#pragma once
#include "pch.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//--------------------------------------------------------//
// Direction
//--------------------------------------------------------//
enum Direction
{
	Down = 0, Left, Right, Up
};

typedef sf::Vector2f CPosition;

const float NEAR_DISTANCE = 1500.0f;

bool NearPosition(const CPosition& Pos1, const CPosition& Pos2);
int PositionInRange(const CPosition& Pos1, const CPosition& Pos2, float range);

////////////////////////////////////////////////////////////
// operator<<
// Affiche la position dans un flux de sortie
//
// Intrants: os: flux de sortie
//           Position: Position
//
// Extrant: flux de sortie
//
////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const CPosition& Position);