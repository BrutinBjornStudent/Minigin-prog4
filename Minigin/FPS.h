#pragma once
#include "Component.h"
#include <chrono>
// inspired by the Elite Timer


class FPSTimer final : public BaseComponent
{
public:
	FPSTimer();
	~FPSTimer();

	FPSTimer(const FPSTimer&) = default;
	FPSTimer(FPSTimer&&) noexcept = default;
	FPSTimer& operator=(const FPSTimer&) = default;
	FPSTimer& operator=(FPSTimer&&) noexcept = default;

	void start();
	void Update();
	void Update(const float ) override {};
	void Render() const override;


	uint32_t GetFPS() { return m_FPS; };
	float GetDeltaTime() { return m_DeltaTime; };
	bool IsRunning() { return m_IsRunning; }
private:

	std::chrono::high_resolution_clock m_HClock = std::chrono::high_resolution_clock();
	std::chrono::steady_clock::time_point m_currentTime;
	std::chrono::steady_clock::time_point m_lastTime;
	
	uint32_t m_lag;
	uint32_t m_FPS;
	uint32_t m_FPSCount;
	float m_FPSTimer;
	float m_TotalTime;
	float m_DeltaTime;
	float m_ElapsedTime;
	float m_PrintTimer;
	bool m_IsRunning = false;
	bool m_PrintTimeConsole = false;
};

