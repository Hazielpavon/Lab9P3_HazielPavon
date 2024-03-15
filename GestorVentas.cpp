#include "GestorVentas.h"
#include <iostream>
#include <fstream>
GestorVentas::GestorVentas()
{
}
GestorVentas::~GestorVentas()
{
	for (auto Concierto : ConciertosDisponibles) {
		delete Concierto;
	}
}
vector<Concierto*> GestorVentas::getConciertosDisponibles()
{
	return ConciertosDisponibles;
}
void GestorVentas::setConciertosDisponibles(vector<Concierto*> vector)
{
	this->ConciertosDisponibles = ConciertosDisponibles;
}
void GestorVentas::agregarConcierto(Concierto* nuevoConcierto) {
	ConciertosDisponibles.push_back(nuevoConcierto);
	cout << "Concierto Agregado Exitosamente" << endl;
}
void GestorVentas::eliminarConcierto(int indiceConcierto) {
	ConciertosDisponibles.erase(ConciertosDisponibles.begin() + indiceConcierto);
	cout << "Concierto Eliminado Exitosamente" << endl;
}
void GestorVentas::venderEntrada(int indiceConcierto, int cantidad) {
	// lo que hago aca es a dinero le agrego el precio de cada entrada por la cantidad de entradas mas el total recaudado por la banda para que
	// se actualicen los fondos de forma correcta 
	// Imprimir solo sirve como referencia para ver cuanto se genero con la venta de las entradas 
	double din = (ConciertosDisponibles[indiceConcierto]->getprecioEntrada() * cantidad) + ConciertosDisponibles[indiceConcierto]->gettotalRecaudado();
	double imprimir = (ConciertosDisponibles[indiceConcierto]->getprecioEntrada() * cantidad);
	ConciertosDisponibles[indiceConcierto]->settotalRecaudado(din);
	int cant = ConciertosDisponibles[indiceConcierto]->getentradasVendidas() + cantidad;
	ConciertosDisponibles[indiceConcierto]->setentradasVendidas(cant);
	cout << "Se Ha vendido las entradas y se agregaron los fondos exitosamente" << endl;
	// resumen de venta
	cout << "Resumen de Venta: " << endl;
	cout << "----------------" << endl;
	cout << "Nombre: " << ConciertosDisponibles[indiceConcierto]->getnombreBanda() << endl;
	cout << "Fecha: " << ConciertosDisponibles[indiceConcierto]->getfechaConcierto() << endl;
	cout << "Entradas Compradas: " << cantidad << endl;
	cout << "Total: " << "$" << imprimir << endl;
	// banda fecha entradas total 

}
void GestorVentas::listarConciertos() {
	for (int i = 0; i < ConciertosDisponibles.size(); i++)
	{
		cout << "Concierto: " << i << endl;
		cout << "Nombre: " << ConciertosDisponibles[i]->getnombreBanda() << endl;
		cout << "Fecha: " << ConciertosDisponibles[i]->getfechaConcierto() << endl;
		cout << "Precio: " << ConciertosDisponibles[i]->getprecioEntrada() << endl;
		cout << "Codigo: " << ConciertosDisponibles[i]->getcodigo() << endl;
	}
	// banda fecha precio codigo 
}
//guardo los datos en el archivo 
void GestorVentas::guardarConciertosCSV() {
	ofstream archivo("Conciertos.csv");
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo Conciertos.csv" << endl;
		return;
	}

	for (Concierto* concierto : ConciertosDisponibles) {
		archivo << concierto->getnombreBanda() << "," << concierto->getprecioEntrada() << "," << concierto->getfechaConcierto() << "," << concierto->getcodigo() << ","
			<< concierto->gettotalRecaudado() << "," << concierto->getentradasVendidas() << endl;
	}

	archivo.close();

}
// aca abro los datos y los almaceno en el vector 
void GestorVentas::cargarConciertosCSV() {
	ifstream archivo("Conciertos.csv");
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo" << endl;
	}
	else {
		string nombre, fecha;
		double entrada, total;
		int codigo, ventas;
		while (archivo >> nombre >> entrada >> fecha >> codigo >> total >> ventas) {
			Concierto* concierto = new Concierto(nombre, entrada, fecha, codigo, total, entrada);
			ConciertosDisponibles.push_back(concierto);
		}
		archivo.close();
		cout << "Se han cargado los archivos correctamente!" << endl;
	}
}