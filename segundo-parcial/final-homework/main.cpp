#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

const string NOMBRE_EMPLEADOS_ARCHIVOS = "empleados.txt";
const string NOMBRE_DEPARTAMENTOS_ARCHIVOS = "departamentos.txt";

struct Empleado {
    int id_empleado;
    char nombre_empleado[50];
    float horas_trabajadas;
    float precio_por_hora;
}empleado;

struct Departamento {
    int id_departamento;
    char nombreDepartamento[50]; 
    char sucursalDepartamento[50];
}departamento;


void agregarEmpleado(ofstream* archivo){
    cout << "Ingresa el id del empleado: ";
    cin >> empleado.id_empleado;
    *archivo << empleado.id_empleado << "\t";

    cout << "Nombre del empleado: ";
    cin >> empleado.nombre_empleado;
    *archivo << empleado.nombre_empleado << "\t";

    do {
        cout << "Horas trabajadas: ";
        cin >> empleado.horas_trabajadas;
        *archivo << empleado.horas_trabajadas << "\t";
    } while (empleado.horas_trabajadas <= 0);

    
    do {
        cout << "Precio de la hora: ";
        cin >> empleado.precio_por_hora;
        *archivo << empleado.precio_por_hora << "\n";
    } while (empleado.precio_por_hora <= 0);

    archivo->close();
}



void listarEmpleados(ifstream* archivo) {
    cout << setw(5) << "ID" 
         << setw(20) << "Nombre" 
         << setw(10) << "Horas" 
         << setw(15) << "Precio/Hora" 
         << setw(15) << "Sueldo Bruto" 
         << setw(15) << "Seguro Médico" 
         << setw(15) << "Cooperativa" 
         << setw(18) << "Total Descuento"
         << setw(15) << "Sueldo Neto" << endl;

    cout << setw(5) << "---" 
         << setw(20) << "------" 
         << setw(10) << "-----" 
         << setw(15) << "-----------" 
         << setw(15) << "------------" 
         << setw(15) << "-------------" 
         << setw(15) << "-----------" 
         << setw(18) << "---------------"
         << setw(15) << "------------" << endl;

    while (*archivo >> empleado.id_empleado >> empleado.nombre_empleado >> empleado.horas_trabajadas >> empleado.precio_por_hora) {
        float sueldo_bruto = empleado.horas_trabajadas * empleado.precio_por_hora;
        float seguro_medico = sueldo_bruto * 0.012;
        float cooperativa = sueldo_bruto * 0.05;
        float total_descuento = seguro_medico + cooperativa;
        float sueldo_neto = sueldo_bruto - total_descuento;

        cout << setw(5) << empleado.id_empleado 
             << setw(20) << empleado.nombre_empleado 
             << setw(10) << empleado.horas_trabajadas 
             << setw(15) << empleado.precio_por_hora 
             << setw(15) << sueldo_bruto 
             << setw(15) << seguro_medico 
             << setw(15) << cooperativa 
             << setw(18) << total_descuento
             << setw(15) << sueldo_neto << endl;
    }
    archivo->close();
}


void agregarDepartamento(ofstream* archivo){
    cout << "Ingresa el id del departamento: ";
    cin >> departamento.id_departamento;
    *archivo << departamento.id_departamento << "\t";

    cout << "Nombre del departamento: ";
    cin >> departamento.nombreDepartamento;
    *archivo << departamento.nombreDepartamento << "\t";
    
    cout << "Sucursal del departamento: ";
    cin >> departamento.sucursalDepartamento;
    *archivo << departamento.sucursalDepartamento << "\n";

    archivo->close();
}



void listarDepartamentos(ifstream* archivo) {
    cout << setw(5) << "ID" 
         << setw(30) << "Nombre Departamento" 
         << setw(30) << "Sucursal" << endl;

    cout << setw(5) << "---" 
         << setw(30) << "-------------------" 
         << setw(30) << "--------" << endl;

    while (*archivo >> departamento.id_departamento 
                   >> departamento.nombreDepartamento 
                   >> departamento.sucursalDepartamento) {
        cout << setw(5) << departamento.id_departamento 
             << setw(30) << departamento.nombreDepartamento 
             << setw(30) << departamento.sucursalDepartamento << endl;
    }
    archivo->close();
}


int main(){
    ofstream empleados;
    ofstream departamentos;
    ifstream empleadosDb;
    ifstream departamentosDb;

    while(true){
            int opt;
            cout << "-------------------------------------------------";
            cout << "\n1. Añadir empleado\n";
            cout << "2. Añadir departamento\n";
            cout << "3. Listar empleados\n";
            cout << "4. Listar departamentos\n";
            cout << "5. Eliminar empleado\n";
            cout << "6. Eliminar departamento\n";
            cout << "7. Salir\n";
            cout << "-------------------------------------------------\n";
            cout << "Opt: ";
            cin >> opt;

            switch (opt){
                case 1:
                    empleados.open(NOMBRE_EMPLEADOS_ARCHIVOS, ios::app);
                    if(empleados.fail()){
                        cout << "Error abriendo el archivo";
                        exit(1);
                    }
                    agregarEmpleado(&empleados);
                    break;
                case 2:
                    departamentos.open(NOMBRE_DEPARTAMENTOS_ARCHIVOS, ios::app);
                    if(departamentos.fail()){
                        cout << "Error abriendo el archivo";
                        exit(1);
                    }
                    agregarDepartamento(&departamentos);
                    break;
                case 3:
                    empleadosDb.open(NOMBRE_EMPLEADOS_ARCHIVOS, ios::in);
                    if(empleadosDb.fail()){
                        cout << "Error abriendo el archivo";
                    }
                    listarEmpleados(&empleadosDb);
                    break;
                case 4:
                    departamentosDb.open(NOMBRE_DEPARTAMENTOS_ARCHIVOS, ios::in);
                    if(departamentosDb.fail()){
                        cout << "Error abriendo el archivo";
                    }
                    listarEmpleados(&departamentosDb);
                    break;
                case 7:
                    return 0;
            }
        }



        return 0;
}