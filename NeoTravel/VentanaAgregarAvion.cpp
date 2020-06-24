/* 
 * File:   VentanaAgregarAvion.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:18 AM
 */

#include "VentanaAgregarAvion.h"

VentanaAgregarAvion::VentanaAgregarAvion() {
    this->set_size_request(350, 300);
    this->set_title("Agregar Avion");
    init();
}

VentanaAgregarAvion::VentanaAgregarAvion(const VentanaAgregarAvion& orig) {
}

VentanaAgregarAvion::~VentanaAgregarAvion() {
}

void VentanaAgregarAvion::init() {
    this->lblNombreAvion.set_label("Nombre avion:");
    this->fixed.put(this->lblNombreAvion, 20, 20);
    this->fixed.put(this->etNombreAvion, 150, 20);

    this->lblCantidadEspacios.set_label("Cantidad espacios:");
    this->fixed.put(this->lblCantidadEspacios, 20, 60);
    this->fixed.put(this->etCantidadEspacios, 150, 60);

    this->lblCantidadVuelos.set_label("Cantidad de vuelos:");
    this->fixed.put(this->lblCantidadVuelos, 20, 100);
    this->fixed.put(this->etCantidadVuelos, 150, 100);

    this->lblHorasDeVuelo.set_label("Horas de vuelo:");
    this->fixed.put(this->lblHorasDeVuelo, 20, 140);
    this->fixed.put(this->etHorasDeVuelo, 150, 140);

    this->btnGuardar.set_label("Guardar");
    this->btnGuardar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAgregarAvion::onButtonClickedGuardar));
    this->fixed.put(this->btnGuardar, 20, 225);

    this->add(fixed);
    this->show_all_children();
}

void VentanaAgregarAvion::onButtonClickedGuardar() {
    if (strcmp(this->etNombreAvion.get_text().c_str(), "") != 0 && strcmp(this->etCantidadEspacios.get_text().c_str(), "") != 0 && strcmp(this->etCantidadVuelos.get_text().c_str(), "") != 0 && strcmp(this->etHorasDeVuelo.get_text().c_str(), "") != 0) {
        avionData->getInstance()->agregarAvion(new Avion(this->etNombreAvion.get_text().c_str(), atoi(this->etCantidadEspacios.get_text().c_str()), atoi(this->etCantidadVuelos.get_text().c_str()), atoi(this->etHorasDeVuelo.get_text().c_str())));
        Gtk::MessageDialog dialogo(*this, "Registro exitoso:", false, Gtk::MESSAGE_INFO);
        dialogo.set_secondary_text(avionData->getInstance()->firstInList()->toString());
        dialogo.run();
        this->etNombreAvion.set_text("");
        this->etCantidadEspacios.set_text("");
        this->etHorasDeVuelo.set_text("");
        this->etCantidadVuelos.set_text("");
    } else {
        Gtk::MessageDialog dialogo(*this, "Registro fallido:", false, Gtk::MESSAGE_WARNING);
        dialogo.set_secondary_text("Es necesario completar todos los espacios vacios");
        dialogo.run();
    }
}