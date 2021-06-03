#pragma once
#include "GameObject.h"


class HealthComponent;

namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> TextObject(const std::string& file, unsigned int size
		, const std::string& text
		, float Xpos = 0, float Ypos = 0);

	std::shared_ptr<dae::GameObject> RenderObject(const std::string& TexturePath
	, float Xpos = 0,  float Ypos = 0);

	std::shared_ptr<dae::GameObject> LivesBar(const std::string& TexturePath,
		float Xpos, float Ypos, HealthComponent* healthComp);
	
	std::shared_ptr<dae::GameObject> Qbert(int lives);

	std::shared_ptr<dae::GameObject> Score(const std::string& file, unsigned int size,
		const std::string& text, float Xpos, float Ypos);


	
}

