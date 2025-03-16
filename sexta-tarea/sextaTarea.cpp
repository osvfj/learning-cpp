#include <iostream>
#include <string>
using namespace std;

int main() {
  string nombre;
  cout << "Ingrese el nombre del cliente: ";
  getline(cin, nombre);

  double subtotal = 0.0, descuento = 0.0;
  char opcion;

  do {
    int cantidad;
    double precio;
    cout << "Ingrese la cantidad de articulos: ";
    cin >> cantidad;
    cout << "Ingrese el precio unitario: ";
    cin >> precio;

    double item_subtotal = cantidad * precio;
    subtotal += item_subtotal;

    char desc;
    cout << "Desea descuento para este articulo? (s/n): ";
    cin >> desc;

    if (desc == 's' || desc == 'S') {
      descuento += item_subtotal * 0.1;
    }

    cout << "Desea continuar facturando otro articulo? (s/n): ";
    cin >> opcion;
  } while (opcion == 's' || opcion == 'S');

  cout << "CLIENTE: " << nombre << endl;
  cout << "SUB-TOTAL: " << subtotal << endl;
  cout << "DESCUENTO: " << descuento << endl;
  cout << "TOTAL A PAGAR: " << (subtotal - descuento) << endl;

  return 0;
}