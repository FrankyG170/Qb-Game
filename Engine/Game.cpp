/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	DrawPlayer();
	MovePlayer();
}

void Game::ComposeFrame()
{

}

void Game::CopyArray(int* A, int* B)
{
	for (int i = 0; i < (sizeof(A) / sizeof(*A)); i++)
	{
		B[i] = A[i];
	}
}

void Game::MovePlayer()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		playerPos.x += 5.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		playerPos.x -= 5.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		playerPos.y -= 5.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		playerPos.y += 5.0f;
	}
}

void Game::DrawPlayer()
{
	gfx.DrawRect(RectF(playerPos, playerWidth, playerHeight), playerC);

	const Vec2 topLeft = playerPos + Vec2(0.5f, 0.5f);


	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) // Funny face
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx1[i];
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) // Right moving state
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx2[i];
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) // Left moving state
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx3[i];
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) // Down moving state
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx4[i];
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP)) // Up moving state
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx5[i];
		}
	}
	else // Neutral state
	{
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = filledRectIndx0[i];
		}
	}

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
			if (i < nShadedRects && i != filledRectIndx[z]) // Draw shaded rect
			{
				gfx.DrawRect(shadedRect.GetExpanded(-padding), playerShadingC);
			}
			else if (i == filledRectIndx[z]) // Draw filled rect
			{
				gfx.DrawRect(filledRect.GetExpanded(-padding), filledRectC);
				z++;
			}
			i++;
		}

	}
}