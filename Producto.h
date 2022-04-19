#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Producto
{
	// atributos
protected: string producto, descripcion, fecha_ingreso;
		 float precio_costo;
		 float precio_ventas;
		 int existencia = 0;
		 // costructor
protected:
	Producto() {
	}
	Producto(string pro, string des, float pre_cos, float pre_ven, int ex, string f_i) {
		producto = pro;
		descripcion = des;
		precio_costo = pre_cos;
		precio_ventas = pre_ven;
		existencia = ex;
		fecha_ingreso = f_i;
	}
	
	void setProducto(string pro) { producto = pro; }
	void setDescripcion(string des) { descripcion = des; }
	void setPrecio_costo(float pre_cos) { precio_costo = pre_cos; }
	void setPrecio_ventas(float pre_ven) { precio_ventas = pre_ven; }
	void setExistencia(int ex) { existencia = ex; }
	void setFecha_ingreso(string f_i) { fecha_ingreso = f_i; }
	//get (mostrar)
	string getProducto() { return producto; }
	string getDescripcion() { return descripcion; }
	float getPrecio_costo() { return precio_costo; }
	float getPrecio_ventas() { return precio_ventas; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Productos ------------" << endl;
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};

