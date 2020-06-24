
/* 
 * File:   VentanaBuscarHorario.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:22 AM
 */

#ifndef VENTANABUSCARHORARIO_H
#define VENTANABUSCARHORARIO_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "Aerolinea.h"
#include "AerolineaData.h"
#include "Vuelo.h"
#include "Horario.h"
#include "Itinerario.h"
class VentanaBuscarHorario : public Gtk::Window{
public:
    VentanaBuscarHorario();
    VentanaBuscarHorario(const VentanaBuscarHorario& orig);
    virtual ~VentanaBuscarHorario();
private:
    
    void onButtonClickedIzqAerolinea();
    void onButtonClickedDerAerolinea();
    void onButtonClickedIzqVuelo();
    void onButtonClickedDerVuelo();
    void onButtonClickedIzqHorario();
    void onButtonClickedDerHorario();

    void init();

    Gtk::Fixed fixed;

    Gtk::Label lblAerolinea;
    Gtk::Label lblAerolineaActual;

    Gtk::Label lblVuelo;
    Gtk::Label lblVueloActual;

    Gtk::Label lblHorarioActual;

    Gtk::Button btnSiguienteHorario;
    Gtk::Button btnAnteriorHorario;
    Horario* horarioActual;

    Gtk::Button btnIzqAerolinea;
    Gtk::Button btnDerAerolinea;

    Gtk::Button btnIzqVuelo;
    Gtk::Button btnDerVuelo;

    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;

    Vuelo* vueloActual;

};

#endif /* VENTANABUSCARHORARIO_H */

