/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "RectF.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(); 
	void Game::CopyArray(int A[], int B[]);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	// Used to make pinkish background for player
	Vec2 playerPos = Vec2(20, 20);
	Color playerC = Colors::MakeRGB(179, 47, 252);
	float playerWidth = 30.0f;
	float playerHeight = 30.0f;

	// Used to make slighty darker rectangles for grid look
	static constexpr float padding = 0.5f;
	float nShadedRectsAcross = playerWidth / 5.0f;
	float nShadedRectsDown = playerHeight / 5.0f;
	float shadedRectWidth = playerWidth / nShadedRectsAcross;
	float shadedRectHeight =  playerHeight / nShadedRectsDown;
	int nShadedRects = nShadedRectsAcross * nShadedRectsDown;
	RectF shadedRect;
	Color playerShadingC = Colors::MakeRGB(101, 25, 151);

	// Used to fill in to make facial expression
	float filledRectWidth = playerWidth / nShadedRectsAcross;
	float filledRectHeight = playerHeight / nShadedRectsDown;
	Color filledRectC = Colors::MakeRGB(0, 0, 0);
	RectF filledRect;
	/********************************/
};