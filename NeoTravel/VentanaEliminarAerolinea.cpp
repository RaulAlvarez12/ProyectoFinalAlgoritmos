
/* 
 * File:   VentanaEliminarAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:20 AM
 */

#include "VentanaEliminarAerolinea.h"

VentanaEliminarAerolinea::VentanaEliminarAerolinea() {
        this->set_size_request(300, 300);
    this->set_title("Eliminar Aerolinea");
    init();
    this->show_all_children();
}

VentanaEliminarAerolinea::VentanaEliminarAerolinea(const VentanaEliminarAerolinea& orig) {
}

VentanaEliminarAerolinea::~VentanaEliminarAerolinea() {
}

void VentanaEliminarAerolinea::aboutWinClose() {

}

void VentanaEliminarAerolinea::init() {
    if(aerolineaData->getInstance()->obtenerListaDeAerolineas()->isEmpty()){
        this->close();
    }else{
 this->aerolineaActual =aerolineaData->getInstance()->firstInList();
    
    this->lblBienvenido.set_label("Seleccione la aerolinea a eliminar");
    this->fixed.put(this->lblBienvenido, 20, 20);
    
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaInfo, 50, 80);

    this->btnDer.set_label("Arriba");
    this->btnDer.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAerolinea::onButtonClickedArriba));
    this->fixed.put(this->btnDer, 150, 50);

    this->btnIzq.set_label("Abajo");
    this->btnIzq.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAerolinea::onButtonClickedAbajo));
    this->fixed.put(this->btnIzq, 150, 90);


    this->btnEscoger.set_label("Eliminar");
    this->btnEscoger.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEliminarAerolinea::onButtonClickedEscoger));
    this->fixed.put(this->btnEscoger, 100, 140);
    
    }
    this->add(fixed);
    this->show_all_children();
}

void VentanaEliminarAerolinea::onButtonClickedAbajo() {
 aerolineaActual = aerolineaData->getInstance()->obtenerAnterior(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaEliminarAerolinea::onButtonClickedArriba() {
aerolineaActual = aerolineaData->getInstance()->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaEliminarAerolinea::onButtonClickedEscoger() {
    aerolineaData->getInstance()->eliminarAerolinea(aerolineaActual);
    Gtk::MessageDialog dialogo(*this, "Aerolinea Eliminada:", false, Gtk::MESSAGE_INFO);
    dialogo.set_secondary_text(aerolineaActual->getNombre());
    dialogo.run();
    this->close();
}
