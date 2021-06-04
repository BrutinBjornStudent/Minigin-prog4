#include "QbertEngine.h"

#include "CellComponent.h"
#include "SceneManager.h"
#include "GameObject.h"


void QbertEngine::LoadGame()
{
	auto scene = dae::SceneManager::GetInstance().CreateScene("Qbert");


	auto obj = std::make_shared<dae::GameObject>();

	SDL_Color test = SDL_Color{100,100,0,255};
	auto cell = new CellComponent(glm::vec3(300, 200, 0), glm::ivec3(0, 0, 0), test, 30);
	
	obj->AddComponent(cell);
	
	scene->Add(obj);
	
}
