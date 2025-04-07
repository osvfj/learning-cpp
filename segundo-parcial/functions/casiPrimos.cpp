#include <iostream>
using namespace std;

int TAM = 5;

void llenarArreglo(int numeros[TAM]) {
    for(int i = 0; i < TAM; i++){
        cout << "Ingrese numero " << i+1 << ": ";
        cin >> numeros[i];
    }
}

bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for(int i = 3; i*i <= n; i += 2)
        if(n % i == 0) return false;
    
    return true;
}

bool esCasiPrimo(int n) {
    if(n < 4) return false;
    
    int factores = 0;
    int temp = n;
    
    for(int d = 2; d <= temp; d++) {
        while(temp % d == 0) {
            if(esPrimo(d)) { 
                factores++;
            }
            temp /= d;
        }
    }
    
    return factores == 2; 
}

int main() {
    int numeros[TAM];
    
    llenarArreglo(numeros);
    
    cout << "\nNumeros casi primos:\n";
    for(int i = 0; i < TAM; i++){
        if(esCasiPrimo(numeros[i])){
            cout << numeros[i] << " ";
        }
    }
    
    return 0;
}