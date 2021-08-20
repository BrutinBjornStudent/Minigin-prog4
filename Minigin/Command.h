#pragma once

#include "ActorComponent.h"

class Command
{

public:
	explicit Command() = default;
	virtual ~Command() = default;
	virtual void Execute() = 0;

};

class DieCommand  final: public Command
{
public:
	DieCommand(ActorComponent* actor):m_actor(actor) {};
	void Execute() override { m_actor->Die(); };
private:
	ActorComponent* m_actor;
};

class JumpCommand final : public Command
{
public:
	JumpCommand(ActorComponent* actor):m_actor(actor) {};
	void Execute() override { m_actor->Jump(); };
private:
	ActorComponent* m_actor;
};

class FireCommand final : public Command
{
public:
	FireCommand(ActorComponent* actor):m_actor(actor) {};
	void Execute() override { m_actor->Fire(); };
private:
	ActorComponent* m_actor;
};

class FartCommand final : public Command
{
public:
	FartCommand(ActorComponent* actor) :m_actor(actor) {};
	void Execute() override { m_actor->Fart(); };
private:
	ActorComponent* m_actor;
};

class MoveUnitCommand final : public Command
{
public:
	MoveUnitCommand(ActorComponent* qbert, float x, float y)
		:m_actor(qbert),m_x(x),m_y(y){}
	
	void Execute() override
	{
		m_actor->SetVelocity(m_x, m_y);
	};

private:
	ActorComponent* m_actor;
	float m_x, m_y;
};



