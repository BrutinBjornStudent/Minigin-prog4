#pragma once
#include "GameObject.h"




namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> PlayerProjectile(const std::string& file);

	std::shared_ptr<dae::GameObject> BeeEnemy(const std::string& file, glm::vec2 position);

	
}

