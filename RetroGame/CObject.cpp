#include "pch.h"
#include "CObject.h"

ostream& operator<<(ostream& os, const CObject& objet)
{
	os << "Objet" << endl << "NOM : " << objet.GetName() << endl << "VIE : " << objet.GetHeal() << endl << "ATTAQUE : " << objet.GetAttack() << endl << "DEFENSE : " << objet.GetDefense() << endl << endl;
	return os;
}

CObject::CObject(sf::Texture& texture, CPosition pos, ObjectType type, string name, string description, int life = 0, int attaque = 0, int defense = 0, int magic = 0)
{
	_Texture = new Texture();
	_Texture = &texture;
	setTexture(texture);
	setPosition(pos);
	setOrigin(getLocalBounds().width / 2, getLocalBounds().height);
	SetType(type);
	SetName(name);
	SetDescription(description);
	SetHeal(life);
	SetAttack(attaque);
	SetDefense(defense);
	SetMagic(magic);
}

void CObject::Display(sf::RenderWindow& Fenetre)
{
	Fenetre.draw(*this);
}

////////////////////////////////////////////////////////////
// IsHover
////////////////////////////////////////////////////////////
bool CObject::IsHover(Vector2f pos)
{
	int x = this->getPosition().x - 15;
	int y = this->getPosition().y - 30;
	int w = this->getTexture()->getSize().x + 10;
	int h = this->getTexture()->getSize().y + 10;

	if (pos.x >= x && pos.x < x + w && pos.y >= y & pos.y < y + h)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// Accesseurs et Mutateurs des attributs
ObjectType CObject::GetType() const
{
	return Type_;
}

string CObject::GetName() const
{
	return Name_;
}

string CObject::GetDescription() const
{
	return Description_;
}

int CObject::GetHeal() const
{
	return Heal_;
}

int CObject::GetAttack() const
{
	return Attaque_;
}

int CObject::GetDefense() const
{
	return Defense_;
}

int CObject::GetMagic() const
{
	return Magic_;
}

Texture* CObject::GetTexture()
{
	return _Texture;
}

void CObject::SetType(ObjectType type)
{
	Type_ = type;
}

void CObject::SetName(string name)
{
	Name_ = name;
}

void CObject::SetDescription(string description)
{
	Description_ = description;
}

void CObject::SetHeal(int life)
{
	Heal_ = life;
}

void CObject::SetAttack(int attaque)
{
	Attaque_ = attaque;
}

void CObject::SetDefense(int defense)
{
	Defense_ = defense;
}

void CObject::SetMagic(int magic)
{
	Magic_ = magic;

}