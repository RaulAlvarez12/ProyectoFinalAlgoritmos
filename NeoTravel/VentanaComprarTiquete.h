/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaComprarTiquete.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 02:36 PM
 */

#ifndef VENTANACOMPRARTIQUETE_H
#define VENTANACOMPRARTIQUETE_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include<sstream>
#include<iostream>

#include "Aerolinea.h"

class VentanaComprarTiquete : public Gtk::Window{
public:
    VentanaComprarTiquete(Aerolinea* aerolinea);
    VentanaComprarTiquete(const VentanaComprarTiquete& orig);
    virtual ~VentanaComprarTiquete();
private:
  void init();
    Gtk::Fixed fixed;
    Gtk::Label lblBienvenido;


    Aerolinea* aerolineaActual;
};

#endif /* VENTANACOMPRARTIQUETE_H */

