#pragma once
class Player;

class PlayerState

{
public:
	virtual ~PlayerState() {}
	virtual void HandleInput(Player& player, Keyboard::Event input) {}
	virtual void Update(Player& player) {}

public:

	Keyboard::Event input;
	Keyboard kbd;
};