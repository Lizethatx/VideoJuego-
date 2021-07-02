#include "Civilizacion.h"
#include "SubMenuGuerreros.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include<list>


Civilizacion::Civilizacion()
{
	
}

Civilizacion::Civilizacion(const string &nombre, float ubicax, float ubicay, float puntuacion)
{
	this->nombre = nombre;
	this->ubicax = ubicax;
	this->ubicay = ubicay;
	this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
	nombre = v;
}

string Civilizacion::getNombre()
{
	return nombre;
}

void Civilizacion::setUbicax(float v)
{
	ubicax = v;
}
float Civilizacion::getUbicax()
{
	return ubicax;
}

void Civilizacion::setUbicay(float v)
{
	ubicay = v;
}
float Civilizacion::getUbicay()
{
	return ubicay;
}

void Civilizacion::setPuntuacion(float v)
{
	puntuacion = v;
}

float Civilizacion::getPuntuacion()
{
	return puntuacion;
}

/*Segunda parte*/

void Civilizacion::agregarAlInicio(const Aldeano &a)
{
	aldeanos.push_front(a);
}

void Civilizacion::agregarAlFinal(const Aldeano &a)
{
	aldeanos.push_back(a);
}

void Civilizacion::imprimir()
{
	cout << left;
	cout<< setw(15) <<"Nombre";
	cout<< setw(10) <<"Edad";
	cout<< setw(10) <<"Genero";
	cout<< setw(10) <<"Salud";
	cout<< endl;
	for(auto it =aldeanos.begin(); it != aldeanos.end(); it++){
		cout << *it << endl;
	}
}

//Eliminnar
void Civilizacion::EliminarNombre(const string &nombre)
{
	for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
		Aldeano &a = *it;
		
		if (nombre== a.getNombre()){
			aldeanos.erase(it);
			break;
		}
	}
}

/*bool comparador(const Aldeano &a)
{
	return a.getSalud() <= "salud" ;
} */

void Civilizacion::EliminarSalud(int salud)
{
	//aldeanos.remove_if(comparador);
	aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::EliminarAldeanosEdad(int edad) //Eliminar aldeanos donde su edad sea mayor o igual a 60
{
	aldeanos.remove_if([edad](const Aldeano &a){return a.getEdad() >= edad;});
}

//Clasificar

void Civilizacion::ClasificarNombre()
{
	aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
	return a1.getEdad() > a2.getEdad();
}
void Civilizacion::ClasificarEdad()
{
	aldeanos.sort(comparadorEdad);
}

void Civilizacion::ClasificarSalud()
{
	aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud()> a2.getSalud();});
}


void Civilizacion::BuscarALdeano(const string &nombre)
{
	for (auto Ald = aldeanos.begin(); Ald != aldeanos.end(); Ald++)
    {
        Aldeano &a = *Ald;

        if (nombre == a.getNombre()){
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(10) << "Edad";
            cout << setw(10) << "Genero";
            cout << setw(10) << "Salud";
            cout << endl;
            cout << *Ald;
            cout << endl;
            break;
        }
    }

}

void Civilizacion::ModificarAldeano(const string &nombre)
{
	for (auto Ald = aldeanos.begin(); Ald != aldeanos.end(); Ald++)
    {
        Aldeano &a = *Ald;

        if (nombre == a.getNombre()){
        	string opc;
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(10) << "Edad";
            cout << setw(10) << "Genero";
            cout << setw(10) << "Salud";
            cout << endl;
            cout << *Ald;
            cout << endl;
            
            while(true){
            	cout << " 1) Nombre " << endl;
                cout << " 2) Edad " << endl;
                cout << " 3) Genero " << endl;
                cout << " 4) Salud " << endl;
                cout << " 0) Salir " << endl;
                
                getline(cin,opc);
                
                if (opc == "1"){
                    string name;
                    cout << endl;
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, name);
                    a.setNombre(name);
                    break;
                }
                else if (opc == "2"){
                    int edad;
                    cout << endl;
                    cout << "Ingrese la nueva Edad: ";
                    cin >> edad; cin.ignore();
                    a.setEdad(edad);
                    break;
                }
				else if (opc == "3"){
                    string genero;
                    cout << endl;
                    cout << "Ingrese el nuevo Genero: ";
                    getline(cin, genero);
                    a.setGenero(genero);
                    break;
                }
				else if (opc == "4"){
                    int salud;
                    cout << endl;
                    cout << "Ingrese la nueva Salud: ";
                    cin >> salud; cin.ignore();
                    a.setSalud(salud);
                    break;
                }
                else if (opc == "0"){
                    break;
                }


                
			}
            
        }
    }
}

void Civilizacion::RespaldarAldeanos()
{
	ofstream ald(getNombre() + ".txt", ios::out);
	for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it){
		Aldeano &a = *it;
		ald << a.getNombre() << endl;
		ald << a.getEdad() << endl;
		ald << a.getGenero() << endl;
		ald << a.getSalud() << endl;
	}
	ald.close();
}

void Civilizacion::RecuperarAldeanos()
{
	ifstream ald(getNombre() + ".txt");
	if(ald.is_open()){
		string temp;
		int edad, salud;
		Aldeano a;
		while(true)
		{
			getline(ald, temp);
			if (ald.eof()){
				break;
			}
			a.setNombre(temp);
			
			getline(ald, temp);
			edad = stoi(temp);
			a.setEdad(edad);
			
			getline(ald, temp);
			a.setGenero(temp);
			
			getline(ald, temp);
			salud = stoi(temp);
			a.setSalud(salud);
			
			agregarAlFinal(a);
		}
	}
	ald.close();
	
}


void Civilizacion::mostrarBarcos()
{
		cout << endl;
		cout << left;
		cout << setw(15) << "Id";
		cout << setw(15) << "Combustible";
		cout << setw(15) << "Velocidad";
		cout << setw(15) << "Armadura";
		cout << setw(15) << "Cantidad Guerreros";
		cout << endl;
		for(auto const &bar: puerto)
		{
			cout << *bar << endl;
		}
		
		
}

void Civilizacion::buscarBarcos(const string &id)
{
	for (auto const &bar: puerto)
    {
        Barco b= *bar;

        if (id == b.getId()){
        	cout << endl;
            cout << left;
            cout << setw(15) << "Id";
            cout << setw(15) << "Combustible";
            cout << setw(15) << "Velocidad";
            cout << setw(15) << "Armadura";
            cout << setw(15) << "Cantidad Guerreros";
            cout << endl;
            cout << *bar;
            cout << endl;
            menuGuerreros(*bar);
            break;
        }
    }
    
}

void Civilizacion::eliminarBarcoId(const string &id)
{
	puerto.remove_if([id](const Barco *a){
		if(id == a->getId()){
			cout << endl;
			cout << left;
        	cout << setw(25) << "ID";
        	cout << setw(25) << "Combustible";
        	cout << setw(25) << "Velocidad";
        	cout << setw(25) << "Armadura";
        	cout << setw(25) << "Cantidad Guerreros";
        	cout << endl;
        	cout << *a ;
        	cout << endl;
        	delete a;
       		cout << endl;
        	cout << "Barco Eliminado con Exito" << endl;
		}
		else{
			return false;
		}
	});
}

void Civilizacion::eliminarBarcoCombustible(float combustible)
{

	puerto.remove_if([combustible](const Barco *a){
		if (a->getCombustible()< combustible)
		{
			delete a;
			return true;
		}
		else{
			return false;
		};
	});
}


