
/* 
 * File:   VentanaEliminarVuelo.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:21 AM
 */

#ifndef VENTANAELIMINARVUELO_H
#define VENTANAELIMINARVUELO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
class VentanaEliminarVuelo : public Gtk::Window{
public:
    VentanaEliminarVuelo();
    VentanaEliminarVuelo(const VentanaEliminarVuelo& orig);
    virtual ~VentanaEliminarVuelo();
private:
    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
     void onButtonClickedEliminar();
    
     void init();
    
     Gtk::Fixed fixed;
    
    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;
    
    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;
    
    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;
    
    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;
    Gtk::Button btnEliminar;
    
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
    
    Vuelo* vueloActual;
    
    string infoItinerario;
    
    
};

#endif /* VENTANAELIMINARVUELO_H */

