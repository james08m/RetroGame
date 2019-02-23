#include "Personnage.h"

ostream& operator<<(ostream& os, const CPersonnage& Personnage)
{
	os << endl << "NOM : " << Personnage.GetNom() << endl << "VIE : " << Personnage.GetVie() << endl << "ATTAQUE : " << Personnage.GetAttaque() << endl << "DEFENSE : " << Personnage.GetDefense() << endl << endl;
	return os;
}


CPersonnage::CPersonnage(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CAnimation(texture, pos)
{
	Nom_ = nom;
	Vie_ = vie;
	Attaque_ = attaque;
	Defense_ = defense;
	Magie_ = magie;
	_Inventory = new CInventory();
}

////////////////////////////////////////////////////////////
// Prendre
////////////////////////////////////////////////////////////
bool CPersonnage::Prendre(CObject objet)
{
	if (_Inventory->AddObject(new CObject(*objet.GetTexture(), CPosition(0, 0), objet.GetType(), objet.GetName(), objet.GetDescription(), objet.GetHeal(), objet.GetAttaque(), objet.GetDefense(), objet.GetMagic())))
		return true;
	else
		return false;
}

////////////////////////////////////////////////////////////
// Use the object passed in parameter
////////////////////////////////////////////////////////////
bool CPersonnage::UseObject(int index)
{
	// Get object bonus
	this->SetVie(this->GetVie() + _Inventory->GetObject(index)->GetHeal());
	this->SetAttaque(this->GetAttaque() + _Inventory->GetObject(index)->GetAttaque());
	this->SetDefense(this->GetDefense() + _Inventory->GetObject(index)->GetDefense());
	this->SetMagie(this->GetMagie() + _Inventory->GetObject(index)->GetMagic());

	// Delete the object
	_Inventory->RemoveObject(index);
	return true;
}

bool CPersonnage::Attack(CPersonnage& personnage)
{
	if (PositionsProches(getPosition(), personnage.getPosition()))
	{
		int random = rand() % (20) + 1;
		if (random >= personnage.GetDefense())
		{
			// Attaque l'adversaire
			int Dommage = rand() % (GetAttaque()) + 1;
			personnage.SetVie(personnage.GetVie() - Dommage);

			cout << GetNom() << " attaque " << personnage.GetNom() << " : " << Dommage << "dmg" << endl << endl;
			cout << *this;
			cout << personnage;

			if (personnage.GetVie() <= 0)
			{
				// Ennemi mort
				return false;
			}

			return true;
		}
		else
		{
			// N'a pas passé la défense de l'adversaire
			return true;
		}
	}
	else
	{
		// N'est pas assez près pour Attack
		return true;
	}
}

////////////////////////////////////////////////////////////
// IsHover
////////////////////////////////////////////////////////////
bool CPersonnage::IsHover()
{
	// lit la position de la souris (relativement à la fenêtre)
	sf::Vector2i cursor = sf::Mouse::getPosition();

	int x = this->getPosition().x;
	int y = this->getPosition().y;
	int w = this->getTexture()->getSize().x;
	int h = this->getTexture()->getSize().y;

	if (cursor.x >= x
		&& cursor.x < x + w
		&& cursor.y >= y
		&& cursor.y < y + h)
		return true;
	else
		return false;
}

// Accesseurs et mutateurs
string CPersonnage::GetNom() const
{
	return Nom_;
}

int CPersonnage::GetVie() const
{
	return Vie_;
}

int CPersonnage::GetAttaque() const
{
	return Attaque_;
}

int CPersonnage::GetDefense() const
{
	return Defense_;
}

int CPersonnage::GetMagie() const
{
	return Magie_;
}

CInventory* CPersonnage::GetInventory()
{
	return _Inventory;
}

void CPersonnage::SetNom(string nom)
{
	Nom_ = nom;
}

void CPersonnage::SetVie(int vie)
{
	if (vie < 0)
	{
		vie = 0;
	}

	Vie_ = vie;
}

void CPersonnage::SetAttaque(int attaque)
{
	Attaque_ = attaque;
}

void CPersonnage::SetDefense(int defense)
{
	Defense_ = defense;
}

void CPersonnage::SetMagie(int magie)
{
	Magie_ = magie;
}