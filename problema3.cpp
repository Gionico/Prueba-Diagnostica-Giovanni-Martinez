#include <iostream>

using namespace std;

int main() {

    int minimo, maximo;

    cout << "Ingrese el numero minimo: ";
    cin >> minimo;

    cout << "Ingrese el numero maximo: ";
    cin >> maximo;

    // Validar intervalo
    if (minimo <= 0 || maximo <= 0 || minimo > maximo) {
        cout << "Intervalo invalido" << endl;
        return 0;
    }

    // Recorrer todos los numeros
    for (int n = minimo; n <= maximo; n++) {

       	int numero = n;

        cout << "\n======================" << endl;
        cout << "Secuencia para " << n << endl;
        cout << "======================" << endl;

        // Imprimir numero inicial
        cout << numero;

        // Aplicar Collatz hasta llegar a 1
        while (numero != 1) {

            // Si es par
            if (numero % 2 == 0) {
                numero = numero / 2;
            }
            // Si es impar
            else {
                numero = 3 * numero + 1;
            }

            cout << " -> " << numero;
        }

        cout << endl;
    }

    return 0;
}