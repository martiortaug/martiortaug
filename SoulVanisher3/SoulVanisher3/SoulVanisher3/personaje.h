#pragma once
#include <iostream>
using namespace std;

class Personaje
{
private:
	string name;
	int lvl;
	int hp;
	int mp;
	int atk;
	int def;
	int spec;
	int posX;
	int posY;
	string type;
	bool isAlive;
public:

	//constructor
	Personaje();
	Personaje(string pName, int lvl, int pHp, int pMp, int pAtk, int pDef, int pSpec, int pPosX, int pPosY, string pType, bool pIsAlive);

	//getters
	string getName();
	int getLvl();
	int getHp();
	int getMp();
	int getAtk();
	int getDef();
	int getSpec();
	int getPosX();
	int getPosY();
	string getType();
	bool getIsAlive();

	//setters
	void setName(string pName);
	void setLvl(int pLvl);
	void setHp(int pHp);
	void setMp(int pMp);
	void setAtk(int pAtk);
	void setDef(int pDef);
	void setSpec(int pSpec);
	void setPosX(int pPosX);
	void setPosY(int pPosY);
	void setType(string pType);
	void setIsAlive(bool pIsAlive);

	//metodos propios
	void printStatus();

	/*
	void accelerate(int die);

	int boatDistance();

	bool useNitro();
	*/
};

class EnemigoFinal : public Personaje
{
private:
	int fireAttack;
	int frozenAttack;
public:
	EnemigoFinal(
		string pName,
		int pLvl,
		int pHp,
		int pMp,
		int pAtk,
		int pDef,
		int pSpec,
		int pPosX,
		int pPosY,
		string pType,
		bool pIsAlive,
		int pFireAttack,
		int pFrozenAttack);


	//getters
	int getFireAttack();
	int getFrozenAttack();

	//setters
	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);
};