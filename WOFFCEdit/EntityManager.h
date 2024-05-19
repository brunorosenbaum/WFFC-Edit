#pragma once
#include <stack>
#include <vector>

#include "DisplayObject.h"

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
	std::vector<DisplayObject>*& getDisplayObjects() { return display_objects;  }

	//Selection
	bool WasSelected(std::vector<int>& ids_vector, int selected); //Returns false if not duplicate

	//For cam focus
	void InitObjects(std::vector<DisplayObject>* scene_objects);
	DisplayObject* getLastSelectedObject();

	//Spawning new objects
	void SpawnObject(DisplayObject* object_);

private:
	std::vector<int> selectedIDs;
	std::vector<DisplayObject>* display_objects;

};

inline EntityManager::EntityManager()
{
	display_objects = nullptr; 
}

