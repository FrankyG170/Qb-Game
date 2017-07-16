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
	switch (keyEvent.GetCode())
	{
	case VK_RIGHT:
		playerPos.x += 5.0f;
		break;
	case VK_LEFT:
		playerPos.x -= 5.0f;
		break;
	case VK_UP:
		playerPos.y -= 5.0f;
		break;
	case VK_DOWN:
		playerPos.y += 5.0f;
		break;
	}
}

void Player::Draw()
{
}

