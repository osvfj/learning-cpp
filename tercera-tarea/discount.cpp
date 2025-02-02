#include <iostream>
#include <string>

using namespace std;

int main(){

	string nombre;
	float monto;
	float descuento;
	float DESCUENTO_PORCENTAJE = 0.20;
	float MAX_PRECIO = 6200;

	cout << "Ingresa tu nombre: ";
	getline(cin, nombre);

	cout << "Ingresa el monto total: ";
	cin >> monto;

	cout << "\n\tCliente: " << nombre << endl;
	cout << "\n\tMonto factura: " <<  monto << endl;

	if(monto > MAX_PRECIO){
		descuento = monto * DESCUENTO_PORCENTAJE;
		cout << "\n\tDescuento: " << descuento << endl;
	}

	cout << "\n\tMonto final a pagar: " <<  monto - descuento << endl;

	return 0;
}
