#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string expresion; //Variable donde se almacena expresion aritmetica del usuario
    
    cout << "Ingrese una expresion: ";
    getline(cin, expresion);

    int i = 0; //iterador iniciado en cero

	//Bucle mientras el iterador sea menor a la longitud de la expresion
    while (i < expresion.length()) {

        // Ignorar espacios
        if (isspace(expresion[i])) {
            i++;
            continue;
        }

        // NUMEROS ENTEROS O REALES
        if (isdigit(expresion[i])) {

            string parteEntera = "";
            string parteDecimal = "";

            // Leer parte entera
            while (i < expresion.length() && isdigit(expresion[i])) {
                parteEntera += expresion[i];
                i++;
            }

            cout << "NUMERO " << parteEntera << "  ";

            // Verificar decimal
            if (i < expresion.length() && expresion[i] == '.') {
                i++; // saltar el punto

                // Leer parte decimal
                while (i < expresion.length() && isdigit(expresion[i])) {
                    parteDecimal += expresion[i];
                    i++;
                }

                if (parteDecimal != "") {
                    cout << "DECIMAL " << parteDecimal << "  ";
                } else {
                    cout << "ERROR . sin decimales" << "  ";
                }
            }

            continue;
        }

        // OPERADORES
        if (expresion[i] == '+' ||
            expresion[i] == '-' ||
            expresion[i] == '*' ||
            expresion[i] == '/') {

            cout << "OPERADOR " << expresion[i] << "  ";
            i++;
            continue;
        }

        // PARENTESIS IZQ
        if (expresion[i] == '(') {
            cout << "PAREN_IZQ (";
            i++;
            continue;
        }

        // PARENTESIS DER
        if (expresion[i] == ')') {
            cout << "PAREN_DER )";
            i++;
            continue;
        }
        
		// CORCHETE IZQ
        if (expresion[i] == '[') {
            cout << "CORCH_IZQ [";
            i++;
            continue;
        }

        // CORCHETE DER
        if (expresion[i] == ']') {
            cout << "CORCH_DER ]";
            i++;
            continue;
        }
        
        // LLAVE IZQ
        if (expresion[i] == '{') {
            cout << "LLAVE_IZQ {";
            i++;
            continue;
        }

        // LLAVE DER
        if (expresion[i] == '}') {
            cout << "LLAVE_DER }";
            i++;
            continue;
        }

        // OPERANDOS
        if (isalpha(expresion[i])) {

            string operando = "";

            while (i < expresion.length() &&
                  (isalnum(expresion[i]) || expresion[i] == '_')) {

                operando += expresion[i];
                i++;
            }

            cout << "OPERANDO " << operando << "  ";
            continue;
        }
        
		// ERROR
        cout << "ERROR " << expresion[i] << "  ";
        i++;
    }

    return 0;
}