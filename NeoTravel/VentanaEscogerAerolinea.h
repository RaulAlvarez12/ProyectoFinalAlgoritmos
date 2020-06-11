/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaEscogerAerolinea.h
 * Author: geraldi
 *
 * Created on 8 de junio de 2020, 02:36 PM
 */

#ifndef VENTANAESCOGERAEROLINEA_H
#define VENTANAESCOGERAEROLINEA_H


#include "VentanaEscogerAerolinea.h"
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include<sstream>
#include<iostream>
#include "ListaEnlazadaCircularDoble.h"
#include "AerolineaData.h"
#include "Aerolinea.h"
#include "VentanaComprarTiquete.h"
using namespace std;

class VentanaEscogerAerolinea : public Gtk::Window {
public:
    VentanaEscogerAerolinea();
    virtual ~VentanaEscogerAerolinea();
private:


    void init();
    void onButtonClickedArriba();
    void onButtonClickedAbajo();
    void onButtonClickedEscoger();
    void aboutWinClose();
    
    Gtk::Fixed fixed;
    Gtk::Label lblAerolineaInfo;
    Gtk::Label lblBienvenido;

    Gtk::Button btnArriba;
    Gtk::Button btnAbajo;
    Gtk::Button btnEscoger;
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
    VentanaComprarTiquete* vTiquete;
protected:
    bool on_key_press_event(GdkEventKey* event);

};
#endif /* VENTANAESCOGERAEROLINEA_H */

