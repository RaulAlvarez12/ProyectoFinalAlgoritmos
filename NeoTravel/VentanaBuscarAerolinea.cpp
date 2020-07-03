
/* 
 * File:   VentanaBuscarAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:22 AM
 */

#include "VentanaBuscarAerolinea.h"
#include "AerolineaData.h"

VentanaBuscarAerolinea::VentanaBuscarAerolinea() {
    this->set_size_request(400, 500);
    this->set_title("Buscar Aerolinea");
    init();
    this->show_all_children();
}

void VentanaBuscarAerolinea::init() {
    if (!this->aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty()) {
        this->aerolineaActual = aerolineaData->getInstance()->firstInList();

        this->lblAerolinea.set_label("Aerolinea");
        this->fixed.put(this->lblAerolinea, 70, 20);
        this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
        this->fixed.put(this->lblAerolineaActual, 80, 50);

        this->btnIzqAerolinea.set_label("<-");
        this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarAerolinea::onButtonClickedIzqAerolinea));
        this->fixed.put(this->btnIzqAerolinea, 50, 100);

        this->btnDerAerolinea.set_label("->");
        this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarAerolinea::onButtonClickedDerAerolinea));
        this->fixed.put(this->btnDerAerolinea, 120, 100);

        this->btnEliminar.set_label("Buscar");
        this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaBuscarAerolinea::onButtonClickedBuscar));
        this->fixed.put(this->btnEliminar, 110, 140);
        this->lblData.set_text("Informacion:\n");
        this->fixed.put(this->lblData, 25, 190);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblAerolinea.set_text("No hay datos registrados");
        this->fixed.put(this->lblAerolinea, 20, 20);
        this->add(fixed);
        this->show_all_children();
    }
}

void VentanaBuscarAerolinea::onButtonClickedBuscar() {
    this->lblData.set_text("Informacion:\n" + aerolineaActual->toString());
}

void VentanaBuscarAerolinea::onButtonClickedDerAerolinea() {

    this->lblData.set_text("Informacion:\n");
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}

void VentanaBuscarAerolinea::onButtonClickedIzqAerolinea() {
    this->lblData.set_text("Informacion:\n");
    aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}

VentanaBuscarAerolinea::VentanaBuscarAerolinea(const VentanaBuscarAerolinea& orig) {
}

VentanaBuscarAerolinea::~VentanaBuscarAerolinea() {
}

