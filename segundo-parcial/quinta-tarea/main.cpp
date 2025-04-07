#include <iostream>
#include <string>

using namespace std;

const int NUMERO_DE_EMPLEADOS = 10;

struct Empleado {
    int id;
    string nombre;
    int horas_trabajadas;
    float precio_por_hora;
    float sueldo_bruto;
    float seguro_medico;
    float cooperativa;
    float total_descuento;
    float sueldo_neto;

    void calcularSalario() {
        sueldo_bruto = horas_trabajadas * precio_por_hora;
    }

    void calcularSeguroMedico(){
        seguro_medico = sueldo_bruto * 0.012;
    }

    void calcularCooperativa(){
        cooperativa = sueldo_bruto * 0.05;
    }

    void calcularTotalDescuento(){
        total_descuento = seguro_medico + cooperativa;
    }

    void calcularSueldoNeto(){
        sueldo_neto = sueldo_bruto - total_descuento;
    }


}empleados[NUMERO_DE_EMPLEADOS];


void agregarEmpleado(){
    for(int i = 0; i < NUMERO_DE_EMPLEADOS; i++){
        if(!empleados[i].id){
            empleados[i].id = i;
            cout << "Nombre del empleado: ";
            cin >> empleados[i].nombre;      

            do {
                cout << "Horas trabajadas: ";
                cin >> empleados[i].horas_trabajadas;
            } while (empleados[i].horas_trabajadas <= 0);

            
            do {
                cout << "Precio de la hora: ";
                cin >> empleados[i].precio_por_hora;
            } while (empleados[i].precio_por_hora <= 0);
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