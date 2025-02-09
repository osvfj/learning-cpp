#include <iostream>
using namespace std;

int main() {
  int estudiantes;
  double p1, p2, notaFinal;
  char calificacion;

  do {
    cout << "Ingresa el número de estudiantes: ";
    cin >> estudiantes;
  } while (estudiantes < 1);

  for (int i = 1; i <= estudiantes; i++) {
    do {
      cout << "Ingrese la calificación para el estudiante #" << i
           << " del primer parcial (0-45): ";
      cin >> p1;
    } while (p1 < 0 || p1 > 45);

    do {
      cout << "Ingrese la calificación para el estudiante #" << i
           << " del segundo parcial (0-55): ";
      cin >> p2;
    } while (p2 < 0 || p2 > 55);

    notaFinal = p1 + p2;

    if (notaFinal >= 90) {
      calificacion = 'A';
    } else if (notaFinal >= 80) {
      calificacion = 'B';
    } else if (notaFinal >= 70) {
      calificacion = 'C';
    } else {
      calificacion = 'D';
    }

    cout << "La calificación final es: " << notaFinal << " (" << calificacion
         << ")" << endl;
  }
  return 0;
}
