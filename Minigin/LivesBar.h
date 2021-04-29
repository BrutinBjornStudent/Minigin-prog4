#pragma once
#include "Observer.h"

class LivesBar final : public QbertObserver, public dae::GameObject
{


public:
	LivesBar(int lives);
	virtual ~LivesBar() = default;

	LivesBar(const LivesBar& other) = default;
	LivesBar(LivesBar && other) = default;
	LivesBar& operator=(const LivesBar & other) = default;
	LivesBar& operator=(LivesBar && other) = default;

	virtual void Update(const float) {};
	virtual void Render() const;

	void PlayerDied() override;

private:
	int m_Lives;
	
};



