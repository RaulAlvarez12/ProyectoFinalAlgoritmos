
/* 
 * File:   VentanaBuscarVuelo.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:22 AM
 */

#ifndef VENTANABUSCARVUELO_H
#define VENTANABUSCARVUELO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>


#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
class VentanaBuscarVuelo : public Gtk::Window{
public:
    VentanaBuscarVuelo();
    VentanaBuscarVuelo(const VentanaBuscarVuelo& orig);
    virtual ~VentanaBuscarVuelo();
private:
    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
     void onButtonClickedBuscar();
    
     void init();
    
     Gtk::Fixed fixed;
    
    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;
    Gtk::Label lblData;
    
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
    

};

#endif /* VENTANABUSCARVUELO_H */

