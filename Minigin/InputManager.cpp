#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


using ControllerCommandMap = std::map<input::XBoxController::ControllerButton,Command*>;
using KeyBoardCommandMap = std::map<input::XBoxController::KeyBoardButton, Command*>;





input::InputManager::InputManager()
{
	int cId = CheckForController();
	if (cId != -1)
	{
		m_pController = new XBoxController(cId);
		std::cout << "controller found: " << cId << std::endl;
	}
	else
	{
		m_pController = nullptr;
		std::cout << "no controller found" << std::endl;
	}

}

input::InputManager::~InputManager()
{
	delete m_pController;
	for (std::list<Action>::iterator iter = m_Actions.begin(); iter != m_Actions.end(); ++iter)
	{
		if (iter->pCommand)
		{
			delete iter->pCommand;
			iter->pCommand = nullptr;
			
		}
		
	}

}

int input::InputManager::CheckForController()
{
	int controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
			controllerId = i;
		
	}
	return controllerId;
}

void input::InputManager::AddAction(const Action& ac)
{
	m_Actions.push_back(ac);
	
}

void input::InputManager::Update()
{
	if (m_pController)
	{
		m_pController->Update();		
		ProcessInput();
	}
}

bool input::InputManager::ProcessInput()
{
	SDL_Event e;


	//keyboard...
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			std::cout << "key pressed" << std::endl;
			if(e.key.keysym.sym == SDLK_w)
			{
				std::cout << "w pressed" << std::endl;
			}
		
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			std::cout << "mouse pressed" << std::endl;
		}
		if (e.type == SDL_KEYUP)
		{
			std::cout << "Key up" << std::endl;
		}
	}

	//XBoxController....
	for (std::list<Action>::iterator iter = m_Actions.begin(); iter != m_Actions.end(); ++iter)
	{
		if (m_pController->IsDown(iter->Button) && iter->type == InputType::down)
		{
			iter->pCommand->Execute();
		}

		if (m_pController->IsPressed(iter->Button) && iter->type == InputType::Pressed)
		{
			iter->pCommand->Execute();
		}

		if (m_pController->IsUp(iter->Button) && iter->type == InputType::Up)
		{
			iter->pCommand->Execute();
		}
	}
	
	return true;
	
}


bool input::InputManager::IsPressed(XBoxController::ControllerButton button) const
{
	return m_pController->IsPressed(button);
}

