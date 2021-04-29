#pragma once

#include "QBert.h"

class Command
{
protected:
	QBert* GetActor()const { return actor; };
public:
	explicit Command(QBert* actor);
	virtual ~Command() = default;
	virtual void Execute() = 0;
private:
	QBert* actor;
};

class DieCommand  final: public Command
{
public:
	DieCommand(QBert* actor):Command(actor) {};
	void Execute() override { GetActor()->Die(); };
};

class JumpCommand final : public Command
{
public:
	JumpCommand(QBert* actor):Command(actor) {};
	void Execute() override { GetActor()->Jump(); };
};

class FireCommand final : public Command
{
public:
	FireCommand(QBert* actor):Command(actor) {};
	void Execute() override { GetActor()->Fire(); };
};
