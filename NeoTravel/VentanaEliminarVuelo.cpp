
/* 
 * File:   VentanaEliminarVuelo.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:21 AM
 */

#include "VentanaEliminarVuelo.h"

VentanaEliminarVuelo::VentanaEliminarVuelo() {
    this->set_size_request(400, 300);
    this->set_title("Eliminar Vuelo ");
    init();
    this->show_all_children();
}

VentanaEliminarVuelo::VentanaEliminarVuelo(const VentanaEliminarVuelo& orig) {
}

VentanaEliminarVuelo::~VentanaEliminarVuelo() {
}

void VentanaEliminarVuelo::init() {
    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();

    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 100);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarVuelo::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarVuelo::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);

    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 100);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarVuelo::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarVuelo::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);

    this->btnEliminar.set_label("Eliminar");
    this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarVuelo::onButtonClickedEliminar));
    this->fixed.put(this->btnEliminar, 150, 250);


    this->add(fixed);
    this->show_all_children();
}

void VentanaEliminarVuelo::onButtonClickedDerAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }

}

void VentanaEliminarVuelo::onButtonClickedIzqAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaEliminarVuelo::onButtonClickedDerVuelo() {
    this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaEliminarVuelo::onButtonClickedIzqVuelo() {
    this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaEliminarVuelo::onButtonClickedEliminar() {

    aerolineaActual->vueloData->borrarVuelo(vueloActual);
     Gtk::MessageDialog dialogo(*this, "Borrado exitoso:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(vueloActual->toString());
        dialogo.run();
    this->close();
}
