
/* 
 * File:   VentanaPantallaVuelos.cpp
 * Author: alsov
 * 
 * Created on 1 de julio de 2020, 07:19 PM
 */

#include "VentanaPantallaVuelos.h"

VentanaPantallaVuelos::VentanaPantallaVuelos() {
    this->set_size_request(800, 300);
    this->set_title("Pantalla de vuelos");
    init();
}

VentanaPantallaVuelos::~VentanaPantallaVuelos() {
}

void VentanaPantallaVuelos::init() {
    if(!this->aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty()){
        
        this->lblTitulo.set_text("Vuelos en transcurso:");
        this->fixed.put(this->lblTitulo, 20, 20);
        
        this->lblVuelos.set_text(this->aerolineaData->getInstance()->mostrarVuelosActivos());//OCURRE MAGIA
        this->fixed.put(this->lblVuelos, 20, 60);
        
        this->add(fixed);
        this->show_all_children();
    }else{
        this->lblTitulo.set_text("Vuelos en transcurso:");
        this->fixed.put(this->lblTitulo, 20, 20);
        
        this->lblVuelos.set_text("No hay datos registrados");
        this->fixed.put(this->lblVuelos, 20, 60);
        
        this->add(fixed);
        this->show_all_children();
    }
}//init