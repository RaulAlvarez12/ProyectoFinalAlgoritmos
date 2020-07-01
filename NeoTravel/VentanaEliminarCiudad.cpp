/* 
 * File:   VentanaEliminarCiudad.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:21 AM
 */

#include "VentanaEliminarCiudad.h"

VentanaEliminarCiudad::VentanaEliminarCiudad() {
    this->set_size_request(300, 300);
    this->set_title("Eliminar Ciudad");
    init();
}

VentanaEliminarCiudad::VentanaEliminarCiudad(const VentanaEliminarCiudad& orig) {
}

VentanaEliminarCiudad::~VentanaEliminarCiudad() {
}

void VentanaEliminarCiudad::init() {
    if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
        this->ciudadActual = ciudadData->getInstance()->firstInList();
        this->lblCiudad.set_label(ciudadActual->toString());
        this->fixed.put(this->lblCiudad, 20, 0);

        this->btnDerecha.set_label("->");
        this->btnDerecha.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarCiudad::onButtonClickedDerecha));
        this->fixed.put(this->btnDerecha, 100, 140);

        this->btnIzquierda.set_label("<-");
        this->btnIzquierda.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarCiudad::onButtonClickedIzquierda));
        this->fixed.put(this->btnIzquierda, 10, 140);

        this->btnEliminar.set_label("Eliminar");
        this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarCiudad::onButtonClickedEliminar));
        this->fixed.put(this->btnEliminar, 10, 200);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblCiudad.set_label("No hay ciudades registradas");
        this->fixed.put(this->lblCiudad, 20, 20);

        this->btnDerecha.set_label("->");
        this->fixed.put(this->btnDerecha, 100, 60);

        this->btnIzquierda.set_label("<-");
        this->fixed.put(this->btnIzquierda, 10, 60);

        this->btnEliminar.set_label("Eliminar");
        this->fixed.put(this->btnEliminar, 10, 140);

        this->add(fixed);
        this->show_all_children();
    }
}//init

void VentanaEliminarCiudad::onButtonClickedIzquierda() {
    ciudadActual = ciudadData->getInstance()->obtenerAnteriorCiudad(ciudadActual);
    this->lblCiudad.set_label(ciudadActual->toString());
}

void VentanaEliminarCiudad::onButtonClickedDerecha() {
    ciudadActual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
    this->lblCiudad.set_label(ciudadActual->toString());
}

void VentanaEliminarCiudad::onButtonClickedEliminar() {
    if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
        Gtk::MessageDialog dialogo(*this, "Eliminacion exitosa:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(ciudadActual->toString());
        dialogo.run();
        ciudadData->getInstance()->eliminarCiudad(ciudadActual);
        if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
            ciudadActual = ciudadData->getInstance()->firstInList();
            this->lblCiudad.set_label(ciudadActual->toString());
        } else {
            this->close();
        }
    }
}

bool VentanaEliminarCiudad::on_key_press_event(GdkEventKey* event) {
    if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
        if (event->keyval == GDK_KEY_Left) {
            onButtonClickedIzquierda();
        } else if (event->keyval == GDK_KEY_Right) {
            onButtonClickedDerecha();
        }
    }
}