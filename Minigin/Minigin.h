#pragma once
#include "FPS.h"
#include "GameObject.h"
#include "Scene.h"

#include "Font.h"
#include "InputManager.h"
#include "Observer.h"

class QBert;
struct SDL_Window;
namespace dae
{
	class Minigin
	{
	public:
		void Initialize();
		void LoadGame();
		void Update();
		void Render();
		void Cleanup();
		void Run();
	private:
//		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_pWindow{};

		
		
		FPSTimer* m_pTimer = nullptr;

		input::InputManager* m_pInputManager = nullptr;
		QbertObserver m_qbertobserver = 0;
		ScoreObserver m_scoreObserver = 0;
		

		std::shared_ptr<GameObject> m_pFps;
		std::shared_ptr<GameObject> m_qbert;
		std::shared_ptr<GameObject> m_pScore;
		std::shared_ptr<GameObject> m_phealthBar;
		//std::vector<BaseComponent*> m_EngineComponents;
	
	};
}