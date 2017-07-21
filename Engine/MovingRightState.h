#pragma once
#include "PlayerState.h"

class MovingRightState : public PlayerState
{
public:
	MovingRightState() {}
	virtual PlayerState* HandleInput(Player& player, Keyboard::Event input)
	{
		if (input.GetCode() == kbd.KeyIsPressed(VK_RIGHT))
		{
			if (input.IsPress())
			{

			}
			else if (input.IsRelease())
			{
				// return to neutral state
			}
		}
	}
	virtual void Update(Player& p_player);

public:
};

