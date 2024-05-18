#pragma once
#include <vector>

class EntityManager
{ //Singleton class for managing objects
public:
	EntityManager();

	static EntityManager& entity_manager()
	{
		static EntityManager entityManager; //Instantiate on construction
		return entityManager; 
	}

	//Disable both construction for next times and assignment
	//Ensuring there is only one instance of this class
	EntityManager( EntityManager const&) = delete;
	void operator=( EntityManager const&) = delete; 

	//Getsetters
	std::vector<int>& getSelectedIDs() { return selectedIDs;  }

	//Selection

private:
	std::vector<int> selectedIDs; 
};

inline EntityManager::EntityManager()
{
	//EntityManager::entity_manager() = 0;
}