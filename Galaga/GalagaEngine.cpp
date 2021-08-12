#include "GalagaEngine.h"


#include "HealthBarComponent.h"
#include "Locator.h"

#include "AllComponents.h"
#include "CellComponent.h"
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
	
	StutusBoardBackground->SetPosition(size.x / 2, 0);
	StutusBoardBackground->SetSize(size.x / 2, 0);
	ScoreBoard->AddComponent(StutusBoardBackground);
	scene->Add(ScoreBoard);



	//score
	auto score = objectConstructors::Score("lingua.otf", 12, "score:", 10, 70);
	scene->Add(score);

	auto scoreComp = score->GetComponent<ScoreComponent>();
	m_EnemyObserver = GalagaEnemyObserver(scoreComp);



	
	//player character
	playerCharacter = objectConstructors::BasicActor(3);// qbert is 16 on 16 big on sprite sheet
	playerCharacter->GetComponent<RenderComponent>()->SetTexture("Galaga/Player1_default.png");
	playerCharacter->GetComponent<RenderComponent>()->SetSize(30, 30);
	playerCharacter->GetComponent<RenderComponent>()->SetOffset(-15, -15);
	scene->Add(playerCharacter);
	
	auto PlayerActor = playerCharacter->GetComponent<ActorComponent>();
	PlayerActor->Translate(float(size.x / 3), float(size.y) - 40 );
	PlayerActor->BindRenderComponent(playerCharacter->GetComponent<RenderComponent>());

	
	
	auto Healthbar = objectConstructors::LivesBar("Galaga/Player1_default.png", float(size.x/3 * 2 +20.f), float(size.y / 2 + 20.f), playerCharacter->GetComponent<HealthComponent>());
	Healthbar->GetComponent<HealthBarComponent>()->SetSize({ 20,20 });
	Healthbar->GetComponent<HealthBarComponent>()->SetPosition(float(size.x / 3 * 2), float(size.y) + 40);
	scene->Add(Healthbar);


	//TestEnemy
	auto TestEnemy = objectConstructors::BeeEnemy("Galaga/bee.png", glm::vec2(size.x / 3.f, 20.f));
	scene->Add(TestEnemy);
	auto BeeComp = TestEnemy->GetComponent<BeeComponent>();
	BeeComp->GetSubject()->AddObserver(&m_EnemyObserver);

	//

	// testProjectile
	auto TestProjectile = objectConstructors::PlayerProjectile("Galaga/PlayerProjectile.png",
		glm::ivec2(float(size.x / 3) + 10, float(size.y) - 40));
	scene->Add(TestProjectile);
	LoadInputs();
	
}


void GalagaEngine::LoadInputs() const
{
	auto PlayerActor = playerCharacter->GetComponent<ActorComponent>();
	// input Action
	auto& inputManager = input::InputManager::GetInstance();

	Action ShootAction = Action();

	ShootAction.pCommand = new FireCommand(PlayerActor);
	ShootAction.type = InputType::IsPressed;
	ShootAction.key = SDL_SCANCODE_Z;
	inputManager.AddAction(ShootAction);

	Action MoveRight = Action();
	MoveRight.pCommand = new MoveUnitCommand(PlayerActor,10.f,0.f );
	MoveRight.type = InputType::IsPressed;
	MoveRight.key = SDL_SCANCODE_RIGHT;
	inputManager.AddAction(MoveRight);

	Action MoveLeft = Action();
	MoveLeft.pCommand = new MoveUnitCommand(PlayerActor, -10.f, 0.f);
	MoveLeft.type = InputType::IsPressed;
	MoveLeft.key = SDL_SCANCODE_LEFT;
	inputManager.AddAction(MoveLeft);
}







