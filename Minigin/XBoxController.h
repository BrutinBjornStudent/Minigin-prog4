#pragma once


//https://docs.microsoft.com/en-us/windows/win32/api/xinput/ns-xinput-xinput_gamepad
namespace input
{
	class XBoxControllerImp;
	class XBoxController
	{
		XBoxControllerImp* m_pImpl;

	public:
		XBoxController(int ControllerIndex);
		~XBoxController();
		
		enum class ControllerButton
		{
			ButtonUp = 0x0001,
			ButtonDown = 0x0002,
			ButtonLeft = 0x0004,
			ButtonRight = 0x0008,

			ButtonA = 0x1000,
			ButtonB = 0x2000,
			ButtonX = 0x4000,
			ButtonY = 0x8000

		};

		enum class KeyBoardButton
		{
			KeyW = 0x0000,
			KeyS = 0x0001,
			KeyA = 0x0004,
			KeyD = 0x0008,

			KeyZ = 0x1000,
			KeyX = 0x2000,
			KeyC = 0x4000,
			KeyV = 0x8000,
		};

		void Update();
		bool IsDown(ControllerButton Button) const;
		bool IsPressed(ControllerButton Button) const;
		bool IsUp(ControllerButton button) const;
	private:
		int m_controllerIdx;

	};

}


