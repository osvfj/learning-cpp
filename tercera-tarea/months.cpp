#include <iostream>
#include <string>

using namespace std;

int main() {
    int mes;

    cout << "Ingrese un número entre 1 y 12: ";
    cin >> mes;

    string nombreMes;
    switch (mes) {
        case 1:
            nombreMes = "Enero";
            break;
        case 2:
            nombreMes = "Febrero";
            break;
        case 3:
            nombreMes = "Marzo";
            break;
        case 4:
            nombreMes = "Abril";
            break;
        case 5:
            nombreMes = "Mayo";
            break;
        case 6:
            nombreMes = "Junio";
            break;
        case 7:
            nombreMes = "Julio";
            break;
        case 8:
            nombreMes = "Agosto";
            break;
        case 9:
            nombreMes = "Septiembre";
            break;
        case 10:
            nombreMes = "Octubre";
            break;
        case 11:
            nombreMes = "Noviembre";
            break;
        case 12:
            nombreMes = "Diciembre";
            break;
        default:
            cout << "Número inválido. Por favor, ingrese un número entre 1 y 12." << endl;
            return 1;
    }

    cout << "El mes correspondiente al número " << mes << " es: " << nombreMes << endl;

    return 0;
}
