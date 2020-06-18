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

VentanaComprarTiquete::VentanaComprarTiquete(Aerolinea* aerolinea) {
    this->aerolineaActual = aerolinea;
    this->set_size_request(300, 400);
    this->set_title("Comprar Tiquete");

    init();
    this->show_all_children();
}

VentanaComprarTiquete::VentanaComprarTiquete(const VentanaComprarTiquete& orig) {
}

VentanaComprarTiquete::~VentanaComprarTiquete() {
}

void VentanaComprarTiquete::init() {

    this->lblBienvenido.set_label("Bienvenido Gracias por viajar con " + aerolineaActual->getNombre());
    this->fixed.put(this->lblBienvenido, 20, 20);


    this->lblDatosPersonales.set_label("Datos Personales:");
    this->fixed.put(this->lblDatosPersonales, 70, 60);

    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 10, 90);
    this->fixed.put(this->etNombre, 115, 90);

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
    this->fixed.put(this->lblDatosVuelo, 70, 250);

    this->lblCiudadSalida.set_label("Ciudad Origen:");
    this->fixed.put(this->lblCiudadSalida, 10, 280);
    this->fixed.put(this->etCiudadOrigen, 115, 280);

    this->lblCiudadDestino.set_label("Ciudad Destino:");
    this->fixed.put(this->lblCiudadDestino, 10, 310);
    this->fixed.put(this->etCiudadDestino, 115, 310);

    this->btnSiguiente.set_label("Siguiente");
    this->btnSiguiente.signal_clicked().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::onButtonClickedSiguiente));
    this->fixed.put(this->btnSiguiente, 115, 345);



    this->fixed.put(this->lblRequisito, 10, 380);

    this->add(fixed);
    this->show_all_children();
}

void VentanaComprarTiquete::aboutWinClose() {
    this->vHorarios = 0;
}

void VentanaComprarTiquete::onButtonClickedSiguiente() {
    if (etNombre.get_text().compare("") != 0 && etEdad.get_text().compare("") != 0 && etGenero.get_text().compare("") != 0
            && etNumID.get_text().compare("") != 0 && etNacionalidad.get_text().compare("") != 0 
            && etCiudadOrigen.get_text().compare("") != 0 && etCiudadDestino.get_text().compare("") != 0) {
        
        Usuario* usuario =  new Usuario(etNombre.get_text(),atoi(etEdad.get_text().c_str()),etGenero.get_text(),atoi(etNumID.get_text().c_str()),etNacionalidad.get_text(), true);
        vHorarios = new VentanaHorarios(usuario,aerolineaActual,new Ciudad(etCiudadOrigen.get_text()),new Ciudad(etCiudadDestino.get_text()));
        this->vHorarios->signal_hide().connect(sigc::mem_fun(*this, &VentanaComprarTiquete::aboutWinClose));
        vHorarios->show();
        this->close();
        
        
    } else {
        this->lblRequisito.set_label("**Debe rellenar todos los espacios");
    }
}