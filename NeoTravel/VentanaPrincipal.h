/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaPrincipal.h
 * Author: geraldi
 *
 * Created on 8 de junio de 2020, 02:36 PM
 */

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "VentanaEscogerAerolinea.h"

class VentanaPrincipal : public Gtk::Window {
public:
    VentanaPrincipal();
    virtual ~VentanaPrincipal();
private:
    void init();
    void aboutWinClose();
    void abrirVentanaEscogerAerolinea();



    VentanaEscogerAerolinea* ventanaescoger;
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo; //abre el contenedor submenu
    Gtk::ImageMenuItem menuEscogerAerolinea;

    Gtk::Fixed fixed; // contenedor

};

#endif /* VENTANAPRINCIPAL_H */

