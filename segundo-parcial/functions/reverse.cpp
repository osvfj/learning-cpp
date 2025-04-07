#include <iostream>

using namespace std;

int longitud(char* text) {
    char* ptr = text;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - text;
}

void invertir(char* text){

	char* inicio = text;
	char* fin = text + longitud(text) - 1;

	while(inicio < fin){
		char temp = *inicio;
		*inicio = *fin;
		*fin = temp;

		inicio++;
		fin--;
	}
}

int main(){
	char texto[100];
	cout << "Ingresa una cadena de texto: ";
	cin >> texto;

	
	 invertir(texto);

}
