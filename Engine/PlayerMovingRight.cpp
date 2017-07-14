#include "PlayerMovingRight.h"


void PlayerMovingRight::MovePlayer(Vec2 & position)
{
	position.x += 5.0f;
	*state = StateManager::state::right;
}

void PlayerMovingRight::DrawPlayer(Vec2 & position, float height, float width, Color & color, int* drawIndex)
{
	//gfx.DrawRect(RectF(position, width, height), color);

	const Vec2 topLeft = position + Vec2(0.5f, 0.5f);

	for (int i = 0; i < 10; i++)
	{
		filledRectIndx[i] = drawIndex[i];
	}
}
