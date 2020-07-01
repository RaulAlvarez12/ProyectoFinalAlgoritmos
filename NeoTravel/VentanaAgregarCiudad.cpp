/* 
 * File:   VentanaAgregarCiudad.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:18 AM
 */

#include "VentanaAgregarCiudad.h"

VentanaAgregarCiudad::VentanaAgregarCiudad() {
    this->set_size_request(270, 180);
    this->set_title("Agregar Ciudad");
    init();
}

VentanaAgregarCiudad::VentanaAgregarCiudad(const VentanaAgregarCiudad& orig) {
}

VentanaAgregarCiudad::~VentanaAgregarCiudad() {
}

void VentanaAgregarCiudad::init() {
    this->lblNombreCiudad.set_label("Nombre ciudad:");
    this->fixed.put(this->lblNombreCiudad, 20, 22);
    this->fixed.put(this->etNombreCiudad, 120, 18);

    this->btnGuardar.set_label("Guardar");
    this->btnGuardar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarCiudad::onButtonClickedGuardar));
    this->fixed.put(this->btnGuardar, 20, 80);

    this->add(fixed);
    this->show_all_children();
}//init

void VentanaAgregarCiudad::onButtonClickedGuardar() {
    if (strcmp(this->etNombreCiudad.get_text().c_str(), "") != 0) {
        ciudadData->getInstance()->agregarCiudad(new Ciudad(this->etNombreCiudad.get_text().c_str()));
        Gtk::MessageDialog dialogo(*this, "Registro exitoso:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(ciudadData->getInstance()->firstInList()->toString());
        dialogo.run();
        this->etNombreCiudad.set_text("");
    } else {
        Gtk::MessageDialog dialogo(*this, "Registro fallido:", false, Gtk::MESSAGE_WARNING);
        dialogo.set_secondary_text("Es necesario completar todos los espacios vacios");
        dialogo.run();
    }
}