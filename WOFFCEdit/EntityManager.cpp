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

void EntityManager::InitObjects(std::vector<DisplayObject>* scene_objects)
{
	//Copy vector so all scene objects can be accessed by the manager class
	display_objects = scene_objects; 
}

DisplayObject* EntityManager::getLastSelectedObject()
{
	//If this is empty return nullptr
	if (display_objects->empty()) return nullptr;

	//Go through objects
	for (int i = 0; i < display_objects->size(); ++i)
	{
		//Return last object selected by user
		if (selectedIDs.back() == i)
		{
			return &display_objects->at(i);
		}
	}
	return nullptr;
}

void EntityManager::SpawnObject(DisplayObject* object_)
{
	//Give default model and txr
	object_->m_model = display_objects->back().m_model;
	object_->m_texture_diffuse = display_objects->back().m_texture_diffuse;
	object_->m_position = display_objects->back().m_position;
	//Edit pos
	object_->m_position.z = display_objects->back().m_position.z + 2;
	object_->m_position.x = display_objects->back().m_position.x + 2;
	object_->m_scale = display_objects->back().m_scale; 
	object_->m_orientation = display_objects->back().m_orientation;
	//Add to vector of all objects
	display_objects->push_back(*object_); 

	//Update id
	for (int i = 0; i < display_objects->size(); i++)
	{
		(*display_objects)[i].m_ID = i;
	}

	
}

