/* 
 * File:   VentanaBuscarAvion.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:22 AM
 */

#include "VentanaBuscarAvion.h"

VentanaBuscarAvion::VentanaBuscarAvion() {
    this->set_size_request(300, 300);
    this->set_title("Buscar Avion");
    init();
}

VentanaBuscarAvion::VentanaBuscarAvion(const VentanaBuscarAvion& orig) {
}

VentanaBuscarAvion::~VentanaBuscarAvion() {
}

void VentanaBuscarAvion::init() {

    if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
        this->avionActual = avionData->getInstance()->firstInList();
        this->lblAviones.set_text("Aviones registrados:");
        this->fixed.put(this->lblAviones, 20, 20);

        //Recorre la lista de aviones para rellenar el combo box con los nombres de los aviones
        for (int i = 0; i < avionData->getInstance()->obtenerListaDeAviones()->getSize(); i++) {
            this->cbAviones.append(this->avionActual->getNombreAvion());
            this->avionActual = this->avionData->getInstance()->obtenerSiguienteAvion(avionActual);
        }

        this->cbAviones.signal_changed().connect(sigc::mem_fun(*this, &VentanaBuscarAvion::on_combo_changed));
        this->fixed.put(this->cbAviones, 160, 20);
        this->fixed.put(this->lblInformacionAvion, 20, 60);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblAviones.set_label("No hay aviones registrados");
        this->fixed.put(this->lblAviones, 20, 20);
        this->fixed.put(this->cbAviones, 190, 20);

        this->add(fixed);
        this->show_all_children();
    }
}//init

void VentanaBuscarAvion::buscarAvion() {
    if (strcmp(cbAviones.get_active_text().c_str(), "") != 0) {
        this->avionActual = avionData->getInstance()->firstInList();
        for (int i = 0; i < avionData->getInstance()->obtenerListaDeAviones()->getSize(); i++) {
            if (strcmp(cbAviones.get_active_text().c_str(), avionActual->getNombreAvion().c_str()) == 0) {
                this->lblInformacionAvion.set_text(avionActual->toString());
            }
            this->avionActual = avionData->getInstance()->obtenerSiguienteAvion(avionActual);
        }
    }
}

void VentanaBuscarAvion::on_combo_changed() {
    Glib::ustring text = cbAviones.get_active_text(); //Para cambiar al texto seleccionado
    buscarAvion();
}