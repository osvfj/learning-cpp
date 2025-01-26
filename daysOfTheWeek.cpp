#include <iostream>

int main() {
    int dia = 3;

    switch (dia) {
        case 1:
            std::cout << "Lunes" << std::endl;
            break;
        case 2:
            std::cout << "Martes" << std::endl;
            break;
        case 3:
            std::cout << "Miércoles" << std::endl;
            break;
        case 4:
            std::cout << "Jueves" << std::endl;
            break;
        case 5:
            std::cout << "Viernes" << std::endl;
            break;
        case 6:
            std::cout << "Sábado" << std::endl;
            break;
        case 7:
            std::cout << "Domingo" << std::endl;
            break;
        default:
            std::cout << "Día no válido" << std::endl;
    }

    return 0;
}
