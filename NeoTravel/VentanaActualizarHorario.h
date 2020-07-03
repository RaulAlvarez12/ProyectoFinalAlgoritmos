/* 
 * File:   VentanaActualizarHorario.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:24 AM
 */

#ifndef VENTANAACTUALIZARHORARIO_H
#define VENTANAACTUALIZARHORARIO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
#include "Horario.h"
#include "Itinerario.h"
class VentanaActualizarHorario : public Gtk::Window{
public:
    VentanaActualizarHorario();
    VentanaActualizarHorario(const VentanaActualizarHorario& orig);
    virtual ~VentanaActualizarHorario();
private:

    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
    void onButtonClickedActualizar();
    void onButtonClickedIzqHorario();
    void onButtonClickedDerHorario();

    void init();

    Gtk::Fixed fixed;

    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;

    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;

    Gtk::Label lblHorarioActual;


    Gtk::Label lblHoraSalida;
    Gtk::Entry etHoraSalida;
    
    Gtk::Label lblHoraLlegada;
    Gtk::Entry etHoraLlegada;

    Gtk::Button btnSiguienteHorario;
    Gtk::Button btnAnteriorHorario;
    Horario* horarioActual;

    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;

    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;
    Gtk::Button btnEliminar;

    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;

    Vuelo* vueloActual;
};

#endif /* VENTANAACTUALIZARHORARIO_H */

