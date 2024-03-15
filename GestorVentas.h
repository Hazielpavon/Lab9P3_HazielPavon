#pragma once
#include <memory.h>
#include <vector>
#include "Concierto.h"
class GestorVentas 
{
private: 
	vector<Concierto*> ConciertosDisponibles; 
public: 
	GestorVentas(); 
	~GestorVentas();
	vector<Concierto*>getConciertosDisponibles(); 
	void setConciertosDisponibles(vector<Concierto*> ConciertosDisponibles);
	void agregarConcierto(Concierto* nuevoConcierto);
	void eliminarConcierto(int indiceConcierto);
	void venderEntrada(int indiceConcierto, int cantidad);
	void listarConciertos();
	void guardarConciertosCSV();
	void cargarConciertosCSV();
};