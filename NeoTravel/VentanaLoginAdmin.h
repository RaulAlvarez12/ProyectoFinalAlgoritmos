/* 
 * File:   VentanaLoginAdmin.h
 * Author: Raul Alvarez Fernandez
 *
 * Created on 22 de junio de 2020, 05:51 PM
 */

#ifndef VENTANALOGINADMIN_H
#define VENTANALOGINADMIN_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class VentanaLoginAdmin : public Gtk::Window{
    
public:
    VentanaLoginAdmin();
    virtual ~VentanaLoginAdmin();
private:
    
    void init();
    void onButtonClickedIngresar();
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblNombre;
    Gtk::Label lblContrasena;

    Gtk::Entry etNombre;
    Gtk::Entry etContrasena;

    Gtk::Button btnIngresar;
};

#endif /* VENTANALOGINADMIN_H */