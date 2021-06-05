#include "BoardComponent.h"




BoardComponent::BoardComponent( dae::Scene& currentScene, const glm::vec3& center, const std::vector<glm::ivec2>& cellPosition, std::string texturepath,
	float radius)
{
	int width = static_cast<int>(sqrt(3) * radius);
	int height = static_cast<int>(radius * 2);
	
	for (int i = 0; i <cellPosition.size();i++)
	{
		glm::vec3 pos = center;


		pos.x = center.x + (cellPosition[i].x * width) + (cellPosition[i].y * width/2);
		pos.y = center.y - (cellPosition[i].y * ( height *3 / 4 ));
		
		
		glm::ivec2 copy = cellPosition[i];


		auto texture = new RenderComponent();
		texture->SetPosition(pos.x - radius, pos.y - radius);
		texture->SetSize(float(width), float(height));
		texture->SetSourceRect(SDL_Rect{ 0,160,32,32 });
		texture->SetTexture(texturepath);

		
		auto cell = new CellComponent(pos, cellPosition[i], texture,radius);
		auto gameobj =  std::make_shared<dae::GameObject>();

		
		gameobj->AddComponent(texture);
		gameobj->AddComponent(cell);
		
		m_cells.push_back(cellPos{ copy,gameobj});
		currentScene.Add(gameobj);

		
	}
	
}

BoardComponent::~BoardComponent()
{

}

void BoardComponent::Render() const
{
	for (int i = 0; i < m_cells.size(); i++)
	{
		m_cells[i].cell->Render();
	}
}
