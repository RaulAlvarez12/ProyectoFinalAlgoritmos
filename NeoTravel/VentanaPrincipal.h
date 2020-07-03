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
#include "VentanaPantallaVuelos.h"

class VentanaPrincipal : public Gtk::Window {
public:
    VentanaPrincipal();
    virtual ~VentanaPrincipal();
private:
    void init();
    
    void aboutWinClose();
    void aboutWinCloseVentanaItinerarios();
    void aboutWinCloseVentanaLogin();
    void aboutWinCloseVentanaPantallaVuelos();
    
    void abrirVentanaLogin();
    void abrirVentanaEscogerAerolinea();
    void abrirVentanaItinerario();
    void abrirVentanaPantallaVuelos();

    //Atributos
    VentanaEscogerAerolinea* ventanaescoger;
    VentanaItinerario* ventanaItinerario;
    VentanaLoginAdmin* ventanaLogin;
    VentanaPantallaVuelos* ventanaPantallaVuelos;
    
    Gtk::MenuBar menuBar;
    
    Gtk::MenuItem menuArchivo;
    Gtk::MenuItem menuItinerario;//item del menu bar
    Gtk::MenuItem menuAdministrativo;
    Gtk::MenuItem menuPantallaVuelos;
    
    Gtk::Menu subMenuArchivo; //abre el contenedor submenu
    Gtk::Menu subMenuItinerario;
    Gtk::Menu subMenuAdministrativo;//Contiene opciones del modulo administrativo
    Gtk::Menu subMenuPantallaVuelos;
    
    Gtk::ImageMenuItem menuEscogerAerolinea;
    Gtk::ImageMenuItem menuItinerarios;//Abre la ventana de itinerarios
    Gtk::ImageMenuItem menuItemAvion;
    Gtk::ImageMenuItem menuItemPantallaVuelos;

    Gtk::Fixed fixed; // contenedor

    AerolineaData* aerolineaData;
    CiudadData* ciudadData;
    AvionData* avionData;
};

#endif /* VENTANAPRINCIPAL_H */