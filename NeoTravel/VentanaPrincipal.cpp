/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaPrincipal.cpp
 * Author: geraldi
 * 
 * Created on 8 de junio de 2020, 02:36 PM
 */

#include "VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal() {
     this->set_size_request(400,300);
     
            init();
       this->ventanaescoger=0;
}


VentanaPrincipal::~VentanaPrincipal() {
}


void VentanaPrincipal::init(){
    this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
        this->menuArchivo.set_label("Usuario");
        this->menuBar.append(this->menuArchivo);
        this->menuArchivo.set_submenu(this->subMenuArchivo);
        
          //agrega submenu a la barra y le asigna una accion
        this->menuEscogerAerolinea.set_label("Comprar Tiquete");
        this->menuEscogerAerolinea.signal_activate().connect(sigc::mem_fun(*this,&VentanaPrincipal::abrirVentanaEscogerAerolinea));
        this->subMenuArchivo.append(this->menuEscogerAerolinea);
         
            
        this->add(fixed);
        this->show_all_children();
}
void VentanaPrincipal::aboutWinClose(){
    this->ventanaescoger=0;
}

void VentanaPrincipal::abrirVentanaEscogerAerolinea(){
    if (this->ventanaescoger != 0)
            return;
        
        this->ventanaescoger = new VentanaEscogerAerolinea();
        this->ventanaescoger->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
        this->ventanaescoger->show();
}