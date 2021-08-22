#include "GalagaEngine.h"


#include "HealthBarComponent.h"
#include "Locator.h"

#include "AllComponents.h"
#include "CellComponent.h"
#include "EnemyManagerComp.h"
#include "GalagaCommand.h"
#include "GalagaConstructor.h"
#include "ObjectConstructors.h"
#include "PlayerComponent.h"


void GalagaEngine::LoadGame()
{

	
	
	glm::ivec2 size = dae::Renderer::GetInstance().GetWindowSize();

	//
	//auto StartScene = dae::SceneManager::GetInstance().CreateScene("StartScene");
	//auto text = objectConstructors::TextObject("lingua.otf", 40, "GALAGA", float(size.x / 2), float(size.y / 2));
	//StartScene->Add(text);
	//
	//auto SpaceBackGroundMenu = objectConstructors::RenderObject("Galaga/SpaceBackground.png");
	//StartScene->Add(SpaceBackGroundMenu);
	//

	

	auto scene = dae::SceneManager::GetInstance().CreateScene("Galaga");

	//background
	auto SpaceBackGround = objectConstructors::RenderObject("Galaga/SpaceBackground.png");
	scene->Add(SpaceBackGround);
	auto background = SpaceBackGround->GetComponent<RenderComponent>();
	background->SetSize(size.x / 3 * 2, size.y);


	//scoreBoard
	auto ScoreBoard = std::make_shared<dae::GameObject>();
	auto* StutusBoardBackground = new RectComponent();
	
	StutusBoardBackground->SetPosition(size.x / 3 * 2, 0);
	StutusBoardBackground->SetSize(size.x / 3, size.y);
	StutusBoardBackground->SetColor(SDL_Color{50,50,50,255});
	
	ScoreBoard->AddComponent(StutusBoardBackground);
	ScoreBoard->SetRenderLayer(2);
	scene->Add(ScoreBoard);
	
	//score
	auto score = objectConstructors::Score("lingua.otf", 12, "score:",float(size.x /4 * 3),float(size.y / 2));
	scene->Add(score);
	
	auto scoreComp = score->GetComponent<ScoreComponent>();
	score->SetRenderLayer(3);
	
	m_EnemyObserver = GalagaEnemyObserver(scoreComp);


	////player character
	m_PlayerCharacter = objectConstructors::GalagaPlayer("Galaga/Player1_default.png",glm::ivec2(30,30));// qbert is 16 on 16 big on sprite sheet
	auto PlayerActor = m_PlayerCharacter->GetComponent<ActorComponent>();
	PlayerActor->Translate(float(size.x / 3), float(size.y) - 40 );

	
	scene->Add(m_PlayerCharacter);


	//healthComponent
	auto Healthbar = objectConstructors::LivesBar(
		"Galaga/Player1_default.png",
		float(size.x/3 * 2 +20.f), 
		float(size.y / 2 + 20.f),3);

	Healthbar->GetComponent<HealthBarComponent>()->SetSize({ 30,30 });
	Healthbar->GetComponent<HealthBarComponent>()->SetPosition(float(size.x / 3 * 2), float(size.y/2) + 40);
	Healthbar->SetRenderLayer(3);
	scene->Add(Healthbar);
	

	auto EnemyManager = std::make_shared<dae::GameObject>();
	EnemyManager->AddComponent(new EnemyManagerComp(glm::vec2(size.x / 3, 90), glm::vec2(30, 30),
	                                            glm::vec2(size.x / 3 * 2, size.y), m_EnemyObserver, "Galaga/waves.json"));

	
	scene->Add(EnemyManager);

	
	auto gameOver = objectConstructors::TextObject("lingua.otf", 40, "GameOver", float(size.x / 3),float(size.y /2));
	gameOver->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 255,0,0,255 });
	gameOver->SetRenderLayer(4);
	gameOver->SetActive(false);
	scene->Add(gameOver);

	
	//player observer
	m_PlayerObserver = GalagaPlayerObserver(Healthbar->GetComponent<HealthComponent>(),EnemyManager->GetComponent<EnemyManagerComp>(),m_PlayerCharacter,size,gameOver);
	m_PlayerCharacter->GetComponent<PlayerComponent>()->GetSubject()->AddObserver(&m_PlayerObserver);
	EnemyManager->GetComponent<EnemyManagerComp>()->GetSubject()->AddObserver(&m_PlayerObserver);

	
	LoadInputs();
	EnemyManager->GetComponent<EnemyManagerComp>()->SpawnEnemys();


	
}


void GalagaEngine::LoadInputs() const
{
	auto PlayerActor = m_PlayerCharacter->GetComponent<ActorComponent>();
	// input Action
	auto& inputManager = input::InputManager::GetInstance();

	Action ShootAction = Action();

	
	ShootAction.pCommand = new ShootCommand(m_PlayerCharacter->GetComponent<GunComponent>());
	ShootAction.type = InputType::IsPressed;
	ShootAction.key = SDL_SCANCODE_Z;
	inputManager.AddAction(ShootAction);

	Action MoveRight = Action();
	MoveRight.pCommand = new MoveUnitCommand(PlayerActor,100.f,0.f );
	MoveRight.type = InputType::IsPressed;
	MoveRight.key = SDL_SCANCODE_RIGHT;
	inputManager.AddAction(MoveRight);

	Action MoveLeft = Action();
	MoveLeft.pCommand = new MoveUnitCommand(PlayerActor, -100.f, 0.f);
	MoveLeft.type = InputType::IsPressed;
	MoveLeft.key = SDL_SCANCODE_LEFT;
	inputManager.AddAction(MoveLeft);


	Action ShootActionController = Action();
	ShootActionController.pCommand = new ShootCommand(m_PlayerCharacter->GetComponent<GunComponent>());
	ShootActionController.XButton = input::XBoxController::ControllerButton::ButtonX;
	ShootActionController.type = InputType::IsPressed;
	inputManager.AddAction(ShootActionController);

	Action MoveRightController = Action();
	MoveRightController.pCommand = new MoveUnitCommand(PlayerActor, 100.f, 0.f);
	MoveRightController.XButton = input::XBoxController::ControllerButton::ButtonRight;
	MoveRightController.type = InputType::IsPressed;
	inputManager.AddAction(MoveRightController);

	Action MoveLeftController = Action();
	MoveLeftController.pCommand = new MoveUnitCommand(PlayerActor, -100.f, 0.f);
	MoveLeftController.XButton = input::XBoxController::ControllerButton::ButtonLeft;
	MoveLeftController.type = InputType::IsPressed;
	inputManager.AddAction(MoveLeftController);


		
}







