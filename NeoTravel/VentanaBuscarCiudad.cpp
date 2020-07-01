/* 
 * File:   VentanaBuscarCiudad.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:22 AM
 */

#include "VentanaBuscarCiudad.h"

VentanaBuscarCiudad::VentanaBuscarCiudad() {
    this->set_size_request(300, 300);
    this->set_title("Buscar Ciudad");
    init();
}

VentanaBuscarCiudad::VentanaBuscarCiudad(const VentanaBuscarCiudad& orig) {
}

VentanaBuscarCiudad::~VentanaBuscarCiudad() {
}

void VentanaBuscarCiudad::init() {

    if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
        this->ciudadActual = ciudadData->getInstance()->firstInList();
        this->lblCiudades.set_text("Ciudades registradas:");
        this->fixed.put(this->lblCiudades, 20, 20);

        //Recorre la lista de aviones para rellenar el combo box con los nombres de los aviones
        for (int i = 0; i < ciudadData->getInstance()->obtenerListaDeCiudades()->getSize(); i++) {
            this->cbCiudades.append(this->ciudadActual->getNombre());
            this->ciudadActual = this->ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
        }

        this->cbCiudades.signal_changed().connect(sigc::mem_fun(*this, &VentanaBuscarCiudad::on_combo_changed));
        this->fixed.put(this->cbCiudades, 160, 20);
        this->fixed.put(this->lblInformacionCiudad, 20, 60);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblCiudades.set_label("No hay ciudades registradas");
        this->fixed.put(this->lblCiudades, 20, 20);
        this->fixed.put(this->cbCiudades, 190, 20);

        this->add(fixed);
        this->show_all_children();
    }
}//init

void VentanaBuscarCiudad::buscarCiudad() {
    if (strcmp(cbCiudades.get_active_text().c_str(), "") != 0) {
        this->ciudadActual = ciudadData->getInstance()->firstInList();
        for (int i = 0; i < ciudadData->getInstance()->obtenerListaDeCiudades()->getSize(); i++) {
            if (strcmp(cbCiudades.get_active_text().c_str(), ciudadActual->getNombre().c_str()) == 0) {
                this->lblInformacionCiudad.set_text("Nombre de la ciudad: " + ciudadActual->toString());
            }
            this->ciudadActual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
        }
    }
}

void VentanaBuscarCiudad::on_combo_changed() {
    Glib::ustring text = cbCiudades.get_active_text(); //Para cambiar al texto seleccionado
    buscarCiudad();
}