#include <iostream>
#include <Windows.h>
#include "boat.h"

using namespace std;

//Game
string graphBoat = "[|||D>";
int lnCount = 0;
bool plWin = false;
bool cpuWin = false;

string gameIntro() {
	string plName;
	srand(time(0));
	PlaySound(TEXT("start.wav"), NULL, SND_ASYNC);
	cout << "\n\t\t\033[36m******************************";
	cout << "\n\t\t*\t\t\t     *";
	cout << "\n\t\t*\t\033[37mNITRO LEAGUE 2\033[36m\t     *";
	cout << "\n\t\t*\t\t\t     *";
	cout << "\n\t\t******************************\033[37m";
	cout << "\n\nWelcome to Nitro League 2, the most exciting boat race!\nPlease insert your racer name:" << endl;


	cin >> plName;
	cout << "The race begins in..." << endl;
	Sleep(1000);
	cout << "3..." << endl;
	Beep(400, 700);
	cout << "2..." << endl;
	Beep(400, 700);
	cout << "1..." << endl;
	Beep(400, 700);
	cout << "GO!!!" << endl;
	Beep(800, 1500);

	return plName;
}

bool askNitro(Boat& player) {
	if (player.getNitro()) {
		char choice;
		cout << "\033[35mUse nitro?\033[37m y/n" << endl;
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
						cout << "\033[32mNITRO SUCCESS!\033[37m Speed is doubled!!" << endl;
						Sleep(1000);
					}
					else {
						cout << "\033[31mNITRO FAIL!\033[37m Speed is halved..." << endl;
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
					cout << "\033[32mNITRO SUCCESS!\033[37m Speed is doubled!!" << endl;
					Sleep(1000);
				}
				else {
					cout << "\033[31mNITRO FAIL!\033[37m Speed is halved..." << endl;
					Sleep(1000);
				}
			}
		}
		int distAdv = player.boatDistance();
		cout << "Player " << player.getName() << "'s new speed is " << player.getSpeed() << endl;
		Sleep(1500);
		cout << "Player " << player.getName() << "'s boat advances " << distAdv << "m!!" << endl;
		Sleep(1500);
		cout << "Player " << player.getName() << "'s total distance is " << player.getDistance() << "m." << endl;
		Sleep(3500);
		
}


void boatGraphics(Boat player) {
	cout << "\n\n";
	int preDist = player.getSpeed() - player.getTurnDie();
	if (preDist > 28) {
		preDist = 20;
	}
	if (player.getType() == "H") {
		cout << "\033[42m\033[37mYOU\033[40m\n";
	}
	else {
		cout << "\033[41m\033[30m" << player.getName() << "\033[40m\033[37m\n";
	}
	if (preDist > 0) {
		for (int i = 0; i < preDist; i++) {
			cout << "\033[34m===\033[37m";
		}
	}
	for (int i = 0; i < player.getTurnDie(); i++) {
		for (int j = i; j >= 0; j--) {
			cout << "\033[34m===\033[37m";
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
	PlaySound(TEXT("race.wav"), NULL, SND_LOOP | SND_ASYNC);
	for (int i = 1; i <= 5; i++) {
		cout << "\033[2J\033[H"; // Borrar pantalla y poner cursor al principio
		cout << "\n\t\t\033[33m**************" << endl;
		cout << "\t\t*   ROUND " << i << "  *" << endl;
		cout << "\t\t**************" << endl;
		cout << "\n\033[42m\033[37mYour turn.\033[40m" << endl;
		Sleep(500);
		plTurn(plBoat,i);
		cout << "\n\033[41m\033[30mCPU turn.\033[40m\033[37m" << endl;
		Sleep(500);
		plTurn(cpuBoat,i);
		boatGraphics(plBoat);
		boatGraphics(cpuBoat);

		if (plBoat.getDistance() > cpuBoat.getDistance()) {
			plWin = true;
			cpuWin = false;
		}
		else if (plBoat.getDistance() < cpuBoat.getDistance()) {
			plWin = false;
			cpuWin = true;
		}
		else {
			plWin = false;
			cpuWin = false;
		}
	}

	if (plWin && !cpuWin) {		
		Sleep(1500);
		cout << "\033[2J\033[H";
		cout << "\n\n\033[42m\033[30mYou won!!\033[40m\033[37m" << endl;
		Sleep(1500);
		cout << "Thanks for playing :) \nGAME OVER." << endl;
		PlaySound(TEXT("samus.wav"), NULL, SND_SYNC);

	}
	else if (!plWin && cpuWin) {		
		Sleep(1500);
		cout << "\033[2J\033[H";
		cout << "\n\n\033[41m\033[30mYou lost...\033[40m\033[37m" << endl;
		Sleep(1500);
		cout << "Thanks for playing :) \nGAME OVER." << endl;
		PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);

	}
	else if (!plWin && !cpuWin) {		
		Sleep(1500);
		cout << "\033[2J\033[H";
		cout << "\n\n\033[43m\033[30mIt's a draw!\033[40m\033[37m" << endl;
		Sleep(1500);
		cout << "Thanks for playing :) \nGAME OVER." << endl;
		PlaySound(TEXT("draw.wav"), NULL, SND_SYNC);
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
