
/* 
 * File:   VentanaActualizarVuelo.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:24 AM
 */

#ifndef VENTANAACTUALIZARVUELO_H
#define VENTANAACTUALIZARVUELO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Ciudad.h"
#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Avion.h"
#include"AvionData.h"
#include "CiudadData.h"
#include "Vuelo.h"
#include "Itinerario.h"


class VentanaActualizarVuelo : public Gtk::Window {
public:
    VentanaActualizarVuelo();
    VentanaActualizarVuelo(const VentanaActualizarVuelo& orig);
    virtual ~VentanaActualizarVuelo();
private:

    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
    void onButtonClickedActualizar();

    void onButtonClickedIzqCiudadO();
    void onButtonClickedDerCiudadO();
    void onButtonClickedIzqCiudadD();
    void onButtonClickedDerCiudadD();
    void onButtonClickedIzqAvion();
    void onButtonClickedDerAvion();
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
    Gtk::Button btnActualizar;

    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;

    Vuelo* vueloActual;
    
     Gtk::Label lblCiudadO;
    Gtk::Label lblCiudadOactual;
    
    Gtk::Label lblCiudadD;
    Gtk::Label lblCiudadDactual;
    
    Gtk::Label lblAvion;
    Gtk::Label lblAvionActual;
    
    Gtk::Button btnIzqCiudadO;
    Gtk::Button btnDerCiudadO;
    
    Gtk::Button btnIzqCiudadD;
    Gtk::Button btnDerCiudadD;
    
    Gtk::Button btnIzqAvion;
    Gtk::Button btnDerAvion;
    
    
    Ciudad* ciudadOactual;
    Ciudad* ciudadDactual;
    
    CiudadData* ciudadData;
    
    Avion* avionActual;
    AvionData* avionData;

};

#endif /* VENTANAACTUALIZARVUELO_H */

