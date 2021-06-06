#pragma once
#include "Command.h"
#include "QBertComponent.h"


class QBertCommand final : public Command
{
public:
	QBertCommand(QBertComponent* qbert, int x, int y)
		:m_Qbert(qbert), m_x(x), m_y(y) {}

	void Execute() override
	{
		m_Qbert->MoveTo(m_x, m_y);
	};

private:

	int m_x, m_y;
	QBertComponent* m_Qbert;
};
