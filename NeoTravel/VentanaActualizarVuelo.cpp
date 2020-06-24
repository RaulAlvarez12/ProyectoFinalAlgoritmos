
/* 
 * File:   VentanaActualizarVuelo.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:24 AM
 */

#include "VentanaActualizarVuelo.h"

VentanaActualizarVuelo::VentanaActualizarVuelo() {
    this->set_size_request(700, 400);
    this->set_title("Actualizar Vuelo");
    init();
    this->show_all_children();
}

VentanaActualizarVuelo::VentanaActualizarVuelo(const VentanaActualizarVuelo& orig) {
}

VentanaActualizarVuelo::~VentanaActualizarVuelo() {
}

void VentanaActualizarVuelo::init() {
    
     if (!ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty() && !aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty() && !avionData->getInstance()->obtenerListaDeAviones()->isEmpty()) {

    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();
    this->avionActual = avionData->getInstance()->firstInList();
    this->ciudadOactual = ciudadData->getInstance()->firstInList();
    this->ciudadDactual = ciudadData->getInstance()->firstInList();

    this->lblAerolinea.set_label("Aerolinea: ");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 50);

    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 90);

    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 90);

    this->lblVuelo.set_label("Vuelo a modificar");
    this->fixed.put(this->lblVuelo, 200, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 50);

    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 90);

    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 90);

    
     this->lblCiudadO.set_label("Nueva Ciudad Origen");
        this->fixed.put(this->lblCiudadO, 30,140);
        this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
        this->fixed.put(this->lblCiudadOactual, 40, 170);
        this->btnIzqCiudadO.set_label("<-");
        this->btnIzqCiudadO.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedIzqCiudadO));
        this->fixed.put(this->btnIzqCiudadO, 10, 215);
        this->btnDerCiudadO.set_label("->");
        this->btnDerCiudadO.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedDerCiudadO));
        this->fixed.put(this->btnDerCiudadO, 80, 215);

        this->lblCiudadD.set_label("Nueva Ciudad Destino");
        this->fixed.put(this->lblCiudadD, 230, 140);
        this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
        this->fixed.put(this->lblCiudadDactual, 240, 170);
        this->btnIzqCiudadD.set_label("<-");
        this->btnIzqCiudadD.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedIzqCiudadD));
        this->fixed.put(this->btnIzqCiudadD, 210, 215);
        this->btnDerCiudadD.set_label("->");
        this->btnDerCiudadD.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedDerCiudadD));
        this->fixed.put(this->btnDerCiudadD, 280, 215);

        this->lblAvion.set_label("Nuevo Avion");
        this->fixed.put(this->lblAvion, 430, 140);
        this->lblAvionActual.set_label(avionActual->getNombreAvion());
        this->fixed.put(this->lblAvionActual, 440, 170);
        this->btnIzqAvion.set_label("<-");
        this->btnIzqAvion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedIzqAvion));
        this->fixed.put(this->btnIzqAvion, 410, 215);
        this->btnDerAvion.set_label("->");
        this->btnDerAvion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedDerAvion));
        this->fixed.put(this->btnDerAvion, 480, 215);
    
    
    
    
    this->btnActualizar.set_label("Actualizar");
    this->btnActualizar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarVuelo::onButtonClickedActualizar));
    this->fixed.put(this->btnActualizar, 250, 280);
     } else {
        this->lblAerolinea.set_label("          No se puede completar la accion\n Agregar los aviones y las ciudades necesarias");
        this->fixed.put(this->lblAerolinea, 50, 20);
//        this->set_size_request(500, 300);
    }

    this->add(fixed);
    this->show_all_children();
}

void VentanaActualizarVuelo::onButtonClickedDerAerolinea() {
       aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaActualizarVuelo::onButtonClickedDerVuelo() {
this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaActualizarVuelo::onButtonClickedActualizar() {
    vueloActual->setCiudadOrigen(ciudadOactual);
    vueloActual->setciudadDestino(ciudadDactual);
    vueloActual->getItinerario()->setAvion(avionActual);
     Gtk::MessageDialog dialogo(*this, "Actualizacion exitosa:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(vueloActual->toString());
        dialogo.run();
    this->close();
}


void VentanaActualizarVuelo::onButtonClickedIzqAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    if (!aerolineaActual->vueloData->obtenerListaVuelos()->isEmpty()) {
        this->vueloActual = this->aerolineaActual->vueloData->firstInList();
        this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    } else {
        this->lblVueloActual.set_label("No hay Vuelos");
    }
}

void VentanaActualizarVuelo::onButtonClickedIzqVuelo() {
this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());

}

void VentanaActualizarVuelo::onButtonClickedDerAvion() {
    avionActual = avionData->getInstance()->obtenerSiguienteAvion(avionActual);
    this->lblAvionActual.set_label(avionActual->getNombreAvion());
}

void VentanaActualizarVuelo::onButtonClickedIzqAvion() {
avionActual = avionData->getInstance()->obtenerAnteriorAvion(avionActual);
    this->lblAvionActual.set_label(avionActual->getNombreAvion());
}

void VentanaActualizarVuelo::onButtonClickedDerCiudadD() {
ciudadDactual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadDactual);
    this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
}

void VentanaActualizarVuelo::onButtonClickedIzqCiudadD() {
  ciudadDactual = ciudadData->getInstance()->obtenerAnteriorCiudad(ciudadDactual);
    this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
}

void VentanaActualizarVuelo::onButtonClickedDerCiudadO() {
ciudadOactual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadOactual);
    this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
}

void VentanaActualizarVuelo::onButtonClickedIzqCiudadO() {
ciudadOactual = ciudadData->getInstance()->obtenerAnteriorCiudad(ciudadOactual);
    this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
}
