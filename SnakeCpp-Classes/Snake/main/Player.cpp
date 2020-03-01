#include "pch.h"
#include "Player.h"


Player::Player()
{
	x = MapWidth / 2;
	y = MapHeight / 2;
	Ntail = 0;
	fruitX = rand() % MapWidth;
	fruitY = rand() % MapHeight;
	Death = false;
	dir = STOP;
    score = 0;
}


Player::~Player()
{
}


//
void Player::Movement()
{

	int prevX = tailX[0];
	int prevY = tailY[0];
	//follow the head
	tailX[0] = x;
	tailY[0] = y;
	//store value of first element (x,y)

	//next element
	int tempX, tempY;
	for (int i = 1; i < Ntail; i++)
	{
		tempX = tailX[i];
		tempY = tailY[i];
		//became like first element
		tailX[i] = prevX;
		tailY[i] = prevY;
		//nexelemt change like this
		prevX = tempX;
		prevY = tempY;
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
	if (x > MapWidth-1 || x<0 || y>MapHeight-1 || y < 0)
	{
		Death = true;
	}
	//teleport();
	SuicideCheck();
}
void Player:: SuicideCheck()
{
	for (int i = 0; i < Ntail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			Death = true;
		}
	}
}
//pass throw the wall
void Player:: teleport()
{
	if (x >= MapWidth)x = 0;
	else if (x < 0)x = MapWidth - 1;
	if (y > MapHeight)y = 0;
	else if (y < 0) y = MapHeight - 1;
}
//eat fruit check,add score and respawn fruit
void Player::EatFruit()
{
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		Ntail++;
		fruitX = rand() % MapWidth;
		fruitY = rand() % MapHeight;
	}
}