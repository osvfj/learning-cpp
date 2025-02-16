#include <iostream>
#include <string>

using namespace std;

int main() {
  string dueño = "";
  float deposito = 0.00;
  float retiro = 0.00;
  float apertura = 0.00;
  float totalDeposito = 0.00;
  float totalRetiro = 0.00;
  float cantidadTotal = 0.00;

  bool seguir = false;
  int opt;

  cout << "Digite su nombre: ";
  getline(cin, dueño);

  cout << "Digite monto de apertura: ";
  cin >> apertura;

  cantidadTotal += apertura;

  while (true) {
    do {
      int continuar;
      cout << "¿Desea continuar? (1. Si/2. No) ";
      cin >> continuar;
      cout << "---------------------" << endl;

      switch (continuar) {
        case 1:
          seguir = true;
          break;
        case 2:
          cout << "\n Cliente: " << dueño << "\n\n Apertura: " << apertura
               << "\n Total Depositado: " << totalDeposito
               << "\n Total Retirado: " << totalRetiro
               << "\n Balance Final: " << cantidadTotal << endl;

          exit(0);
        default:
          continue;
          break;
      }
    } while (!seguir);

    cout << "¿Tansacción? \n";
    cout << "1. Depósito\n2. Retiro\n";
    cout << "Opción: ";
    cin >> opt;
    cout << "---------------------";

    switch (opt) {
      case 1:
        cout << endl << "Digite depósito: ";
        cin >> deposito;

        cantidadTotal += deposito;
        totalDeposito += deposito;
        break;
      case 2:
        while (true) {
          cout << endl << "Digite retiro: ";
          cin >> retiro;
          if (retiro > cantidadTotal) {
            cout << "No cuenta con los fondos necesarios para retirar esa "
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