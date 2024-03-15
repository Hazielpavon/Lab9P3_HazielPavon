#include "GestorVentas.h"

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

}
void GestorVentas::listarConciertos() {

}
void GestorVentas::guardarConciertosCSV() {

}
void GestorVentas::cargarConciertosCSV() {

}