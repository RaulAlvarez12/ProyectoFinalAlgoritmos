/* 
 * File:   main.cpp
 * Author: Raul Alvarez Fernandez
 * Created on 9 de junio de 2020, 08:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <gtkmm.h>
#include "VentanaPrincipal.h"

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
    
}//finMain