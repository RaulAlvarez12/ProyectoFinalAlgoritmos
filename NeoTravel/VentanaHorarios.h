/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaHorarios.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 05:04 PM
 */

#ifndef VENTANAHORARIOS_H
#define VENTANAHORARIOS_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include<sstream>
#include<iostream>
#include "Ciudad.h"
#include "Aerolinea.h"
#include "Usuario.h"

class VentanaHorarios : public Gtk::Window{
public:
    VentanaHorarios(Usuario* usuario,Aerolinea* aerolinea, Ciudad* ciudadOrigen, Ciudad* ciudadDestino);
    VentanaHorarios(const VentanaHorarios& orig);
    virtual ~VentanaHorarios();
private:
    void init();
    Aerolinea* aerolinea;
    Ciudad* ciudadOrigen;
    Ciudad* ciudadDestino;
    Usuario* usuario;
};

#endif /* VENTANAHORARIOS_H */

