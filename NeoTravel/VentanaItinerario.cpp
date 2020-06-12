/* 
 * File:   VentanaItinerario.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 11 de junio de 2020, 05:08 PM
 */

#include "VentanaItinerario.h"
#include "AerolineaData.h"

VentanaItinerario::VentanaItinerario() {
    this->aerolineaData = new AerolineaData();
    this->set_size_request(800, 600);
    this->set_title("Itinerarios de las aerolineas");
    init();
    this->show_all_children();
}//Constructor


VentanaItinerario::~VentanaItinerario() {
}//destructor

void VentanaItinerario::init(){
    
    this->aerolineaActual = aerolineaData->firstInList();
    
    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 20, 20);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaActual, 20, 100);
    
    this->btnIzqAerolinea.set_label("<-");
    this->btnIzqAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedIzqAerolinea));
    this->fixed.put(this->btnIzqAerolinea, 10, 150);
    
    this->btnDerAerolinea.set_label("->");
    this->btnDerAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedDerAerolinea));
    this->fixed.put(this->btnDerAerolinea, 80, 150);
    
    this->lblVuelo.set_label("Vuelo");
    this->fixed.put(this->lblVuelo, 250, 20);
    this->lblVueloActual.set_label("POR HACER");
    this->fixed.put(this->lblVueloActual, 250, 100);
    
    this->btnIzqVuelo.set_label("<-");
    this->btnIzqVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnIzqVuelo, 210, 150);
    
    this->btnDerVuelo.set_label("->");
    this->btnDerVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerario::onButtonClickedDerVuelo));
    this->fixed.put(this->btnDerVuelo, 300, 150);
    
    this->lbl_Itinerario.set_label("Itinerario");
    this->fixed.put(this->lbl_Itinerario, 500, 20);
    this->lbl_ItinerarioActual.set_label("POR HACER");
    this->fixed.put(this->lbl_ItinerarioActual, 500, 100);
    
    this->add(fixed);
    this->show_all_children();
}//init

void VentanaItinerario::onButtonClickedIzqAerolinea(){
    aerolineaActual = aerolineaData->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}//onButtonClickedIzqAerolinea

void VentanaItinerario::onButtonClickedDerAerolinea(){
    aerolineaActual = aerolineaData->obtenerAnterior(aerolineaActual);
    this->lblAerolineaActual.set_label(aerolineaActual->getNombre());
}//onButtonClickedDerAerolinea

void VentanaItinerario::onButtonClickedIzqVuelo(){
    
}//onButtonClickedIzqVuelo

void VentanaItinerario::onButtonClickedDerVuelo(){
    
}//onButtonClickedDerVuelo
