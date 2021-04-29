#include "MiniginPCH.h"
#include "FPS.h"

FPSTimer::FPSTimer()
	
{
	m_HClock = std::chrono::high_resolution_clock();
	m_currentTime = m_HClock.now();
	m_lastTime = m_HClock.now();
	m_DeltaTime = 0;
	m_ElapsedTime = 0;
	m_FPSTimer = 0.0f;
	m_FPS = uint32_t(0);
	m_FPSCount = 0 ;
	m_lag = 0 ;
	m_TotalTime = 0.0f;
	m_PrintTimer = 0.f;
}

FPSTimer::~FPSTimer()
{
}

void FPSTimer::start()
{
	m_IsRunning = true;
	m_lastTime = m_HClock.now();
}

void FPSTimer::Update()
{
	if (!m_IsRunning)
	{
		m_TotalTime = uint32_t(0.f);
		m_DeltaTime = uint32_t(0.f);
	}
	else
	{
		m_currentTime = m_HClock.now();
		m_DeltaTime = std::chrono::duration<float>(m_currentTime - m_lastTime).count();

		m_FPSTimer += m_DeltaTime;
		++m_FPSCount;

		if (m_FPSTimer >= 1.0f)
		{
			m_FPS = m_FPSCount;
			m_FPSCount = 0;
			m_FPSTimer -= 1.f;
		}

		m_lastTime = m_currentTime;
	}


	if (m_PrintTimeConsole)
	{
		m_PrintTimer += m_DeltaTime;
		if (m_PrintTimer >= 1.f)
		{
			m_PrintTimer -= 1.f;
			std::cout << m_FPS << std::endl;
		}
	}


}

void FPSTimer::Render() const
{
}






