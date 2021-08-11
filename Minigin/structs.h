#pragma once
#include <glm/vec2.hpp>
// contains glm::ivec2 pos and glm::ivec2 size;
struct Rect
{
	Rect(int posX, int posY, int sizeX, int sizeY)
		:pos(posX, posY), size(sizeX, sizeY) {};
	glm::ivec2 pos;
	glm::ivec2 size;
};
