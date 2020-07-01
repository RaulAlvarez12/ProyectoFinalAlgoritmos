/* 
 * File:   VentanaActualizarAvionLista.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:23 AM
 */

#include "VentanaActualizarAvionLista.h"

VentanaActualizarAvionLista::VentanaActualizarAvionLista() {
    this->set_size_request(400, 400);
    this->set_title("Actualizar Avion");
    init();
}

VentanaActualizarAvionLista::VentanaActualizarAvionLista(const VentanaActualizarAvionLista& orig) {
}

VentanaActualizarAvionLista::~VentanaActualizarAvionLista() {
}

void VentanaActualizarAvionLista::init() {

    if (!(avionData->getInstance()->obtenerListaDeAviones()->isEmpty())) {
        this->avionActual = avionData->getInstance()->firstInList();
        this->lblAviones.set_text("Aviones registrados:");
        this->fixed.put(this->lblAviones, 20, 20);

        //Recorre la lista de aviones para rellenar el combo box con los nombres de los aviones
        for (int i = 0; i < avionData->getInstance()->obtenerListaDeAviones()->getSize(); i++) {
            this->cbAviones.append(this->avionActual->getNombreAvion());
            this->avionActual = this->avionData->getInstance()->obtenerSiguienteAvion(avionActual);
        }

        this->cbAviones.signal_changed().connect(sigc::mem_fun(*this, &VentanaActualizarAvionLista::on_combo_changed));
        this->fixed.put(this->cbAviones, 160, 20);

        this->lblNombreAvion.set_text("Nombre del avión:");
        this->fixed.put(this->lblNombreAvion, 20, 60);
        this->fixed.put(this->etNombreAvion, 170, 60);

        this->lblCantidadEspacios.set_text("Cantidad de espacios:");
        this->fixed.put(this->lblCantidadEspacios, 20, 100);
        this->fixed.put(this->etCantidadEspacios, 170, 100);

        this->lblCantidadVuelos.set_text("Cantidad de vuelos:");
        this->fixed.put(this->lblCantidadVuelos, 20, 140);
        this->fixed.put(this->etCantidadVuelos, 170, 140);

        this->lblHorasVuelo.set_text("Horas de vuelo:");
        this->fixed.put(this->lblHorasVuelo, 20, 180);
        this->fixed.put(this->etHorasVuelos, 170, 180);

        this->btnActualizar.set_label("Actualizar");
        this->btnActualizar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaActualizarAvionLista::onButtonClickedActualizar));
        this->fixed.put(this->btnActualizar, 20, 260);

        this->add(fixed);
        this->show_all_children();
    } else {
        this->lblAviones.set_label("No hay aviones registrados");
        this->fixed.put(this->lblAviones, 20, 20);
        this->fixed.put(this->cbAviones, 190, 20);

        this->lblNombreAvion.set_text("Nombre del avión:");
        this->fixed.put(this->lblNombreAvion, 20, 60);
        this->fixed.put(this->etNombreAvion, 170, 60);

        this->lblCantidadEspacios.set_text("Cantidad de espacios:");
        this->fixed.put(this->lblCantidadEspacios, 20, 100);
        this->fixed.put(this->etCantidadEspacios, 170, 100);

        this->lblCantidadVuelos.set_text("Cantidad de vuelos:");
        this->fixed.put(this->lblCantidadVuelos, 20, 140);
        this->fixed.put(this->etCantidadVuelos, 170, 140);

        this->lblHorasVuelo.set_text("Horas de vuelo:");
        this->fixed.put(this->lblHorasVuelo, 20, 180);
        this->fixed.put(this->etHorasVuelos, 170, 180);

        this->add(fixed);
        this->show_all_children();
    }
}//init

void VentanaActualizarAvionLista::onButtonClickedActualizar() {//FALTA QUE VALIDE SI LOS CAMPOS QUE REQUIEREN NUMEROS ESTOS SEAN RELLENADOS CON NUMEROS
    if (strcmp(this->etNombreAvion.get_text().c_str(), "") != 0 && strcmp(this->etCantidadEspacios.get_text().c_str(), "") != 0 && strcmp(this->etCantidadVuelos.get_text().c_str(), "") != 0 && strcmp(this->etHorasVuelos.get_text().c_str(), "") != 0) {
        this->avionActual = this->avionData->getInstance()->buscarAvion(this->cbAviones.get_active_text().c_str());
        this->avionActual->setNombre(this->etNombreAvion.get_text().c_str());
        this->avionActual->setCantidadEspacios(atoi(this->etCantidadEspacios.get_text().c_str()));
        this->avionActual->setCantidadVuelos(atoi(this->etCantidadVuelos.get_text().c_str()));
        this->avionActual->setHorasVuelo(atoi(this->etHorasVuelos.get_text().c_str()));
        Gtk::MessageDialog dialogo(*this, "Actualización exitosa", false, Gtk::MESSAGE_INFO);
        dialogo.run();
        this->cbAviones.remove_all();
        this->avionActual = this->avionData->getInstance()->firstInList();
        for (int i = 0; i < avionData->getInstance()->obtenerListaDeAviones()->getSize(); i++) {
            this->cbAviones.append(this->avionActual->getNombreAvion());
            this->avionActual = this->avionData->getInstance()->obtenerSiguienteAvion(avionActual);
        }
        cbAviones.set_active_text(this->avionData->getInstance()->firstInList()->getNombreAvion());
    } else {
        Gtk::MessageDialog dialogo(*this, "Actualización fallida:", false, Gtk::MESSAGE_WARNING);
        dialogo.set_secondary_text("Es necesario completar todos los espacios vacios");
        dialogo.run();
    }
}

void VentanaActualizarAvionLista::buscarAvion() {
    if (strcmp(cbAviones.get_active_text().c_str(), "") != 0) {
        this->avionActual = avionData->getInstance()->firstInList();
        for (int i = 0; i < avionData->getInstance()->obtenerListaDeAviones()->getSize(); i++) {
            if (strcmp(cbAviones.get_active_text().c_str(), avionActual->getNombreAvion().c_str()) == 0) {
                
                this->etNombreAvion.set_text(avionActual->getNombreAvion());
                Glib::ustring auxStr = Glib::ustring::format(avionActual->getCantidadEspacios()) ;//LINEA PARA CONVERTIR ENTEROS EN USTRING
                this->etCantidadEspacios.set_text(auxStr);
                auxStr = Glib::ustring::format(avionActual->getCantidadVuelos());
                this->etCantidadVuelos.set_text(auxStr);
                auxStr = Glib::ustring::format(avionActual->getHorasVuelo());
                this->etHorasVuelos.set_text(auxStr);
            }
            this->avionActual = avionData->getInstance()->obtenerSiguienteAvion(avionActual);
        }
    }
}

void VentanaActualizarAvionLista::on_combo_changed() {
    Glib::ustring text = cbAviones.get_active_text(); //Para cambiar al texto seleccionado
    buscarAvion();
}