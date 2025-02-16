#include <iostream>
#include <string>

int main() {
  std::string cliente = "";
  float balanceDeApertura = 0.00;
  float deposito = 0.0f;
  float retiro = 0.0f;

  // Totales en base la acción
  float balanceTotalDepositado = 0.00;
  float balanceTotalRetirado = 0.00;
  float balanceFinal = 0.00;

  bool seguir = false;
  int tipoDeTransaccion;

  std::cout << "Digite su nombre: ";
  std::getline(std::cin, cliente);

  std::cout << "Digite monto de apertura: ";
  std::cin >> balanceDeApertura;

  balanceFinal = balanceDeApertura;

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
          std::cout << "\n Cliente: " << cliente
                    << "\n\n balanceDeApertura: " << balanceDeApertura
                    << "\n Total Depositado: " << balanceTotalDepositado
                    << "\n Total Retirado: " << balanceTotalRetirado
                    << "\n Balance Final: " << balanceFinal << std::endl;

          exit(0);
        default:
          continue;
          break;
      }
    } while (!seguir);

    std::cout << "¿Tansacción? \n";
    std::cout << "1. Depósito\n2. Retiro\n";
    std::cout << "Opción: ";
    std::cin >> tipoDeTransaccion;
    std::cout << "---------------------";

    switch (tipoDeTransaccion) {
      case 1:
        std::cout << std::endl << "Digite depósito: ";
        std::cin >> deposito;

        balanceFinal += deposito;
        balanceTotalDepositado += deposito;
        break;
      case 2:
        while (true) {
          std::cout << std::endl << "Digite retiro: ";
          std::cin >> retiro;
          if (retiro > balanceFinal) {
            std::cout << "No cuenta con los fondos necesarios para retirar esa "
                         "cantidad \n";
          } else {
            balanceFinal -= retiro;
            balanceTotalRetirado += retiro;
            break;
          }
        }
      default:
        std::cout << std::endl
                  << "Opción inválida. Por favor, intente nuevamente."
                  << std::endl;
    }
    std::cout << "---------------------" << std::endl;
  }

  return 0;
}