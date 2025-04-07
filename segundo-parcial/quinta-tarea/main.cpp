#include <iostream>
#include <string>

using namespace std;

const int NUMERO_DE_EMPLEADOS = 10;

struct Empleado {
    int id;
    string nombre;
    int horas_trabajadas;
    int precio_por_hora;
}empleados[NUMERO_DE_EMPLEADOS];


void agregarEmpleado(){
    for(int i = 0; i < NUMERO_DE_EMPLEADOS; i++){
        if(!empleados[i].id){
            empleados[i].id = i;
            cout << "Nombre del empleado: ";
            cin >> empleados[i].nombre;
            cout << "Horas trabajadas: ";
            cin >> empleados[i].horas_trabajadas;
            cout << "Precio de la hora: ";
            cin >> empleados[i].precio_por_hora;
            break;
        }
    }
}


int main(){

    while(true){
        int opt;
        cout << "1. Agregar empleado\n";
        cout << "2. Mostrar datos de los empleados\n";
        cout << "3. Mostrar datos de los empleados con menor precio por hora\n";
        cout << "4. Salir\n";
        cout << "Opt: ";
        cin >> opt;



        switch (opt){
            case 1:
                agregarEmpleado();
        }
    }

    return 0;
}