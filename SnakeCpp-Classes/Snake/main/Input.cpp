#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

void Input::SetInput(Directions & dir)
{
	//keyboard input check
	if (_kbhit())
	{
		//check char
		switch (_getch())
		{
		case 'a':if(dir!=RIGHT)
			dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT)
			dir = RIGHT;
			break;
		case 'w':if (dir != DOWN)
			dir = UP;
			break;
		case 's':if (dir != UP)
			dir = DOWN;
			break;
		//case 'x':GameOver = true;
		default:
			break;
		}
	}
}
