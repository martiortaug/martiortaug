#include "boat.h"
#include <iostream>

using namespace std;
	//constructor
	Boat::Boat() {
	}

	Boat::Boat(string pName, int pSpeed, int pDistance, bool pNitro, string pType, int pTurnDie) {
		name = pName;
		speed = pSpeed;
		distance = pDistance;
		nitro = pNitro;
		type = pType;
		turnDie = pTurnDie;
	}

	//getters

	std::string Boat::getName() {
		return name;
	}

	int Boat::getSpeed() {
		return speed;
	}

	int Boat::getDistance() {
		return distance;
	}

	bool Boat::getNitro() {
		return nitro;
	}
	
	string Boat::getType() {
		return type;
	}

	int Boat::getTurnDie() {
		return turnDie;
	}


	//setters

	void Boat::setName(string pName) {
		name = pName;
	}

	void Boat::setSpeed(int pSpeed) {
		speed = pSpeed;
	}

	void Boat::setDistance(int pDistance) {
		distance = pDistance;
	}

	void Boat::setNitro(bool pNitro) {
		nitro = pNitro;
	}

	void Boat::setType(string pType) {
		type = pType;
	}

	void Boat::setTurnDie(int pTurnDie) {
		turnDie = pTurnDie;
	}


	//Metodos propios

	void Boat::printStatus() {
		cout << "El nombre del enemigo es " << getName() << ", tiene una velocidad de " << getSpeed() << std::endl;
	}

	void Boat::accelerate(int die) {
		int acceleration = die;
		setSpeed(getSpeed() + acceleration);
	}

	int Boat::boatDistance() {
		int newDist = getSpeed() * 100;
		setDistance(getDistance() + newDist);
		return newDist;
	}

	bool Boat::useNitro() {
		int luck = rand() % 2;
		if (luck == 0) {
			setSpeed(getSpeed() / 2);
			setNitro(false);
			return false;
		}
		else {
			setSpeed(getSpeed() * 2);
			setNitro(false);
			return true;
		}		
	}