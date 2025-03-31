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

int invertir(string text){
	for(int i=0; i <= longitud(text); i--){
	 for (int j=0; i <= longitud(text); i++){
	 	
	 }
	}
}

int main(){
	string texto;
	cout << "Ingresa una cadena de texto: ";
	cin >> texto;



	cout << longitud(texto);

 //string reverseText = invertirTexto(texto);

}
