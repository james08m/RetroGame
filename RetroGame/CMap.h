#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include "CPosition.h"

//--------------------------------------------------------//
// CMap
//--------------------------------------------------------//
class CMap : public sf::Sprite
{
public:
	////////////////////////////////////////////////////////////
	// CMap
	// Constructeur param�trique
	//
	// Intrants: 
	// Texture: Texture contenant l'image du monde 
	//                  
	// Obstruction: L'image d'obstruction est une version de
	//              l'image du monde o� les pixels
	//              o� les personnages peuvent passer
	//              sont de couleurs noires(RGB 0,0,0)
	////////////////////////////////////////////////////////////
	CMap(sf::Texture& LaTexture, sf::Image& Obstruction);

	////////////////////////////////////////////////////////////
	// Afficher
	// Affiche la carte dans une fen�tre
	//
	// Intrant: Fenetre: Fen�tre dans laquelle la carte doit
	//                    �tre affich�e
	////////////////////////////////////////////////////////////
	void Display(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// EstPositionValide
	// Permet de v�rifier si un personnage peut se trouver �
	// une certain position sur la carte
	//
	// Intrant: Position: Position du personnage
	//
	// Extrant: Vrai si le personnage peut se trouver � cette
	//          position sur la carte, faux dans le cas 
	//          contraire
	////////////////////////////////////////////////////////////
	bool IsValidPosition(const CPosition& Position);


private:
	// Bloquer la copie
	CMap(const CMap&);
	CMap& operator=(const CMap&);

	// Image d'obstruction
	sf::Image& Obstruction_;
};