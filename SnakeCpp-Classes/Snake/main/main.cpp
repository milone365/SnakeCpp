#include "pch.h"
#include"Graphic.h"
#include"Player.h"
#include"Input.h"


using namespace std;

int main()
{
	Graphic graph;
	Input input;
	Player player;
	while (!player.Death)
	{
		input.SetInput(player.dir);
		player.Logic();
		graph.Draw(&player);
		Sleep(20);
	}
	return 0;
}







