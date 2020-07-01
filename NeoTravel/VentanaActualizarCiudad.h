/* 
 * File:   VentanaActualizarCiudad.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:24 AM
 */

#ifndef VENTANAACTUALIZARCIUDAD_H
#define VENTANAACTUALIZARCIUDAD_H

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm/comboboxtext.h>
#include <string.h>
#include <iostream>

#include "Ciudad.h"
#include "CiudadData.h"

class VentanaActualizarCiudad : public Gtk::Window {
public:
    VentanaActualizarCiudad();
    VentanaActualizarCiudad(const VentanaActualizarCiudad& orig);
    virtual ~VentanaActualizarCiudad();
    
    protected:
        
        void on_combo_changed();
        Gtk::ComboBoxText cbCiudades;
    
private:
    
    void init();
    void buscarCiudad();//Sirve para actualizar el label con la informacion del la ciudad seleccionada en el combo box
    void onButtonClickedActualizar();
    
    //Atributos
    Gtk::Fixed fixed;
    Gtk::Label lblCiudades;
    Gtk::Label lblNombreCiudad;
    
    Gtk::Entry etNombreCiudad;
    
    Gtk::Button btnActualizar;

    Ciudad* ciudadActual;
    CiudadData* ciudadData;
};

#endif /* VENTANAACTUALIZARCIUDAD_H */