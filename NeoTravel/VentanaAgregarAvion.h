/* 
 * File:   VentanaAgregarAvion.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:18 AM
 */

#ifndef VENTANAAGREGARAVION_H
#define VENTANAAGREGARAVION_H

#include <gtkmm.h>

#include "Avion.h"
#include "AvionData.h"

class VentanaAgregarAvion : public Gtk::Window{
public:
    VentanaAgregarAvion();
    VentanaAgregarAvion(const VentanaAgregarAvion& orig);
    virtual ~VentanaAgregarAvion();
private:
    
    void init();
    void onButtonClickedGuardar();
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblNombreAvion;
    Gtk::Label lblCantidadEspacios;
    Gtk::Label lblCantidadVuelos;
    Gtk::Label lblHorasDeVuelo;
    

    Gtk::Entry etNombreAvion;
    Gtk::Entry etCantidadEspacios;
    Gtk::Entry etCantidadVuelos;
    Gtk::Entry etHorasDeVuelo;

    Gtk::Button btnGuardar;
    
    AvionData* avionData;
    
};

#endif /* VENTANAAGREGARAVION_H */