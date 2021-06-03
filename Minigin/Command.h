#pragma once

#include "QBertComponent.h"

class Command
{
protected:
	QBertComponent* GetActor()const { return actor; };
public:
	explicit Command(QBertComponent* actor);
	virtual ~Command() = default;
	virtual void Execute() = 0;
private:
	QBertComponent* actor;
};

class DieCommand  final: public Command
{
public:
	DieCommand(QBertComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Die(); };
};

class JumpCommand final : public Command
{
public:
	JumpCommand(QBertComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Jump(); };
};

class FireCommand final : public Command
{
public:
	FireCommand(QBertComponent* actor):Command(actor) {};
	void Execute() override { GetActor()->Fire(); };
};

class FartCommand final : public Command
{
public:
	FartCommand(QBertComponent* actor) :Command(actor) {};
	void Execute() override { GetActor()->Fart(); };
};


