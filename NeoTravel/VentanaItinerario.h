/* 
 * File:   VentanaItinerario.h
 * Author: Raul Alvarez Fernandez
 *
 * Created on 11 de junio de 2020, 05:08 PM
 */

#ifndef VENTANAITINERARIO_H
#define VENTANAITINERARIO_H

#include <gtkmm.h>
#include <vector>

#include "Aerolinea.h"
#include "AerolineaData.h"

using namespace std;

class VentanaItinerario : public Gtk::Window{

public:
    
    VentanaItinerario();
    virtual ~VentanaItinerario();

private:
    
    void init();
    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
    
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;
    
    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;
    
    Gtk::Label lbl_Itinerario;
    Gtk::Label lbl_ItinerarioActual;
    
    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;
    
    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;
    
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
    
    Vuelo* vueloActual;
    
    string infoItinerario;
};

#endif /* VENTANAITINERARIO_H */