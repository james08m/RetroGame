#pragma once
#include "pch.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include "CPosition.h"

//--------------------------------------------------------//
// CAnimation
//--------------------------------------------------------//
class CAnimation : public sf::Sprite
{
public:
	////////////////////////////////////////////////////////////
	// CAnimation
	// Constructeur
	//
	// Intrants : Texture, position, NbImages par direction et vitesse
	// La texture doit contenir autant de directions que d'images 
	// Exemple: 4x4
	//
	////////////////////////////////////////////////////////////
	CAnimation(sf::Texture& LaTexture, const CPosition& Pos, int NbFrames = 4, int Vitesse = 3);

	////////////////////////////////////////////////////////////
	// Afficher
	// Méthode virtuelle qui affiche l'animation dans
	// la fenêtre. 
	// Intrant: Fenetre dans laquelle il faut afficher  
	//          l'animation
	//
	////////////////////////////////////////////////////////////
	void Display(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// GetDirection
	// Retourne la direction courante de l'amimation
	// (voir enum dans Position.h)
	//
	// Extrant: direction de l'animation 
	//
	////////////////////////////////////////////////////////////
	Direction GetDirection() const;

	////////////////////////////////////////////////////////////
	// SetDirection
	// Modifie la direction de l'animation
	//
	// Intrant: d : une direction (voir enum dans Position.h)  
	//
	////////////////////////////////////////////////////////////
	void SetDirection(Direction d);

	////////////////////////////////////////////////////////////
	// DetermineDirection
	// Determine direction relative to a given position
	//
	// Intrant: pos : CPosition (See Position.h)  
	//
	////////////////////////////////////////////////////////////
	Direction DetermineDirection(CPosition pos);

	int GetCounter() const;
	void SetCounter(int i);

private:
	// Bloquer la copie et l'affectation
	CAnimation(const CAnimation&);
	CAnimation& operator=(const CAnimation&);

	// Nombre d'images dans l'animation
	const int NbFrames_;
	// Vitesse de l'animation 
	const int Speed_;
	// Numéro de l'image
	unsigned int Counter_;
	// Hauteur en pixels d'une image
	int FrameHeight_;
	// Largeur en pixels d'une image
	int FrameWidth_;
	// Direction courante de l'animation 
	Direction Direction_;
	// Position précédente
	CPosition OldPosition_;
};
