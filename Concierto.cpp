#include "Concierto.h"
Concierto::Concierto(string nombreBanda, double precioEntrada, string fechaConcierto, int codigo, double totalRecaudado, int entradasVendidas) :
	nombreBanda(nombreBanda), precioEntrada(precioEntrada), fechaConcierto(fechaConcierto), codigo(codigo), totalRecaudado(totalRecaudado), entradasVendidas(entradasVendidas) 
{}
Concierto::Concierto()
{
	// constructor vacio y sobre cargado junto con los metodos getters y setters 
}
Concierto::~Concierto()
{
	string nombreBanda = " ";
	double precioEntrada = 0.0;
	string fechaConcierto = " ";
	int codigo = 0;
	double totalRecaudado = 0;
	int entradasVendidas = 0;
}
string Concierto::getnombreBanda() 
{
	return nombreBanda;
}
void Concierto::setnombreBanda(string nombreBanda)
{
	this->nombreBanda = nombreBanda; 
}
double Concierto::getprecioEntrada() 
{
	return precioEntrada;
}
void Concierto::setprecioEntrada(double precioEntrada)
{
	this->precioEntrada = precioEntrada; 
}
string Concierto::getfechaConcierto() 
{
	return fechaConcierto;
}
void Concierto::setfechaConcierto(string fechaConcierto)
{
	this->fechaConcierto = fechaConcierto; 
}
int Concierto::getcodigo() const
{
	return codigo;
}
void Concierto::setcodigo(int codigo)
{
	this->codigo = codigo; 
}
double Concierto::gettotalRecaudado() 
{
	return totalRecaudado;
}
void Concierto::settotalRecaudado(double totalRecaudado)
{
	this->totalRecaudado = totalRecaudado; 
}
int Concierto::getentradasVendidas() 
{
	return entradasVendidas;
}
void Concierto::setentradasVendidas(int entradasVendidas)
{
	this->entradasVendidas = entradasVendidas; 
}