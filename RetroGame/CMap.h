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
	// Constructeur paramétrique
	//
	// Intrants: 
	// Texture: Texture contenant l'image du monde 
	//                  
	// Obstruction: L'image d'obstruction est une version de
	//              l'image du monde où les pixels
	//              où les personnages peuvent passer
	//              sont de couleurs noires(RGB 0,0,0)
	////////////////////////////////////////////////////////////
	CMap(sf::Texture& LaTexture, sf::Image& Obstruction);

	////////////////////////////////////////////////////////////
	// Afficher
	// Affiche la carte dans une fenêtre
	//
	// Intrant: Fenetre: Fenêtre dans laquelle la carte doit
	//                    être affichée
	////////////////////////////////////////////////////////////
	void Display(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// EstPositionValide
	// Permet de vérifier si un personnage peut se trouver à
	// une certain position sur la carte
	//
	// Intrant: Position: Position du personnage
	//
	// Extrant: Vrai si le personnage peut se trouver à cette
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