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

#include "VentanaHorarios.h"
#include "Aerolinea.h"
#include "Ciudad.h"

VentanaHorarios::VentanaHorarios(Usuario* usuario,Aerolinea* aerolinea, Ciudad* ciudadOrigen, Ciudad* ciudadDestino) {
    this->usuario=usuario;
    this->aerolinea=aerolinea;
    this->ciudadDestino=ciudadDestino;
    this->ciudadOrigen=ciudadOrigen;
    this->set_size_request(300, 200);
    this->set_title("Escoger Horario");

    init();
    this->show_all_children();
}

VentanaHorarios::VentanaHorarios(const VentanaHorarios& orig) {
}

void VentanaHorarios::init() {
    cout<<"hola"<<usuario->toString()<<"\n"<<aerolinea->getNombre()<<"\n"<<ciudadDestino->getNombre()<<"\n"<<ciudadOrigen->getNombre()<<endl;

}

VentanaHorarios::~VentanaHorarios() {
}

