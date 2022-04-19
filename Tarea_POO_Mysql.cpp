// Tarea_POO_Mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include "Producto.h"

using namespace std;
int q_estado;

void marcas();
void producto();

int main() {
   int a, b;
    do {
        
        cout << "Seleccione una Opcion:\n";
        cout << "1.Ingresar A Marcas:\n";
        cout << "2.Ingresar A Productos:\n";
        cin >> a;

        switch (a) {
        case 1:
            marcas(); break;
        case 2:
            producto(); break;
        default:
            cout << "El numero seleccionado no es una opcion, vuelva a intentarlo";
        }

        cout << "Realizar otra accion? (s/n): ";
        cin >>b;
    } while (b == 's' || b == 'S');
    return 0;
}

void marcas() {
    
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empres@123", "id_empresa2", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion Exitosa.." << endl;
        string marca;
        cout << "Ingrese Marca:";
        cin >> marca;
        string insert = "insert into marcas(marca) values (' " + marca + " ')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitosa.." << endl;
        }
        else {
            cout << "XXXX Error al Ingresar XXXX" << endl;
        }
        string cosulta = "select * from marcas;";
        const char* c = cosulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "Error en el select xxx" << endl;
        }    
    }
    else {
    cout << "No hay Conexion xxx " << endl;
    }
    
    system("pause");
}

void producto() {

    Producto c = Producto ();
    c.leer();

   

}