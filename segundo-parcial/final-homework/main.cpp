#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

const string NOMBRE_EMPLEADOS_ARCHIVO = "empleados.txt";
const string NOMBRE_DEPARTAMENTOS_ARCHIVO = "departamentos.txt";

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



void esperarEnter();
void agregarEmpleado(ofstream* archivo, ifstream* db);
void eliminarEmpleado(ofstream* archivo, ifstream* db);
void listarEmpleados(ifstream* archivo);
void agregarDepartamento(ofstream* archivo, ifstream* db);
void listarDepartamentos(ifstream* archivo);
void eliminarDepartamento(ofstream* archivo, ifstream* db);


int main(){
    ofstream empleados;
    ofstream departamentos;
    ifstream empleadosDb;
    ifstream departamentosDb;

    while(true){
            system("cls");
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
                    agregarEmpleado(&empleados, &empleadosDb);
                    break;
                case 2:
                    agregarDepartamento(&departamentos, &departamentosDb);
                    break;
                case 3:
                    listarEmpleados(&empleadosDb);
                    break;
                case 4:
                    listarDepartamentos(&departamentosDb);
                    break;
                 case 5:
                    eliminarEmpleado(&empleados, &empleadosDb);
                    break;
                case 6:
                    eliminarDepartamento(&departamentos, &departamentosDb);
                    break;
                case 7:
                    return 0;
            }
        }



    return 0;
}






/* 
    "Simulación de getch", debido a que mi compilador no tiene la cabecera conio.h
*/
void esperarEnter() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(); 
    cin.get();
}

void agregarEmpleado(ofstream* archivo, ifstream* db){
    archivo->open(NOMBRE_EMPLEADOS_ARCHIVO, ios::app);
    db->open(NOMBRE_EMPLEADOS_ARCHIVO, ios::in);
    if(archivo->fail() || db->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        exit(1);
    }

    int id;

    if (*db >> empleado.id_empleado){
        do {
            cout << "Ingresa el id del empleado: ";
            cin >> id;
            if(id == empleado.id_empleado){
                cout << "Ya existe un usuario con este ID\n";
            }
        } while(id == empleado.id_empleado);
    } else {
        cout << "Ingresa el id del empleado: ";
        cin >> id;
    }

    empleado.id_empleado = id;
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
    db->close();
}



void eliminarEmpleado(ofstream* archivo, ifstream* db) {
    int idAEliminar;
    cout << "Ingresa el id del empleado: ";
    cin >> idAEliminar;


    db->open(NOMBRE_EMPLEADOS_ARCHIVO, ios::in);
    if(db->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        return;
    }

    Empleado* empleados = nullptr; 
    int contador = 0;
    int tamano = 5; 

    empleados = new Empleado[tamano];

    while (*db >> empleados[contador].id_empleado >> empleados[contador].nombre_empleado >> empleados[contador].horas_trabajadas >> empleados[contador].precio_por_hora) {
            contador++;
            if (contador >= tamano) {
                tamano *= 2; 
                Empleado* nuevosEmpleados = new Empleado[tamano];
                for (int i = 0; i < contador; i++) {
                    nuevosEmpleados[i] = empleados[i]; 
                }
                delete[] empleados; 
                empleados = nuevosEmpleados; 
            }
    }

    db->close();

    archivo->open(NOMBRE_EMPLEADOS_ARCHIVO, ios::out);

    bool encontrado = false;

    for (int i = 0; i < contador; i++) {
        if (empleados[i].id_empleado == idAEliminar) {
            encontrado = true;
            continue;
        }

         *archivo << empleados[i].id_empleado << "\t"
                     << empleados[i].nombre_empleado << "\t"
                     << empleados[i].horas_trabajadas << "\t"
                     << empleados[i].precio_por_hora << "\n";
    }

    archivo->close();
    delete[] empleados; 

    if(encontrado){
          cout << "Empleado eliminado exitosamente." << endl;
    } else {
        cout << "No existe empleado con el ID especificado" << endl;
    }

    esperarEnter();
}


void listarEmpleados(ifstream* archivo) {
    float total_sueldo_bruto = 0.0;
    float total_seguro_medico = 0.0;
    float total_cooperativa = 0.0;
    float total_descuento_acomulado = 0.0;
    float total_sueldo_neto = 0.0;

    archivo->open(NOMBRE_EMPLEADOS_ARCHIVO, ios::in);
    if(archivo->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        return;
    }

    cout << setw(5) << "ID" 
         << setw(20) << "Empleado" 
         << setw(10) << "Horas trabajadas" 
         << setw(15) << "Precio x Hora" 
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

        total_sueldo_bruto += sueldo_bruto;
        total_seguro_medico += seguro_medico;
        total_cooperativa += cooperativa;
        total_descuento_acomulado += total_descuento;
        total_sueldo_neto += sueldo_neto;

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


    cout << setw(5) << "Total" 
         << setw(20) << "" 
         << setw(10) << "" 
         << setw(15) << "" 
         << setw(15) << total_sueldo_bruto 
         << setw(15) << total_seguro_medico 
         << setw(15) << total_cooperativa 
         << setw(18) << total_descuento_acomulado 
         << setw(15) << total_sueldo_neto << endl;
    archivo->close();
    esperarEnter();
}

void agregarDepartamento(ofstream* archivo, ifstream* db) {
    archivo->open(NOMBRE_DEPARTAMENTOS_ARCHIVO, ios::app);
    db->open(NOMBRE_DEPARTAMENTOS_ARCHIVO, ios::in);
    if (archivo->fail() || db->fail()) {
        cout << "Error abriendo el archivo o no existe...\n";
        exit(1);
    }

    int id;
    
   if (*db >> departamento.id_departamento) {
        do {
            cout << "Ingresa el id del departamento: ";
            cin >> id;
            if (id == departamento.id_departamento) {
                cout << "Ya existe un departamento con este ID\n";
            }
        } while (id == departamento.id_departamento);
    } else {
        cout << "Ingresa el id del departamento: ";
        cin >> id;
    }

    departamento.id_departamento = id;
    *archivo << departamento.id_departamento << "\t";

    cout << "Nombre del departamento: ";
    cin >> departamento.nombreDepartamento;
    *archivo << departamento.nombreDepartamento << "\t";

    cout << "Sucursal del departamento: ";
    cin >> departamento.sucursalDepartamento;
    *archivo << departamento.sucursalDepartamento << "\n";

    archivo->close();
    db->close();
}



void listarDepartamentos(ifstream* archivo) {

    archivo->open(NOMBRE_DEPARTAMENTOS_ARCHIVO, ios::in);
    if(archivo->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        return;
    }

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
    esperarEnter();
}


void eliminarDepartamento(ofstream* archivo, ifstream* db) {
    int idAEliminar;
    cout << "Ingresa el id del departamento: ";
    cin >> idAEliminar;


    db->open(NOMBRE_DEPARTAMENTOS_ARCHIVO, ios::in);
    if(db->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        return;
    }

    Departamento* departamentos = nullptr; 
    int contador = 0;
    int tamano = 5; 

    departamentos = new Departamento[tamano];

    while (*db >> departamentos[contador].id_departamento >> departamentos[contador].nombreDepartamento >> departamentos[contador].sucursalDepartamento) {
        contador++;
        if (contador >= tamano) {
            tamano *= 2; 
            Departamento* nuevosDepartamentos = new Departamento[tamano];
            for (int i = 0; i < contador; i++) {
                nuevosDepartamentos[i] = departamentos[i]; 
            }
            delete[] departamentos; 
            departamentos = nuevosDepartamentos; 
        }
    }

    db->close();

    archivo->open(NOMBRE_DEPARTAMENTOS_ARCHIVO, ios::out);
    if(archivo->fail()){
        cout << "Error abriendo el archivo o no existe...\n";
        exit(1);
    }

    bool encontrado = false;

    for (int i = 0; i < contador; i++) {
        if (departamentos[i].id_departamento == idAEliminar) {
            encontrado = true;
            continue;
        } 


         *archivo << departamentos[i].id_departamento << "\t"
                     << departamentos[i].nombreDepartamento << "\t"
                     << departamentos[i].sucursalDepartamento << "\n";
    }

    archivo->close();
    delete[] departamentos; 

    cout << "Departamento eliminado exitosamente." << endl;

    if (encontrado) {
        cout << "Departamento eliminado exitosamente." << endl;
    } else {
        cout << "No existe un departamento con el ID especificado." << endl;
    }

    esperarEnter();

}