#pragma once
#include "Component.h"
#include "TextComponent.h"

class ScoreComponent :
    public BaseComponent
{
public:
	ScoreComponent(dae::TextComponent* text);
	~ScoreComponent() = default;

	void Update(const float) override;
	void Render() const override;
	
	void AddScore(int score)
	{
		
		m_score += score;
		m_needsUpdate = true;
	};
	int GetScore()
	{
		
		return m_score;
	};

private:
	dae::TextComponent* nm_pTextComp;
	bool m_needsUpdate;
	int m_score;
};

