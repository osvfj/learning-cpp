#include <iostream>
using namespace std;

double calcularPotencia(double base, int exponente) {
   
    double resultado = 1.0;
    for (int i = 0; i < exponente; ++i) {
        resultado *= base;
    }
    
    return resultado;
}

int main() {
    double base;
    int exponente;
    
    cout << "Ingresa la base: ";
    cin >> base;
    cout << "Ingresa la potencia: ";
    cin >> exponente;
    

    cout << "Resultado: " << calcularPotencia(base, exponente) << endl;
    return 0;
}