#pragma once
#include "GameObject.h"

enum CollisionID
{
	Enemy = 0,
	Player = 1
};

namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> Projectile(const std::string& file,glm::ivec2 position, CollisionID colision,glm::vec2 dir);

	std::shared_ptr<dae::GameObject> BeeEnemy(const std::string& file, glm::ivec2 position);


	std::shared_ptr<dae::GameObject> GalagaPlayer(const std::string file, glm::ivec2 size, int lives);
	
}

