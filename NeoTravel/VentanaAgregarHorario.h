
/* 
 * File:   VentanaAgregarHorario.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:18 AM
 */

#ifndef VENTANAAGREGARHORARIO_H
#define VENTANAAGREGARHORARIO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
#include "Horario.h"
#include "Itinerario.h"
class VentanaAgregarHorario : public Gtk::Window{
public:
    VentanaAgregarHorario();
    VentanaAgregarHorario(const VentanaAgregarHorario& orig);
    virtual ~VentanaAgregarHorario();
private:

    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
     void onButtonClickedAgregar();
    
     void init();
    
     Gtk::Fixed fixed;
    
    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;
    
    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;
    
    Gtk::Label lblHoraSalida;
    Gtk::Entry etHoraSalida;
    
    Gtk::Label lblHoraLlegada;
    Gtk::Entry etHoraLlegada;
    
    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;
    
    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;
    Gtk::Button btnAgregar;
    
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
    
    Vuelo* vueloActual;
    
};

#endif /* VENTANAAGREGARHORARIO_H */

