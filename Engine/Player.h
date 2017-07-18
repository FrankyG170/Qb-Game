#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "PlayerState.h"

enum State
{
	MOVING_RIGHT,
	MOVING_LEFT,
	MOVING_UP,
	MOVING_DOWN,
	STANDING
};


class Player
{
public:
	// State Machine methods
	virtual void HandleInput(Keyboard::Event input);
	virtual void Update();
public:
	virtual ~Player() {}
public:
	Vec2 playerPos = Vec2(100.0f, 100.0f);
	static constexpr float speed = 2.5f;
	PlayerState* state_;

protected:
	// Used to make pinkish background for player
	Keyboard kbd;
	Color playerC = Colors::MakeRGB(179, 47, 252);
	static constexpr float playerWidth = 30.0f;
	static constexpr float playerHeight = 30.0f;

	// Used to make slighty darker rectangles for grid look
	static constexpr float padding = 0.5f;
	float nShadedRectsAcross = playerWidth / 5.0f;
	float nShadedRectsDown = playerHeight / 5.0f;
	float shadedRectWidth = playerWidth / nShadedRectsAcross;
	float shadedRectHeight = playerHeight / nShadedRectsDown;
	float nShadedRects = nShadedRectsAcross * nShadedRectsDown;
	RectF shadedRect;
	Color playerShadingC = Colors::MakeRGB(101, 25, 151);

	// Used to fill in to make facial expression
	float filledRectWidth = playerWidth / nShadedRectsAcross;
	float filledRectHeight = playerHeight / nShadedRectsDown;
	Color filledRectC = Colors::MakeRGB(0, 0, 0);
	RectF filledRect;
	int face[10] = {};
	static constexpr int faces[6][10] =
	{
		{ 7,10,19,20,21,22,26,27 },
		{ 6,11,19 - 6,20 - 6,21 - 6,22 - 6,26 - 6,27 - 6 },
		{ 8,11,20,21,22,23,27,28 },
		{ 6,9,18,19,20,21,25,26 },
		{ 7 + 6,10 + 6,19 + 6,20 + 6,21 + 6,22 + 6,26 + 6,27 + 6 },
		{ 7 - 6,10 - 6,19 - 6,20 - 6,21 - 6,22 - 6,26 - 6,27 - 6 }
	};
};