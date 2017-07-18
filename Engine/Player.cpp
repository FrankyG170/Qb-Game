#include "Player.h"

void Player::HandleInput(Keyboard::Event input)
{
	PlayerState* state = state_->HandleInput(*this, input);
	if (state != NULL) 
	{
		delete state_;
		state_ = state;
	}
}

void Player::Update()
{
	state_->Update(*this);
}
