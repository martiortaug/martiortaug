// SoulVanisher3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "personaje.h"
#include <chrono>
#include <thread>

const int SCREEN_WIDTH = 12;
const int SCREEN_HEIGHT = 25;
const char BLOCK_CHAR = (char)219u;


using namespace std;
string plName;
int plClass;
int attack;
int plMaxHP;
int plMaxMP;
Personaje plCharacter(plName, 1, 1000, 0, 0, 0, 0, 0, 0, "", false);
int enemyPositions[4][2];


void drawSpiral()
{
    int startX = 0;
    int startY = 0;
    int endX = SCREEN_WIDTH - 1;
    int endY = SCREEN_HEIGHT - 1;
    int direction = 0;

    while (startX <= endX && startY <= endY)
    {
        if (direction == 0)
        {
            for (int i = startY; i <= endY; ++i)
                std::cout << BLOCK_CHAR;

            startX++;
        }
        else if (direction == 1)
        {
            for (int i = startX; i <= endX; ++i)
            {
                std::cout << "\033[" << i + 1 << ";" << endY + 1 << "H" << BLOCK_CHAR;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            endY--;
        }
        else if (direction == 2)
        {
            for (int i = endY; i >= startY; --i)
                std::cout << "\033[" << endX + 1 << ";" << i + 1 << "H" << BLOCK_CHAR;

            endX--;
        }
        else if (direction == 3)
        {
            for (int i = endX; i >= startX; --i)
                std::cout << "\033[" << i + 1 << ";" << startY + 1 << "H" << BLOCK_CHAR;

            startY++;
        }

        direction = (direction + 1) % 4;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << std::endl;
}

void chooseAttack() {
    cout << "Choose an attack:\n";
    cout << "[1] Sword slash\n";
    cout << "[2] Jump kick\n";
    cout << "[3] Archer shot\n";
    cout << "[4] Fire ball [10MP]\n";
    cin >> attack;
}

bool checkPlayerIsAlive(Personaje player) {
    if (player.getHp() <= 0) {
        player.setHp(0);
        return false;
    }
    else {
        return true;
    }
}

void enemyTurn(Personaje& enemy, Personaje& player) {
    system("cls");
    int enemyDamage = (enemy.getAtk()*5) - (player.getDef()+2);
    player.setHp(player.getHp() - enemyDamage);
    cout << enemy.getName() << " strikes back!\n";
    Sleep(700);
    cout << enemy.getName() << " deals " << enemyDamage << " damage.\n";
    Sleep(1500);
    player.setIsAlive(checkPlayerIsAlive(player));
    Sleep(1000);
    cout << "The enemy " << enemy.getName() << " has " << enemy.getHp() << " HP remaining.\n";
    Sleep(1000);
}

void levelUp(Personaje& player) {
    system("cls");
    cout << "You leveled up! You recovered health and magic points.\nYour stats increased:\n";
    cout << "Level: " << player.getLvl() << " -> " << player.getLvl() + 1 << endl;
    Sleep(2000);
    cout << "HP: " << plMaxHP << " -> " << round(plMaxHP * 1.5) << endl;
    Sleep(1000);
    cout << "MP: " << plMaxMP << " -> " << round(plMaxMP * 1.5) << endl;
    Sleep(1000);
    cout << "Atk: " << player.getAtk() << " -> " << round(player.getAtk() * 1.5) << endl;
    Sleep(1000);
    cout << "Def: " << player.getDef() << " -> " << round(player.getDef() * 1.5) << endl;
    Sleep(1000);
    cout << "Spec: " << player.getSpec() << " -> " << round(player.getSpec() * 1.5) << endl;
    Sleep(2000);
    player =Personaje(
        player.getName(),
        (player.getLvl() + 1),
        (plMaxHP * 1.5),
        (plMaxMP * 1.5),
        (player.getAtk() * 1.5),
        (player.getDef() * 1.5),
        (player.getSpec() * 1.5),
        player.getPosX(),
        player.getPosY(),
        "H",
        true);
    plMaxHP = player.getHp();
    plMaxMP = player.getMp();
    Sleep(3000);
}

void enemyKill(Personaje& enemy, int maxHp, Personaje& player) {
    if (enemy.getHp() <= 0) {
        enemy.setHp(0);
        cout << "The enemy " << enemy.getName() << " has " << enemy.getHp() << "/" << maxHp << " HP." << endl;
        Sleep(1000);
        enemy.setIsAlive(false);
        cout << "You defeated " << enemy.getName() << "!!" << endl;
        Sleep(1000);
        levelUp(player);

        // Update the enemy positions based on the enemy object
        for (int i = 0; i < 4; i++) {
            if (enemyPositions[i][0] == enemy.getPosX() && enemyPositions[i][1] == enemy.getPosY()) {
                enemyPositions[i][0] = -1;
                enemyPositions[i][1] = -1;
                break;
            }
        }
    }
}





void battleSequence(Personaje& player, Personaje& enemy) {
    int swordAtk = round(player.getAtk() * 5) * player.getLvl() - round(enemy.getDef() * 2);
    int kickAtk = round(15 + (player.getAtk() * 2.2)) * player.getLvl() - round(enemy.getDef() * 2);
    int archAtk = round((player.getAtk() + player.getSpec()) * 2.5) * player.getLvl() - round(enemy.getDef() * 2);
    int fireAtk = round(player.getSpec() * 8) - round(enemy.getSpec() * 2);
    int enemyMaxHP = enemy.getHp();
    if (swordAtk <= 0) {
        swordAtk = 1;
    }
    if (kickAtk <= 0) {
        kickAtk = 1;
    }
    if (archAtk <= 0) {
        archAtk = 1;
    }
    if (fireAtk <= 0) {
        fireAtk = 1;
    }
    drawSpiral();
    system("cls");
    cout << "The enemy " << enemy.getName() << " approaches!" << endl;
    Sleep(1000);
    do {
        system("cls");
        cout << "You have " << player.getHp() << "/" << plMaxHP << "HP and " << player.getMp() << " MP." << endl;
        cout << "The enemy " << enemy.getName() << " has " << enemy.getHp() << "/" << enemyMaxHP << " HP." << endl;
        Sleep(1000);
        cout << "What will you do?" << endl;
        chooseAttack();
        switch (attack) {
        case 1:
            cout << "Sword slash!" << endl;
            Sleep(1000);
            enemy.setHp(enemy.getHp() - swordAtk);
            cout << "You dealt " << swordAtk << " points of damage to " << enemy.getName() << "!" << endl;
            Sleep(1000);
            enemyKill(enemy, enemyMaxHP, player);
            Sleep(1000);
            break;
        case 2:
            cout << "Jump kick!" << endl;
            Sleep(1000);
            enemy.setHp(enemy.getHp() - kickAtk);
            cout << "You dealt " << kickAtk << " points of damage to " << enemy.getName() << "!" << endl;
            Sleep(1000);
            enemyKill(enemy, enemyMaxHP, player);
            Sleep(1000);
            break;
        case 3:
            cout << "Archer shot!" << endl;
            Sleep(1000);
            enemy.setHp(enemy.getHp() - archAtk);
            cout << "You dealt " << archAtk << " points of damage to " << enemy.getName() << "!" << endl;
            Sleep(1000);
            enemyKill(enemy, enemyMaxHP, player);
            Sleep(1000);
            break;
        case 4:
            if (player.getMp() >= 10) {
                cout << "Fire ball!" << endl;
                player.setMp(player.getMp() - 10);
                Sleep(1000);
                enemy.setHp(enemy.getHp() - fireAtk);
                cout << "You dealt " << fireAtk << " points of damage to " << enemy.getName() << "!" << endl;
                Sleep(1000);
                enemyKill(enemy, enemyMaxHP, player);
                Sleep(1000);
            }
            else {
                cout << "You don't have enough magic points!\n";
                Sleep(1000);
                continue;
            }
            Sleep(1200);
            break;
            break;
        default:
            cout << "Invalid selection." << endl;
            Sleep(1000);
            if (attack > 4) {
                continue;
            }
            break;
        }
        enemyTurn(enemy, player);
    } while (player.getIsAlive() && enemy.getIsAlive());
}

void chooseClass(Personaje& player) {
    cout << "Choose class." << endl;
    cout << "[1]\t\t\t\t[2]\t\t\t\t[3]" << endl;
    cout << "Warrior\t\t\t\tMage\t\t\t\tKnight" << endl;
    cout << "Atk: 10\t\t\t\tAtk: 2\t\t\t\tAtk: 8" << endl;
    cout << "Def: 6\t\t\t\tDef: 6\t\t\t\tDef: 10" << endl;
    cout << "Spec: 2\t\t\t\tSpec: 10\t\t\tSpec: 0" << endl;
    int plClass;
    cin >> plClass;
    switch (plClass) {
    case 1:
    {
        player = Personaje(plName, 1, 500, 40, 0, 6, 2, 0, rand() % 10 + 1, "H", true);
        plMaxHP = player.getHp();
        plMaxMP = player.getMp();
        break;
    }
    case 2:
    {
        player = Personaje(plName, 1, 400, 150, 2, 6, 10, 0, rand() % 10 + 1, "H", true);
        plMaxHP = player.getHp();
        plMaxMP = player.getMp();
        break;
    }
    case 3:
    {
        player = Personaje(plName, 1, 700, 0, 8, 10, 0, 0, rand() % 10 + 1, "H", true);
        plMaxHP = player.getHp();
        plMaxMP = player.getMp();
        break;
    }
    default:
        cout << "Invalid selection." << endl;
        Sleep(1000);
        system("cls");
        chooseClass(player);
        break;
    }
}




int main()
{
    srand(time(0));

    cout << "Soul Vanisher 3" << endl;
    cout << "Insert character name:" << endl;
    string plName;
    cin >> plName;
    chooseClass(plCharacter);
    int x = plCharacter.getPosX();
    int y = plCharacter.getPosY();
    Personaje enmyChar1("Malo", 1, 100, 0, 5, 5, 0, enemyPositions[0][0], enemyPositions[0][1], "M", true);
    Personaje enmyChar2("Maloso", 2, 200, 0, 8, 8, 5, enemyPositions[0][0], enemyPositions[0][1], "M", true);
    Personaje enmyChar3("Malvado", 3, 500, 0, 12, 12, 8, enemyPositions[0][0], enemyPositions[0][1], "M", true);
    EnemigoFinal finalBoss("Terrible", 5, 1000, 0, 20, 20, 12, enemyPositions[0][0], enemyPositions[0][1], "M", true, 20, 20);
    for (int i = 0; i < 3; i++) {
        int row;
        do {
            row = rand() % 3 + 1;
        } while (row == enemyPositions[0][0] || row == enemyPositions[1][0] || row == enemyPositions[2][0]);
        enemyPositions[i][0] = row;
        enemyPositions[i][1] = rand() % 10;
        if (i == 0) {
           // Personaje   enmyChar1("Malo", 1, 100, 5, 5, 0, enemyPositions[i][0], enemyPositions[i][1], "M", true);
            enmyChar1.setPosX(enemyPositions[i][0]);
            enmyChar1.setPosY(enemyPositions[i][1]);
        }
        else if (i == 1) {
            enmyChar2.setPosX(enemyPositions[i][0]);
            enmyChar2.setPosY(enemyPositions[i][1]);
        }
        else {
            enmyChar3.setPosX(enemyPositions[i][0]);
            enmyChar3.setPosY(enemyPositions[i][1]);
        }
    }

    


    char move;
    bool exit = false;
#define underline "\033[4m"
    do {
        system("cls");
        cout << "Map:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                bool enemy = false;
                if (i == 4 && j == 4) {
                    cout << underline << "B\033[0m ";
                    enemy = true;
                }
                else {
                    for (int k = 0; k < 3; k++) {
                        if (enemyPositions[k][0] == i && enemyPositions[k][1] == j) {
                            if ((enmyChar1.getPosY() == j && enmyChar1.getPosX() == i && enmyChar1.getIsAlive()) ||
                                (enmyChar2.getPosY() == j && enmyChar2.getPosX() == i && enmyChar2.getIsAlive()) ||
                                (enmyChar3.getPosY() == j && enmyChar3.getPosX() == i && enmyChar3.getIsAlive())) {
                                cout << underline << "Y\033[0m ";
                                enemy = true;
                                break;
                            }
                            else {
                                enemy = false;
                                break;
                            }
                        }
                    }
                }
                if (!enemy) {
                    if (i == x && j == y) {
                        cout << underline << "X\033[0m ";
                    }
                    else {
                        cout << "_ ";
                    }
                }
            }
            cout << endl;
        }
        cout << "Use 'W', 'A', 'S', 'D' to move. Press 'E' to exit." << endl;
        move = _getch();
        switch (move) {
        case 'w':
            if (x > 0) {
                x--;
            }
            break;
        case 's':
            if (x < 4) {
                x++;
            }
            break;
        case 'a':
            if (y > 0) {
                y--;
            }
            break;
        case 'd':
            if (y < 9) {
                y++;
            }
            break;
        case 'e':
            exit = true;
            break;
        default:
            cout << "Invalid move. Please enter 'W', 'A', 'S', or 'D'." << endl;
            Sleep(500);
            break;
        }
        plCharacter.setPosX(x);
        plCharacter.setPosY(y);
        bool battle = false;
        if (x == 4 && y == 4) {
            battle = true;
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (enemyPositions[i][0] == x && enemyPositions[i][1] == y) {
                    battle = true;
                    break;
                }
            }
        }
        if (battle) {
            system("cls");
            cout << "You have encountered an enemy! Prepare for battle!" << endl;
            Sleep(2000);
            system("cls");
            if (enmyChar1.getIsAlive() && plCharacter.getPosX() != 4 && plCharacter.getPosY() != 4) {
                battleSequence(plCharacter, enmyChar1);
            }
            else if (!enmyChar1.getIsAlive() && enmyChar2.getIsAlive() && plCharacter.getPosX() != 4 && plCharacter.getPosY() != 4) {
                battleSequence(plCharacter, enmyChar2);
            }
            else if (!enmyChar1.getIsAlive() && !enmyChar2.getIsAlive() && enmyChar3.getIsAlive() && plCharacter.getPosX() != 4 && plCharacter.getPosY() != 4) {
                battleSequence(plCharacter, enmyChar3);
            }
            else if (plCharacter.getPosX() == 4 && plCharacter.getPosY() == 4){
                battleSequence(plCharacter, finalBoss);
            }

        }

    } while (!exit);

    cout << "Exiting game..." << endl;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
