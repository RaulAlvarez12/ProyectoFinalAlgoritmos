
/* 
 * File:   VentanaEliminarHorario.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:21 AM
 */

#include "VentanaEliminarHorario.h"

VentanaEliminarHorario::VentanaEliminarHorario() {
    this->set_size_request(600, 400);
    this->set_title("Eliminar Horario");
    init();
    this->show_all_children();
}

VentanaEliminarHorario::VentanaEliminarHorario(const VentanaEliminarHorario& orig) {
}

VentanaEliminarHorario::~VentanaEliminarHorario() {
}

void VentanaEliminarHorario::init() {
    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();
    horarioActual = aerolineaActual->vueloData->firstInList()->getItinerario()->getColaPrioridad()->frente();


    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 100);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);

    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 100);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);


    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->fixed.put(this->lblHorarioActual, 375, 20);

    this->btnAnteriorHorario.set_label("<-");
    this->btnAnteriorHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedIzqHorario));
    this->fixed.put(this->btnAnteriorHorario, 385, 150);
    this->btnSiguienteHorario.set_label("->");
    this->btnSiguienteHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedDerHorario));
    this->fixed.put(this->btnSiguienteHorario, 485, 150);


    this->btnEliminar.set_label("Eliminar");
    this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarHorario::onButtonClickedEliminar));
    this->fixed.put(this->btnEliminar, 250, 200);


    this->add(fixed);
    this->show_all_children();
}

void VentanaEliminarHorario::onButtonClickedDerAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
        this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaEliminarHorario::onButtonClickedIzqAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
        this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaEliminarHorario::onButtonClickedIzqHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerAnteriorHorario(horarioActual);
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
}

void VentanaEliminarHorario::onButtonClickedDerHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerSiguienteHorario(horarioActual);
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
}

void VentanaEliminarHorario::onButtonClickedDerVuelo() {
    this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
        this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
}

void VentanaEliminarHorario::onButtonClickedIzqVuelo() {
    this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
        this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
}

void VentanaEliminarHorario::onButtonClickedEliminar() {
    vueloActual->getItinerario()->getColaPrioridad()->eliminar(horarioActual);
    Gtk::MessageDialog dialogo(*this, "Horario Eliminado:", false, Gtk::MESSAGE_INFO);
    dialogo.set_secondary_text(vueloActual->toString());
    dialogo.run();
    this->close();

}
