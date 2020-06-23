/* 
 * File:   VentanaItinerario.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 11 de junio de 2020, 05:08 PM
 */

#include "VentanaItinerario.h"
#include "AerolineaData.h"

VentanaItinerario::VentanaItinerario() {
    this->set_size_request(800, 300);
    this->set_title("Itinerarios ");
    init();
    this->show_all_children();
}//Constructor


VentanaItinerario::~VentanaItinerario() {
}//destructor

void VentanaItinerario::init(){
    this->aerolineaActual = aerolineaData->getInstance()->firstInList();
    this->vueloActual = aerolineaActual->vueloData->firstInList();
    
    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 30, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 40, 100);
    
    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);
    
    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);
    
    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->fixed.put(this->lblVueloActual, 230, 100);
    
    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);
    
    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);
    

    this->lbl_Itinerario.set_label("Itinerario");
    this->fixed.put(this->lbl_Itinerario, 600, 20);
    this->lbl_ItinerarioActual.set_label(this->vueloActual->getItinerario()->toString());
    this->fixed.put(this->lbl_ItinerarioActual, 550, 35);
    
    this->add(fixed);
    this->show_all_children();
}//init

void VentanaItinerario::onButtonClickedIzqAerolinea(){
    aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->vueloActual = this->aerolineaActual->vueloData->firstInList();
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->lbl_ItinerarioActual.set_label(this->vueloActual->getItinerario()->toString());
}//onButtonClickedIzqAerolinea

void VentanaItinerario::onButtonClickedDerAerolinea(){
    aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->vueloActual = this->aerolineaActual->vueloData->firstInList();
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->lbl_ItinerarioActual.set_label(this->vueloActual->getItinerario()->toString());
}//onButtonClickedDerAerolinea

void VentanaItinerario::onButtonClickedIzqVuelo(){
    this->vueloActual = this->aerolineaActual->vueloData->obtenerAnteriorVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->lbl_ItinerarioActual.set_label(this->vueloActual->getItinerario()->toString());
}//onButtonClickedIzqVuelo

void VentanaItinerario::onButtonClickedDerVuelo(){
    this->vueloActual = this->aerolineaActual->vueloData->obtenerSiguienteVuelo(this->vueloActual);
    this->lblVueloActual.set_label(this->vueloActual->getCiudadOrigen()->toString() + " a " + this->vueloActual->getciudadDestino()->toString());
    this->lbl_ItinerarioActual.set_label(this->vueloActual->getItinerario()->toString());
}//onButtonClickedDerVuelo
