#include "personaje.h"
#include <iostream>

using namespace std;

//constructor
Personaje::Personaje() {
}

Personaje::Personaje(string pName,
	int pLvl,
	int pHp,
	int pMp,
	int pAtk,
	int pDef,
	int pSpec,
	int pPosX,
	int pPosY,
	string pType,
	bool pIsAlive) {
		name = pName;
		lvl = pLvl;
		hp = pHp;
		mp = pMp;
		atk = pAtk;
		def = pDef;
		spec = pSpec;
		posX = pPosX;
		posY = pPosY;
		type = pType;
		isAlive = pIsAlive;
}





//getters

string Personaje::getName() {
	return name;
}

int Personaje::getLvl() {
	return lvl;
}

int Personaje::getHp() {
	return hp;
}

int Personaje::getMp() {
	return mp;
}

int Personaje::getAtk() {
	return atk;
}

int Personaje::getDef() {
	return def;
}

int Personaje::getSpec() {
	return spec;
}

int Personaje::getPosX() {
	return posX;
}

int Personaje::getPosY() {
	return posY;
}

string Personaje::getType() {
	return type;
}

bool Personaje::getIsAlive() {
	return isAlive;
}


//setters

void Personaje::setName(string pName) {
	name = pName;
}

void Personaje::setLvl(int pLvl) {
	lvl = pLvl;
}

void Personaje::setHp(int pHp) {
	hp = pHp;
}

void Personaje::setMp(int pMp) {
	mp = pMp;
}

void Personaje::setAtk(int pAtk) {
	atk = pAtk;
}

void Personaje::setDef(int pDef) {
	def = pDef;
}

void Personaje::setSpec(int pSpec) {
	spec = pSpec;
}

void Personaje::setPosX(int pPosX) {
	posX = pPosX;
}

void Personaje::setPosY(int pPosY) {
	posY = pPosY;
}

void Personaje::setType(string pType) {
	type = pType;
}

void Personaje::setIsAlive(bool pIsAlive) {
	isAlive = pIsAlive;
}


//Metodos propios

void Personaje::printStatus() {
	cout << 
		"\nName: " << getName() << "\n" <<
		"Level: " << getLvl() << "\n" <<
		"HP: " << getHp() << "\n" <<
		"MP: " << getMp() << "\n" <<
		"Attack: " << getAtk() << "\n" <<
		"Defense: " << getDef() << "\n" << 
		"Special: " << getSpec() << "\n" << endl;
}

/*
void Personaje::accelerate(int die) {
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
*/


EnemigoFinal::EnemigoFinal(string pName, int pLvl, int pHp, int pMp, int pAtk, int pDef, int pSpec, int pPosX, int pPosY, string pType, bool pIsAlive, int pFireAttack, int pFrozenAttack)
    : Personaje(pName, pLvl, pHp, pMp, pAtk, pDef, pSpec, pPosX, pPosY, pType, pIsAlive)
{
    fireAttack = pFireAttack;
    frozenAttack = pFrozenAttack;
}


//Getters
int EnemigoFinal::getFireAttack() {
	return fireAttack;
}
int EnemigoFinal::getFrozenAttack() {
	return frozenAttack;
}

//setters
void EnemigoFinal::setFireAttack(int pFireAttack) {
	fireAttack = pFireAttack;
}
void EnemigoFinal::setFrozenAttack(int pFrozenAttack) {
	frozenAttack = pFrozenAttack;
}