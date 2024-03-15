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
	string getnombreBanda() const; 
	void setnombreBanda(string nombreBanda); 
	double getprecioEntrada() const; 
	void setprecioEntrada(double precioEntrada);
	string getfechaConcierto() const;
	void setfechaConcierto(string fechaConcierto);
	int getcodigo() const; 
	void setcodigo(int codigo);
	double gettotalRecaudado() const; 
	void settotalRecaudado(double totalRecaudado);
	int getentradasVendidas()const;
	void setentradasVendidas(int entradasVendidas);



};

// string getNombre()const; 
//void setNombre(string _nombre);
