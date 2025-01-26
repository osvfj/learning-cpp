#include <iostream>

int main(){

    int edad = 18;
    int tieneCedula = false;
    if(edad >= 18){
	if(tieneCedula){
	  std::cout << "Eres mayor y tienes tu cédula, puedes entrar. \n";
	} else {
	  std::cout << "Eres mayor, pero sin tu cédula, no puedes entrar. \n";
	}
    } else {
	std::cout << "No eres mayor de edad, no puedes entrar." << std::endl; 	
    }

    return 0;
}
