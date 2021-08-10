#pragma once
#include <list>
#include <XInput.h>
#include "Singleton.h"
#include <map>
#include <SDL_keycode.h>

#include "Command.h"
#include "XBoxController.h"



enum class InputType
{
	down, Up, IsPressed
};

struct Action
{
	input::XBoxController::ControllerButton XButton;
	SDL_Scancode key = SDL_SCANCODE_UNKNOWN;
	Command* pCommand = nullptr;
	InputType type = InputType::down;
};


namespace input
{

	
class InputManager final : public dae::Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

		int CheckForController();
		void AddAction(const Action& ac);
		void Update();
	
		bool ProcessInput();
		bool IsPressed(XBoxController::ControllerButton button) const;
	private:


		XBoxController* m_pController;
		std::list<Action> m_Actions;
	//	std::map<input::XBoxController::ControllerButton, Command*> m_Commands;
	//	std::map<input::XBoxController::KeyBoardButton, Command*> m_KeyBoardCommands;


	};
}
