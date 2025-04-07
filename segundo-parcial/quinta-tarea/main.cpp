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
            empleados[i].id = i + 1;
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

void mostrarEmpleados() {
    cout << "ID\tNombre\tHoras\tPrecio/Hora\tSueldo Bruto\tSeguro Médico\tCooperativa\tTotal Descuento\tSueldo Neto" << endl;
    cout << "---\t------\t-----\t-----------\t------------\t-------------\t-----------\t---------------\t------------" << endl;

    for (int i = 0; i < NUMERO_DE_EMPLEADOS; i++) {
        if (empleados[i].id) {
            empleados[i].calcularSalario();
            empleados[i].calcularSeguroMedico();
            empleados[i].calcularCooperativa();
            empleados[i].calcularTotalDescuento();
            empleados[i].calcularSueldoNeto();

            cout << empleados[i].id << "\t" << empleados[i].nombre << "\t" << empleados[i].horas_trabajadas << "\t" << empleados[i].precio_por_hora << "\t\t" << empleados[i].sueldo_bruto << "\t\t" << empleados[i].seguro_medico << "\t\t" << empleados[i].cooperativa << "\t\t" << empleados[i].total_descuento << "\t\t" << empleados[i].sueldo_neto << endl;
        }
    }
}



int main(){

    while(true){
        int opt;
        cout << "-------------------------------------------------";
        cout << "\n1. Agregar empleado\n";
        cout << "2. Mostrar datos de los empleados\n";
        cout << "3. Mostrar datos de los empleados con menor precio por hora\n";
        cout << "4. Salir\n";
        cout << "-------------------------------------------------\n";
        cout << "Opt: ";
        cin >> opt;



        switch (opt){
            case 1:
                agregarEmpleado();
                break;
            case 2:
                mostrarEmpleados();
        }
    }

    return 0;
}