/* 
 * File:   VentanaEliminarCiudad.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:21 AM
 */

#ifndef VENTANAELIMINARCIUDAD_H
#define VENTANAELIMINARCIUDAD_H

#include <gtkmm.h>

#include "Ciudad.h"
#include "CiudadData.h"

class VentanaEliminarCiudad : public Gtk::Window {
public:
    VentanaEliminarCiudad();
    VentanaEliminarCiudad(const VentanaEliminarCiudad& orig);
    virtual ~VentanaEliminarCiudad();

protected:
    bool on_key_press_event(GdkEventKey* event);

private:

    void init();
    void onButtonClickedDerecha();
    void onButtonClickedIzquierda();
    void onButtonClickedEliminar();

    Gtk::Fixed fixed;
    Gtk::Label lblCiudad;

    Gtk::Button btnIzquierda;
    Gtk::Button btnDerecha;
    Gtk::Button btnEliminar;

    Ciudad* ciudadActual;
    CiudadData* ciudadData;

};

#endif /* VENTANAELIMINARCIUDAD_H */