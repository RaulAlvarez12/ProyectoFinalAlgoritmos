/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaComprarTiquete.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 02:36 PM
 */

#include "VentanaComprarTiquete.h"
#include "Ciudad.h"
#include "Tiquete.h"

VentanaComprarTiquete::VentanaComprarTiquete(Aerolinea* aerolinea) {
    this->aerolineaActual = aerolinea;
    this->set_size_request(700, 350);
    this->set_title("Comprar Tiquete");

    init();
    this->show_all_children();
}

VentanaComprarTiquete::VentanaComprarTiquete(const VentanaComprarTiquete& orig) {
}

VentanaComprarTiquete::~VentanaComprarTiquete() {
}

void VentanaComprarTiquete::init() {
    vueloActual = aerolineaActual->vueloData->firstInList();
    horarioActual= aerolineaActual->vueloData->firstInList()->getItinerario()->getColaPrioridad()->frente();
    this->lblBienvenido.set_label("Bienvenido Gracias por viajar con " + aerolineaActual->getNombre());
    this->fixed.put(this->lblBienvenido, 200, 20);


    this->lblDatosPersonales.set_label("Datos Personales:");
    this->fixed.put(this->lblDatosPersonales, 70, 60);

    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 10, 90);
    this->fixed.put(this->etNombre, 115, 90);
    this->etEdad.set_max_length(3);
    this->etNumID.set_max_length(9);
    this->lblEdad.set_label("Edad:");
    this->fixed.put(this->lblEdad, 10, 120);
    this->fixed.put(this->etEdad, 115, 120);

    this->lblGenero.set_label("Genero:");
    this->fixed.put(this->lblGenero, 10, 150);
    this->fixed.put(this->etGenero, 115, 150);

    this->lblNumID.set_label("Num. Pasaporte:");
    this->fixed.put(this->lblNumID, 10, 180);
    this->fixed.put(this->etNumID, 115, 180);

    this->lblNacionalidad.set_label("Nacionalidad:");
    this->fixed.put(this->lblNacionalidad, 10, 210);
    this->fixed.put(this->etNacionalidad, 115, 210);

    this->lblDatosVuelo.set_label("Datos del Vuelo:");
    this->fixed.put(this->lblDatosVuelo, 400, 60);



    this->lblVuelo.set_label("Vuelo: "+vueloActual->getCiudadOrigen()->getNombre() + " con destino " + vueloActual->getciudadDestino()->getNombre());
    this->fixed.put(this->lblVuelo, 375, 90);

    this->btnAnteriorVuelo.set_label("<-");
    this->btnAnteriorVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedIzqVuelo));
    this->fixed.put(this->btnAnteriorVuelo, 385, 120);
    this->btnSiguienteVuelo.set_label("->");
    this->btnSiguienteVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedDerVuelo));
    this->fixed.put(this->btnSiguienteVuelo, 485, 120);
    
    this->lblHorario.set_label("Horario: "+horarioActual->toString());
    this->fixed.put(this->lblHorario, 375, 180);

     this->btnAnteriorHorario.set_label("<-");
    this->btnAnteriorHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedIzqHorario));
    this->fixed.put(this->btnAnteriorHorario, 385, 200);
    this->btnSiguienteHorario.set_label("->");
    this->btnSiguienteHorario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedDerHorario));
    this->fixed.put(this->btnSiguienteHorario, 485, 200);
    
    
    this->btnComprar.set_label("Comprar");
    this->btnComprar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedComprar));
    this->fixed.put(this->btnComprar, 335, 270);



    this->fixed.put(this->lblRequisito, 10, 290);

    this->add(fixed);
    this->show_all_children();
}

void VentanaComprarTiquete::aboutWinClose() {
    this->vFactura = 0;
}

void VentanaComprarTiquete::onButtonClickedIzqVuelo() {
    vueloActual = aerolineaActual->vueloData->obtenerAnteriorVuelo(vueloActual);
    horarioActual= vueloActual->getItinerario()->getColaPrioridad()->frente();
    this->lblVuelo.set_label("Vuelo: "+vueloActual->getCiudadOrigen()->getNombre() + " con destino  " + vueloActual->getciudadDestino()->getNombre());
    this->lblHorario.set_label("Horario: "+horarioActual->toString());
}

void VentanaComprarTiquete::onButtonClickedDerVuelo() {
    
    vueloActual = aerolineaActual->vueloData->obtenerSiguienteVuelo(vueloActual);
    horarioActual= vueloActual->getItinerario()->getColaPrioridad()->frente();
    this->lblVuelo.set_label("Vuelo: "+vueloActual->getCiudadOrigen()->getNombre() + " con destino " + vueloActual->getciudadDestino()->getNombre());
    this->lblHorario.set_label("Horario: "+horarioActual->toString());
}

void VentanaComprarTiquete::onButtonClickedDerHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerSiguienteHorario(horarioActual);
    this->lblHorario.set_label("Horario: "+horarioActual->toString());
}

void VentanaComprarTiquete::onButtonClickedIzqHorario() {
    horarioActual = vueloActual->getItinerario()->getColaPrioridad()->obtenerAnteriorHorario(horarioActual);
    this->lblHorario.set_label("Horario: "+horarioActual->toString());
}

void VentanaComprarTiquete::onButtonClickedComprar() {
    if (!etNombre.get_text().empty() && !etEdad.get_text().empty() && !etGenero.get_text().empty()
            && !etNumID.get_text().empty()&& !etNacionalidad.get_text().empty()) {
        this->etNacionalidad.set_editable(false);


        Usuario* usuario = new Usuario(etNombre.get_text(), atoi(etEdad.get_text().c_str()), etGenero.get_text(), atoi(etNumID.get_text().c_str()), etNacionalidad.get_text().c_str(), true);
        usuario->compruebaPermiso(vueloActual->getciudadDestino()->getNombre());
        Tiquete* tiqueteCompra = new Tiquete(usuario,this->aerolineaActual,this->vueloActual,this->horarioActual);
        if (usuario->getPermisoIngreso() == false) {
            Gtk::MessageDialog dialogo(
                    *this,
                    "*****AVISO IMPORTANTE*****",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Debido a las nuevas regulaciones migratorias\nDefinidas en los articulos 15 y 23, inciso b) y d) respectivamente\nUsted NO puede ingresar a " + vueloActual->getciudadDestino()->getNombre() + "\n\nAun así puede elegir otro destino");
            dialogo.run();
        } else {
            vFactura = new VentanaFactura(tiqueteCompra);
            this->vFactura->signal_hide().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::aboutWinClose));
            vFactura->show();
            this->close();
        }

    } else {
        this->lblRequisito.set_label("**Debe rellenar todos los espacios");
    }
}