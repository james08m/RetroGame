#include "pch.h"
#include "CCharacter.h"
ostream& operator<<(ostream& os, const CCharacter& Personnage)
{
	os << endl << "NOM : " << Personnage.GetName() << endl << "VIE : " << Personnage.GetLife() << endl << "ATTAQUE : " << Personnage.GetAttack() << endl << "DEFENSE : " << Personnage.GetDefense() << endl << endl;
	return os;
}


CCharacter::CCharacter(sf::Texture& texture, const CPosition& pos, string nom, int vie, int attaque, int defense, int magie) : CAnimation(texture, pos)
{
	_Name = nom;
	_Stance = Idle;
	_Life = vie;
	_MaxLife = vie;
	_Attack = attaque;
	_Defense = defense;
	_Magic = magie/2; // Character alway start with half his magic points
	_MaxMagic = magie;
	_Inventory = new CInventory();
}

////////////////////////////////////////////////////////////
// Take object and add it to inventory
////////////////////////////////////////////////////////////
bool CCharacter::Take(CObject objet)
{
	if (_Inventory->AddObject(new CObject(*objet.GetTexture(), CPosition(0, 0), objet.GetType(), objet.GetName(), objet.GetDescription(), objet.GetHeal(), objet.GetAttack(), objet.GetDefense(), objet.GetMagic())))
		return true; // If true is return the object eill be destroyed on the map
	else
		return false;
}

////////////////////////////////////////////////////////////
// UseObject() : Add Object passed in parameter to the 
//				 character inventory.
////////////////////////////////////////////////////////////
bool CCharacter::UseObject(CObject* obj)
{
	// Get object life bonus
	if (this->GetLife() + obj->GetHeal() <= this->GetMaxLife())
		this->SetLife(this->GetLife() + obj->GetHeal());
	else
		this->SetLife(this->GetMaxLife());

	// Get object magic bonus
	if (this->GetMagic() + obj->GetMagic() <= this->GetMaxMagic())
		this->SetMagic(this->GetMagic() + obj->GetMagic());
	else
		this->SetMagic(this->GetMaxMagic());

	// Get others object bonus
	this->SetAttack(this->GetAttack() + obj->GetAttack());
	this->SetDefense(this->GetDefense() + obj->GetDefense());

	// Delete the object
	_Inventory->RemoveObject(obj);
	return true;
}

////////////////////////////////////////////////////////////
// Attack() : Try to attack the enemy passed in parameter
////////////////////////////////////////////////////////////
bool CCharacter::Attack(CCharacter& personnage)
{
	// If near enough and time elapsed since clock was restarted is bigger than the character action cooldown
	if (NearPosition(getPosition(), personnage.getPosition()) && _Clock.getElapsedTime() > this->GetCooldown())
	{
		// Set character stance to Combat
		this->SetStance(Combat);

		// Set enemy stance to Combat
		personnage.SetStance(Combat);
		
		if ((rand() % (this->GetAttack()) + 1) + (rand() % (this->GetAttack()) + 1) >= (rand() % (personnage.GetDefense()) + 1) + (rand() % (personnage.GetDefense()) + 1))
		{

			// Attack enemy
			int Dommage = rand() % (this->GetAttack()) + 1;
			personnage.SetLife(personnage.GetLife() - Dommage);

			// Restart character cooldown clock
			_Clock.restart();

			// Check id enemy life is below 0
			if (personnage.GetLife() <= 0)
			{
				// Set character stance to Idle
				this->SetStance(Idle);

				// Enemy is dead
				return false;
			}

			// Enemy is still alive
			return true;
		}

		// Failled to attack
		else
		{
			// Enemy is still alive
			return true;
		}
	}

	// Not close enough
	else
	{
		// Enemy is still alive
		return true;
	}
}

////////////////////////////////////////////////////////////
// IsHover() : Check if mouse position is hover the 
//			   character.
////////////////////////////////////////////////////////////
bool CCharacter::IsHover()
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

////////////////////////////////////////////////////////////
// Get MEthods
////////////////////////////////////////////////////////////
string CCharacter::GetName() const
{
	return _Name;
}

Stance CCharacter::GetStance() const
{
	return _Stance;
}

int CCharacter::GetLife() const
{
	return _Life;
}

int CCharacter::GetMaxLife() const
{
	return _MaxLife;
}

int CCharacter::GetAttack() const
{
	return _Attack;
}

int CCharacter::GetDefense() const
{
	return _Defense;
}

int CCharacter::GetMagic() const
{
	return _Magic;
}

int CCharacter::GetMaxMagic() const
{
	return _MaxMagic;
}

CInventory* CCharacter::GetInventory()
{
	return _Inventory;
}

Time CCharacter::GetCooldown() const
{
	return _Cooldown;
}

void CCharacter::SetName(string nom)
{
	_Name = nom;
}

void CCharacter::SetStance(Stance s)
{
	_Stance = s;
}

void CCharacter::SetLife(int vie)
{
	if (vie < 0)
	{
		vie = 0;
	}

	_Life = vie;
}

void CCharacter::SetMaxLife(int life)
{
	_MaxLife = life;
}

void CCharacter::SetAttack(int attaque)
{
	_Attack = attaque;
}

void CCharacter::SetDefense(int defense)
{
	_Defense = defense;
}

void CCharacter::SetMagic(int magie)
{
	_Magic = magie;
}

void CCharacter::SetMaxMagic(int magic)
{
	_MaxMagic = magic;
}

void CCharacter::SetCooldown(Time time)
{
	_Cooldown = time;
}