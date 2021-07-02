#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include "Civilizacion.h"
#include <vector>

using namespace std;
class VideoGame
{
	vector<Civilizacion> civilizaciones;
public:
	VideoGame();
	string usuario;
	VideoGame(const string &usario);
	void setUsuario(const string &u);
	string getUsuario();
	
	void agregarCivilizacion(const Civilizacion &c);
	void insertar(const Civilizacion &c, size_t pos);
	size_t size();
	void crearCivilizaciones(const Civilizacion &c, size_t n);
	void primeraCivilizacion();
	void ultimaCivilizacion();
	void ordenarNombre();
	void ordenarUbicax();
	void ordenarUbicay();
	void ordenarPuntuacion();
	void eliminarCivilizacion( Civilizacion c);
	void total();
	void modificarNombre(Civilizacion c);
	void modificarUbicax(Civilizacion c);
	void modificarUbicay(Civilizacion c);
	void modificarPuntuacion(Civilizacion c);
	void buscarCivilizacion( Civilizacion c);
	void submenu();
	void submenuBarcos();
	
	void RespaldarCivilizaciones();
	void RecuperarCivilizaciones();
	
	friend VideoGame operator<<(VideoGame &v, const Civilizacion &c)
	{
		v.agregarCivilizacion(c);
		
		return v;
	}
	
};

#endif

