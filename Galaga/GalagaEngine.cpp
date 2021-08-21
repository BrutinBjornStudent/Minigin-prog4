#include "GalagaEngine.h"


#include "HealthBarComponent.h"
#include "Locator.h"

#include "AllComponents.h"
#include "CellComponent.h"
#include "EnemySpawner.h"
#include "GalagaCommand.h"
#include "GalagaConstructor.h"
#include "ObjectConstructors.h"


void GalagaEngine::LoadGame()
{
	auto scene = dae::SceneManager::GetInstance().CreateScene("Galaga");
	glm::ivec2 size = dae::Renderer::GetInstance().GetWindowSize();



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


	//player character
	playerCharacter = objectConstructors::GalagaPlayer("Galaga/Player1_default.png",glm::ivec2(30,30),3);// qbert is 16 on 16 big on sprite sheet
	auto PlayerActor = playerCharacter->GetComponent<ActorComponent>();
	PlayerActor->Translate(float(size.x / 3), float(size.y) - 40 );
	PlayerActor->BindRenderComponent(playerCharacter->GetComponent<RenderComponent>());
	scene->Add(playerCharacter);
	

	
	
	auto Healthbar = objectConstructors::LivesBar("Galaga/Player1_default.png", float(size.x/3 * 2 +20.f), float(size.y / 2 + 20.f), playerCharacter->GetComponent<HealthComponent>());
	Healthbar->GetComponent<HealthBarComponent>()->SetSize({ 30,30 });
	Healthbar->GetComponent<HealthBarComponent>()->SetPosition(float(size.x / 3 * 2), float(size.y/2) + 40);
	Healthbar->SetRenderLayer(3);
	scene->Add(Healthbar);
	


	
	auto EnemyManager = std::make_shared<dae::GameObject>();
	EnemyManager->AddComponent(new EnemySpawner(glm::vec2(size.x / 3, 90), glm::vec2(30, 30),
	                                            glm::vec2(size.x / 3 * 2, size.y), m_EnemyObserver, "Galaga/waves.json"));

	
	scene->Add(EnemyManager);
	EnemyManager->GetComponent<EnemySpawner>()->SpawnEnemys();
	
	LoadInputs();
	
}


void GalagaEngine::LoadInputs() const
{
	auto PlayerActor = playerCharacter->GetComponent<ActorComponent>();
	// input Action
	auto& inputManager = input::InputManager::GetInstance();

	Action ShootAction = Action();

	
	ShootAction.pCommand = new ShootCommand(playerCharacter->GetComponent<GunComponent>());
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
	ShootActionController.pCommand = new ShootCommand(playerCharacter->GetComponent<GunComponent>());
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







