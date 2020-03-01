#pragma once
class Player
{
public:
	Player();
	~Player();
	int x, y, fruitX, fruitY, score;
	//array For positions
	int tailX[100], tailY[100];
	//tail counter
	int Ntail=1;
	bool Death;
	Directions dir;
	//GameUpdate
	void Logic()
	{
		Movement();
		EatFruit();
	}
private:
	void Movement();
	void SuicideCheck();
	void teleport();
	void EatFruit();
};

