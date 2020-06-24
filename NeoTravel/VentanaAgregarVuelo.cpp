
/* 
 * File:   VentanaAgregarVuelo.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:19 AM
 */

#include "VentanaAgregarVuelo.h"

VentanaAgregarVuelo::VentanaAgregarVuelo() {
    this->set_size_request(800, 300);
    this->set_title("Agregar Vuelos");
    init();
    this->show_all_children();
}

VentanaAgregarVuelo::VentanaAgregarVuelo(const VentanaAgregarVuelo& orig) {
}

VentanaAgregarVuelo::~VentanaAgregarVuelo() {
}

void VentanaAgregarVuelo::init() {

    if (!ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty() && !aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty() && !avionData->getInstance()->obtenerListaDeAviones()->isEmpty()) {


        
        this->aerolineaActual = aerolineaData->getInstance()->firstInList();
        this->avionActual = avionData->getInstance()->firstInList();
        this->ciudadOactual = ciudadData->getInstance()->firstInList();
        this->ciudadDactual = ciudadData->getInstance()->firstInList();

        this->lblAerolinea.set_label("Aerolinea");
        this->fixed.put(this->lblAerolinea, 30, 20);
        this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
        this->fixed.put(this->lblAerolineaActual, 40, 70);
        this->btnIzqAerolinea.set_label("<-");
        this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedIzqAerolinea));
        this->fixed.put(this->btnIzqAerolinea, 10, 115);
        this->btnDerAerolinea.set_label("->");
        this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedDerAerolinea));
        this->fixed.put(this->btnDerAerolinea, 80, 115);

        this->lblCiudadO.set_label("Ciudad Origen");
        this->fixed.put(this->lblCiudadO, 230, 20);
        this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
        this->fixed.put(this->lblCiudadOactual, 240, 70);
        this->btnIzqCiudadO.set_label("<-");
        this->btnIzqCiudadO.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedIzqCiudadO));
        this->fixed.put(this->btnIzqCiudadO, 210, 115);
        this->btnDerCiudadO.set_label("->");
        this->btnDerCiudadO.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedDerCiudadO));
        this->fixed.put(this->btnDerCiudadO, 280, 115);

        this->lblCiudadD.set_label("Ciudad Destino");
        this->fixed.put(this->lblCiudadD, 430, 20);
        this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
        this->fixed.put(this->lblCiudadDactual, 440, 70);
        this->btnIzqCiudadD.set_label("<-");
        this->btnIzqCiudadD.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedIzqCiudadD));
        this->fixed.put(this->btnIzqCiudadD, 410, 115);
        this->btnDerCiudadD.set_label("->");
        this->btnDerCiudadD.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedDerCiudadD));
        this->fixed.put(this->btnDerCiudadD, 480, 115);

        this->lblAvion.set_label("Avion");
        this->fixed.put(this->lblAvion, 630, 20);
        this->lblAvionActual.set_label(avionActual->getNombreAvion());
        this->fixed.put(this->lblAvionActual, 640, 70);
        this->btnIzqAvion.set_label("<-");
        this->btnIzqAvion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedIzqAvion));
        this->fixed.put(this->btnIzqAvion, 610, 115);
        this->btnDerAvion.set_label("->");
        this->btnDerAvion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedDerAvion));
        this->fixed.put(this->btnDerAvion, 680, 115);

        this->btnAgregar.set_label("Agregar");
        this->btnAgregar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarVuelo::onButtonClickedAgregar));
        this->fixed.put(this->btnAgregar, 330, 250);
    } else {
        this->lblAerolinea.set_label("          No se puede completar la accion\n Agregar los aviones y las ciudades necesarias");
        this->fixed.put(this->lblAerolinea, 50, 20);
        this->set_size_request(500, 300);
    }


    this->add(fixed);
    this->show_all_children();
}

void VentanaAgregarVuelo::onButtonClickedDerAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedIzqAerolinea() {
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedDerAvion() {
    avionActual = avionData->getInstance()->obtenerSiguienteAvion(avionActual);
    this->lblAvionActual.set_label(avionActual->getNombreAvion());
}

void VentanaAgregarVuelo::onButtonClickedIzqAvion() {
    avionActual = avionData->getInstance()->obtenerAnteriorAvion(avionActual);
    this->lblAvionActual.set_label(avionActual->getNombreAvion());
}

void VentanaAgregarVuelo::onButtonClickedDerCiudadD() {
    ciudadDactual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadDactual);
    this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedIzqCiudadD() {
    ciudadDactual = ciudadData->getInstance()->obtenerAnteriorCiudad(ciudadDactual);
    this->lblCiudadDactual.set_label(ciudadDactual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedDerCiudadO() {
    ciudadOactual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadOactual);
    this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedIzqCiudadO() {
    ciudadOactual = ciudadData->getInstance()->obtenerAnteriorCiudad(ciudadOactual);
    this->lblCiudadOactual.set_label(ciudadOactual->getNombre());
}

void VentanaAgregarVuelo::onButtonClickedAgregar() {
    Itinerario* itinerario = new Itinerario();
    itinerario->setAvion(this->avionActual);
    Vuelo* vuelo = new Vuelo(itinerario, ciudadOactual, ciudadDactual);
    this->aerolineaActual->vueloData->insertarVuelo(vuelo);
    Gtk::MessageDialog dialogo(*this, "Registro exitoso:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(aerolineaActual->vueloData->firstInList()->toString());
        dialogo.run();

}
