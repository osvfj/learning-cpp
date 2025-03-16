#include <iostream>
#include <string>

int main() {
    const int MAX_TELEFONOS = 10;
    std::string telefonos[MAX_TELEFONOS];
    int contador = 0;

    std::cout << "Ingrese hasta " << MAX_TELEFONOS << " números de teléfono (ingrese 'fin' para terminar):" << std::endl;

    for (int i = 0; i < MAX_TELEFONOS; ++i) {
        std::cout << "Número " << (i + 1) << ": ";
        std::getline(std::cin, telefonos[i]);

        if (telefonos[i] == "fin") {
            break;
        }

        contador++;
    }

    std::cout << "\nNúmeros de teléfono ingresados:" << std::endl;
    for (int i = 0; i < contador; ++i) {
        std::cout << telefonos[i] << std::endl;
    }

    return 0;
}

