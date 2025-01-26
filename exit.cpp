#include <iostream>
#include <cstdlib> // Para usar exit()
using namespace std;

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int valorBuscado = 30;

    for (int i = 0; i < 5; i++) {
        if (array[i] == valorBuscado) {
            cout << "Valor encontrado en la posición " << i << endl;
            exit(0); // Termina el programa
        }
        cout << "Buscando... (" << array[i] << ")" << endl;
    }

    cout << "El valor no fue encontrado." << endl;
    return 0;
}
