/* 
 * File:   VentanaEliminarAvion.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:21 AM
 */

#ifndef VENTANAELIMINARAVION_H
#define VENTANAELIMINARAVION_H

#include <gtkmm.h>

#include "Avion.h"
#include "AvionData.h"

class VentanaEliminarAvion : public Gtk::Window {
public:
    VentanaEliminarAvion();
    VentanaEliminarAvion(const VentanaEliminarAvion& orig);
    virtual ~VentanaEliminarAvion();
private:

    void init();
    void onButtonClickedDerecha();
    void onButtonClickedIzquierda();
    void onButtonClickedEliminar();

    Gtk::Fixed fixed;
    Gtk::Label lblAvion;

    Gtk::Button btnIzquierda;
    Gtk::Button btnDerecha;
    Gtk::Button btnEliminarAvion;

    Avion* avionActual;
    AvionData* avionData;

protected:
    bool on_key_press_event(GdkEventKey* event);
};

#endif /* VENTANAELIMINARAVION_H */