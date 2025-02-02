#include <iostream>

int main(){

	int edad;

	std::cout << "Ingresa tu edad: ";
	std::cin >> edad;

	if(edad >= 18){
		std::cout << "Eres mayor de edad\n";
	} else {
		std::cout << "Eres menor de edad\n";
	}

	return 0;
}
