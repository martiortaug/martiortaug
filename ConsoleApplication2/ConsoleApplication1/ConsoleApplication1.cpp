// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

// Atributos del Enemigo 1
int enemy1HP = 450;
int enemy1Damage;
bool enemy1IsAlive = true;
string enemy1Name = "Malo";
int bleed1 = 0;

// Atributos del Enemigo 2
int enemy2HP = 350;
int enemy2Damage;
bool enemy2IsAlive = true;
string enemy2Name = "Peor";
int bleed2 = 0;

// Atributos del Jugador
string playerName;
int playerHP = 2500;
int playerMP = 325;
bool playerIsAlive = true;
int objetivo;
int attack;
int attack1 = 30;
int attack2 = 250;
int attack3 = 120;
int attack4;
int bleedDmg = 40;


void intro() {
    Sleep(500);
    srand(time(NULL));
    cout << "SOUL "; Beep(500, 270); Sleep(200); cout << "VANISHER "; Beep(370, 250); Sleep(150); cout << "2\n"; Beep(475, 500);
    Sleep(200);
    cout << "La Venganza del Emperador Oscuro\n\n\n\n";
    Sleep(1000);
    cout << "Introduce el nombre de tu personaje:\n";
    cin >> playerName;
    cout << "Eres el heroe " << playerName << ", el guerrero legendario desertador de almas.\n";
    Sleep(1000);
    cout << "Tienes " << playerHP << " puntos de salud y " << playerMP << " puntos de magia.\n";
    cout << "________________________________________________________________________________________\n\n";
    Sleep(1500);
    cout << "Paseabas por el campo cuando"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".\n"; Sleep(500);
    cout << "El enemigo " << enemy1Name << " aparece con " << enemy1HP << " puntos de salud.\n"; Beep(370, 500); Sleep(1200);
    cout << "Cuidado! Tambien se acerca el enemigo " << enemy2Name << "!! Tiene " << enemy2HP << " puntos de salud.\n"; Beep(385, 500);
}

int enemigoEl() {
    cin >> objetivo;
    if (objetivo == 1) {
        return 1;
    }
    else {
        return 2;
    }
}

void plattack1() {
    bleed1 = 3;
    enemy1HP = enemy1HP - attack1;
    if (enemy1HP <= 0) {
        enemy1HP = 0;
        enemy1IsAlive = false;
    }
    cout << "Has atacado a " << enemy1Name << " con Navajazo!!\n";
    Sleep(1000);
    cout << "Infliges -" << attack1 << "HP a " << enemy1Name << ".\n";
    Beep(650, 150);
    Beep(570, 200);
    Sleep(1000);
    cout << "Infliges sangrado a " << enemy1Name << "!!\n";
    Sleep(700);
    cout << "Durante 3 turnos pierde puntos de vida por sangrado.\n";
    Sleep(1200);
}

void plattack3() {
    enemy1HP = enemy1HP - attack3;
    if (enemy1HP <= 0) {
        enemy1HP = 0;
        enemy1IsAlive = false;
    }
    Beep(523, 150);
    cout << "Has atacado a " << enemy1Name << " con Tiro con arco!!\n";
    Sleep(1000);
    cout << "Infliges -" << attack3 << "HP a " << enemy1Name << ".\n";
    Sleep(1200);
}

void enemy1Turn() {
    if (enemy2IsAlive) {
        enemy1Damage = 90 + rand() % (181 - 90);
    }
    else {
        enemy1Damage = 180 + rand() % (251 - 180);
    }
    if (enemy1Damage > 140) {
        playerHP = playerHP - round(enemy1Damage * 1.25);
        cout << enemy1Name << " contraataca!\n";
        Sleep(700);
        cout << enemy1Name << ": 'GNYAH!!!'\n";
        Beep(650, 300);
        Sleep(500);
        cout << "GOLPE CRITICO.\n";
        Sleep(700);
        cout << "El enemigo te ha infligido -" << round(enemy1Damage * 1.25) << "HP.\n";
    }
    else {
        playerHP = playerHP - enemy1Damage;
        cout << enemy1Name << " contraataca!\n";
        Sleep(700);
        cout << enemy1Name << ": 'Gnyah!!!'\n";
        Beep(650, 300);
        Sleep(500);
        cout << "El enemigo te ha infligido -" << enemy1Damage << "HP.\n";
    }
    Sleep(1500);
    if (playerHP <= 0) {
        playerHP = 0;
        playerIsAlive = false;
    }
    if (bleed1 > 0) {
        bleed1 = bleed1 - 1;
        enemy1HP = enemy1HP - bleedDmg;
        if (enemy1HP <= 0) {
            enemy1HP = 0;
            enemy1IsAlive = false;
        }
        Sleep(1000);
        cout << "El enemigo " << enemy1Name << " sufre -" << bleedDmg << "HP por sangrado!\n";
        Sleep(500);

        cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de salud.\n";
        Sleep(1000);
        if (enemy1IsAlive == false) {
            enemy2HP = 350;
            cout << "Has derrotado a " << enemy1Name << "!!! :D\n";
            Beep(700, 800);
            Sleep(1000);
            cout << "El enemigo " << enemy2Name << " llora la muerte de su gran amigo...\n";
            Sleep(1500);
            cout << enemy2Name << " dice: 'MALO!!!'\n";
            Sleep(1000);
            cout << enemy2Name << ": 'No puede ser";
            Sleep(700);
            cout << ".";
            Sleep(700);
            cout << ".";
            Sleep(700);
            cout << ".'\n";
            Sleep(1500);
            cout << enemy2Name << ": 'Acabare contigo, escoria!!!!'\n";
            Sleep(1000);
            cout << "El poder de la amistad eleva las caracteristicas de " << enemy2Name << ".\n";
            Sleep(1000);
            cout << "El ataque de " << enemy2Name << " sube mucho!!\n";
            Sleep(1500);
            cout << "El enemigo " << enemy2Name << " ha recuperado toda su salud!\n";
            Sleep(1000);
        }
    }
}

void enemy2Turn() {
    if (enemy1IsAlive) {
        enemy2Damage = 120 + rand() % (201 - 120);
    }
    else {
        enemy2Damage = 200 + rand() % (401 - 200);
    }
    if (enemy2Damage > 186) {
        playerHP = playerHP - round(enemy2Damage * 1.15);
        cout << enemy2Name << " contraataca!\n";
        Sleep(700);
        cout << enemy2Name << ": 'KYAAAAAH!!!'\n";
        Beep(650, 300);
        cout << "GOLPE CRITICO.\n";
        Sleep(700);
        Sleep(500);
        cout << "El enemigo te ha infligido -" << round(enemy2Damage * 1.15) << "HP.\n";
    }
    else {
        playerHP = playerHP - enemy2Damage;
        cout << enemy2Name << " contraataca!\n";
        Sleep(700);
        cout << enemy2Name << ": 'Kyaaaaah!!!'\n";
        Beep(650, 300);
        Sleep(500);
        cout << "El enemigo te ha infligido -" << enemy2Damage << "HP.\n";
    }
    Sleep(1500);
    if (playerHP <= 0) {
        playerHP = 0;
        playerIsAlive = false;
    }
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".\n";
    if (bleed2 > 0) {
        bleed2 = bleed2 - 1;
        enemy2HP = enemy2HP - bleedDmg;
        if (enemy2HP <= 0) {
            enemy2HP = 0;
            enemy2IsAlive = false;
        }
        Sleep(1000);
        cout << "El enemigo " << enemy1Name << " sufre -" << bleedDmg << "HP por sangrado!\n";
        Sleep(500);
        cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de salud.\n";
        Sleep(1000);
        if (enemy2IsAlive == false) {
            enemy1HP = 450;
            cout << "Has derrotado a " << enemy2Name << "!!! :D\n";
            Beep(700, 800);
            Sleep(1000);
            cout << "El enemigo " << enemy1Name << " llora la muerte de su gran amigo...\n";
            Sleep(1500);
            cout << enemy1Name << " dice: 'NO!!!!!!'\n";
            Sleep(1000);
            cout << enemy1Name << ": 'PEOR!!!'\n";
            Sleep(1000);
            cout << enemy1Name << ": 'Maldito seas, " << playerName;
            Sleep(700);
            cout << ".";
            Sleep(700);
            cout << ".";
            Sleep(700);
            cout << ".'\n";
            Sleep(700);
            cout << enemy1Name << ": 'Me vengare!!!!!'\n";
            Sleep(1000);
            cout << "El poder de la amistad eleva las caracteristicas de " << enemy1Name << ".\n";
            Sleep(1500);
            cout << "El ataque de " << enemy1Name << " sube mucho!!\n";
            Sleep(1000);
            cout << "El enemigo " << enemy1Name << " ha recuperado toda su salud!\n";
            Sleep(1000);
        }
    }
}

int main()
{
    intro();
    Sleep(1500);
    while (playerIsAlive && (enemy1IsAlive && enemy2IsAlive)) {
        cout << "\n\nTe quedan " << playerHP << " puntos de salud y " << playerMP << " puntos de magia.\n";
        cout << "Es tu turno.\n";
        cout << "Elige a quien atacaras:\n";
        cout << "[1] " << enemy1Name << " - " << enemy1HP << "HP\n[2] " << enemy2Name << " - " << enemy2HP << "HP\n";
        enemigoEl();
        switch (objetivo) {
        case 1:
            cout << "Has elegido atacar al enemigo " << enemy1Name << ".\n";
            cout << "Elige un ataque:\n";
            cout << "[1] Navajazo\n";
            cout << "[2] Curacion (25MP)\n";
            cout << "[3] Tiro con arco\n";
            cout << "[4] Bola de Fuego (100MP)\n";
            cin >> attack;
            Sleep(500);
            switch (attack) {
            case 1:
                plattack1();
                break;
            case 2:
                if (playerMP >= 25) {
                    if (playerHP == 2500) {
                        cout << "Tu salud ya esta al maximo!";
                        continue;
                    }
                    playerMP = playerMP - 25;
                    playerHP = playerHP + attack2;
                    if (playerHP > 2500) {
                        playerHP = 2500;
                    }                    
                    cout << "Has usado el hechizo de curacion!!\n";
                    Sleep(1000);
                    cout << "Restableces " << attack2 << " puntos de salud.\n";
                    Beep(700, 100);
                    Beep(720, 100);
                    cout << "Te quedan " << playerHP << " puntos de salud.\n";
                    Sleep(1200);
                }
                else {
                    cout << "No te quedan suficientes puntos de magia!\n";
                    continue;
                }
                break;
            case 3:
                plattack3();
                break;
            case 4:
                if (playerMP >= 100) {
                    attack4 = 150 + rand() % (226 - 150);
                    playerMP = playerMP - 100;
                    enemy1HP = enemy1HP - attack4;
                    Beep(575, 275);
                    cout << "Has atacado a " << enemy1Name << " con Bola de Fuego!! Consumes -100 puntos de magia.\n";
                    cout << "Te quedan " << playerMP << " puntos de magia.\n";
                    Sleep(1000);
                    cout << "Infliges -" << attack4 << "HP a " << enemy1Name << ".\n";
                    if (enemy1HP <= 0) {
                        enemy1HP = 0;
                        enemy1IsAlive = false;
                    }
                }
                else {
                    cout << "No te quedan suficientes puntos de magia!\n";
                    continue;
                }
                Sleep(1200);
                break;
            default:
                cout << "Opcion incorrecta.\n";
                Beep(250, 600);
                if (attack > 4) {
                    continue;
                }
                break;
            }
            break;
        case 2:
            cout << "Has elegido atacar al enemigo " << enemy2Name << ".\n";
            cout << "Elige un ataque:\n";
            cout << "[1] Navajazo\n";
            cout << "[2] Curacion (25MP)\n";
            cout << "[3] Tiro con arco\n";
            cout << "[4] Bola de Fuego (100MP)\n";
            cin >> attack;
            Sleep(500);
            switch (attack) {
            case 1:
                bleed2 = 3;
                enemy2HP = enemy2HP - attack1;
                Beep(400, 200);
                cout << "Has atacado a " << enemy2Name << " con Navajazo!!\n";
                Sleep(1000);
                cout << "Infliges -" << attack1 << "HP a " << enemy2Name << ".\n";
                Sleep(1000);
                cout << "Infliges sangrado a " << enemy2Name << "!!\n";
                Sleep(700);
                cout << "Durante 3 turnos pierde puntos de vida por sangrado.\n";
                Sleep(1200);
                break;
            case 2:
                if (playerMP >= 25) {
                    playerMP = playerMP - 25;
                    playerHP = playerHP + attack2;
                    if (playerHP > 2500) {
                        playerHP = 2500;
                    }
                    if (playerHP == 2500) {
                        cout << "Tu salud ya esta al maximo!";
                        continue;
                    }
                    cout << "Has usado el hechizo de curacion!!\n";
                    Sleep(1000);
                    cout << "Restableces " << attack2 << " puntos de salud.\n";
                    Beep(700, 100);
                    Beep(720, 100);
                    cout << "Te quedan " << playerHP << " puntos de salud.\n";
                    Sleep(1200);
                }
                else {
                    cout << "No te quedan suficientes puntos de magia!\n";
                    continue;
                }
                break;
            case 3:
                enemy2HP = enemy2HP - attack3;
                Beep(523, 150);
                cout << "Has atacado a " << enemy2Name << " con Tiro con arco!!\n";
                Sleep(1000);
                cout << "Infliges -" << attack3 << "HP a " << enemy2Name << ".\n";
                Sleep(1200);
                break;
            case 4:
                if (playerMP >= 100) {
                    attack4 = 150 + rand() % (226 - 150);
                    playerMP = playerMP - 100;
                    enemy2HP = enemy2HP - attack4;
                    Beep(575, 275);
                    cout << "Has atacado a " << enemy2Name << " con Bola de Fuego!! Consumes -100 puntos de magia.\n";
                    cout << "Te quedan " << playerMP << " puntos de magia.\n";
                    Sleep(1000);
                    cout << "Infliges -" << attack4 << "HP a " << enemy2Name << ".\n";
                    if (enemy2HP <= 0) {
                        enemy2HP = 0;
                        enemy2IsAlive = false;
                    }
                }
                else {
                    cout << "No te quedan suficientes puntos de magia!\n";
                    continue;
                }
                Sleep(1200);
                break;
            default:
                cout << "Opcion incorrecta.\n";
                Beep(250, 600);
                if (attack > 4) {
                    continue;
                }
                break;
            }
            break;
        default:
            cout << "Opcion incorrecta.\n";
            Beep(250, 600);
            if (objetivo > 2) {
                continue;
            }
            break;
        }
        Sleep(1000);
        if (enemigoEl == 1) {
            cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de salud.\n";
        }
        if (enemigoEl == 2) {
            cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de salud.\n";
        }
        Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".\n"; Sleep(500);
        if (enemy1IsAlive == false) {
            enemy2HP = 350;
            cout << "Has derrotado a " << enemy1Name << "!!! :D\n"; Beep(700, 800);
            Sleep(1000);
            cout << "El enemigo " << enemy2Name << " llora la muerte de su gran amigo...\n";
            Sleep(1500);
            cout << enemy2Name << " dice: 'MALO!!!'\n";
            Sleep(1000);
            cout << enemy2Name << ": 'No puede ser"; Sleep(700); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << ".'\n";
            Sleep(1500);
            cout << enemy2Name << ": 'Acabare contigo, escoria!!!!'\n";
            Sleep(1000);
            cout << "El poder de la amistad eleva las caracteristicas de " << enemy2Name << ".\n";
            Sleep(1000);
            cout << "El ataque de " << enemy2Name << " sube mucho!!\n";
            Sleep(1500);
            cout << "El enemigo " << enemy2Name << " ha recuperado toda su salud!\n";
            Sleep(1000);
        }
        if (enemy2IsAlive == false) {
            enemy1HP = 450;
            cout << "Has derrotado a " << enemy2Name << "!!! :D\n"; Beep(700, 800);
            Sleep(1000);
            cout << "El enemigo " << enemy1Name << " llora la muerte de su gran amigo...\n";
            Sleep(1500);
            cout << enemy1Name << " dice: 'NO!!!!!!'\n";
            Sleep(1000);
            cout << enemy1Name << ": 'PEOR!!!'\n";
            Sleep(1000);
            cout << enemy1Name << ": 'Maldito seas, " << playerName; Sleep(700); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << ".'\n";
            Sleep(700);
            cout << enemy1Name << ": 'Me vengare!!!!!'\n";
            Sleep(1000);
            cout << "El poder de la amistad eleva las caracteristicas de " << enemy1Name << ".\n";
            Sleep(1500);
            cout << "El ataque de " << enemy1Name << " sube mucho!!\n";
            Sleep(1000);
            cout << "El enemigo " << enemy1Name << " ha recuperado toda su salud!\n";
            Sleep(1000);
        }
        if (enemy1IsAlive) {
            enemy1Turn();
        }
        if (enemy2IsAlive) {
            enemy2Turn();
        }
        if (playerIsAlive == false) {
            Beep(320, 100);
            Beep(250, 100);
            Beep(200, 150);
            cout << "Has morido.\nGame Over.\n";
        }
    }
    Sleep(500);
    while (playerIsAlive && enemy1IsAlive && (enemy2IsAlive == false)) {
        Sleep(1500);
        cout << "\n\nTe quedan " << playerHP << " puntos de salud y " << playerMP << " puntos de magia.\n";
        Sleep(700);
        cout << "Es tu turno.\n";
        Sleep(700);
        cout << "Te preparas para atacar al enemigo " << enemy1Name << " (" << enemy1HP << "HP).\n";
        cout << "Elige un ataque:\n";
        cout << "[1] Navajazo\n";
        cout << "[2] Curacion (25MP)\n";
        cout << "[3] Tiro con arco\n";
        cout << "[4] Bola de Fuego (100MP)\n";
        cin >> attack;
        Sleep(500);
        switch (attack) {
        case 1:
            plattack1();
            break;
        case 2:
            if (playerMP >= 25) {
                playerMP = playerMP - 25;
                playerHP = playerHP + attack2;
                if (playerHP > 2500) {
                    playerHP = 2500;
                }
                if (playerHP == 2500) {
                    cout << "Tu salud ya esta al maximo!";
                    continue;
                }
                cout << "Has usado el hechizo de curacion!!\n";
                Sleep(1000);
                cout << "Restableces " << attack2 << " puntos de salud.\n";
                Beep(700, 100);
                Beep(720, 100);
                cout << "Te quedan " << playerHP << " puntos de salud.\n";
                Sleep(1200);
            }
            else {
                cout << "No te quedan suficientes puntos de magia!\n";
                continue;
            }
            break;
        case 3:
            plattack3();
            break;
        case 4:
            if (playerMP >= 100) {
                attack4 = 150 + rand() % (226 - 150);
                playerMP = playerMP - 100;
                enemy1HP = enemy1HP - attack4;
                Beep(575, 275);
                cout << "Has atacado a " << enemy1Name << " con Bola de Fuego!! Consumes -100 puntos de magia.\n";
                Sleep(1000);
                cout << "Infliges -" << attack4 << "HP a " << enemy1Name << ".\n";
                cout << "Te quedan " << playerMP << " puntos de magia.\n";
                if (enemy1HP <= 0) {
                    enemy1HP = 0;
                    enemy1IsAlive = false;
                }
            }
            else {
                cout << "No te quedan suficientes puntos de magia!\n";
                continue;
            }
            break;
        default:
            cout << "Opcion incorrecta.\n";
            Beep(250, 600);
            if (attack > 4) {
                continue;
            }
            if (enemy1HP <= 0) {
                enemy1HP = 0;
                enemy1IsAlive = false;
            }
            break;
        }
        Sleep(1000);
        cout << "Al enemigo " << enemy1Name << " le quedan " << enemy1HP << " puntos de salud.\n"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500);
        cout << ".\n";
        Sleep(500);
        if (enemy1HP <= 0) {
            enemy1HP = 0;
            enemy1IsAlive = false;
        }
        if (enemy1IsAlive == false) {
            cout << "Has derrotado a " << enemy1Name << "!!! :D\n";
            Beep(700, 800);
        }
        if (enemy1IsAlive) {
            enemy1Turn();
        }
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".\n";
        if (playerIsAlive == false) {
            Beep(320, 100);
            Beep(250, 100);
            Beep(200, 150);
            cout << "Te quedan 0 puntos de salud.\n";
            cout << "Has morido.\nGame Over.\n";
        }
    }
    while (playerIsAlive && enemy2IsAlive && (enemy1IsAlive == false)) {
        Sleep(1500);
        cout << "\n\nTe quedan " << playerHP << " puntos de salud y " << playerMP << " puntos de magia.\n";
        Sleep(700);
        cout << "Es tu turno.\n";
        Sleep(700);
        cout << "Te preparas para atacar al enemigo " << enemy2Name << " (" << enemy2HP << "HP).\n";
        cout << "Elige un ataque:\n";
        cout << "[1] Navajazo\n";
        cout << "[2] Curacion (25MP)\n";
        cout << "[3] Tiro con arco\n";
        cout << "[4] Bola de Fuego (100MP)\n";
        cin >> attack;
        Sleep(500);
        switch (attack) {
        case 1:
            bleed2 = 3;
            enemy2HP = enemy2HP - attack1;
            Beep(400, 200);
            cout << "Has atacado a " << enemy2Name << " con Navajazo!!\n";
            Sleep(1000);
            cout << "Infliges -" << attack1 << "HP a " << enemy2Name << ".\n";
            Sleep(1000);
            cout << "Infliges sangrado a " << enemy2Name << "!!\n";
            Sleep(700);
            cout << "Durante 3 turnos pierde puntos de vida por sangrado.\n";
            Sleep(1200);
            break;
        case 2:
            if (playerMP >= 25) {
                playerMP = playerMP - 25;
                playerHP = playerHP + attack2;
                if (playerHP > 2500) {
                    playerHP = 2500;
                }
                if (playerHP == 2500) {
                    cout << "Tu salud ya esta al maximo!";
                    continue;
                }
                cout << "Has usado el hechizo de curacion!!\n";
                Sleep(1000);
                cout << "Restableces " << attack2 << " puntos de salud.\n";
                Beep(700, 100);
                Beep(720, 100);
                cout << "Te quedan " << playerHP << " puntos de salud.\n";
                Sleep(1200);
            }
            else {
                cout << "No te quedan suficientes puntos de magia!\n";
                continue;
            }
            break;
        case 3:
            enemy2HP = enemy2HP - attack3;
            if (enemy2HP <= 0) {
                enemy2HP = 0;
                enemy2IsAlive = false;
            }
            Beep(523, 150);
            cout << "Has atacado a " << enemy2Name << " con Tiro con arco!!\n";
            Sleep(1000);
            cout << "Infliges -" << attack3 << "HP a " << enemy2Name << ".\n";
            break;
        case 4:
            if (playerMP >= 100) {
                attack4 = 150 + rand() % (226 - 150);
                playerMP = playerMP - 100;
                enemy2HP = enemy2HP - attack4;
                Beep(575, 275);
                cout << "Has atacado a " << enemy2Name << " con Bola de Fuego!! Consumes -100 puntos de magia.\n";
                cout << "Te quedan " << playerMP << " puntos de magia.\n";
                Sleep(1000);
                cout << "Infliges -" << attack4 << "HP a " << enemy2Name << ".\n";
                if (enemy2HP <= 0) {
                    enemy2HP = 0;
                    enemy2IsAlive = false;
                }
            }
            else {
                cout << "No te quedan suficientes puntos de magia!\n";
                continue;
            }
            break;
        default:
            cout << "Opcion incorrecta1.\n";
            Beep(250, 600);
            if (attack > 4) {
                continue;
            }
            if (enemy2HP <= 0) {
                enemy2HP = 0;
                enemy2IsAlive = false;
            }
            break;
        }

        Sleep(1000);
        cout << "Al enemigo " << enemy2Name << " le quedan " << enemy2HP << " puntos de salud.\n";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".\n";
        Sleep(500);
        if (enemy2HP <= 0) {
            enemy2HP = 0;
            enemy2IsAlive = false;
        }
        if (enemy2IsAlive == false) {
            cout << "Has derrotado a " << enemy2Name << "!!! :D\n";
            Beep(700, 800);
        }
        if (enemy2IsAlive) {
            enemy2Turn();
        }
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".\n";
        if (playerIsAlive == false) {
            Beep(320, 100);
            Beep(250, 100);
            Beep(200, 150);
            cout << "Te quedan 0 puntos de salud.\n";
            cout << "Has morido.\nGame Over.\n";
        }
    }
    if (enemy1IsAlive == false && enemy2IsAlive == false && playerIsAlive) {
        Sleep(1200);
        cout << "Has vencido a Malo y Peor, el temible duo fatal que atemorizaba las tierras de Tierralandia.\n"; Sleep(1200); cout << "."; Sleep(1200); cout << "."; Sleep(1200); cout << ".\n";
        cout << "Tu mision ha terminado. Se escribiran libros sobre tu leyenda y se cantaran canciones sobre tus hitos.\n"; Sleep(1200); cout << "."; Sleep(1200); cout << "."; Sleep(1200); cout << ".\n";
        cout << "Ve en paz, heroe " << playerName <<". Que tu vida sea longeva y tu felicidad, eterna.\n"; Sleep(1200); cout << "."; Sleep(1200); cout << "."; Sleep(1200); cout << ".\n";
        cout << "THE END.";Sleep(200); cout << "\n"; Sleep(200); cout << "\n"; Sleep(200); cout << "\n";Sleep(200); cout << "\n"; Sleep(200);cout << "\n"; Sleep(200);
        cout << "\n"; Sleep(200);cout << "\n";Sleep(200); cout << "\n";Sleep(200); cout << "\n"; Sleep(200); cout << "\n"; Sleep(200); cout << "\n"; Sleep(200); cout << "\n";
        Sleep(200); cout << "\n"; Sleep(200); cout << "\n"; Sleep(200); cout << "\n";  Sleep(200); cout << "\n"; Sleep(200);
        cout << "CREDITS\n";
        Sleep(200);
        cout << "_______\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        cout << "Written and Directed by:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Produced by:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Lead Programmer:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Character Design:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Sound Design:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Art Department:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "Special Thanks to:\n";
        Sleep(200);
        cout << "Marti Ortiz\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "FIN\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
        Sleep(200);
        cout << "\n";
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
