#include "CAnimation.h"
using namespace sf;

CAnimation::CAnimation(Texture& LaTexture, const CPosition& Pos, int NbFrames, int Vitesse) :
Sprite(LaTexture), Direction_(Bas), NbFrames_(NbFrames), Vitesse_(Vitesse), Compteur_(0)
{
	setPosition(Pos.x, Pos.y);
	FrameLargeur_ = LaTexture.getSize().x / NbFrames_;
	FrameHauteur_ = LaTexture.getSize().y / NbFrames_;
	setOrigin(static_cast<float>(FrameLargeur_ / 2), 
		      static_cast<float>(FrameHauteur_)); // Les pieds!
}
void CAnimation::Afficher(RenderWindow& Fenetre)
{
	// Si la position est différente, changer d'image
	if (AnciennePosition_ != getPosition())
	{
		Compteur_++;
		AnciennePosition_ = getPosition();
	}

	// Calcul du rectangle source
	IntRect Rect;
	Rect.left = FrameLargeur_* (Compteur_/Vitesse_%NbFrames_);
	Rect.top = FrameHauteur_*Direction_;
	Rect.height = FrameHauteur_;
	Rect.width = FrameLargeur_;
	setTextureRect(Rect);

	// Affichage
	Fenetre.draw(*this);
}
void CAnimation::SetDirection(Direction d)
{
	Direction_ = d;
}
Direction CAnimation::GetDirection() const
{
	return Direction_;
}
