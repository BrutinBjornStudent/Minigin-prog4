#pragma once
#include <list>
#include <XInput.h>
#include "Singleton.h"
#include <map>
#include "Command.h"
#include "XBoxController.h"



enum class InputType
{
	down, Up, Pressed
};

struct Action
{
	input::XBoxController::ControllerButton Button;
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
