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
#include "VentanaFactura.h"

class VentanaComprarTiquete : public Gtk::Window {
public:
    VentanaComprarTiquete(Aerolinea* aerolinea);
    VentanaComprarTiquete(const VentanaComprarTiquete& orig);
    virtual ~VentanaComprarTiquete();
private:
    void init();
    void aboutWinClose();
    void onButtonClickedComprar();
    void onButtonClickedIzqHorario();
    void onButtonClickedDerHorario();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();

    Gtk::Fixed fixed;
    Gtk::Label lblBienvenido;
    Gtk::Label lblDatosPersonales;
    Gtk::Label lblNombre;
    Gtk::Label lblEdad;
    Gtk::Label lblGenero;
    Gtk::Label lblNumID;
    Gtk::Label lblNacionalidad;
    Gtk::Label lblVuelo;
    Gtk::Label lblDatosVuelo;
    Gtk::Label lblRequisito;
    Gtk::Label lblHorario;

    Gtk::Entry etNombre;
    Gtk::Entry etEdad;
    Gtk::Entry etGenero;
    Gtk::Entry etNumID;
    Gtk::Entry etNacionalidad;


    Vuelo* vueloActual;
    Gtk::Button btnComprar;
    Gtk::Button btnSiguienteVuelo;
    Gtk::Button btnAnteriorVuelo;
    
    Gtk::Button btnSiguienteHorario;
    Gtk::Button btnAnteriorHorario;
    Horario* horarioActual;
    
    VentanaFactura* vFactura;
    Aerolinea* aerolineaActual;
};

#endif /* VENTANACOMPRARTIQUETE_H */

