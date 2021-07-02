#ifndef SUBMENUGUERREROS_H
#define SUBMENUGUERREROS_H
#include "Barco.h"

Guerrero capturarGuerrero()
{
	Guerrero a;
    string id;
	int salud;
    float fuerza;
    float escudo;
    string tipoguerrero;
    
    cout << endl;
    cout << "Id: ";
    getline(cin, id);
    a.setId(id);

    cout << endl;
    cout << "Salud: ";
    cin >> salud;
    a.setSalud(salud);cin.ignore();

    cout << endl;
    cout << "Fuerza: ";
    cin >> fuerza;
    a.setFuerza(fuerza); cin.ignore();

    cout << endl;
    cout << "Escudo: ";
    cin >> escudo;
    a.setEscudo(escudo); cin.ignore();
    
    cout << endl;
    cout << "Tipos de Guerreros" << endl;
    cout << "1)Arquero" << endl;
    cout << "2)Ninja" << endl;
    cout << "3)Samurai" << endl;
    cout << "4)Infectado" << endl;
    cout << endl;
    cout << "Tipo: ";
    getline(cin, tipoguerrero);
    a.setTipoguerrero(tipoguerrero);

    return a;
}


void menuGuerreros(Barco &b)
{
	string opc;
	while(true)
    {

        cout << "1) Agregar Guerrero" << endl;
        cout << "2) Eliminar Guerrero" << endl;
        cout << "3) Mostrar Ultimo Guerrero" << endl;
        cout << "4) Mostrar Guerreros" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);

        if (opc == "1"){
        	b.agregarGuerreros(capturarGuerrero());
        	b.setTotal(1);
        	b.setCantidadG(b.getCantidadG()+b.getTotal());
		}
		else if(opc == "2"){
            string id;
            cout << endl;
            cout << "Eliminar Guerrero" << endl;
            if(b.getCantidadG() > 0){
            	cout << endl;
            	cout << "Eliminado con Exito"<<endl;
            	cout << endl;
            	b.eliminarGuerrero();
            	b.setTotal(-1);
            	b.setCantidadG(b.getCantidadG()+b.getTotal());
			}
			else{
				cout << "No fue posible eliminar"<<endl;
			}
            
        }
        else if(opc == "3"){
        	b.Tope();
		}
		else if(opc == "4"){
			b.mostrarGuerreros();
		}
		else if(opc == "0"){
			break;
		}
	}


}
#endif
