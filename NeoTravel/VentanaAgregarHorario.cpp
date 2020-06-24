
/* 
 * File:   VentanaAgregarHorario.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:18 AM
 */

#include "VentanaAgregarHorario.h"

VentanaAgregarHorario::VentanaAgregarHorario() {
        this->set_size_request(500, 500);
    this->set_title("Agregar Horario");
    init();
    this->show_all_children();
}

VentanaAgregarHorario::VentanaAgregarHorario(const VentanaAgregarHorario& orig) {
}

VentanaAgregarHorario::~VentanaAgregarHorario() {
}

void VentanaAgregarHorario::init() {

    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();

    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 100);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarHorario::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarHorario::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);

    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 100);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarHorario::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarHorario::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);

    this->btnAgregar.set_label("Agregar");
    this->btnAgregar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarHorario::onButtonClickedAgregar));
    this->fixed.put(this->btnAgregar, 150, 350);

    this->lblHoraSalida.set_text("Hora de salida: ");
    this->fixed.put(this->lblHoraSalida, 20, 220);
    this->fixed.put(this->etHoraSalida, 150, 220);
    
    this->lblHoraLlegada.set_text("Hora de LLegada: ");
    this->fixed.put(this->lblHoraLlegada, 20, 250);
    this->fixed.put(this->etHoraLlegada, 150, 250);

    this->add(fixed);
    this->show_all_children();
}

void VentanaAgregarHorario::onButtonClickedDerAerolinea() {
 aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaAgregarHorario::onButtonClickedIzqAerolinea() {
aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaAgregarHorario::onButtonClickedDerVuelo() {
this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaAgregarHorario::onButtonClickedIzqVuelo() {
this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaAgregarHorario::onButtonClickedAgregar() {
    this->vueloActual->getItinerario()->getColaPrioridad()->encolar(new Horario(atoi(etHoraSalida.get_text().c_str()),atoi(etHoraLlegada.get_text().c_str())));
    this->etHoraLlegada.set_text("");
    this->etHoraSalida.set_text("");
     Gtk::MessageDialog dialogo(*this, "Horario Agregado:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(vueloActual->toString());
        dialogo.run();
}
