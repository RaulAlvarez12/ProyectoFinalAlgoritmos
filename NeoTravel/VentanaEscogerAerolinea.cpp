/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "VentanaEscogerAerolinea.h"
#include "AerolineaData.h"
#include <iostream>
using namespace std;

/* 
 * File:   VentanaEscogerAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 8 de junio de 2020, 02:36 PM
 */


VentanaEscogerAerolinea::VentanaEscogerAerolinea() {
    this->aerolineaData = new AerolineaData();
    this->set_size_request(300, 200);
    this->set_title("Escoger Aerolinea");

    init();
    this->show_all_children();
}

VentanaEscogerAerolinea::~VentanaEscogerAerolinea() {

}

void VentanaEscogerAerolinea::init() {
    this->aerolineaActual =aerolineaData->firstInList();
    
    this->lblBienvenido.set_label("Bienvenido Escoja su aerolinea preferida");
    this->fixed.put(this->lblBienvenido, 20, 20);
    
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
    this->fixed.put(this->lblAerolineaInfo, 50, 80);

    this->btnArriba.set_label("Arriba");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedArriba));
    this->fixed.put(this->btnArriba, 150, 50);

    this->btnAbajo.set_label("Abajo");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedAbajo));
    this->fixed.put(this->btnAbajo, 150, 90);


    this->btnEscoger.set_label("Escoger");
    this->btnEscoger.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedEscoger));
    this->fixed.put(this->btnEscoger, 100, 140);
    
    
    this->add(fixed);
    this->show_all_children();
}

void VentanaEscogerAerolinea::onButtonClickedArriba() {
    aerolineaActual = aerolineaData->obtenerSiguiente(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaEscogerAerolinea::onButtonClickedAbajo() {
    aerolineaActual = aerolineaData->obtenerAnterior(aerolineaActual);
    this->lblAerolineaInfo.set_label(aerolineaActual->getNombre());
}

void VentanaEscogerAerolinea::aboutWinClose() {
    vTiquete=0;
}


void VentanaEscogerAerolinea::onButtonClickedEscoger() {
    vTiquete = new VentanaComprarTiquete(this->aerolineaActual);
    this->vTiquete->signal_hide().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::aboutWinClose));
    vTiquete->show();
    this->close();
}


bool VentanaEscogerAerolinea::on_key_press_event(GdkEventKey* event) {

    if (event->keyval == GDK_KEY_Down) {
        onButtonClickedAbajo();
    } else if (event->keyval == GDK_KEY_Up) {
        onButtonClickedArriba();
    }

}