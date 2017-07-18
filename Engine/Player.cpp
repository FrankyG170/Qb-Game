#include "Player.h"
#define MY_KEY 10

/*void Player::Update(Keyboard::Event& keyEvent, Keyboard& kbd)
{
	// Move( keyEvent );
	if (kbd.KeyIsPressed(VK_UP)) // Up moving state
	{
		playerPos.y -= speed;
		FaceSwap(5);
	}
	else if (kbd.KeyIsPressed(VK_DOWN)) // Down moving state
	{
		playerPos.y += speed;
		FaceSwap(4);
	}
	else if (kbd.KeyIsPressed(VK_LEFT)) // Left moving state
	{
		playerPos.x -= speed;
		FaceSwap(3);
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) // Right moving state
	{
		playerPos.x += speed;
		FaceSwap(2);
	}
	else // Neutral state
	{
		FaceSwap(0);
	}	
}


/// Not Used
void Player::Move(Keyboard::Event& keyEvent)
{
	switch (keyEvent.GetCode())
	{
	case VK_RIGHT:
		playerPos.x += speed;
		break;
	case VK_LEFT:
		playerPos.x -= speed;
		break;
	case VK_UP:
		playerPos.y -= speed;
		break;
	case VK_DOWN:
		playerPos.y += speed;
		break;
	}
}

void Player::Draw(Graphics& gfx)
{
	while (playerPos.x <= 0)
		++playerPos.x;
	while (playerPos.x >= gfx.ScreenWidth)
		--playerPos.x;
	while (playerPos.y <= 0)
		++playerPos.y;
	while (playerPos.y >= gfx.ScreenHeight)
		--playerPos.y;
	gfx.DrawRect(RectF(playerPos, playerWidth, playerHeight), playerC);

	const Vec2 topLeft = playerPos + Vec2(0.5f, 0.5f);

	{ // Code block will destroy itself at end of run, frees up memory
	int i = 0; // Tracks for entire loop to see how many rects are left to be place
	int z = 0; // Tracks for filled squares to see which spots should be filled

		for (int y = 0; y < nShadedRectsDown; y++)
		{
			for (int x = 0; x < nShadedRectsAcross; x++)
			{
				// Shaded Rectangle
				shadedRect = RectF(topLeft + Vec2(x * shadedRectWidth, y * shadedRectHeight), shadedRectWidth, shadedRectHeight);
				// New Vec for the filled black rect to use
				const Vec2 shadedTopLeft = topLeft + Vec2(x * shadedRectWidth, y * shadedRectHeight);
				// Black Rectangle
				filledRect = RectF(shadedTopLeft, filledRectWidth, filledRectHeight);
				if (i < nShadedRects && i != face[z]) // Draw shaded rect
				{
					gfx.DrawRect(shadedRect.GetExpanded(-padding), playerShadingC);
				}
				else if (i == face[z]) // Draw filled rect
				{
					gfx.DrawRect(filledRect.GetExpanded(-padding), filledRectC);
					z++;
				}
				i++;
			}

		}
	}
}

void Player::FaceSwap(int newFace)
{
	for (int i = 0; i < 10; i++)
	{
		face[i] = faces[newFace][i];
	}
}*/

void Player::HandleInput(Keyboard::Event input)
{
	PlayerState* state = state_->HandleInput(*this, input);
	if (state != NULL) 
	{

	}
}

void Player::Update()
{
	state_->Update(*this);
}
