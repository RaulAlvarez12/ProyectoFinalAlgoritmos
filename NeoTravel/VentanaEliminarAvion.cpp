/* 
 * File:   VentanaEliminarAvion.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:21 AM
 */

#include "VentanaEliminarAvion.h"

VentanaEliminarAvion::VentanaEliminarAvion() {
    this->set_size_request(300, 300);
    this->set_title("Eliminar Avion");
    init();
}

VentanaEliminarAvion::VentanaEliminarAvion(const VentanaEliminarAvion& orig) {
}

VentanaEliminarAvion::~VentanaEliminarAvion() {
}

void VentanaEliminarAvion::init() {
    if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
        this->avionActual = avionData->getInstance()->firstInList();
        this->lblAvion.set_label(avionActual->toString());
        this->fixed.put(this->lblAvion, 20, 0);

        this->btnDerecha.set_label("->");
        this->btnDerecha.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAvion::onButtonClickedDerecha));
        this->fixed.put(this->btnDerecha, 100, 140);

        this->btnIzquierda.set_label("<-");
        this->btnIzquierda.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAvion::onButtonClickedIzquierda));
        this->fixed.put(this->btnIzquierda, 10, 140);


        this->btnEliminarAvion.set_label("Eliminar");
        this->btnEliminarAvion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAvion::onButtonClickedEliminar));
        this->fixed.put(this->btnEliminarAvion, 10, 200);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblAvion.set_label("No hay aviones registrados");
        this->fixed.put(this->lblAvion, 20, 20);

        this->btnDerecha.set_label("->");
        this->fixed.put(this->btnDerecha, 100, 60);

        this->btnIzquierda.set_label("<-");
        this->fixed.put(this->btnIzquierda, 10, 60);

        this->btnEliminarAvion.set_label("Eliminar");
        this->fixed.put(this->btnEliminarAvion, 10, 140);

        this->add(fixed);
        this->show_all_children();
    }
}

void VentanaEliminarAvion::onButtonClickedDerecha() {
    avionActual = avionData->getInstance()->obtenerSiguienteAvion(avionActual);
    this->lblAvion.set_label(avionActual->toString());
}

void VentanaEliminarAvion::onButtonClickedIzquierda() {
    avionActual = avionData->getInstance()->obtenerAnteriorAvion(avionActual);
    this->lblAvion.set_label(avionActual->toString());
}

void VentanaEliminarAvion::onButtonClickedEliminar() {
    if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
        Gtk::MessageDialog dialogo(*this, "Eliminacion exitosa:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(avionActual->toString());
        dialogo.run();
        avionData->getInstance()->eliminarAvion(avionActual);
        if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
            avionActual = avionData->getInstance()->firstInList();
            this->lblAvion.set_label(avionActual->toString());
        } else {
            this->close();
        }
    }
}

bool VentanaEliminarAvion::on_key_press_event(GdkEventKey* event) {
    if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
        if (event->keyval == GDK_KEY_Left) {
            onButtonClickedIzquierda();
        } else if (event->keyval == GDK_KEY_Right) {
            onButtonClickedDerecha();
        }
    }
}