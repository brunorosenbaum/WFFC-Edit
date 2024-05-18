#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool rotRight;
	bool rotLeft;

	//Mouse
	int mouse_X;
	int mouse_Y;
	bool mouse_LB_Down;

	//Selection
	bool isTabDown; 

	void InitValues()
	{
		mouse_X = 0; mouse_Y = 0;
		mouse_LB_Down = false;

		isTabDown = false; 

		forward = 0;
		back = 0;
		right = 0;
		left = 0;
		rotLeft = 0;
		rotRight = 0; 
	}

	
};
