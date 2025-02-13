#include <iostream>
#include <string>

using namespace std;

int main() {
  string dueño = "";
  float cantidadTotal = 0.00;
  bool seguir = false;

  cout << "Digite su nombre: ";
  getline(cin, dueño);

  cout << "Digite monto de apertura: ";
  cin >> cantidadTotal;

  do {
    char continuar;
    cout << "¿Desea continuar? (S/n) ";
    cin >> continuar;

    switch (continuar) {
      case 's':
        seguir = true;
        break;
      case 'n':
        exit(0);
      default:
        continue;
        break;
    }
  } while (!seguir);

  cout << "Continue...";

  return 0;
}