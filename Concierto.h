#pragma once
#include <iostream>
using namespace std;
class Concierto
{
private : 
	string nombreBanda;
	double precioEntrada;
	string fechaConcierto;
	int codigo;
	double totalRecaudado;
	int entradasVendidas; 
public: 
	Concierto(string nombreBanda, double precioEntrada, string fechaConcierto, int codigo, double totalRecaudado, int entradasVendidas); 
	Concierto(); 
	~Concierto(); 
	string getnombreBanda() ; 
	void setnombreBanda(string nombreBanda); 
	double getprecioEntrada() ; 
	void setprecioEntrada(double precioEntrada);
	string getfechaConcierto() ;
	void setfechaConcierto(string fechaConcierto);
	int getcodigo() const; 
	void setcodigo(int codigo);
	double gettotalRecaudado() ; 
	void settotalRecaudado(double totalRecaudado);
	int getentradasVendidas();
	void setentradasVendidas(int entradasVendidas);
};
// string getNombre()const; 
//void setNombre(string _nombre);