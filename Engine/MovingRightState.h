#pragma once
#include "PlayerState.h"

class MovingRightState : public PlayerState
{
public:
	MovingRightState();
	virtual void HandleInput(Player& p_player, Keyboard::Event input)
	{
		if (input.GetCode() == kbd.KeyIsPressed(VK_RIGHT))
		{
			// Set to moving right state
			
		}
	}
	virtual void Update(Player& p_player);

public:
	Player& ref_player;
};

