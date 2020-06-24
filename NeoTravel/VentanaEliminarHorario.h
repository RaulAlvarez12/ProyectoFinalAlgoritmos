
/* 
 * File:   VentanaEliminarHorario.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:21 AM
 */

#ifndef VENTANAELIMINARHORARIO_H
#define VENTANAELIMINARHORARIO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
#include "Horario.h"
#include "Itinerario.h"

class VentanaEliminarHorario : public Gtk::Window {
public:
    VentanaEliminarHorario();
    VentanaEliminarHorario(const VentanaEliminarHorario& orig);
    virtual ~VentanaEliminarHorario();
private:

    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
    void onButtonClickedEliminar();
    void onButtonClickedIzqHorario();
    void onButtonClickedDerHorario();

    void init();

    Gtk::Fixed fixed;

    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;

    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;


    Gtk::Button btnSiguienteHorario;
    Gtk::Button btnAnteriorHorario;
    Horario* horarioActual;
  Gtk::Label lblHorarioActual;

    Gtk::Label lblHoraLlegada;
    Gtk::Entry etHoraLlegada;

    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;

    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;
    Gtk::Button btnEliminar;

    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;

    Vuelo* vueloActual;
};

#endif /* VENTANAELIMINARHORARIO_H */

