#include "Player.h"
#define MY_KEY 10


Player::Player(Vec2 & pos_in, float width_in, float height_in, Color & color_in)
	:
	playerPos(pos_in),
	playerWidth(width_in),
	playerHeight(height_in),
	playerC(color_in)
{
}

void Player::Move(Keyboard::Event& keyEvent)
{
	if (keyEvent.IsPress()) 
	{
		switch (keyEvent.GetCode())
		{
		case VK_RIGHT:
			Player::playerPos.x += 5.0f;
			break;
		case VK_LEFT:
			Player::playerPos.x -= 5.0f;
			break;
		case VK_UP:
			Player::playerPos.y -= 5.0f;
			break;
		case VK_DOWN:
			Player::playerPos.y += 5.0f;
			break;
		}
	}
}

void Player::Draw()
{
}

Vec2 Player::GetPos()
{
	return playerPos;
}

