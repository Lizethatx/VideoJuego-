#include "VideoGame.h"
#include "menuCivilizacion.h"
#include "submenuBarco.h"
#include <fstream>
#include <algorithm>
#include<vector>

VideoGame::VideoGame()
{
	
}

VideoGame::VideoGame( const string &usuario)
{
	this->usuario = usuario;
}
void VideoGame::setUsuario(const string &v)
{
	usuario = v;
}

string VideoGame::getUsuario()
{
	return usuario;
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
	civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
	civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void VideoGame::crearCivilizaciones(const Civilizacion &c, size_t n)
{
	civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::primeraCivilizacion()
{
	if (civilizaciones.empty()){
    	cout << "No hay registros"<<endl;
	}
	else{
		cout << civilizaciones.front()<<endl;
	}
}

void VideoGame::ultimaCivilizacion()
{
	if(civilizaciones.empty()){
		cout << "No hay registros"<<endl;
	}
	else{
		cout << civilizaciones.back() << endl;
	}

}

void VideoGame::ordenarNombre()
{
	sort(civilizaciones.begin(), civilizaciones.end(),
	[](Civilizacion c1, Civilizacion c2){ return c1.getNombre() < c2.getNombre();});
}

void VideoGame::ordenarUbicax()
{
	sort(civilizaciones.begin(),civilizaciones.end(),
	[](Civilizacion c1, Civilizacion c2){return c1.getUbicax() < c2.getUbicax();});
}

void VideoGame::ordenarUbicay()
{
	sort(civilizaciones.begin(),civilizaciones.end(),
	[](Civilizacion c1, Civilizacion c2){return c1.getUbicay() < c2.getUbicay();});
}

void VideoGame::ordenarPuntuacion()
{
	sort(civilizaciones.begin(),civilizaciones.end(),
	[](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminarCivilizacion( Civilizacion c)
{
	size_t pos;
	for(pos=0; pos < civilizaciones.size();pos++)
	{
		if(civilizaciones[pos].getNombre()==c.getNombre())
		{
			civilizaciones.erase(civilizaciones.begin()+pos);
			cout << "Eliminado"<<endl;
			return;
		}
	}

}


void VideoGame::total()
{
	
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(18) << "Ubicacion en x";
    cout << setw(18) << "Ubicacion en y";
    cout << setw(18) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &c = civilizaciones[i];
        cout << c;
	}
}

void VideoGame::modificarNombre(Civilizacion c)
{
	string nombre;
	size_t pos;
	cout << "Ingresa la civilizacion a modificar: ";
	getline(cin,nombre); cin.ignore();
	for (pos=0; pos< civilizaciones.size();pos++){
		if (civilizaciones[pos].getNombre()== nombre)
		{
			string nombre;
			cout <<"   Civilizacion a modificar   "<< endl;
			cout <<"Nombre: "<< civilizaciones[pos].getNombre() << endl;
			cout <<"Ubicacion en x: "<< civilizaciones[pos].getUbicax() << endl;
			cout <<"Ubicacion en y: "<< civilizaciones[pos].getUbicay() << endl;
			cout <<"Puntuacion: "<< civilizaciones[pos].getPuntuacion() << endl;
			
			cout << "Ingrese el nuevo nombre: ";
			getline(cin,nombre); 
			
			civilizaciones[pos].setNombre(nombre);
			cout << "Modificacion exitosa"<< endl;
			break;
		}
	}
}

void VideoGame::modificarUbicax(Civilizacion c)
{
	string nombre;
	size_t pos;
	cout << "Ingresa la civilizacion a modificar: ";
	getline(cin,nombre); cin.ignore();
	for (pos=0; pos< civilizaciones.size();pos++){
		if (civilizaciones[pos].getNombre()== nombre)
		{
			float ubicax;
			cout <<"   Civilizacion a modificar   "<< endl;
			cout <<"Nombre: "<< civilizaciones[pos].getNombre() << endl;
			cout <<"Ubicacion en x: "<< civilizaciones[pos].getUbicax() << endl;
			cout <<"Ubicacion en y: "<< civilizaciones[pos].getUbicay() << endl;
			cout <<"Puntuacion: "<< civilizaciones[pos].getPuntuacion() << endl;
			
			cout << "Ingrese la nueva ubicacion en x: ";
			cin>> ubicax; cin.ignore();
			
			civilizaciones[pos].setUbicax(ubicax);
			cout << "     Modificacion exitosa   "<< endl;
			break;
		}
	}
}

void VideoGame::modificarUbicay(Civilizacion c)
{
	string nombre;
	size_t pos;
	cout << "Ingresa la civilizacion a modificar: ";
	getline(cin,nombre); cin.ignore();
	for (pos=0; pos< civilizaciones.size();pos++){
		if (civilizaciones[pos].getNombre()== nombre)
		{
			float ubicay;
			cout <<"   Civilizacion a modificar   "<< endl;
			cout <<"Nombre: "<< civilizaciones[pos].getNombre() << endl;
			cout <<"Ubicacion en x: "<< civilizaciones[pos].getUbicax() << endl;
			cout <<"Ubicacion en y: "<< civilizaciones[pos].getUbicay() << endl;
			cout <<"Puntuacion: "<< civilizaciones[pos].getPuntuacion() << endl;
			
			cout << "Ingrese la nueva ubicacion en y: ";
			cin>> ubicay; cin.ignore();
			
			civilizaciones[pos].setUbicay(ubicay);
			cout << "     Modificacion exitosa   "<< endl;
			cout<< endl;
			break;
		}
	}
}

void VideoGame::modificarPuntuacion(Civilizacion c)
{
	string nombre;
	size_t pos;
	cout << "Ingresa la civilizacion a modificar: ";
	getline(cin,nombre); cin.ignore();
	for (pos=0; pos< civilizaciones.size();pos++){
		if (civilizaciones[pos].getNombre()== nombre){
			float puntuacion;
			cout <<"   Civilizacion a modificar   "<< endl;
			cout <<"Nombre: "<< civilizaciones[pos].getNombre() << endl;
			cout <<"Ubicacion en x: "<< civilizaciones[pos].getUbicax() << endl;
			cout <<"Ubicacion en y: "<< civilizaciones[pos].getUbicay() << endl;
			cout <<"Puntuacion: "<< civilizaciones[pos].getPuntuacion() << endl;
			
			cout << "Ingrese la nueva puntuacion: ";
			cin>>puntuacion; cin.ignore();
			
			civilizaciones[pos].setPuntuacion(puntuacion);
			cout << "     Modificacion exitosa   "<< endl;
			break;
		}
	}
	
}

void VideoGame::buscarCivilizacion( Civilizacion c)
{
	
	string nombre;
	size_t ban;
	size_t pos;
    cout << "Nombre de la civilizacion a buscar: ";
    getline(cin,nombre); cin.ignore();
	for (pos=0; pos< civilizaciones.size();pos++){
		if (civilizaciones[pos].getNombre() == nombre)
		{
			ban= 1;
			cout << "   Informacion de la civilizacion   "<< endl;
			cout <<"Nombre: "<< civilizaciones[pos].getNombre() << endl;
			cout <<"Ubicacion en x: "<< civilizaciones[pos].getUbicax() << endl;
			cout <<"Ubicacion en y: "<< civilizaciones[pos].getUbicay() << endl;
			cout <<"Puntuacion: "<< civilizaciones[pos].getPuntuacion() << endl;
		}
	}
	if (ban== 0){
		cout <<"No se encontro"<< endl;
	}
}

void VideoGame::submenu()
{
	if(civilizaciones.empty()){
		cout << "No hay civilizaciones"<< endl;
	}
	else{
		for (size_t i=0;i<civilizaciones.size(); i++){
			Civilizacion &civilizacion = civilizaciones[i];
			
			cout <<i+1 <<")";
			cout << civilizacion.getNombre() << endl;
		}
		cout << "0) Salir" << endl;
		size_t posi;
		cin>> posi;cin.ignore();
		
		if(posi> civilizaciones.size()){
			cout << "Opcion incorrecta" << endl;
		}
		else if(posi != 0){
			Civilizacion &civilizacion = civilizaciones[posi-1];
			menu(civilizacion);
		}
	}
}

void VideoGame::RespaldarCivilizaciones()
{
	ofstream archivo("civilizaciones.txt", ios::out);
	for (int i=0; i < civilizaciones.size(); i++){
		Civilizacion &c = civilizaciones[i];
		archivo << c.getNombre() << endl;
		archivo << c.getUbicax() << endl;
		archivo << c.getUbicay() << endl;
		archivo << c.getPuntuacion() << endl;
		c.RespaldarAldeanos();
	}
	archivo.close();
}


void VideoGame::RecuperarCivilizaciones()
{
	ifstream archivo("civilizaciones.txt");
	if (archivo.is_open()){
		string temp;
		float ubicax;
		float ubicay;
		float puntuacion;
		
		while(true){
			Civilizacion c;
			getline(archivo, temp);
			if (archivo.eof()){
				break;
			}
			c.setNombre(temp);
			
			getline(archivo, temp);
			ubicax=stof(temp);
			c.setUbicax(ubicax);
			
			getline(archivo, temp);
			ubicay=stof(temp);
			c.setUbicay(ubicay);
			
			getline(archivo, temp);
			puntuacion=stof(temp);
			c.setPuntuacion(puntuacion);
						
			c.RecuperarAldeanos();
			
			agregarCivilizacion(c);
		}
	}
	archivo.close();
}

void VideoGame::submenuBarcos()
{
	if(civilizaciones.empty()){
		cout << "No hay civilizaciones"<< endl;
	}
	else{
		for (size_t i=0;i<civilizaciones.size(); i++){
			Civilizacion &civilizacion = civilizaciones[i];
			
			cout <<i+1 <<")";
			cout << civilizacion.getNombre() << endl;
		}
		cout << "0) Salir" << endl;
		size_t posi;
		cin>> posi;cin.ignore();
		
		if(posi> civilizaciones.size()){
			cout << "Opcion incorrecta" << endl;
		}
		else if(posi != 0){
			Civilizacion &civilizacion = civilizaciones[posi-1];
			menuBarco(civilizacion);
		}
	}
}
