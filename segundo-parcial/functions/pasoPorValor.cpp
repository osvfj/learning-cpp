#include <iostream>

using namespace std;

void modificarValor(int num) {
    num = num * 2; // Modificamos el valor local
    cout << "Valor modificado dentro de la función: " << num << endl;
}

int main() {
    int numero = 5;
    cout << "Valor original antes de la función: " << numero << endl;

    modificarValor(numero); // Llamamos a la función con el valor de 'numero'

    cout << "Valor original después de la función: " << numero << endl; // El valor original no cambia

    return 0;
}

