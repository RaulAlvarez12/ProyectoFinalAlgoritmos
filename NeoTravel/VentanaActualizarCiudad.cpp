/* 
 * File:   VentanaActualizarCiudad.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:24 AM
 */

#include "VentanaActualizarCiudad.h"

VentanaActualizarCiudad::VentanaActualizarCiudad() {
    this->set_size_request(300, 300);
    this->set_title("Actualizar Ciudad");
    init();
}

VentanaActualizarCiudad::VentanaActualizarCiudad(const VentanaActualizarCiudad& orig) {
}

VentanaActualizarCiudad::~VentanaActualizarCiudad() {
}

void VentanaActualizarCiudad::init() {
    if (!(ciudadData->getInstance()->obtenerListaDeCiudades()->isEmpty())) {
        this->ciudadActual = ciudadData->getInstance()->firstInList();
        this->lblCiudades.set_text("Ciudades registradas:");
        this->fixed.put(this->lblCiudades, 20, 20);

        //Recorre la lista de aviones para rellenar el combo box con los nombres de los aviones
        for (int i = 0; i < ciudadData->getInstance()->obtenerListaDeCiudades()->getSize(); i++) {
            this->cbCiudades.append(this->ciudadActual->getNombre());
            this->ciudadActual = this->ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
        }
        
        cout << this->ciudadData->getInstance()->obtenerListaDeCiudades()->toString() << endl;
        
        this->cbCiudades.signal_changed().connect(sigc::mem_fun(*this, &VentanaActualizarCiudad::on_combo_changed));
        this->fixed.put(this->cbCiudades, 160, 20);

        this->lblNombreCiudad.set_text("Nombre de la ciudad:");
        this->fixed.put(this->lblNombreCiudad, 20, 60);
        this->fixed.put(this->etNombreCiudad, 170, 60);

        this->btnActualizar.set_label("Actualizar");
        this->btnActualizar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarCiudad::onButtonClickedActualizar));
        this->fixed.put(this->btnActualizar, 20, 150);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblCiudades.set_label("No hay ciudades registradas");
        this->fixed.put(this->lblCiudades, 20, 20);
        this->fixed.put(this->cbCiudades, 190, 20);

        this->lblNombreCiudad.set_text("Nombre de la ciudad:");
        this->fixed.put(this->lblNombreCiudad, 20, 60);
        this->fixed.put(this->etNombreCiudad, 170, 60);

        this->add(fixed);
        this->show_all_children();
    }
}//init

void VentanaActualizarCiudad::onButtonClickedActualizar() {
    if (strcmp(this->etNombreCiudad.get_text().c_str(), "") != 0) {
        this->ciudadActual = this->ciudadData->getInstance()->buscarCiudad(this->cbCiudades.get_active_text().c_str());
        this->ciudadActual->setNombre(this->etNombreCiudad.get_text().c_str());
        Gtk::MessageDialog dialogo(*this, "Actualización exitosa", false, Gtk::MESSAGE_INFO);
        dialogo.run();
        cout << this->ciudadData->getInstance()->obtenerListaDeCiudades()->toString() << endl;
        cbCiudades.remove_all();
        this->ciudadActual = this->ciudadData->getInstance()->firstInList();
        for (int i = 0; i < ciudadData->getInstance()->obtenerListaDeCiudades()->getSize(); i++) {
            this->cbCiudades.append(this->ciudadActual->getNombre());
            this->ciudadActual = this->ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
        }
        cbCiudades.set_active_text(this->ciudadData->getInstance()->firstInList()->toString());
    } else {
        Gtk::MessageDialog dialogo(*this, "Actualización fallida:", false, Gtk::MESSAGE_WARNING);
        dialogo.set_secondary_text("Es necesario completar todos los espacios vacios");
        dialogo.run();
    }
}

void VentanaActualizarCiudad::buscarCiudad() {
    if (strcmp(cbCiudades.get_active_text().c_str(), "") != 0) {
        this->ciudadActual = ciudadData->getInstance()->firstInList();
        for (int i = 0; i < ciudadData->getInstance()->obtenerListaDeCiudades()->getSize(); i++) {
            if (strcmp(cbCiudades.get_active_text().c_str(), ciudadActual->getNombre().c_str()) == 0) {
                this->etNombreCiudad.set_text(ciudadActual->getNombre());
            }
            this->ciudadActual = ciudadData->getInstance()->obtenerSiguienteCiudad(ciudadActual);
        }
    }
}

void VentanaActualizarCiudad::on_combo_changed() {
    Glib::ustring text = cbCiudades.get_active_text(); //Para cambiar al texto seleccionado
    buscarCiudad();
}