#include <iostream>
using namespace std;
#include "GestorVentas.h"
#include "Concierto.h"
#include <string>
void ejercicio1() {
	bool seguir = true;
	bool vali = false;
	int contador = 0;
	bool vali2 = false;
	bool archivocargado = false;
	GestorVentas* gestor = new GestorVentas();
	Concierto* concierto = new Concierto(); 
	while (seguir) {
		cout << "Bienvenido Al Menu de Conciertos" << endl;
		cout << "--------------------------------" << endl;
		cout << "1. Agregar Concierto" << endl;
		cout << "2. Eliminar Concierto" << endl;
		cout << "3. Vender Entrada" << endl;
		cout << "4. Listar Conciertos" << endl;
		cout << "5. Cargar Conciertos desde CSV" << endl;
		cout << "6. Guardar Conciertos en CSV" << endl;
		cout << "7. Salir" << endl;
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			vali2 = false;
			string nombreBanda = " ", fechaConcierto = " ";
			double precioEntrada = 0.0, totalRecaudado = 0;
			int codigo = 0, entradasVendidas = 0;
			cout << "Ingrese el Nombre de la banda: ";
			cin.ignore();
			getline(cin, nombreBanda);
			cout << "Ingrese el precio de la entrada: ";
			cin >> precioEntrada;
			cout << "Ingrese la fecha del concierto (dd/mm/aaaa): ";
			cin.ignore();
			getline(cin, fechaConcierto);
			int contador = 0;
			if (contador != 0) {
				while (contador < gestor->getConciertosDisponibles().size()) {
					cout << "Ingrese el codigo: ";
					int codigo2 = 0;
					cin >> codigo2;
					if (codigo2 > 999 && codigo2 < 10000 && gestor->getConciertosDisponibles()[contador]->getcodigo() != codigo2) {
						codigo = codigo2; 
					}
					else {
						cout << "El codigo existe en otra banda o el codigo no cumple con la condicion que debe ser mayor a 1000 y menor a 9999" << endl;
					}
					contador++;
				}
			}
			else {
				while (!vali2 ) {
					cout << "Ingrese el codigo: ";
					codigo = 0;
					cin >> codigo;
					if (codigo > 999 && codigo < 10000) {
						vali2 = true;
					}
					else {
						cout << "El codigo existe en otra banda o el codigo no cumple con la condicion que debe ser mayor a 1000 y menor a 9999" << endl;
					}
				}
			}
				concierto = new Concierto(nombreBanda, precioEntrada, fechaConcierto, codigo, totalRecaudado, entradasVendidas);
				gestor->agregarConcierto(concierto);
				vali = true;
				contador++;
				break;
			}
		case 2: {
			// eliminando y validar si ya creo conciertos antes de querer hacer alguna opcion 
			if (vali || archivocargado) {
				gestor->listarConciertos();
				cout << "Ingrese el indice del concierto que quiere eliminar" << endl;
				int indice;
				cin >> indice;
				if (indice >= 0 && indice <= gestor->getConciertosDisponibles().size()) {
					gestor->eliminarConcierto(indice - 1);
					contador--;
				}
				else {
					cout << "Indice incorrecto" << endl;
				}
			}
			else {
				cout << "Cree un concierto antes de querer eliminarlo o carguelos del archivo" << endl;
			}
			if (contador == 0) {
				vali = false;
			}
			break;
		}
		case 3: {
			// pido datos y vendo entradas 
			if (vali || archivocargado) {
				gestor->listarConciertos();
				cout << "Ingrese el indice del concierto al que desea vender entradas" << endl;
				int indice;
				cin >> indice;
				cout << "Ingrese la cantidad de entradas a vender" << endl;
				int ventas;
				cin >> ventas;
				if (indice >= 0 && indice <= gestor->getConciertosDisponibles().size()) {
					gestor->venderEntrada(indice, ventas);
				}
				else {
					cout << "Indice incorrecto" << endl;
				}
			}
			else {
				cout << "Cree un concierto antes de querer vender entradas o carguelos del archivo" << endl;
			}
			break;
		}
		case 4: {
			if (vali || archivocargado) {
				gestor->listarConciertos();
			}
			else {
				cout << "Cree un concierto antes de querer mostrarlo o carguelos del archivo" << endl;
			}
			break;
		}
		case 5: {
			gestor->cargarConciertosCSV();
			vali = true;
			archivocargado = true;
			break;
		}
		case 6: {
			if (vali || archivocargado) {
				gestor->guardarConciertosCSV();
			}
			else {
				cout << "Cree un concierto antes de querer guardarlo al archivo o carguelos del archivo" << endl;
			}
			break;
		}
		case 7: {
			cout << "Saliendo..." << endl;
			seguir = false;
			break;
		}
		default:
			cout << "Ingrese una opcion correcta" << endl;
		}
		}
		delete gestor;
		delete concierto;
	}
	int main()
	{
		ejercicio1();
	}