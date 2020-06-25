/* 
 * File:   VentanaBuscarAvion.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:22 AM
 */

#ifndef VENTANABUSCARAVION_H
#define VENTANABUSCARAVION_H

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm/comboboxtext.h>
#include "Avion.h"
#include "AvionData.h"

class VentanaBuscarAvion : public Gtk::Window {
public:
    VentanaBuscarAvion();
    VentanaBuscarAvion(const VentanaBuscarAvion& orig);
    virtual ~VentanaBuscarAvion();
    

protected:

    void on_combo_changed();
    Gtk::ComboBoxText cbAviones;

private:

    void init();
    void buscarAvion();//Sirve para actualizar el label con la informacion del avion seleccionado en el combo box
    
    //Atributos
    Gtk::Fixed fixed;
    Gtk::Label lblAviones;
    Gtk::Label lblInformacionAvion;

    Avion* avionActual;
    AvionData* avionData;

};

#endif /* VENTANABUSCARAVION_H */