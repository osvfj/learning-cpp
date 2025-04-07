#include <iostream>

using namespace std;

// Prototipos de funciones, no es necesario nombrar los parámetros
void modificarValorPorValor(int);
void modificarValorPorReferencia(int&);

int main() {
    int numero1 = 5;
    int numero2 = 5;

    cout << "Valor original antes de la función (pase por valor): " << numero1 << endl;
    modificarValorPorValor(numero1); // Llamamos a la función con el valor de 'numero1'
    cout << "Valor original después de la función (pase por valor): " << numero1 << endl; // No cambia

    cout << "Valor original antes de la función (pase por referencia): " << numero2 << endl;
    modificarValorPorReferencia(numero2); // Llamamos a la función con el valor de 'numero2'
    cout << "Valor original después de la función (pase por referencia): " << numero2 << endl; // Cambia

    return 0;
}

void modificarValorPorValor(int num) {
    num = num * 2;
    cout << "Valor modificado dentro de la función (pase por valor): " << num << endl;
}

void modificarValorPorReferencia(int& num) {
    num = num * 2; 
    cout << "Valor modificado dentro de la función (pase por referencia): " << num << endl;
}

