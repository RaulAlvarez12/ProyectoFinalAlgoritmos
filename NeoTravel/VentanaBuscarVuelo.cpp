
/* 
 * File:   VentanaBuscarVuelo.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:22 AM
 */

#include "VentanaBuscarVuelo.h"

VentanaBuscarVuelo::VentanaBuscarVuelo() {
        this->set_size_request(400, 500);
    this->set_title("Buscar vuelo");
    init();
    this->show_all_children();
}

VentanaBuscarVuelo::VentanaBuscarVuelo(const VentanaBuscarVuelo& orig) {
}

VentanaBuscarVuelo::~VentanaBuscarVuelo() {
}

void VentanaBuscarVuelo::init() {
this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();

    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 50);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarVuelo::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 100);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarVuelo::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 100);

    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 50);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarVuelo::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 100);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarVuelo::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 100);

    this->btnEliminar.set_label("Buscar");
    this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarVuelo::onButtonClickedBuscar));
    this->fixed.put(this->btnEliminar, 150, 150);
    this->lblData.set_text("Informacion:\n");
    this->fixed.put(this->lblData, 125, 190);

    this->add(fixed);
    this->show_all_children();
}

void VentanaBuscarVuelo::onButtonClickedDerAerolinea() {
    this->lblData.set_text("Informacion:\n");
aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaBuscarVuelo::onButtonClickedDerVuelo() {
    this->lblData.set_text("Informacion:\n");
 this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaBuscarVuelo::onButtonClickedBuscar() {
    this->lblData.set_text("Informacion:\n"+vueloActual->toString());

}

void VentanaBuscarVuelo::onButtonClickedIzqAerolinea() {
    this->lblData.set_text("Informacion:\n");
 aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaBuscarVuelo::onButtonClickedIzqVuelo() {
    this->lblData.set_text("Informacion:\n");
    this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}
