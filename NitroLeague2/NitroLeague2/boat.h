#pragma once
#include <iostream>
using namespace std;

class Boat
{
private:
	string name;
	int speed;
	int distance;
	bool nitro;
	string type;
	int turnDie;
public:

	//constructor
	Boat();
	Boat(string pName, int pSpeed, int pDistance, bool pNitro, string pType, int pTurnDie);

	//getters
	string getName();
	int getSpeed();
	int getDistance();
	bool getNitro();
	string getType();
	int getTurnDie();

	//setters
	void setName(string pName);
	void setSpeed(int pSpeed);
	void setDistance(int pDistance);
	void setNitro(bool pNitro);
	void setType(string pType);
	void setTurnDie(int pTurnDie);

	//metodos propios
	void printStatus();
	void accelerate(int die);

	int boatDistance();

	bool useNitro();

};