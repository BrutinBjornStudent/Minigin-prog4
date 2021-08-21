#pragma once

#include "GameObject.h"

enum class EnemyType;

enum CollisionID
{
	Collision_Id_Enemy = 0,
	Collision_Id_Player = 1
};

namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> Projectile(const std::string& file,glm::ivec2 position, CollisionID colision,glm::vec2 dir);

	std::shared_ptr<dae::GameObject> Enemy(const std::string& file, glm::ivec2 position, EnemyType type);

	std::shared_ptr<dae::GameObject> GalagaPlayer(const std::string file, glm::ivec2 size, int lives);
	
}

