#pragma once

#include "ActorComponent.h"

class Command
{
protected:
	ActorComponent* GetActor()const { return actor; };
public:
	explicit Command(ActorComponent* actor);
	virtual ~Command() = default;
	virtual void Execute() = 0;
private:
	ActorComponent* actor;
};

class DieCommand  final: public Command
{
public:
	DieCommand(ActorComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Die(); };
};

class JumpCommand final : public Command
{
public:
	JumpCommand(ActorComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Jump(); };
};

class FireCommand final : public Command
{
public:
	FireCommand(ActorComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Fire(); };
};

class FartCommand final : public Command
{
public:
	FartCommand(ActorComponent* actor) :Command(actor) {};
	void Execute() override { GetActor()->Fart(); };
};

class MoveUnitCommand final : public Command
{
public:
	MoveUnitCommand(ActorComponent* qbert, float x, float y)
		:Command(qbert),m_x(x),m_y(y){}
	
	void Execute() override
	{
		m_xBefore = GetActor()->GetPosition().x;
		m_yBefore = GetActor()->GetPosition().y;
		GetActor()->MoveTo(m_x, m_y);
		
	};
	
	void Undo() { GetActor()->MoveTo(m_xBefore, m_yBefore); };
	

private:

	float m_x, m_y;
	float m_xBefore, m_yBefore;
	
};

