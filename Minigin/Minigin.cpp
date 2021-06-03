#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"

#include "ResourceManager.h"
#include "QBertComponent.h"
#include "Locator.h"

#include "ObjectConstructors.h"
#pragma warning(push)
#pragma warning(disable:26812)
#pragma warning(disable:26819)
#include "HealthBarComponent.h"
#include "SDL.h"
#include "SoundSystem.h"

#include "TextComponent.h"
#pragma warning(pop)


using namespace std;
using namespace std::chrono;



void dae::Minigin::Initialize()
{

	
	//intialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_pWindow = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_pWindow == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}


	Renderer::GetInstance().Init(m_pWindow);
	m_pTimer = new FPSTimer();
	m_pTimer->start();

	m_pInputManager = new input::InputManager();

	
	
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame()
{
	auto scene = SceneManager::GetInstance().CreateScene("Demo");


	Locator::RegisterSoundSystem(new SDLSoundSystem());


	//auto& t1 = Locator::GetSoundSystem();


	//t1.loadSound(1, "Level Music 1.mp3");
	//t1.play(1,1,"level Music 1.mp3");
	//
	//t1.loadSound(2, "Level Music 2.mp3");
	//t1.play(2, 1, "level Music 2.mp3");


	

	auto background = objectConstructors::RenderObject("background.jpg");
	scene->Add(background);
	
	auto logo = objectConstructors::RenderObject("logo.png", 216, 180);
	scene->Add(logo);

	auto to = objectConstructors::TextObject("lingua.otf", 36, "Programming 4 Assignment",80,20);
	scene->Add(to);
	// end background

	m_qbert = objectConstructors::Qbert(3);
	scene->Add(m_qbert);
	// base qbert
;
	m_pFps = objectConstructors::TextObject("lingua.otf", 12, "fps:", 10, 50);
	m_pFps->GetComponent<TextComponent>()->SetColor(SDL_Color{ 255, 255, 0, 255 });
	scene->Add(m_pFps);

	m_phealthBar = objectConstructors::LivesBar("HeartSymbol.png", 10, 60, m_qbert->GetComponent<HealthComponent>());
	m_phealthBar->GetComponent<HealthBarComponent>()->SetSize(glm::vec2(10, 10));
	scene->Add(m_phealthBar);

	m_pScore = objectConstructors::Score("lingua.otf", 12, "score:", 10, 70);
	scene->Add(m_pScore);
	// end GUI

	
	m_qbertobserver = QbertObserver(m_qbert->GetComponent<HealthComponent>());
	
	auto* qbertcomp = m_qbert->GetComponent<QBertComponent>();	
	qbertcomp->GetSubject()->AddObserver(&m_qbertobserver);
	// add healthObserver

	m_scoreObserver = ScoreObserver(m_pScore->GetComponent<ScoreComponent>());
	qbertcomp->GetSubject()->AddObserver(&m_scoreObserver);
	// add score observer

	
	//InputManager
	Action newAction = Action();
	newAction.pCommand = new DieCommand(qbertcomp);
	newAction.Button = input::XBoxController::ControllerButton::ButtonA;
	newAction.type = InputType::down;
	m_pInputManager->AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new FireCommand(qbertcomp);
	newAction.Button = input::XBoxController::ControllerButton::ButtonB;
	newAction.type = InputType::Pressed;
	m_pInputManager->AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new JumpCommand(qbertcomp);
	newAction.Button = input::XBoxController::ControllerButton::ButtonX;
	newAction.type = InputType::Up;
	m_pInputManager->AddAction(newAction);

	newAction = Action();
	newAction.pCommand = new FartCommand(qbertcomp);
	newAction.Button = input::XBoxController::ControllerButton::ButtonY;
	newAction.type = InputType::down;
	m_pInputManager->AddAction(newAction);
	
	//end input

	
}


void dae::Minigin::Update()
{
	m_pTimer->Update();
	auto& sceneManager = SceneManager::GetInstance();
	sceneManager.Update(m_pTimer->GetDeltaTime());
	m_pInputManager->Update();

}

void dae::Minigin::Render()
{
	auto& sceneManager = SceneManager::GetInstance();
	sceneManager.Render();
}

void dae::Minigin::Cleanup()
{
	delete m_pTimer;
	delete m_pInputManager;

	Locator::CloseSoundSystem();
	
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");
	float printTimer = 0.f;

	LoadGame();
	{
		//auto& Scene = SceneManager::GetInstance();
		auto& renderer = Renderer::GetInstance();
		auto& input = input::InputManager::GetInstance();

		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();


			doContinue = input.ProcessInput();
			Update();
			renderer.Render();
			
			printTimer += m_pTimer->GetDeltaTime();
			if (printTimer > 1.f)
			{
				printTimer -= 1.f;
				std::cout << m_pTimer->GetFPS() << std::endl;
				m_pFps->GetComponent<TextComponent>()->SetText("FPS: " + std::to_string(m_pTimer->GetFPS()));
				
			}


		}
	}

	Cleanup();
}
