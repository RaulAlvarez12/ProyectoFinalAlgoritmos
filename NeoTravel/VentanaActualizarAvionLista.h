/* 
 * File:   VentanaActualizarAvionLista.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:23 AM
 */

#ifndef VENTANAACTUALIZARAVIONLISTA_H
#define VENTANAACTUALIZARAVIONLISTA_H

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm/comboboxtext.h>
#include <string.h>

#include "Avion.h"
#include "AvionData.h"

class VentanaActualizarAvionLista : public Gtk::Window {
public:
    VentanaActualizarAvionLista();
    VentanaActualizarAvionLista(const VentanaActualizarAvionLista& orig);
    virtual ~VentanaActualizarAvionLista();

protected:

    void on_combo_changed();
    Gtk::ComboBoxText cbAviones;

private:

    void init();
    void buscarAvion();//Sirve para actualizar el label con la informacion del avion seleccionado en el combo box
    void onButtonClickedActualizar();
    
    //Atributos
    Gtk::Fixed fixed;
    Gtk::Label lblAviones;
    Gtk::Label lblNombreAvion;
    Gtk::Label lblCantidadEspacios;
    Gtk::Label lblCantidadVuelos;
    Gtk::Label lblHorasVuelo;
    
    Gtk::Entry etNombreAvion;
    Gtk::Entry etCantidadEspacios;
    Gtk::Entry etCantidadVuelos;
    Gtk::Entry etHorasVuelos;
    
    Gtk::Button btnActualizar;

    Avion* avionActual;
    AvionData* avionData;
};

#endif /* VENTANAACTUALIZARAVIONLISTA_H */