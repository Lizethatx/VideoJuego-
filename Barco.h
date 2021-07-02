#ifndef BARCO_H
#define BARCO_H

#include <iostream>
#include <iomanip>
#include <stack>
#include "Guerrero.h"
using namespace std;

class Barco
{
	string id;
	float combustible;
	float velocidad;
	float armadura;
	int cantidadGuerreros;
	int total;
	stack<Guerrero> guerreros;
public:
	Barco()
	{
		cantidadGuerreros=0;
	}
	Barco(string id, float combustible , float velocidad, float armadura ):
		id(id), combustible(combustible), velocidad(velocidad), armadura(armadura), cantidadGuerreros(cantidadGuerreros), total(total) {}
	
	void setId(const string &id);
	string getId() const ;
	
	void setCombustible(float combustible);
	float getCombustible() const ;
	
	void setVelocidad(float velocidad);
	float getVelocidad() const ;
	
	void setArmadura(float armadura);
	float getArmadura() const ;
	
	void setCantidadG(int cantidadGuerreros);
	int getCantidadG() const;
	
	void setTotal(int total);
	int getTotal() const;
	
	//metodos guerreros
	
	void agregarGuerreros(const Guerrero &g);
	void eliminarGuerrero();
	void Tope();
	void mostrarGuerreros();
	
	friend ostream& operator <<(ostream &out, const Barco &b)
	{
		out << left;
		out << setw(15) << b.id;
		out << setw(15) << b.combustible;
		out << setw(15) << b.velocidad;
		out << setw(15) << b.armadura;
		
		return out;
	}
	
	bool operator<(const Barco &b) 
	{
		return id < b.getId();
	}	

    bool operator<(Barco *b)
    {
        return combustible < b->getCombustible();
    }

    bool operator<(Barco *b) const
    {
        return combustible < b->getCombustible();
    }

    bool operator == (const Barco &p)
    {
        return id == p.id;
    }
    bool operator == (const Barco &p) const
    {
        return id == p.id;
    }

};

#endif
