////////////////////////////////////////////////////////////
// Position.h
// Déclaration de l'énumération Direction et de la classe
// CPosition
//
// Joan-Sébastien Morales 
// Création: 2 mai 2010
// Version 1.0
// Version 2.0 : CPosition est un alias de sf::Vector2f - 9 mai 2014
////////////////////////////////////////////////////////////

#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//--------------------------------------------------------//
// Direction
//--------------------------------------------------------//
enum Direction
{
	Bas=0, Gauche, Droite, Haut 
};

typedef sf::Vector2f CPosition;

const float DistanceMax = 100.0f;

bool PositionsProches(const CPosition& Pos1, const CPosition& Pos2);

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


