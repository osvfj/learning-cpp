#include <iostream>
#include <string>

int main() {
  std::string dueño = "";
  float deposito = 0.00;
  float retiro = 0.00;
  float apertura = 0.00;
  float totalDeposito = 0.00;
  float totalRetiro = 0.00;
  float cantidadTotal = 0.00;

  bool seguir = false;
  int opt;

  std::cout << "Digite su nombre: ";
  std::getline(std::cin, dueño);

  std::cout << "Digite monto de apertura: ";
  std::cin >> apertura;

  cantidadTotal += apertura;

  while (true) {
    do {
      int continuar;
      std::cout << "¿Desea continuar? (1. Si/2. No) ";
      std::cin >> continuar;
      std::cout << "---------------------" << std::endl;

      switch (continuar) {
        case 1:
          seguir = true;
          break;
        case 2:
          std::cout << "\n Cliente: " << dueño << "\n\n Apertura: " << apertura
                    << "\n Total Depositado: " << totalDeposito
                    << "\n Total Retirado: " << totalRetiro
                    << "\n Balance Final: " << cantidadTotal << std::endl;

          exit(0);
        default:
          continue;
          break;
      }
    } while (!seguir);

    std::cout << "¿Tansacción? \n";
    std::cout << "1. Depósito\n2. Retiro\n";
    std::cout << "Opción: ";
    std::cin >> opt;
    std::cout << "---------------------";

    switch (opt) {
      case 1:
        std::cout << std::endl << "Digite depósito: ";
        std::cin >> deposito;

        cantidadTotal += deposito;
        totalDeposito += deposito;
        break;
      case 2:
        while (true) {
          std::cout << std::endl << "Digite retiro: ";
          std::cin >> retiro;
          if (retiro > cantidadTotal) {
            std::cout << "No cuenta con los fondos necesarios para retirar esa "
                         "cantidad \n";
          } else {
            cantidadTotal -= retiro;
            totalRetiro += retiro;
            break;
          }
        }
      default:
        break;
    }
  }

  return 0;
}