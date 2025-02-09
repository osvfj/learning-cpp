#include <iostream>

using namespace std;

int main() {
  int opcion = 0;

  /*
    Agregamos directamente el valor de la condición en "true", así se mantendrá
    ejecutando el programa "infinitamente" hasta que el usuario intervenga y
    decida salir.
  */
  while (true) {
    cout << "\nMenú de Opciones:" << endl;
    cout << "1. Calcular factorial" << endl;
    cout << "2. Mostrar serie de Fibonacci hasta un límite" << endl;
    cout << "3. Salir" << endl;
    cout << "Elija una opción: ";
    cin >> opcion;

    // Evaluamos cada caso en base a la selección del usuario
    switch (opcion) {
      case 1: {
        int numero;
        cout << "Ingrese un número para calcular su factorial: ";
        cin >> numero;
        if (numero < 0) {
          cout << "El factorial no está definido para números negativos."
               << endl;
        } else {
          unsigned long long resultado = 1;
          int contador = numero;
          while (contador > 1) {
            resultado *= contador;
            contador--;
          }
          cout << "El factorial de " << numero << " es: " << resultado << endl;
        }
        break;
      }
      case 2: {
        int limite;
        cout << "Ingrese el límite para la serie de Fibonacci: ";
        cin >> limite;
        cout << "Serie de Fibonacci hasta " << limite << ":" << endl;
        int a = 0, b = 1;
        while (a <= limite) {
          cout << a << " ";
          int siguiente = a + b;
          a = b;
          b = siguiente;
        }
        cout << endl;
        break;
      }
      case 3: {
        cout << "Saliendo del programa. Hasta luego." << endl;
        return 0;
      }
      default: {
        cout << "Opción inválida. Por favor, elija una opción correcta."
             << endl;
      }
    }

    return 0;
  }
}