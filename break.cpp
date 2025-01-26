#include <iostream>
using namespace std;

int main() {
    int lista[] = {1, 2, 3, 4, 5, 6, 6, 8, 9, 10};
    int objetivo = 6;

    for (int i = 0; i < 10; i++) {
        if (lista[i] == objetivo) {
            cout << "Elemento encontrado en la posición " << i << endl;
            break; // Salimos del bucle porque ya encontramos el elemento
        }
    }
    return 0;
}
