// Blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;


//Player
string plName;
int bank = 1000;
int tempBet;
int totalLoss;
int totalGains;
int plPoints;
int optSelect;
bool plWin = false;
bool bust = false;

//Dealer
string dlName = "Martino";
int dlPoints;
bool dlWin = false;
bool hideFirstCard;
bool showHiddenCard;
int shownCard, shownCardValue;
int hiddenCard, hiddenCardValue, hiddenSuit;


//Game
const int suit = 4;
const int card = 13;
const char* signs = "\3 \4 \5 \6";
int deck[suit][card];
int cardCount = 52;

void initializeDeck() {
	if (cardCount >= 52) {
		cout << "Shuffling the deck";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".\n";
		for (int i = 0; i < suit; i++) {
			for (int j = 0; j < card; j++) {
				deck[i][j] = 1;
			}
		}
		cardCount = 0;
	}
}

void placeBet(int& amountBank, int& amountBet) {
	bool playerHasBet = false;
	int bet;
		do {
			if (amountBank > 0) {
				cout << "Please select amount to bet:\n";
				cout << "1. 25 eur\n";
				cout << "2. 50 eur\n";
				cout << "3. 125 eur\n";
				cout << "4. 500 eur\n";
				cout << "5. ALL IN\n";
				cin >> bet;
				switch (bet) {
				case 1:
					if (amountBank < 25) {
						cout << "You don't have enough credit!\n";
						break;
					}
					else {
						amountBet = 25;
						cout << "Bank: " << amountBank << " - " << amountBet << "\n";
						cout << "Bank: " << amountBank - amountBet << "\n";
						amountBank = amountBank - amountBet;
						playerHasBet = true;
					}
					break;
				case 2:
					if (amountBank < 50) {
						cout << "You don't have enough credit!\n";
						break;
					}
					else {
						amountBet = 50;
						cout << "Bank: " << amountBank << " - " << amountBet << "\n";
						cout << "Bank: " << amountBank - amountBet << "\n";
						amountBank = amountBank - amountBet;
						playerHasBet = true;
					}
					break;
				case 3:
					if (amountBank < 125) {
						cout << "You don't have enough credit!\n";
						break;
					}
					else {
						amountBet = 125;
						cout << "Bank: " << amountBank << " - " << amountBet << "\n";
						cout << "Bank: " << amountBank - amountBet << "\n";
						amountBank = amountBank - amountBet;
						playerHasBet = true;
					}
					break;
				case 4:
					if (amountBank < 500) {
						cout << "You don't have enough credit!\n";
						break;
					}
					else {
						amountBet = 500;
						cout << "Bank: " << amountBank << " - " << amountBet << "\n";
						cout << "Bank: " << amountBank - amountBet << "\n";
						amountBank = amountBank - amountBet;
						playerHasBet = true;
					}
					break;
				case 5:
					amountBet = amountBank;
					cout << "Bank: " << amountBank << " - " << amountBet << "\n";
					cout << "Bank: " << amountBank - amountBet << "\n";
					amountBank = amountBank - amountBank;
					playerHasBet = true;
					break;
				default:
					cout << "Invalid selection.\n";
					break;
				}
			}
		} while (!playerHasBet);
	}

void showDrawnCard(string player, int card, int cardValue, int suit) {
	// Normal show
	if (!showHiddenCard) {
		if (player == dlName) {
			cout << "The house has drawn a";
		}
		else {
			cout << "The player " << player << " has drawn a";
		}
	}
	// Reveal house first card
	else {
		cout << "The house reveals its first card:";
		Sleep(1000);
		showHiddenCard = false;
	}
	if (player == dlName && hideFirstCard) {
		cout << " card.\n";
	}
	else {
		if (card == 0 || card > 10) {
			string cardJQK;
			if (card == 11) {
				cardJQK = " J";
				cout << cardJQK;
			}
			else if (card == 12) {
				cardJQK = " Q";
				cout << cardJQK;
			}
			else if (card == 13) {
				cardJQK = " K";
				cout << cardJQK;
			}
			else if (card == 0) {
				cardJQK = " Ace";
				cout << cardJQK;
			}
			switch (suit) {
			case 0:
				cout << "\3 " << "(" << cardJQK << " of hearts).\n";
				break;
			case 1:
				cout << "\4 " << "(" << cardJQK << " of diamonds).\n";
				break;
			case 2:
				cout << "\5 " << "(" << cardJQK << " of clovers).\n";
				break;
			case 3:
				cout << "\6 " << "(" << cardJQK << " of spades).\n";
				break;
			}
		}
		else {
			cout << " " << cardValue;
			switch (suit) {
			case 0:
				cout << "\3 " << "(" << cardValue << " of hearts).\n";
				break;
			case 1:
				cout << "\4 " << "(" << cardValue << " of diamonds).\n";
				break;
			case 2:
				cout << "\5 " << "(" << cardValue << " of clovers).\n";
				break;
			case 3:
				cout << "\6 " << "(" << cardValue << " of spades).\n";
				break;
			}
		}
	}
}

bool drawCards(int& totalPoints, string player, bool win) {
	int randomSuit = rand() % suit;
	int randomCard = rand() % card;

	// TEST ACE
	/*
	randomSuit = 0;
	randomCard = 0;
	*/
	

	if (deck[randomSuit][randomCard] == 0) {
		for (int i = 0; i < (card * suit); i++) {
			while (deck[randomSuit][randomCard] == 0) {
				randomSuit = rand() % suit;
				randomCard = rand() % card;
			}
			initializeDeck();
			if (deck[randomSuit][randomCard] != 0) {
				break;
			}
		}
	}

	int randomCardValue = randomCard + 1;

	// Defines value of J, Q, K
	if (randomCardValue > 10) {
		randomCardValue = 10;
	}

	// Defines value of Ace
	if (randomCard == 0) {
		if (totalPoints + 11 > 21) {
			randomCardValue = 1;
		}
		else {
			randomCardValue = 11;
		}
	}

	

	deck[randomSuit][randomCard] = 0;
	cardCount++;
	totalPoints += randomCardValue;

	if (!hideFirstCard) {
		shownCardValue = randomCardValue;
		shownCard = randomCard;
	}
	else {
		hiddenCard = randomCard;
		hiddenCardValue = randomCardValue;
		hiddenSuit = randomSuit;
	}

	// Show drawn card
	showDrawnCard(player,randomCard,randomCardValue,randomSuit);

	Sleep(2600);

	if (totalPoints == 21) {
		Sleep(1000);
		cout << "\n21 BLACKJACK\n\n";
		Sleep(1000);
		win = true;
	}

	if (totalPoints > 21) {
		Sleep(1000);
		cout << "\nBUST\n\n";
		Sleep(1000);
		return true;
	}
	return false;
}

void plSelect() {
		do {
			cout << "What do you want to do?\n";
			cout << "1. Hit\n";
			cout << "2. Stand\n";

			cin >> optSelect;
			switch (optSelect) {
			case 1:
				bust = drawCards(plPoints, plName, plWin);
				if (bust) {
					dlWin = true;
					plWin = false;
					cout << "You have " << plPoints << " points.\n";
					break;
				}
				else if (plPoints == 21) {
					plWin = true;
					break;
				}
				else {
					cout << "You have " << plPoints << " points.\n";
				}
				break;
			case 2:
				cout << "Player " << plName << " stands with " << plPoints << " points.\n";
				break;
			default:
				cout << "Invalid selection.\n";
				break;
			}
		} while (optSelect != 2 && !bust && !plWin);	
}

void houseTurn() {
	if (!dlWin) {
		showHiddenCard = true;
		showDrawnCard(dlName, hiddenCard, hiddenCardValue, hiddenSuit);
		Sleep(1000);
		cout << "The house has " << dlPoints << " points.\n";
		Sleep(1000);
		while (dlPoints < 17 && dlPoints < plPoints) {
			Sleep(2000);
			drawCards(dlPoints, dlName, dlWin);
			cout << "The house has " << dlPoints << " points.\n";
		}
	}
}

void checkWinner() {
		if (plPoints == dlPoints) {
			cout << "\nPUSH\n";
			Sleep(1000);
			cout << "Bet is returned.\nBank: " << bank << " + " << tempBet << "\n";
			Sleep(1000);
			bank = bank + tempBet;
			cout << "Bank: " << bank << "\n";
		}
		if (dlPoints > 21 || (plPoints > dlPoints && plPoints <= 21)) {
			cout << "\n" << plName << " WINS!!\n";
			Sleep(1000);
			cout << "Bank: " << bank << " + " << tempBet << "x2\n";
			Sleep(1000);
			bank = bank + tempBet * 2;
			cout << "Bank: " << bank << "\n";
			totalGains += tempBet * 2;
		}
		if (plPoints > 21 || (dlPoints > plPoints && dlPoints <= 21)) {
			cout << "THE HOUSE WINS.\n";
			Sleep(1000);
			cout << "Bank: " << bank << "\n";
			Sleep(1000);
			totalLoss += tempBet;

		}
}

bool continueGame() {
	char endGame;
	if (bank < 5000) {
		cout << "Do you want to continue? y/n\n";
	}
	else {
		cout << "Will you put up a fight? y/n\n";
	}
	cin >> endGame;
	if (endGame == 'y' || endGame == 'Y') {
		return false;
	}
	else if (endGame == 'n' || endGame == 'N') {
		/*
		if (bank > 5000) {
			bank = 0;
			cout << "The men in suits took your money and kicked you out.\n";
		}
		*/
		return true;
	}
	else {
		cout << "Invalid input. Please enter 'y' or 'n'.\n";
		continueGame();
	}
}









int main()
{
	srand((unsigned int)time(NULL));
	bool gameOver = false;
	cout << "\3 \4 \5 \6\n";
	cout << "Welcome to Casino 'il Martino'.\n";
	cout << "\6 \5 \4 \3\n";
	cout << "I'll be your dealer today. ";
	do {
		cout << "My name is " << dlName << ". What's your name?\n";
		getline(cin, plName);
		if (plName == dlName) {
			cout << "Uhhh... ";
		}
	} while (plName == dlName);
	cout << "Alright, " << plName << "... Let's play some BlackJack, shall we? \n";
	initializeDeck();
	Sleep(2000);
	while (!gameOver) {
		hideFirstCard = true;
		showHiddenCard = false;
		tempBet = 0;
		plPoints = 0;
		dlPoints = 0;
		plWin = false;
		dlWin = false;
		placeBet(bank, tempBet);
		drawCards(plPoints, plName, plWin);
		drawCards(dlPoints, dlName, dlWin);
		hideFirstCard = false;
		drawCards(plPoints, plName, plWin);
		drawCards(dlPoints, dlName, dlWin);
		cout << "\nYou have " << plPoints << " points.\n";
		if (shownCard == 0) {
			cout << "The house has an ace.\n";
		}
		else {
			cout << "The house has " << shownCardValue << " points.\n";
		}
		if (plPoints == 21 && dlPoints < 17) {
			checkWinner();
		}
		else if (!plWin) {
			plSelect();
			houseTurn();
			checkWinner();
		}
		if (bank == 0) {
			cout << "You don't have any money to continue playing!\n";
			gameOver = true;
			break;
		}
		gameOver = continueGame();
	}

	if (gameOver) {
		cout << "\n\nGame over!\n";
		Sleep(1000);
		cout << "Amount won: " << totalGains << "\n";
		Sleep(1000);
		cout << "Amount lost: -" << totalLoss << "\n";
		Sleep(1000);
		cout << "Net total: " << totalGains - totalLoss << "\n";
		Sleep(2000);
		cout << "\nWe hope to see you again soon!\n";
		Sleep(1000);
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
