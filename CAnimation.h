////////////////////////////////////////////////////////////
// Animation.h
// 
// Déclaration de la classe CAnimation qui représente
// et permet de manipuler une animation
//
// Joan-Sébastien Morales 
// Création: 28 avril 2010
// Version 1.0
// Version 1.1 - Bloquer la copie
// Version 2.0 - CAnimation - Dérive de Sprite - 5 mai 2014
////////////////////////////////////////////////////////////
#pragma once
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
   CAnimation(sf::Texture& LaTexture, const CPosition& Pos, int NbFrames=4, int Vitesse=3);

	////////////////////////////////////////////////////////////
	// Afficher
	// Méthode virtuelle qui affiche l'animation dans
	// la fenêtre. 
	// Intrant: Fenetre dans laquelle il faut afficher  
	//          l'animation
	//
	////////////////////////////////////////////////////////////
    void Afficher(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// SetDirection
	// Modifie la direction de l'animation
	//
	// Intrant: d : une direction (voir enum dans Position.h)  
	//
	////////////////////////////////////////////////////////////
	void SetDirection(Direction d);

	////////////////////////////////////////////////////////////
	// GetDirection
	// Retourne la direction courante de l'amimation
	// (voir enum dans Position.h)
	//
	// Extrant: direction de l'animation 
	//
	////////////////////////////////////////////////////////////
	Direction GetDirection() const;

private:
	// Bloquer la copie et l'affectation
	CAnimation(const CAnimation&);
	CAnimation& operator=(const CAnimation&);

	// Nombre d'images dans l'animation
	const int NbFrames_;
	// Vitesse de l'animation 
	const int Vitesse_;
	// Numéro de l'image
	unsigned int Compteur_;  
	// Hauteur en pixels d'une image
	int FrameHauteur_;  
	// Largeur en pixels d'une image
	int FrameLargeur_;  
	// Direction courante de l'animation 
	Direction Direction_;  
	// Position précédente
	CPosition AnciennePosition_; 
};
