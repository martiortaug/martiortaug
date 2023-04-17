#include <iostream>
#include <Windows.h>
#include "boat.h"

using namespace std;

//Game
string graphBoat = "[|||D>";
int lnCount = 0;
bool plWin = false;
bool cpuWin = false;
Boat player;
Boat cpu;

string gameIntro() {
	string plName;
	srand(time(0));
	cout << "Nitro League 2!!" << endl;
	cout << "Welcome to the most exciting boat race! Please insert your racer name:" << endl;
	cin >> plName;
	cout << "The race begins in..." << endl;
	Sleep(1000);
	cout << "3..." << endl;
	Sleep(1000);
	cout << "2..." << endl;
	Sleep(1000);
	cout << "1..." << endl;
	Sleep(1000);
	cout << "GO!!!" << endl;
	return plName;
}

bool askNitro(Boat& player) {
	if (player.getNitro()) {
		char choice;
		cout << "Use nitro? y/n" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			player.setNitro(false);
			return true;
		}
		else if (choice == 'n' || choice == 'N') {
			return false;
		}
		else {
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
			askNitro(player);
		}
	}
	return false;
}

void plTurn(Boat& player, int currentTurn) {
		int dieThrow = rand() % 6 + 1;
		player.setTurnDie(dieThrow);
		int preSpeed = player.getSpeed();
		int preDist = player.getDistance();
		cout << "Throwing the die";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << "." << endl;
		Sleep(500);
		player.accelerate(dieThrow);
		cout << "Player " << player.getName() << " got a " << dieThrow << "!!" << endl;
		Sleep(500);
		if (player.getType() == "H") {
			if (player.getNitro()) {
				if (askNitro(player)) {
					if (player.useNitro()) {
						Sleep(1500);
						cout << "NITRO SUCCESS! Speed is doubled!!" << endl;
						Sleep(1000);
					}
					else {
						cout << "NITRO FAIL! Speed is halved..." << endl;
						Sleep(1000);
					}
				}
			}
		}
		else {
			if (currentTurn >= 3 && plWin && player.getNitro()) {
				Sleep(500);
				cout << "Player " << player.getName() << " uses NITRO BOOST!" << endl;
				Sleep(1500);
				if (player.useNitro()) {
					cout << "NITRO SUCCESS! Speed is doubled!!" << endl;
					Sleep(1000);
				}
				else {
					cout << "NITRO FAIL! Speed is halved..." << endl;
					Sleep(1000);
				}
			}
		}
		int distAdv = player.boatDistance();
		cout << "Player " << player.getName() << "'s new speed is " << player.getSpeed() << endl;
		Sleep(1500);
		cout << "Player " << player.getName() << "'s boat advances " << distAdv << "m!!" << endl;
		Sleep(1500);
		cout << "Player " << player.getName() << "'s total distance is " << player.getDistance() << endl;
		Sleep(3500);
		
}

void boatGraphics(Boat player) {
	cout << "\n\n";
	int preDist = player.getSpeed() - player.getTurnDie();
	if (player.getType() == "H") {
		cout << "YOU\n";
	}
	else {
		cout << player.getName() << "\n";
	}
	if (preDist > 0) {
		for (int i = 0; i < preDist; i++) {
			cout << "===";
		}
	}
	for (int i = 0; i < player.getTurnDie(); i++) {
		for (int j = i; j >= 0; j--) {
			cout << "===";
		}
		cout << graphBoat << endl;
		cout << "\033[A"; //Mover cursor una línea hacia arriba
		if (preDist > 0) {
			for (int j = 0; j < preDist+i; j++) {
				cout << "\033[C\033[C\033[C"; //Desplazar cursor 3 veces hacia la derecha
			}
		}					
		Sleep(500);
	}
	cout << endl;
}


int main()
{	
	//Player 1
	string plName = gameIntro();
	string cpuName = "Typhoon";

	//Objects
	Boat plBoat(plName, 0, 0, true, "H", 0);
	Boat cpuBoat(cpuName, 0, 0, true, "M", 0);
	player = plBoat;
	cpu = cpuBoat;

	for (int i = 1; i <= 5; i++) {
		cout << "\n\nTURN " << i << "\n";
		cout << "\nYour turn." << endl;
		Sleep(500);
		plTurn(plBoat,i);
		cout << "\nCPU turn." << endl;
		Sleep(500);
		plTurn(cpuBoat,i);
		boatGraphics(plBoat);
		boatGraphics(cpuBoat);

		if (player.getDistance() > cpu.getDistance()) {
			plWin = true;
			cpuWin = false;
		}
		else {
			plWin = false;
			cpuWin = true;
		}
	}

	if (plWin) {
		Sleep(1500);
		cout << "\n\nYou won!!" << endl;
		Sleep(1500);
		cout << "Thanks for playing :) \nGAME OVER." << endl;
	}
	else {
		Sleep(1500);
		cout << "\n\nYou lost..." << endl;
		Sleep(1500);
		cout << "Thanks for playing :) \nGAME OVER." << endl;
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
