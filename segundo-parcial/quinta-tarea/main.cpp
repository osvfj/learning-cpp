#include <iostream>
#include <string>


using namespace std;

struct Empleado {
    int id;
    string nombre;
    int horas_trabajadas;
    int precio_por_hora;
}empleados[10];

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
            
        }
    }

    return 0;
}