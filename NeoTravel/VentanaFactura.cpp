/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaHorarios.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 05:04 PM
 */

#include "VentanaFactura.h"
#include "Aerolinea.h"
#include "Ciudad.h"

VentanaFactura::VentanaFactura(Tiquete* tiqueteCompra) {
    this->tiqueteComprar= tiqueteCompra;
    this->set_size_request(350, 400);
    this->set_title("Factura");

    init();
    this->show_all_children();
}

VentanaFactura::VentanaFactura(const VentanaFactura& orig) {
}

void VentanaFactura::init() {
    
    this->lblDatos.set_label("Gracias por viajar con " + this->tiqueteComprar->getAerolinea()->getNombre()+"\n\n"+this->tiqueteComprar->toString());
    this->fixed.put(this->lblDatos, 78, 20);

    this->btnAceptar.set_label("Aceptar");
    this->btnAceptar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaFactura::onButtonClickedAceptar));
    this->fixed.put(this->btnAceptar, 120, 290);

    this->add(fixed);
    this->show_all_children();

}

void VentanaFactura::aboutWinClose() {
    this->close();
}

void VentanaFactura::onButtonClickedAceptar() {
this->close();
}


VentanaFactura::~VentanaFactura() {
    
}

