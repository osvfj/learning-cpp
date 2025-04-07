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

Empleado empleadosOrdenados[NUMERO_DE_EMPLEADOS];


void agregarEmpleado();
void mostrarEmpleado(Empleado empleado);
void ordernarEmpleadoMenorPresio();
void mostrarDatosEmpleados();
void mostrarEmpleadosMenorMayor();


int main(){

    while(true){
        int opt;
        cout << "-------------------------------------------------";
        cout << "\n1. Agregar empleados\n";
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
                if(!empleados[0].id){
                    cout << "No hay empleados que mostrar...\n";
                    break;
                }

                mostrarDatosEmpleados();
                break;
            case 3:
                if(!empleados[0].id){
                    cout << "No hay empleados que mostrar...\n";
                    break;
                }
                mostrarEmpleadosMenorMayor();
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}





void agregarEmpleado(){
    for(int i = 0; i < NUMERO_DE_EMPLEADOS; i++){
        if(!empleados[i].id){
            empleados[i].id = i + 1;
            cout << "Nombre del empleado #" <<  i + 1 << ": ";
            cin.ignore();
            getline(cin, empleados[i].nombre);

            do {
                cout << "Horas trabajadas #" <<  i + 1 << ": ";
                cin >> empleados[i].horas_trabajadas;
            } while (empleados[i].horas_trabajadas <= 0);

            
            do {
                cout << "Precio de la hora  #" <<  i + 1 << ": ";
                cin >> empleados[i].precio_por_hora;
            } while (empleados[i].precio_por_hora <= 0);
        }
    }
}

void mostrarEmpleado(Empleado empleado) {
    if (empleado.id) {
        empleado.calcularSalario();
        empleado.calcularSeguroMedico();
        empleado.calcularCooperativa();
        empleado.calcularTotalDescuento();
        empleado.calcularSueldoNeto();

        cout << empleado.id << "\t" << empleado.nombre << "\t" << empleado.horas_trabajadas << "\t" << empleado.precio_por_hora << "\t\t" << empleado.sueldo_bruto << "\t\t" << empleado.seguro_medico << "\t\t" << empleado.cooperativa << "\t\t" << empleado.total_descuento << "\t\t" << empleado.sueldo_neto << endl;
    }
}


void ordernarEmpleadoMenorPresio(){
    for (int i = 0; i < NUMERO_DE_EMPLEADOS; i++) {
        empleadosOrdenados[i] = empleados[i];
    }


   for(int i = 0; i < NUMERO_DE_EMPLEADOS - 1; i++){
       for (int j = 0; j < NUMERO_DE_EMPLEADOS - i - 1; j++) {
              if (empleadosOrdenados[j].precio_por_hora > empleadosOrdenados[j + 1].precio_por_hora) {
                Empleado temp = empleadosOrdenados[j];
                empleadosOrdenados[j] = empleadosOrdenados[j + 1];
                empleadosOrdenados[j + 1] = temp;
            }
       }
   }

}


void mostrarDatosEmpleados(){
    cout << "ID\tNombre\tHoras\tPrecio/Hora\tSueldo Bruto\tSeguro Médico\tCooperativa\tTotal Descuento\tSueldo Neto" << endl;
    cout << "---\t------\t-----\t-----------\t------------\t-------------\t-----------\t---------------\t------------" << endl;

    for(int i = 0; i <= NUMERO_DE_EMPLEADOS; i++){
        mostrarEmpleado(empleados[i]);
    }
}

void mostrarEmpleadosMenorMayor(){
    ordernarEmpleadoMenorPresio();
    cout << "ID\tNombre\tHoras\tPrecio/Hora\tSueldo Bruto\tSeguro Médico\tCooperativa\tTotal Descuento\tSueldo Neto" << endl;
    cout << "---\t------\t-----\t-----------\t------------\t-------------\t-----------\t---------------\t------------" << endl;

    for(int i = 0; i <= NUMERO_DE_EMPLEADOS; i++){
        mostrarEmpleado(empleadosOrdenados[i]);
    }
}