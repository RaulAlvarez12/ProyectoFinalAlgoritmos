/* 
 * File:   VentanaPrincipal.h
 * Author: geraldi
 *
 * Created on 8 de junio de 2020, 02:36 PM
 */

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "VentanaEscogerAerolinea.h"
#include "VentanaItinerario.h"

class VentanaPrincipal : public Gtk::Window {
public:
    VentanaPrincipal();
    virtual ~VentanaPrincipal();
private:
    void init();
    
    void aboutWinClose();
    void aboutWinCloseVentanaItinerarios();
    
    void abrirVentanaEscogerAerolinea();
    void abrirVentanaItinerario();

    //Atributos
    VentanaEscogerAerolinea* ventanaescoger;
    VentanaItinerario* ventanaItinerario;
    
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::MenuItem menuItinerario;//item del menu bar
    Gtk::Menu subMenuArchivo; //abre el contenedor submenu
    Gtk::Menu subMenuItinerario;
    Gtk::ImageMenuItem menuEscogerAerolinea;
    Gtk::ImageMenuItem menuItinerarios;//Abre la ventana de itinerarios

    Gtk::Fixed fixed; // contenedor

};

#endif /* VENTANAPRINCIPAL_H */