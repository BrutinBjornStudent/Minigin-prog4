#include "QbertEngine.h"

#include "CellComponent.h"
#include "BoardComponent.h"
#include "SceneManager.h"
#include "GameObject.h"

#include "HealthBarComponent.h"
#include "Locator.h"
#include "ObjectConstructors.h"
#include "QBertComponent.h"
#include "SpriteComponent.h"
#include "QbertCommand.h"

void QbertEngine::LoadGame()
{
	auto scene = dae::SceneManager::GetInstance().CreateScene("Qbert");


	auto obj = std::make_shared<dae::GameObject>();

	//SDL_Color test = SDL_Color{100,100,0,255};
	//auto cell = new CellComponent(glm::vec3(300, 200, 0), glm::ivec2(0, 0), test, 30);	
	//obj->AddComponent(cell);
	//scene->Add(obj);


	Locator::RegisterSoundSystem(new SDLSoundSystem());
	
	auto& t1 = Locator::GetSoundSystem();
	t1.loadSound(1, "Level Music 1.mp3");
	t1.play(1,1,"level Music 1.mp3");
	
	t1.loadSound(2, "Level Music 2.mp3");
	t1.play(2, 1, "level Music 2.mp3");

	
	auto boardObj = std::make_shared<dae::GameObject>();
	
	std::vector<glm::ivec2> cellposition;
	cellposition.emplace_back(0, 0);
	cellposition.emplace_back(1, 0);
	cellposition.emplace_back(-1, 0);
	cellposition.emplace_back(1, -1);
	cellposition.emplace_back(-1, 1);
	cellposition.emplace_back(0, 1);
	cellposition.emplace_back(0, -1);
	cellposition.emplace_back(-1, 2);
	
	auto board = 
		new BoardComponent(*scene,glm::vec3(300,200,0),cellposition,"sprites.png",30);

	boardObj->AddComponent(board);
	scene->Add(boardObj);

	
	auto Qbert = objectConstructors::BasicActor(3);// qbert is 16 on 16 big on sprite sheet


	auto QbertLogic = new QBertComponent({ 0,1 }, board, Qbert->GetComponent<RenderComponent>());
	Qbert->AddComponent(QbertLogic);

	Qbert->GetComponent<RenderComponent>()->SetTexture("sprites.png");
	Qbert->GetComponent<RenderComponent>()->SetSize(30, 30);
	Qbert->GetComponent<RenderComponent>()->SetOffset(-20,-40);


	auto SpriteManager = new SpriteComponent(Qbert->GetComponent<RenderComponent>(), SDL_Rect{ 0,0,16,16 }, 8, 1);
	SpriteManager->SetXSprite(6);
	SpriteManager->setYSprite(1);
	Qbert->AddComponent(SpriteManager);
	scene->Add(Qbert);


	auto Healthbar = objectConstructors::LivesBar("HeartSymbol.png",20, 20, Qbert->GetComponent<HealthComponent>());

	Healthbar->GetComponent<HealthBarComponent>()->SetSize({20,20});
	scene->Add(Healthbar);


	Action newAction = Action();

	

	auto& inputManager = input::InputManager::GetInstance();
	
	newAction.pCommand = new QBertCommand(QbertLogic,0,1);
	newAction.Button = input::XBoxController::ControllerButton::ButtonUp;
	newAction.type = InputType::Up;
	inputManager.AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new QBertCommand(QbertLogic, 0, -1);
	newAction.Button = input::XBoxController::ControllerButton::ButtonDown;
	newAction.type = InputType::Up;
	inputManager.AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new QBertCommand(QbertLogic, 1, -1);
	newAction.Button = input::XBoxController::ControllerButton::ButtonRight;
	newAction.type = InputType::Up;
	inputManager.AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new QBertCommand(QbertLogic, -1, 1);
	newAction.Button = input::XBoxController::ControllerButton::ButtonLeft;
	newAction.type = InputType::Up;
	inputManager.AddAction(newAction);

	//glm::vec2 newpos = boardObj->GetComponent<BoardComponent>()->GetCellFromPos(0, 0)->GetComponent<CellComponent>()->GetPosition();
	//Qbert->GetComponent<RenderComponent>()->SetPosition(newpos.x,newpos.y);


}
