#pragma once
#include "FPS.h"
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "Font.h"
#include "InputManager.h"

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
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_pWindow{};

		QBert* m_qbert = nullptr;
		FPSTimer* m_pTimer = nullptr;

		input::InputManager* m_pInputManager = nullptr;
		QbertObserver m_qbertobserver;
		
		std::shared_ptr<TextObject> m_FPSText;
		std::shared_ptr<TextObject> m_Score;
		std::vector<BaseComponent*> m_EngineComponents;
	
	};
}