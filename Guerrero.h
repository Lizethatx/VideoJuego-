#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Guerrero
{
	string id;
	int salud;
	float fuerza;
	float escudo;
	string tipoguerrero;	
public:
	Guerrero(){}
	Guerrero(string id, int salud , float fuerza, float escudo, const string &tipoguerrero):
		id(id), salud(salud), fuerza(fuerza), escudo(escudo), tipoguerrero(tipoguerrero) {}
		
	void setId(const string &id);
	string getId() const ;
	
	void setSalud(int salud);
	int getSalud() const ;
	
	void setFuerza(float fuerza);
	float getFuerza() const ;
	
	void setEscudo(float escudo);
	float getEscudo() const ;
	
	void setTipoguerrero(const string &tipoguerrero);
	string getTipoguerrero() const ;
	
	friend ostream& operator <<(ostream &out, Guerrero &g)
	{
		out << left;
		out << setw(15) << g.id;
		out << setw(15) << g.salud;
		out << setw(15) << g.fuerza;
		out << setw(15) << g.escudo;
		out << setw(15) << g.tipoguerrero;
		
		return out;
	}
	
	bool operator<(const Guerrero &g) 
	{
		return id < g.getId();
	}
		
};

#endif
