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
#include "Tiquete.h"

class VentanaFactura : public Gtk::Window{
public:
    VentanaFactura(Tiquete* tiqueteCompra);
    VentanaFactura(const VentanaFactura& orig);
    virtual ~VentanaFactura();
private:
    void init();
    Tiquete* tiqueteComprar;
    
    void aboutWinClose();
    void onButtonClickedAceptar();


    Gtk::Fixed fixed;
    Gtk::Label lblDatos;
    Vuelo* vueloActual;
    Gtk::Button btnAceptar;

};

#endif /* VENTANAHORARIOS_H */

