#pragma once
#include "GameObject.h"


namespace objectConstructors
{
	std::shared_ptr<dae::GameObject> TextObject(const std::string& file, unsigned int size
		, const std::string& text
		, float Xpos = 0, float Ypos = 0);

	std::shared_ptr<dae::GameObject> RenderObject(const std::string& TexturePath
	, float Xpos = 0,  float Ypos = 0);

	dae::GameObject LivesBar();





	
}

