#include "CInventory.h"

////////////////////////////////////////////////////////////
// Constructeur
////////////////////////////////////////////////////////////
CInventory::CInventory()
{
	_Objects.reserve(NB_OF_SPACE);
}

////////////////////////////////////////////////////////////
// Get number of objects in the vector
////////////////////////////////////////////////////////////
int CInventory::GetNbObjects() const
{
	return _Objects.size();
}

////////////////////////////////////////////////////////////
// Get number of empty place in inventory
////////////////////////////////////////////////////////////
int CInventory::GetNbEmpty() const
{
	return NB_OF_SPACE - _Objects.size();
}

////////////////////////////////////////////////////////////
// Return an object with is index
////////////////////////////////////////////////////////////
CObject* CInventory::GetObject(int index)
{
	return _Objects[index];
}

////////////////////////////////////////////////////////////
// Add an object in the inventory
////////////////////////////////////////////////////////////
bool CInventory::AddObject(CObject* object)
{
	if (_Objects.size() < NB_OF_SPACE)
	{
		_Objects.push_back(object);
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////
// Remove an object from the inventory
////////////////////////////////////////////////////////////
bool CInventory::RemoveObject(int index)
{
	// Replace the element to be remove by the one in front till the end of inventory
	for (int i = index ; i < _Objects.size() - 1; i++)
	{
			_Objects[i] = _Objects[i + 1];
	}

	//Then delete the last one (Or it clone the last object of the inventory)
	_Objects.erase(_Objects.end());

	return true;
}