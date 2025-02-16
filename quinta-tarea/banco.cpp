#include <iostream>
#include <string>

using namespace std;

int main() {
  string dueño = "";
  float cantidadTotal = 0.00;
  float deposito = 0.00;
  float retiro = 0.00;

  bool seguir = false;
  int opt;

  cout << "Digite su nombre: ";
  getline(cin, dueño);

  cout << "Digite monto de apertura: ";
  cin >> cantidadTotal;

  do {
    int continuar;
    cout << "¿Desea continuar? (1. Si/2. No) ";
    cin >> continuar;

    switch (continuar) {
      case 1:
        seguir = true;
        break;
      case 2:
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

  switch (opt) {
    case 1:
      cout << "Digite depósito: ";
      cin >> deposito;

      cantidadTotal += deposito;

      cout << cantidadTotal << endl;
      break;
    case 2:
      while (true) {
        cout << "Digite retiro: ";
        cin >> retiro;
        if (retiro > cantidadTotal) {
          cout << "No cuenta con los fondos necesarios para retirar esa "
                  "cantidad \n";
        } else {
          cantidadTotal -= retiro;
          break;
        }
      }
    default:
      break;
  }

  return 0;
}