#pragma once

class StateManager
{
	void Update()
	{
		switch (l_state)
		{
		case state::idle:
			// Call idle functions
			break;
		case state::left:
			// Call left functions
			break;
		case state::right:
			// Call right functions
			break;
		case state::up:
			// Call up functions
			break;
		case state::down:
			// Call down functions
			break;
		};
	}

public:
	enum class state { idle = 0, right = 1, left = 2, down = 3, up = 4 };
	state l_prevState;
	state l_state;  // local var that represents our state
};