#include "EntityManager.h"



//Removes id so we don't have duplicated
bool EntityManager::WasSelected(std::vector<int>& ids_vector, int selected)
{
	// Find selected object
	auto it = std::find(ids_vector.begin(), ids_vector.end(), selected);
	if (it != ids_vector.end()) //iterate thru vector and find it
	{
		// delete it
		ids_vector.erase(it);
		return true;
	}
	//else, not found, false
	return false;
}