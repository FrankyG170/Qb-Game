#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Keyboard.h"
#include "StateManager.h"
#include "Graphics.h"

class Player
{
public:
	Player(StateManager::state* state_in)
		:
		state(state_in)
	{};
	virtual void MovePlayer() = 0;
	virtual void DrawPlayer() = 0;

protected:
	// Pointer to state machine variables
	StateManager::state* state;

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
	float shadedRectHeight = playerHeight / nShadedRectsDown;
	int nShadedRects = nShadedRectsAcross * nShadedRectsDown;
	RectF shadedRect;
	Color playerShadingC = Colors::MakeRGB(101, 25, 151);

	// Used to fill in to make facial expression
	float filledRectWidth = playerWidth / nShadedRectsAcross;
	float filledRectHeight = playerHeight / nShadedRectsDown;
	Color filledRectC = Colors::MakeRGB(0, 0, 0);
	RectF filledRect;
	int filledRectIndx[10] = {};
	// Standing still face expression
	static constexpr int filledRectIndx0[10] = { 7,10,19,20,21,22,26,27 };
	// Weird face (6 makes you go up 1 line.)
	static constexpr int filledRectIndx1[10] = { 6,11,19 - 6,20 - 6,21 - 6,22 - 6,26 - 6,27 - 6 };
	// Moving right face expression
	static constexpr int filledRectIndx2[10] = { 8, 11, 20, 21, 22, 23, 27, 28 };
	// Moving left face expression
	static constexpr int filledRectIndx3[10] = { 6, 9, 18, 19, 20, 21, 25, 26 };
	// Moving down face expression
	static constexpr int filledRectIndx4[10] = { 7 + 6,10 + 6,19 + 6,20 + 6,21 + 6,22 + 6,26 + 6,27 + 6 };
	// Moving up face expression
	static constexpr int filledRectIndx5[10] = { 7 - 6,10 - 6,19 - 6,20 - 6,21 - 6,22 - 6,26 - 6,27 - 6 };
};