
/* 
 * File:   VentanaAgregarAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:17 AM
 */

#include "VentanaAgregarAerolinea.h"

VentanaAgregarAerolinea::VentanaAgregarAerolinea() {
        this->set_size_request(300, 300);
    this->set_title("Actualizar Aerolinea");
    init();
    this->show_all_children();
}

VentanaAgregarAerolinea::VentanaAgregarAerolinea(const VentanaAgregarAerolinea& orig) {
}

VentanaAgregarAerolinea::~VentanaAgregarAerolinea() {
}

void VentanaAgregarAerolinea::init() {
this->lblNombre.set_label("Nombre Aerolinea:");
    this->fixed.put(this->lblNombre, 20, 20);
    this->fixed.put(this->etNombre, 145, 20);


    this->btnIngresar.set_label("Agregar");
    this->btnIngresar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarAerolinea::onButtonClickedIngresar));
    this->fixed.put(this->btnIngresar, 70, 75);

    this->add(fixed);
    this->show_all_children();
}

void VentanaAgregarAerolinea::aboutWinClose() {

}

void VentanaAgregarAerolinea::onButtonClickedIngresar() {
    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea(etNombre.get_text().c_str()));
    Gtk::MessageDialog dialogo(*this, "Aerolinea Agregada:", false, Gtk::MESSAGE_INFO);
    dialogo.set_secondary_text( aerolineaData->getInstance()->firstInList()->toString());
    dialogo.run();
    this->etNombre.set_text("");
    
    
}
