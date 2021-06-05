#pragma once
#include <Component.h>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "CellComponent.h"
#include <Transform.h>

#include "GameObject.h"
#include "Scene.h"


struct cellPos
{
	glm::ivec2 position;
	std::shared_ptr<dae::GameObject> cell;
};

//https://www.redblobgames.com/grids/hexagons/#size-and-spacing
class BoardComponent :
    public BaseComponent
{
public:
	BoardComponent( dae::Scene& currentScene, const glm::vec3& center, const std::vector<glm::ivec2>& cellPosition, std::string texturepath,
	               float radius);
	BoardComponent(std::string path) {};

	~BoardComponent();
	
	void Update(const float ) override {};
	void Render() const override;
	
	

private:
	std::vector<cellPos> m_cells;
	dae::Transform m_center;



	
};

