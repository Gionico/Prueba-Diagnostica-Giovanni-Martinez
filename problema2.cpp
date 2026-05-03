#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

// Verifica si una pieza es válida
bool piezaValida(char c) {
    string piezas = "prnbqkPRNBQK";
    return piezas.find(c) != string::npos;
}

// Verifica si una cadena es número entero
bool esNumero(string s) {

    if (s.empty())
        return false;

    for (char c : s) {
        if (!isdigit(c))
            return false;
    }

    return true;
}

int main() {

    string fen;

    cout << "Ingrese cadena FEN:\n";
    getline(cin, fen);

    stringstream ss(fen); //convertimos la cadena fen en un stream

    vector<string> campos; //Se almacena cada parte de la cadena FEN
    string temp;

    // Separar por espacios
    while (ss >> temp) {
        campos.push_back(temp);
    }

    // VALIDAR 6 CAMPOS
    if (campos.size() != 6) {
        cout << "FEN INVALIDO: Debe tener 6 campos" << endl;
        return 0;
    }

    // CAMPO 1: TABLERO
    string tablero = campos[0];

    vector<string> filas; //Vector donde se van almacenando el contenido de cada fila
    string fila = ""; //Acumalador de contenido de fila

	//Recorrido de tablero 
    for (char c : tablero) {
		
        if (c == '/') {//Llega a final de fila
            filas.push_back(fila);
            fila = "";
        }
        else {//Sigue acumulando
            fila += c; 
        }
    }

    filas.push_back(fila);

    // Deben existir 8 filas
    if (filas.size() != 8) {
        cout << "FEN INVALIDO: El tablero debe tener 8 filas" << endl;
        return 0;
    }

    // Validar cada fila
    for (string f : filas) {

        int suma = 0;

        for (char c : f) {

            if (isdigit(c)) {
                suma += c - '0';
            }
            else if (piezaValida(c)) {
                suma++;
            }
            else {
                cout << "FEN INVALIDO: Pieza invalida -> " << c << endl;
                return 0;
            }
        }

        if (suma != 8) {
            cout << "FEN INVALIDO: Una fila no suma 8 casillas" << endl;
            return 0;
        }
    }

    // CAMPO 2: TURNO
    if (!(campos[1] == "w" || campos[1] == "b")) {
        cout << "FEN INVALIDO: Turno invalido" << endl;
        return 0;
    }

    // CAMPO 3: ENROQUE
    string enroque = campos[2];

    if (enroque != "-") {

        for (char c : enroque) {

            if (string("KQkq").find(c) == string::npos) {
                cout << "FEN INVALIDO: Enroque invalido" << endl;
                return 0;
            }
        }
    }

    // CAMPO 4: EN PASSANT
    string enpassant = campos[3];

    if (enpassant != "-") {

        if (enpassant.length() != 2) {
            cout << "FEN INVALIDO: En passant invalido" << endl;
            return 0;
        }

        char columna = enpassant[0];
        char filaEP = enpassant[1];

        if (!(columna >= 'a' && columna <= 'h' &&
              filaEP >= '1' && filaEP <= '8')) {

            cout << "FEN INVALIDO: En passant invalido" << endl;
            return 0;
        }
    }

    // CAMPOS 5 Y 6
    if (!esNumero(campos[4])) {
        cout << "FEN INVALIDO: Halfmove incorrecto" << endl;
        return 0;
    }

    if (!esNumero(campos[5])) {
        cout << "FEN INVALIDO: Fullmove incorrecto" << endl;
        return 0;
    }

    cout << "FEN VALIDO" << endl;

    return 0;
}