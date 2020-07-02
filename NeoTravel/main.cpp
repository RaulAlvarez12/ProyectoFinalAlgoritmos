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
#include "Vertice.h"
#include "GrafoListaEnlazada.h"

using namespace std;

/*
 *  
 */
int main(int argc, char** argv) {

    //    Glib::RefPtr<Gtk::Application> app =
    //            Gtk::Application::create(argc, argv, "flag2");
    //
    //    VentanaPrincipal ventana;
    //    ventana.set_title("NeoTravel");
    //
    //    return app->run(ventana);

    Ciudad* c1 = new Ciudad("Cartago");
    Ciudad* c2 = new Ciudad("Alajuela");
    Ciudad* c3 = new Ciudad("Heredia");
    Ciudad* c4 = new Ciudad("Limon");
    Ciudad* c5 = new Ciudad("Guanacaste");
    Ciudad* c6 = new Ciudad("Puntarenas");
    Vertice* v1 = new Vertice(c1, 1, 1);
    Vertice* v2 = new Vertice(c2, 2, 2);
    Vertice* v3 = new Vertice(c3, 3, 3);
    Vertice* v4 = new Vertice(c4, 4, 4);
    Vertice* v5 = new Vertice(c5, 5, 5);
    Vertice* v6 = new Vertice(c6, 5, 5);
    GrafoListaEnlazada* gl = new GrafoListaEnlazada();
    gl->agregarVertice(v1);
    gl->agregarVertice(v2);
    gl->agregarVertice(v3);
    gl->agregarVertice(v4);
    gl->agregarVertice(v5);
    gl->agregarVertice(v6);
    gl->agregarArista(v1, v2);
    gl->agregarArista(v2, v1);
    gl->agregarArista(v3, v4);
    gl->agregarArista(v1, v3);
    gl->agregarArista(v2, v3);
    cout << gl->toString() << endl;


    //  gl.agregarVertice();

    cout << gl->existeVertice(v1) << endl;




    return 0;

}//finMain