#include <iostream>
#include <fstream>

using namespace std;

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

int main(){
    ofstream empleados;
    ofstream departamentos;

    while(true){
            system("clear");
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
                    empleados.open("empleados.txt", ios::app);
                    if(empleados.fail()){
                        cout << "Error abriendo el archivo";
                        exit(1);
                    }
                    agregarEmpleado(&empleados);
                    break;
                case 2:
                    departamentos.open("departamentos.txt", ios::app);
                    if(departamentos.fail()){
                        cout << "Error abriendo el archivo";
                        exit(1);
                    }
                    agregarDepartamento(&departamentos);
                    break;
                case 7:
                    return 0;
            }
        }



        return 0;
}