#include "Guerrero.h"

void Guerrero::setId(const string &id)
{
	this -> id = id;
}
string Guerrero::getId() const
{
	return id;
}

void Guerrero::setSalud(int salud)
{
	this -> salud = salud; 
}
int Guerrero::getSalud() const
{
	return salud;
}

void Guerrero::setFuerza(float fuerza)
{
	this -> fuerza = fuerza;
}
float Guerrero::getFuerza() const
{
	return fuerza;
}

void Guerrero::setEscudo(float escudo)
{
	this -> escudo = escudo;
}
float Guerrero::getEscudo() const
{
	return escudo;
}

void Guerrero::setTipoguerrero(const string &tipoguerrero)
{
	this -> tipoguerrero = tipoguerrero;
}
string Guerrero::getTipoguerrero() const
{
	return tipoguerrero;
}



