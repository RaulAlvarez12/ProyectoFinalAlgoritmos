
/* 
 * File:   VentanaActualizarAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:23 AM
 */

#include "VentanaActualizarAerolinea.h"
#include "Aerolinea.h"

VentanaActualizarAerolinea::VentanaActualizarAerolinea() {
        this->set_size_request(300, 300);
    this->set_title("Actualizar Aerolinea");
    init();
    this->show_all_children();
}

VentanaActualizarAerolinea::VentanaActualizarAerolinea(const VentanaActualizarAerolinea& orig) {
}

VentanaActualizarAerolinea::~VentanaActualizarAerolinea() {
}

void VentanaActualizarAerolinea::aboutWinClose() {

}

void VentanaActualizarAerolinea::init() {
if(aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty()){
        this->close();
    }else{
 this->aerolineaActual =aerolineaData->getInstance()->firstInList();
    
    this->lblBienvenido.set_label("Bienvenido Escoja su aerolinea preferida");
    this->fixed.put(this->lblBienvenido, 20, 20);
    
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaInfo, 50, 80);

    this->btnDer.set_label("Arriba");
    this->btnDer.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarAerolinea::onButtonClickedArriba));
    this->fixed.put(this->btnDer, 150, 50);

    this->btnIzq.set_label("Abajo");
    this->btnIzq.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarAerolinea::onButtonClickedAbajo));
    this->fixed.put(this->btnIzq, 150, 90);
    
    
    this->lblNombre.set_label("Nombre Nuevo:");
    this->fixed.put(this->lblNombre, 20, 200);
    this->fixed.put(this->etNombre, 125, 200);


    this->btnEscoger.set_label("Actualizar");
    this->btnEscoger.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarAerolinea::onButtonClickedIngresar));
    this->fixed.put(this->btnEscoger, 100, 300);
    
    }
    this->add(fixed);
    this->show_all_children();
}

void VentanaActualizarAerolinea::onButtonClickedAbajo() {
 aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaActualizarAerolinea::onButtonClickedArriba() {
aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaActualizarAerolinea::onButtonClickedIngresar() {
    aerolineaActual->setNombre(etNombre.get_text().c_str());
    Gtk::MessageDialog dialogo(*this, "Aerolinea Actualizada:", false, Gtk::MESSAGE_INFO);
    dialogo.set_secondary_text(aerolineaActual->getNombre());
    dialogo.run();
    this->etNombre.set_text("");
}
