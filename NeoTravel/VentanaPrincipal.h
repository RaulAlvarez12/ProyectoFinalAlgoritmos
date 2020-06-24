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
#include "VentanaLoginAdmin.h"
#include "AerolineaData.h"
#include "CiudadData.h"
#include "AvionData.h"
#include "Avion.h"
#include "Ciudad.h"
#include "Itinerario.h"
#include"Horario.h"

class VentanaPrincipal : public Gtk::Window {
public:
    VentanaPrincipal();
    virtual ~VentanaPrincipal();
private:
    void init();
    
    void aboutWinClose();
    void aboutWinCloseVentanaItinerarios();
    void aboutWinCloseVentanaLogin();
    
    void abrirVentanaLogin();
    void abrirVentanaEscogerAerolinea();
    void abrirVentanaItinerario();

    //Atributos
    VentanaEscogerAerolinea* ventanaescoger;
    VentanaItinerario* ventanaItinerario;
    VentanaLoginAdmin* ventanaLogin;
    
    Gtk::MenuBar menuBar;
    
    Gtk::MenuItem menuArchivo;
    Gtk::MenuItem menuItinerario;//item del menu bar
    Gtk::MenuItem menuAdministrativo;
    
    Gtk::Menu subMenuArchivo; //abre el contenedor submenu
    Gtk::Menu subMenuItinerario;
    Gtk::Menu subMenuAdministrativo;//Contiene opciones del modulo administrativo
    
    Gtk::ImageMenuItem menuEscogerAerolinea;
    Gtk::ImageMenuItem menuItinerarios;//Abre la ventana de itinerarios
    Gtk::ImageMenuItem menuItemAvion;

    Gtk::Fixed fixed; // contenedor

    AerolineaData* aerolineaData;
    CiudadData* ciudadData;
    AvionData* avionData;
};

#endif /* VENTANAPRINCIPAL_H */