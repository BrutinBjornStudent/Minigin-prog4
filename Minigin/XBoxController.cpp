#include "MiniginPCH.h"
#include "XBoxController.h"
#include <XInput.h>


namespace input
{
	class XBoxControllerImp
	{
	public:
		XBoxControllerImp();
	
		void Update();
		bool IsDown(XBoxController::ControllerButton button) const;
		bool IsUp(XBoxController::ControllerButton button) const;
		bool IsPressed(XBoxController::ControllerButton button) const;
	private:
		XINPUT_STATE previeusState{};
		XINPUT_STATE CurrentState{};
		
	};


	XBoxControllerImp::XBoxControllerImp()
	{
		
	}

	void XBoxControllerImp::Update()
	{
		CopyMemory(&previeusState, &CurrentState, sizeof(XINPUT_STATE));
		ZeroMemory(&CurrentState, sizeof(XINPUT_STATE));
		XInputGetState(0, &CurrentState);
	}

	bool XBoxControllerImp::IsDown(XBoxController::ControllerButton button) const
	{
		return ((CurrentState.Gamepad.wButtons & static_cast<unsigned int>(button)) != 0) &&
			((previeusState.Gamepad.wButtons & static_cast<unsigned int>(button)) == 0);
	}

	bool XBoxControllerImp::IsUp(XBoxController::ControllerButton button) const
	{
		return ((CurrentState.Gamepad.wButtons & static_cast<unsigned int>(button)) == 0) &&
			((previeusState.Gamepad.wButtons & static_cast<unsigned int>(button)) != 0);
	}

	bool XBoxControllerImp::IsPressed(XBoxController::ControllerButton button) const
	{
		return (CurrentState.Gamepad.wButtons & static_cast<unsigned int>(button)) != 0;
	}


	XBoxController::XBoxController(int ControllerIndex) 
		: m_controllerIdx(ControllerIndex)
	{
		m_pImpl = new XBoxControllerImp();
	}

	XBoxController::~XBoxController()
	{
		delete m_pImpl;
	}

	void XBoxController::Update()
	{
		if (m_pImpl)
		m_pImpl->Update();
	}

	bool XBoxController::IsDown(ControllerButton Button) const
	{
		return m_pImpl->IsDown(Button);
	}

	bool XBoxController::IsPressed(ControllerButton Button) const
	{
		return m_pImpl->IsPressed(Button);
	}

	bool XBoxController::IsUp(ControllerButton button) const
	{
		return m_pImpl->IsUp(button);
	}



}

