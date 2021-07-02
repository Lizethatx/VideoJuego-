#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include "Aldeano.h"
#include "Barco.h"
using namespace std;

class Civilizacion
{
	string nombre;
	float ubicax;
	float ubicay;
	float puntuacion;
	list <Aldeano> aldeanos;
	list <Barco*> puerto;
public:
	Civilizacion();
	Civilizacion(const string &nombre, float ubicax, float ubicay, float puntuacion);
	void setNombre(const string &v);
	string getNombre();
	void setUbicax(float v);
	float getUbicax();
	void setUbicay(float v);
	float getUbicay();
	void setPuntuacion(float v);
	float getPuntuacion();
	//agregar
	void agregarAlFinal(const Aldeano &a);
	void agregarAlInicio(const Aldeano &a);
	void imprimir();
	//Eliminar
	void EliminarNombre(const string &nombre);
	void EliminarSalud(int salud);
	void EliminarAldeanosEdad(int edad);
	//clasificar
	void ClasificarNombre();
	void ClasificarEdad();
	void ClasificarSalud();
	
	void BuscarALdeano(const string &nombre);
	void ModificarAldeano(const string &nombre);
	
	void RespaldarAldeanos();
	void RecuperarAldeanos();
	
	//barcos
	void AgregarBarco(Barco *b)
	{
		puerto.push_back(b);
	}
	
	void mostrarBarcos();
	void buscarBarcos(const string &id);
	void eliminarBarcoId(const string &id);
	void eliminarBarcoCombustible(float combustible);
	
	friend ostream& operator<<(ostream &out, const Civilizacion &c)
	{
		out << left;
		out << setw(15) << c.nombre;
		out << setw(18) << c.ubicax;
		out << setw(18) << c.ubicay;
		out << setw(18) << c.puntuacion;
		out << endl;
		
		return out;
	}
	
	friend istream& operator>>(istream &in, Civilizacion &c)
	{
		cout << "Nombre: ";
		getline(cin, c.nombre);
		
		cout << "Ubicacion en x: ";
		cin>> c.ubicax;
		
		cout << "Ubicacion en y: ";
		cin>> c.ubicay;
		
		cout << "Puntuacion: ";
		cin >> c.puntuacion;
		
		return in;
	}
	
	bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c)
    {
        return 2;
    }
    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
	
};

#endif

