#pragma once
#include "Keyboard.h"
#include "Graphics.h"

class Player;

class PlayerState
{
public:
	virtual ~PlayerState() {}
	virtual PlayerState* HandleInput(Player& player, Keyboard::Event input) {}
	virtual void Update(Player& player) {}

public:

	Keyboard::Event input;
	Keyboard kbd;
};