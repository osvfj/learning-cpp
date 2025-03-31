#include <iostream>
#include <string>

using namespace std;


int longitud(string text){
	int i;
	while(text[i] != '\0'){
		i++;
	}
	return i;
}

string invertir(string text){
	string invertido = "";
	for(int i=longitud(text); i >= 0; i--){
		invertido += text[i];
	}
	return invertido;
}

int main(){
	string texto;
	cout << "Ingresa una cadena de texto: ";
	cin >> texto;

	cout << invertir(texto);
}
