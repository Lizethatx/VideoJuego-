#ifndef MENUCIVILIZACION_H
#define MENUCIVILIZACION_H
#include "Civilizacion.h"


Aldeano capturar()
{
	Aldeano a;
	string nombre;
	string genero;
	int edad;
	int salud;
	
	cout << "Nombre: ";
	getline(cin, nombre);
	a.setNombre(nombre);
	
	cout << "Edad: ";
	cin >> edad;
	a.setEdad(edad); cin.ignore();
	
	cout << "Genero: ";
	getline(cin, genero);
	a.setGenero(genero);
	
	cout << "Salud: ";
	cin >> salud; cin.ignore();
	a.setSalud(salud);
	
	return a;
}
void menu(Civilizacion &c)
{
	string opc;
	
	while(true)
	{
		cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);
        
        if (opc == "1"){
        	string op;
    		while(true){
    			cout << "1. Agregar aldeano al inicio" << endl;
    			cout << "2. Agregar aldeano al final" << endl;
    			cout << "0. Volver al menu"<< endl;
    			getline(cin,op);
    			if(op == "1"){
    				c.agregarAlInicio(capturar());
    				c.setPuntuacion(c.getPuntuacion()+100);
				}
				else if( op == "2"){
					c.agregarAlFinal(capturar());
					c.setPuntuacion(c.getPuntuacion()+100);
				}
				else if (op == "0"){
					break;
				}
    			
			}
		}
		
		else if(opc == "2"){
        	string op;
        	while (true){
        		cout << "1. Eliminar por nombre" << endl;
    			cout << "2. Eliminar por salud" << endl;
    			cout << "3. Eliminar por edad" << endl;
    			cout << "0. Volver al menu"<< endl;
    			getline(cin,op);
    			if(op == "1"){
    				string nombre;
    				cout << "Nombre: ";
    				getline(cin,nombre);
    				c.EliminarNombre(nombre);
    			}
    			else if(op == "2"){
    				int salud;
    				cout <<"Salud: ";
    				cin>> salud;cin.ignore();
    				c.EliminarSalud(salud);
    			}
    			else if(op == "3"){
    				c.EliminarAldeanosEdad(60);
    			}
    			
    			else if(op == "0"){
    				break;
				}
			}
			
		}
		
		else if(opc == "3"){
        	string op;
    		while (true){
    			cout << "1. Clasificar por nombre" << endl;
    			cout << "2. Clasificar por edad" << endl;
    			cout << "3. Clasificar por salud" << endl;
    			cout << "0. Volver al menu"<< endl;
    			getline(cin,op);
    			if(op == "1"){
                    c.ClasificarNombre();
                }
				else if (op == "2"){
                    c.ClasificarEdad();
                }
				else if (op == "3"){
                    c.ClasificarSalud();
                }
				else if (op == "0"){
                    break;
				}
			}
    		
		}
		else if(opc == "4"){
			string nombre;
			cout <<"Nombre a buscar: ";
			getline(cin,nombre);
			c.BuscarALdeano(nombre);
		}
		
		else if(opc == "5"){
			string nombre;
			cout <<"Nombre a buscar: ";
			getline(cin,nombre);
			c.ModificarAldeano(nombre);
		}
		
		else if (opc == "6"){
			c.imprimir();
		}
		
		else if(opc == "0"){
			break;
		}
		
	}
	
}

#endif
