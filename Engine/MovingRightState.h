#pragma once
#include "PlayerState.h"

class MovingRightState : public PlayerState
{
public:
	MovingRightState() {}
	virtual PlayerState* HandleInput(Player& p_player, Keyboard::Event input)
	{
		if (input.GetCode() == kbd.KeyIsPressed(VK_RIGHT))
		{
			if (input.IsPress())
			{
				
			}
			else if (input.IsRelease())
			{

			}
		}
	}
	virtual void Update(Player& p_player);

public:
};

