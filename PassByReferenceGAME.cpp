// PassByReferenceGAME.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP1 = 100;
string enemyName1 = "Zombie";
bool enemyIsAlive1 = true;

//Atributos del enemigo 2
int enemyHP2 = 150;
string enemyName2 = "Creeper";
bool enemyIsAlive2 = true;

//Atributos del personaje
int heroHP = 2000;
int heroDamage;
string heroName;
bool heroIsAlive = true;

//Atributos del juego
int enemyChosen = 0;
int magicPoints = 2;
int sopapoValue = 10;
int espadazoValue = 30;
int magicValue = 50;

void gameStart() {
    cout << "El enemigo " << enemyName1 << " ha aparecido\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}

void checkEnemyStatus(int& enemyHP, string enemyName, bool& enemyIsAlive) {
    if (enemyHP <= 0) {
        cout << "Te has cargado al enemigo " << enemyName << " \n";
        enemyHP = 0;
        enemyIsAlive = false;
    }
    else {
        cout << "El enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida\n";
        enemyIsAlive = true;
    }
}

void chooseEnemy(int& enemyChosen) {
    int enemyChoose = 0;
    while (enemyChoose != 1 && enemyChoose != 2) {
        cout << "A que enemigo quieres atacar? \n";
        if (enemyIsAlive1) {
            cout << "1.- " << enemyName1 << "\n";
        }
        if (enemyIsAlive2) {
            cout << "2.- " << enemyName2 << "\n";
        }
        cin >> enemyChoose;
        if (enemyChoose <= 0 || enemyChoose > 2) {
            cout << "La opcion elegida no es correcta. Por favor, elige una opcion valida. \n";
        }
        if (!enemyIsAlive1 && enemyChoose == 1) {
            cout << "El enemigo " << enemyName1 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo." " \n";
            enemyChoose = 0;
        }
        if (!enemyIsAlive2 && enemyChoose == 2) {
            cout << "El enemigo " << enemyName2 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo." " \n";
            enemyChoose = 0;
        }
    }
    enemyChosen = enemyChoose;
}

void chooseAttack() {
    int attackChoose = 0;
    while (attackChoose != 1 && attackChoose != 2 && attackChoose != 3) {
        cout << "Que ataque quieres usar? \n";
        cout << "1.- Espadazo \n";
        cout << "2.- Sopapo \n";
        if (magicPoints > 0) {
            cout << "3.- Magia\n";
        }
        cin >> attackChoose;
        if (attackChoose <= 0 || attackChoose > 3) {
            cout << "El ataque seleccionado no es correcto. Por favor, elige una opcion valida. \n";
        }
        if (attackChoose == 3) {
            if (magicPoints > 0) {
                magicPoints--;
            }
            else {
                attackChoose = 0;
                cout << "No te queda magia. Por favor selecciona un ataque que puedas usar. \n";
            }
        }
    }
    if (attackChoose == 1) {
        heroDamage = espadazoValue;
    }
    else if (attackChoose == 2) {
        heroDamage = sopapoValue;
    }
    else {
        heroDamage = magicValue;
    }
}

void heroAttackEnemy(int damage, string enemyName, int& enemyHP) {
    cout << "Atacas al enemigo " << enemyName << " y le haces un danyo de " << damage << " \n";
    enemyHP= enemyHP - damage;
}

void enemyAttack(int damage, string enemyName) {
    heroHP = heroHP - damage;
    if (heroHP > 0) {
        cout << "El enemigo " << enemyName << " te ha atacado y te quedan " << heroHP << " puntos de vida\n";
    }
    else {
        cout << "El enemigo " << enemyName << " te ha atacado y te ha matado. El mundo esta condenado. \n";
        heroIsAlive = false;
    }
}

int main()
{
    gameStart();
    while (heroIsAlive && (enemyIsAlive1 || enemyIsAlive2)) {
        //ELEGIMOS ENEMIGO AL QUE ATACAR
        chooseEnemy(enemyChosen);
        //ELEGIMOS ATAQUE Y CAPTURAMOS EL VALOR DEL DANYO QUE HAREMOS
        chooseAttack();

        if (enemyChosen == 1) {
            //ATACAMOS AL ENEMIGO 1
            heroAttackEnemy(heroDamage, enemyName1, enemyHP1);
            checkEnemyStatus(enemyHP1, enemyName1, enemyIsAlive1);
        }
        else {
            //ATACAMOS AL ENEMIGO 2
            heroAttackEnemy(heroDamage, enemyName2, enemyHP2);
            checkEnemyStatus(enemyHP2, enemyName2, enemyIsAlive2);         
        }
        //ATACA EL ENEMIGO 1 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive1 && heroIsAlive) {
            enemyAttack((30 + rand() % 20), enemyName1);
        }
        //ATACA EL ENEMIGO 2 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive2 && heroIsAlive) {
            enemyAttack((30 + rand() % 20), enemyName2);
        }
    }
}
