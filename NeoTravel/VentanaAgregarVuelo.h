/* 
 * File:   VentanaAgregarVuelo.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:19 AM
 */

#ifndef VENTANAAGREGARVUELO_H
#define VENTANAAGREGARVUELO_H
#include <gtkmm.h>
#include <iostream>

#include "Ciudad.h"
#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Avion.h"
#include"AvionData.h"
#include "CiudadData.h"
#include "Vuelo.h"
#include "Itinerario.h"

using namespace std;

class VentanaAgregarVuelo : public Gtk::Window{
public:
    VentanaAgregarVuelo();
    VentanaAgregarVuelo(const VentanaAgregarVuelo& orig);
    virtual ~VentanaAgregarVuelo();
private:
    
    void init();
    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqCiudadO();
    void onButtonClickedDerCiudadO();
    void onButtonClickedIzqCiudadD();
    void onButtonClickedDerCiudadD();
    void onButtonClickedIzqAvion();
    void onButtonClickedDerAvion();
    void onButtonClickedAgregar();
    
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;
    
    Gtk::Label lblCiudadO;
    Gtk::Label lblCiudadOactual;
    
    Gtk::Label lblCiudadD;
    Gtk::Label lblCiudadDactual;
    
    Gtk::Label lblAvion;
    Gtk::Label lblAvionActual;
    
    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;
    
    Gtk::Button btnIzqCiudadO;
    Gtk::Button btnDerCiudadO;
    
    Gtk::Button btnIzqCiudadD;
    Gtk::Button btnDerCiudadD;
    
    Gtk::Button btnIzqAvion;
    Gtk::Button btnDerAvion;
    
    Gtk::Button btnAgregar;
    
    Ciudad* ciudadOactual;
    Ciudad* ciudadDactual;
    
    CiudadData* ciudadData;
    
    
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
    
    Avion* avionActual;
    AvionData* avionData;
    
    string infoItinerario;
};

#endif /* VENTANAAGREGARVUELO_H */

