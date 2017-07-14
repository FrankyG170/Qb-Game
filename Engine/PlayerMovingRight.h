#pragma once
#include "Player.h"

class PlayerMovingRight : public Player
{
public:
	PlayerMovingRight() = default;
	virtual void MovePlayer(Vec2& position);
	virtual void DrawPlayer(Vec2& position, float height, float width, Color& color, int* drawIndex);

public:
};

