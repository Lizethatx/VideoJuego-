#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <stack>

#include "Barco.h"


void Barco::setId(const string &id)
{
	this -> id = id;
}
string Barco::getId() const
{
	return id;
}

void Barco::setCombustible(float combustible)
{
	this -> combustible = combustible;
}
float Barco::getCombustible() const
{
	return combustible;
}

void Barco::setVelocidad(float velocidad)
{
	this -> velocidad = velocidad;
}
float Barco::getVelocidad() const
{
	return velocidad;
}

void Barco::setArmadura(float armadura)
{
	this -> armadura = armadura;
}
float Barco::getArmadura() const
{
	return armadura;
}

void Barco::setCantidadG(int cantidadGuerreros)
{
	this -> cantidadGuerreros = cantidadGuerreros;
}
int  Barco::getCantidadG() const
{
	return cantidadGuerreros;
}

void Barco::setTotal(int total)
{
	this -> total = total;
}
int Barco::getTotal() const
{
	return total;
}

//metodos guerreros

void Barco::agregarGuerreros(const Guerrero &g)
{
	guerreros.push(g);
}

void Barco::eliminarGuerrero()
{
	if(!guerreros.empty())
	{
		guerreros.pop();
	}
	else{
		cout << "No existen guerreros"<< endl;
	}
}

void Barco::Tope()
{
	cout << endl;
	cout << "Ultimo guerrero"<< endl;
	cout << endl;
    cout << left;
    cout << setw(15) << "Id";
    cout << setw(15) << "Salud";
    cout << setw(15) << "Fuerza";
    cout << setw(15) << "Escudo";
    cout << setw(15) << "Tipo";
    cout << endl;
	cout << guerreros.top() << endl;
}

void Barco::mostrarGuerreros()
{
	stack<Guerrero>Copia(guerreros);
	cout << endl;
    cout << left;
    cout << setw(15) << "ID";
    cout << setw(15) << "Salud";
    cout << setw(15) << "Fuerza";
    cout << setw(15) << "Escudo";
    cout << setw(15) << "Tipo";
    cout << endl;
    while(!Copia.empty())
    {
    	auto const &e = Copia.top();
    	cout<< e <<endl;
    	Copia.pop();
	}

}

