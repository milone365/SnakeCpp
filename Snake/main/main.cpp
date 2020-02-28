#include "pch.h"
#include <iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;
bool GameOver;
const int width = 20; 
const int height = 20;

//array For positions
int tailX[100], tailY[100];
//tail counter
int Ntail;
int x, y, fruitX, fruitY, score;
enum Directions { STOP = 0, LEFT, RIGHT, UP, DOWN };
Directions dir;

//functions
void Draw();
void Setup();
void Input();
void Logic();
void Movement();
void EatFruit();
void SuicideCheck();
void teleport();

int main()
{
	Setup();
	while (!GameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(20);
	}
	return 0;
}

//start
void Setup()
{
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

//graphic
void Draw()
{
	system("cls");//clear
	//draw  first border line
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			//draw snake
			if (i == y && j == x)
			{
				cout << "*";
			}
			//draw fruit
			else if (i == fruitY && j == fruitX)
			{
				cout << "o";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < Ntail; k++) 
				{
					
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "*";
						print = true;
					}
					
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score;
}

//player Controller & gameExit
void Input()
{
	//keyboard input check
	if (_kbhit())
	{
		//check char
		switch (_getch())
		{
		case 'a':dir = LEFT;
			break;
		case 'd':dir = RIGHT;
			break;
		case 'w':dir = UP;
			break;
		case 's':dir = DOWN;
			break;
		case 'x':GameOver = true;
		default:
			break;
		}
	}
}

//GameUpdate
void Logic()
{
	Movement();
	EatFruit();
}

//
void Movement()
{
	//follow the head
	tailX[0] = x;
	tailY[0] = y;
	//store value of first element (x,y)
	int prevX = tailX[0];
	int prevY = tailY[0];
	
	//next element
	int prev2X, prev2Y;
	for (int i = 1; i < Ntail; i++) 
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		//became like first element
		tailX[i] = prevX;
		tailY[i] = prevY;
		//nexelemt change like this
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if go out of border game over
	if (x > width || x<0 || y>height || y < 0)
	{
		GameOver = true;
	}
	//teleport();
	SuicideCheck();
}

//eat fruit check,add score and respawn fruit
void EatFruit()
{
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		Ntail++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}
//
void SuicideCheck() 
{
	for (int i = 0; i < Ntail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			GameOver = true;
		}
	}
}
//pass throw the wall
void teleport()
{
	if (x >= width)x = 0;
	else if (x < 0)x = width - 1;
	if (y > height)y = 0;
	else if (y < 0) y = height - 1;
}