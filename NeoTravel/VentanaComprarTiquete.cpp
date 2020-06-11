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

VentanaComprarTiquete::VentanaComprarTiquete(Aerolinea* aerolinea) {
    this->aerolineaActual=aerolinea;
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
    
    this->lblBienvenido.set_label("Bienvenido Gracias por viajar con:  "+aerolineaActual->getNombre());
    this->fixed.put(this->lblBienvenido, 20, 20);
    
    this->add(fixed);
    this->show_all_children();
}


