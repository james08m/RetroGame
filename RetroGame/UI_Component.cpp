#include "pch.h"
#include "UI_Component.h"

UI_Component::UI_Component(Texture& texture, Font& font) : Sprite(texture)
{
	_Font = font;
	_Title.setFont(_Font);
	_Text.setFont(_Font);
}