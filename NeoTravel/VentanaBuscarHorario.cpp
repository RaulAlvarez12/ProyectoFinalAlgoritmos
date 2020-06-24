
/* 
 * File:   VentanaBuscarHorario.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:22 AM
 */

#include "VentanaBuscarHorario.h"

VentanaBuscarHorario::VentanaBuscarHorario() {
    this->set_size_request(300, 300);
    this->set_title("Buscar Horario");
    init();
    this->show_all_children();
}

VentanaBuscarHorario::VentanaBuscarHorario(const VentanaBuscarHorario& orig) {
}

VentanaBuscarHorario::~VentanaBuscarHorario() {
}

void VentanaBuscarHorario::init() {
    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();
    horarioActual = aerolineaActual->vueloData->firstInList()->getItinerario()->getColaPrioridad()->frente();


    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 100);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);

    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 190, 100);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);


    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->fixed.put(this->lblHorarioActual, 375, 20);

    this->btnAnteriorHorario.set_label("<-");
    this->btnAnteriorHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedIzqHorario));
    this->fixed.put(this->btnAnteriorHorario, 385, 150);
    this->btnSiguienteHorario.set_label("->");
    this->btnSiguienteHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarHorario::onButtonClickedDerHorario));
    this->fixed.put(this->btnSiguienteHorario, 485, 150);

    this->add(fixed);
    this->show_all_children();
}

void VentanaBuscarHorario::onButtonClickedDerAerolinea() {
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

void VentanaBuscarHorario::onButtonClickedIzqAerolinea() {
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

void VentanaBuscarHorario::onButtonClickedDerHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerSiguienteHorario(horarioActual);
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
}

void VentanaBuscarHorario::onButtonClickedIzqHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerAnteriorHorario(horarioActual);
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
}

void VentanaBuscarHorario::onButtonClickedDerVuelo() {
    
    this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
}

void VentanaBuscarHorario::onButtonClickedIzqVuelo() {
    this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    horarioActual =vueloActual->getItinerario()->getColaPrioridad()->frente();
    this->lblHorarioActual.set_label("Horario: \n\n\n\n\n" + horarioActual->toString());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
}

