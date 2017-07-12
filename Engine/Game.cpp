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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
	gfx.DrawRect(RectF(playerPos, playerWidth, playerHeight), playerC);
	
	const Vec2 topLeft = playerPos + Vec2(0.5f, 0.5f);

	// int filledRectIndx[50] = { 46, 52, 56, 58, 62, 64, 66, 70, 72, 76, 144, 152, 156, 157, 161, 162, 167, 168, 169, 170, 171, 172, 173, 179, 180, 181, 182, 183, 190, 191, 192, 193, 194, 202, 203, 204, 214 }; // Location of squears to be filled

	int filledRectIndx[10] = { };

	if (wnd.kbd.KeyIsEmpty())
	{
		int newFilledRectIndx [10] = { 7, 10, 19, 20, 21, 22, 26, 27 };
		for (int i = 0; i < 10; i++)
		{
			filledRectIndx[i] = newFilledRectIndx[i];
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_LSHIFT)) // Does not work, pressing shift breaks face, ow
	{
		 int newFilledRectIndx[10] = { 7, 10, 19, 21, 23, 24, 26, 28 };
		 for (int i = 0; i < 10; i++)
		 {
			 filledRectIndx[i] = newFilledRectIndx[i];
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
			else if (i == filledRectIndx[z] && wnd.kbd.KeyIsEmpty()) // Draw filled rect
			{
				gfx.DrawRect(filledRect.GetExpanded(-padding), filledRectC);
				z++;
			}
			i++;
		}
			
	}
	
	
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