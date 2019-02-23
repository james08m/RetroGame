#include "pch.h"
#include "CAnimation.h"

using namespace sf;

CAnimation::CAnimation(Texture& LaTexture, const CPosition& Pos, int NbFrames, int Vitesse) :
	Sprite(LaTexture), Direction_(Down), NbFrames_(NbFrames), Speed_(Vitesse), Counter_(0)
{
	setPosition(Pos.x, Pos.y);
	FrameWidth_ = LaTexture.getSize().x / NbFrames_;
	FrameHeight_ = LaTexture.getSize().y / NbFrames_;
	setOrigin(static_cast<float>(FrameWidth_ / 2),
		static_cast<float>(FrameHeight_)); // Les pieds!
}
void CAnimation::Display(RenderWindow& Fenetre)
{
	// Si la position est différente, changer d'image
	if (OldPosition_ != getPosition())
	{
		Counter_++;
		OldPosition_ = getPosition();
	}

	// Calcul du rectangle source
	IntRect Rect;
	Rect.left = FrameWidth_ * (Counter_ / Speed_ % NbFrames_);
	Rect.top = FrameHeight_ * Direction_;
	Rect.height = FrameHeight_;
	Rect.width = FrameWidth_;
	setTextureRect(Rect);

	// Affichage
	Fenetre.draw(*this);
}

Direction CAnimation::GetDirection() const
{
	return Direction_;
}

void CAnimation::SetDirection(Direction d)
{
	Direction_ = d;
}

Direction CAnimation::DetermineDirection(CPosition pos)
{
	float dx = getPosition().x - pos.x;
	float dy = getPosition().y - pos.y;

	if (fabs(dx) >= fabs(dy)) // if x absolute diferance is >= then absolute y
	{
		// left or right
		if (dx >= 0)
			return Left;
		else
			return Right;
	}
	else
	{
		// up or down
		if (dy >= 0)
			return Up;
		else
			return Down;
	}
}

int CAnimation::GetCounter() const
{
	return Counter_;
}

void CAnimation::SetCounter(int i)
{
	Counter_ = i;
}