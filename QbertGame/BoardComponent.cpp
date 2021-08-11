#include "BoardComponent.h"





BoardComponent::BoardComponent( dae::Scene& currentScene, const glm::vec3& center, const std::vector<glm::ivec2>& cellHexPosition, std::string texturepath,
	float radius)
{
	int width = static_cast<int>(sqrt(3) * radius);
	int height = static_cast<int>(radius * 2);
	
	for (uint32_t i = 0; i < cellHexPosition.size();i++)
	{
		glm::vec3 pos = center;


		pos.x = center.x + (cellHexPosition[i].x * width) + (cellHexPosition[i].y * width/2);
		pos.y = center.y - (cellHexPosition[i].y * (height *3 / 4 ));
		
		
		//glm::ivec2 copy = cellHexPosition[i];


		auto texture = new RenderComponent();
		texture->SetPosition(pos.x - radius, pos.y - radius);
		texture->SetSize((width), (height));
		texture->SetSourceRect(SDL_Rect{ 0,160,32,32 });
		texture->SetTexture(texturepath);

		
		auto cell = new CellComponent(pos, cellHexPosition[i], texture,radius);
		auto gameobj =  std::make_shared<dae::GameObject>();

		
		gameobj->AddComponent(texture);
		gameobj->AddComponent(cell);
		
		m_cells.push_back(cellPos{ cellHexPosition[i],gameobj});
		currentScene.Add(gameobj);

		
	}
	
}

BoardComponent::~BoardComponent()
{

}

void BoardComponent::Render() const
{
	for (uint32_t i = 0; i < m_cells.size(); i++)
	{
		m_cells[i].cell->Render();
	}
}

std::shared_ptr<dae::GameObject> BoardComponent::GetCellFromPos(int x, int y)
{

	for (std::vector<cellPos>::iterator it = m_cells.begin(); it != m_cells.end(); ++it)
	{
		if (it->position.x == x && it->position.y == y)
		{
			return it->cell;
		}
	}
	
	return nullptr;
}

std::shared_ptr<dae::GameObject> BoardComponent::GetCellFromPos(glm::ivec2 pos)
{
	return GetCellFromPos(pos.x, pos.y);
}
