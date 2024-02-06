#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funció per obtenir la suma de dos daus llançats
int tirarDaus() {
    return rand() % 6 + 1 + rand() % 6 + 1;
}

// Funció per gestionar una ronda de joc
void jugar(int& diners) {
    cout << "Opcio 1 - Realitzar aposta" << endl;
    cout << "Opcio 2 - Sortir" << endl;
    cout << "Selecciona una opcio: ";

    int opcio;
    cin >> opcio;

    if (opcio == 1) {
        cout << "Introdueix la quantitat de diners que vols apostar: ";
        int aposta;
        cin >> aposta;

        // Llançar els daus
        int sumaDaus = tirarDaus();
        cout << "La suma dels daus es: " << sumaDaus << endl;

        // Calcular el resultat de l'aposta
        if (sumaDaus == aposta) {
            diners += 10 * aposta;
            cout << "Has guanyat 10 vegades la quantitat apostada!" << endl;
        }
        else if (abs(sumaDaus - aposta) <= 1) {
            diners += 2 * aposta;
            cout << "Has guanyat 2 vegades la quantitat apostada!" << endl;
        }
        else if (abs(sumaDaus - aposta) <= 2) {
            diners += aposta;
            cout << "Has guanyat 1 vegada la quantitat apostada!" << endl;
        }
        else {
            diners -= aposta;
            cout << "Has perdut la quantitat apostada." << endl;
        }

        cout << "Saldo actual: " << diners << "$" << endl;
    }
    else if (opcio == 2) {
        cout << "Has sortit del joc." << endl;
    }
    else {
        cout << "Opcio no valida." << endl;
    }
}

int main() {
    srand(time(0));  // Inicialitzar la llavor per als nombres aleatoris

    int saldo = 100;  // Saldo inicial del jugador

    while (saldo > 0) {
        jugar(saldo);

        if (saldo <= 0) {
            cout << "Has quedat sense diners. Fi del joc." << endl;
        }
    }

    return 0;
}