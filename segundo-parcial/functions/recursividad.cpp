#include <iostream>

using namespace std;

int factorial(int n);

int main() {
    int numero;
    cout << "Introduce un número para calcular su factorial: ";
    cin >> numero;

    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;

    return 0;
}

// Definición de la función recursiva
int factorial(int n) {
    if (n <= 1) { // Caso base, evitamos que la función corra indefinidamente.
        return 1;
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

