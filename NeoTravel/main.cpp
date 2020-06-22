/* 
 * File:   main.cpp
 * Author: Raul Alvarez Fernandez
 * Created on 9 de junio de 2020, 08:44 PM
 */
//#include "ListaEnlazadaCircularDoble.h"
#include <cstdlib>
#include <iostream>
#include <gtkmm.h>
#include "VentanaPrincipal.h"
#include "Usuario.h"
//#include "PruebaCola.h"
//#include "Vuelo.h"
//#include "Ciudad.h"
//#include "Avion.h"
//#include "Horario.h"
//#include "Cola.h"
//#include "Itinerario.h"
//#include "VueloData.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

      Glib::RefPtr<Gtk::Application> app= 
            Gtk::Application::create(argc, argv, "flag2");
        
        VentanaPrincipal ventana;
        ventana.set_title("NeoTravel");
        
        return app->run(ventana);
    //    ListaEnlazadaCircularDoble<Vuelo>* listaVuelos = new ListaEnlazadaCircularDoble<Vuelo>;
    //    
    //    Ciudad* cOrigen = new Ciudad("San Jose");
    //    Ciudad* cDestino = new Ciudad("Barcelona");
    //    Avion* avion = new Avion("Boeing", 80, 20, 60);
    //    Horario* horario1 = new Horario(1, 5);
    //    Horario* horario2 = new Horario(2, 6);
    //    Cola* cola = new Cola();
    //    cola->encolar(horario2);
    //    cola->encolar(horario1);
    //    
    ////    cout << "Ciudad origen "<< cOrigen->toString() << endl;
    ////    cout << "Ciudad destino "<< cDestino->toString() << endl;
    ////    cout << "Avion "<< avion->toString() << endl;
    ////    cout << "Horario1 "<< horario1->toString() << endl;
    ////    cout << "Cola "<< cola->toString() << endl;
    //    
    //    Itinerario* itinerario = new Itinerario(avion, cola);
    //    
    ////////    cout << "Itinerario"<< itinerario->toString() << endl;
    //    
    //    Vuelo* v1 = new Vuelo(itinerario, cOrigen, cDestino);
    //    
    ////    cout << "Vuelo1 "<< v1->toString() << endl;
    //    
    //    listaVuelos->insertar(v1);
    //    
    ////    cout << "lista vuelos "<< listaVuelos->toString() << endl;
    ////    cout << "lista vuelos "<< listaVuelos->toString() << endl;
    //    Ciudad* c2Origen = new Ciudad("New York");
    //    Ciudad* c2Destino = new Ciudad("Wuhan");
    //    Avion* avion2 = new Avion("AvionetaMieo", 20, 10, 30);
    //    Horario* horario3 = new Horario(3, 8);
    //    Horario* horario4 = new Horario(6, 7);
    //    Cola* cola2 = new Cola();
    //    cola2->encolar(horario3);
    //    cola2->encolar(horario4);
    //    
    //    Itinerario* itinerario2 = new Itinerario(avion2, cola2);
    //    
    //    Vuelo* v2 = new Vuelo(itinerario2, c2Origen, c2Destino);
    //    //cout << "lista vuelos "<< listaVuelos->toString() << endl;
    //    listaVuelos->insertar(v2);
    //    
    //    cout << "lista vuelos "<< listaVuelos->toString() << endl;
    //    
    //    //cout << listaVuelos->toString() << endl;
    //   return 0;
}//finMain