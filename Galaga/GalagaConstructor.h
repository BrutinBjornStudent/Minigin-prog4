#pragma once
#include "GameObject.h"




namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> PlayerProjectile(const std::string& file,glm::ivec2 position);

	std::shared_ptr<dae::GameObject> BeeEnemy(const std::string& file, glm::ivec2 position);

	
}

