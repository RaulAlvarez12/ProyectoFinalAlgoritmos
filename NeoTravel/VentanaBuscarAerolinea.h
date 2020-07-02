
/* 
 * File:   VentanaBuscarAerolinea.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:22 AM
 */

#ifndef VENTANABUSCARAEROLINEA_H
#define VENTANABUSCARAEROLINEA_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"

class VentanaBuscarAerolinea : public Gtk::Window{
public:
    VentanaBuscarAerolinea();
    VentanaBuscarAerolinea(const VentanaBuscarAerolinea& orig);
    virtual ~VentanaBuscarAerolinea();
private:
void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
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
    
    Gtk::Button btnEliminar;
    
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;

};

#endif /* VENTANABUSCARAEROLINEA_H */

