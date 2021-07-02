#include <iostream>
#include "VideoGame.h"
using namespace std;

int main() {
	VideoGame v;
	string opc;
	
	
	while (true)
	{
		cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar civilizacion" << endl;
        cout << "3) Insertar civilizacion" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Primera civilizacion" << endl;
        cout << "6) Ultima civilizacion" << endl;
        cout << "7) Ordenar civilizaciones" << endl;
        cout << "8) Eliminar civilizacion" << endl;
        cout << "9) Buscar civilizacion" << endl;
        cout << "10) Modificar civilizaciones" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Buscar civilizacion |Aldeanos y Barcos|"<< endl;
        cout << "13) Respaldar civilizaciones" << endl;
        cout << "14) Recuperar civilizaciones" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);
        
        if (opc == "1"){
			
			cout<<"Usuario: ";
        	getline(cin, v.usuario);
		}
		
        else if(opc == "2"){
        	Civilizacion c;
        	cin>> c;
        	
        	v.agregarCivilizacion(c);
        	cin.ignore();
		}
		
		else if (opc == "3"){
			Civilizacion c;
        	cin>> c;
        	
        	size_t pos;
        	cout<<"posicion: ";
        	cin>> pos; 
			cin.ignore();
        	if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.insertar(c,pos);
            }
        }
        
        else if (opc == "4"){
        	
        	Civilizacion c;
        	cin>> c;
        	
        	size_t n;
        	cout << "n: ";
        	cin>> n; cin.ignore();
        	
        	v.crearCivilizaciones(c,n);
    	}
    	
    	else if (opc == "5"){
			v.primeraCivilizacion();
    	}
    	
    	else if(opc == "6"){
    		v.ultimaCivilizacion();
		}
    	
    	else if(opc == "7"){
    		Civilizacion c;
    		int op;
    		cout << "1. Ordenar por nombre (ascendente)" << endl;
    		cout << "2. Ordenar por posicion en x (ascendente)" << endl;
    		cout << "3. Ordenar por posicion en y (ascendente)" << endl;
    		cout << "4. Ordenar por puntuacion (descendente)" << endl;
    		cout << "5. Volver al menu"<< endl;
    		cin >> op; cin.ignore();
    		switch (op){
    			case 1: v.ordenarNombre(); break;
    			case 2: v.ordenarUbicax(); break;
    			case 3: v.ordenarUbicay(); break;
    			case 4: v.ordenarPuntuacion(); break;
    			case 5: break;
			}
    	}
    	
    	else if(opc == "8"){
    		Civilizacion c;
    		string nombre;
    		cout << "Nombre de la civilizacion a eliminar: ";
    		getline(cin,nombre); cin.ignore();
			
			c.setNombre(nombre);
			v.eliminarCivilizacion(c); 
		}
    	
        else if (opc == "9"){
        	Civilizacion c;
            v.buscarCivilizacion(c);
        }
        
        else if (opc == "10"){
        	Civilizacion c;
        			int op;
    				cout << "1. Modificar nombre" << endl;
    				cout << "2. Modificar ubicacion en x" << endl;
    				cout << "3. Modificar ubicacion en y" << endl;
    				cout << "4. Modificar puntuacion" << endl;
    				cout << "5.Volver al menu"<< endl;
    				cin >> op; cin.ignore();
    				switch (op){
    					case 1: v.modificarNombre(c); break;
    					case 2: v.modificarUbicax(c); break;
    					case 3: v.modificarUbicay(c); break;
    					case 4: v.modificarPuntuacion(c); break;
    					case 5: break;
					}
   		}
		else if (opc == "11"){
			v.total();
		}
		else if (opc == "12"){
			string opc;
			while (true)
			{
				cout << "1) Aldeanos" << endl;
                cout << "2) Barcos" << endl;
                cout << "0) Salir" << endl;
                cout << endl;
                cout << "Ingresa la Opcion deseada: " ;
                getline(cin, opc);
                if(opc == "1")
                {
                    v.submenu();
                }
                else if(opc == "2")
                {
                    v.submenuBarcos();
                }
                else if (opc == "0")
                {
                    break;
                }
			}
			
		}
		else if(opc == "13"){
			
			v.RespaldarCivilizaciones();
		}
		else if (opc == "14"){
			v.RecuperarCivilizaciones();
		}

		else if (opc == "0"){
			break;
		}
	}
	return 0;
}
