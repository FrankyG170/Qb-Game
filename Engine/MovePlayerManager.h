#pragma once
#include "Player.h"

class MovePlayerManager : public Player
{
	Movement m_Movement = Movement::None;
public:
	MovePlayerManager() = default;
	~MovePlayerManager() override = default;
	void MovePlayer() { if (m_MovePlayerManager != nullptr) { m_Movement = Movement::Right; } }
};

