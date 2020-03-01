#include "pch.h"
#include "Graphic.h"
using namespace std;

Graphic::Graphic()
{
}


Graphic::~Graphic()
{
}
 void Graphic:: Draw(Player* player)
{
	system("cls");//clear
				  //draw  first border line
	for (int i = 0; i < MapWidth + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	///i
	for (int i = 0; i < MapHeight; i++)
	{
		//j
		for (int j = 0; j < MapWidth; j++)
		{
			//tate no kabe
			if (j == 0)
			{
				cout << "#";
			}
			if (j == MapWidth - 1)
			{
				cout << "#";
			}
			//draw snake atama
			if (i == player->y && j == player->x)
			{
				cout << "*";
			}
			//draw fruit
			else if (i == player->fruitY && j == player->fruitX)
			{
				cout << "o";
			}
			else
			{
				bool print = false;
				//nagasa kakunin
				for (int k = 0; k < player-> Ntail; k++)
				{

					if (player->tailX[k] == j && player->tailY[k] == i)
					{
						cout << "*";
						print = true;
					}

				}
				if (!print)
					cout << " ";
				
			}
			
			
		}
		cout << endl;
	}
	for (int i = 0; i < MapWidth + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << player->score;
}
