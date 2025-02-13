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

    if (continuar == 's') {
      seguir = true;
      break;
    } else if (continuar == 'n') {
      exit(0);
    }

  } while (!seguir);

  cout << "Continue...";

  return 0;
}