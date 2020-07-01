/* 
 * File:   VentanaBuscarCiudad.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:22 AM
 */

#ifndef VENTANABUSCARCIUDAD_H
#define VENTANABUSCARCIUDAD_H

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm/comboboxtext.h>

#include "Ciudad.h"
#include "CiudadData.h"

class VentanaBuscarCiudad : public Gtk::Window {
public:
    VentanaBuscarCiudad();
    VentanaBuscarCiudad(const VentanaBuscarCiudad& orig);
    virtual ~VentanaBuscarCiudad();

protected:

    void on_combo_changed();
    Gtk::ComboBoxText cbCiudades;

private:
    
    void init();
    void buscarCiudad();//Actualiza label con el toString de la ciudad
    
    //Atributos
    Gtk::Fixed fixed;
    Gtk::Label lblCiudades;
    Gtk::Label lblInformacionCiudad;

    Ciudad* ciudadActual;
    CiudadData* ciudadData;
};

#endif /* VENTANABUSCARCIUDAD_H */