/* 
 * File:   VentanaActualizarAerolinea.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:23 AM
 */

#ifndef VENTANAACTUALIZARAEROLINEA_H
#define VENTANAACTUALIZARAEROLINEA_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"
class VentanaActualizarAerolinea: public Gtk::Window {
public:
    VentanaActualizarAerolinea();
    VentanaActualizarAerolinea(const VentanaActualizarAerolinea& orig);
    virtual ~VentanaActualizarAerolinea();
private:
  void init();
    void onButtonClickedIngresar();
    void aboutWinClose();
     void onButtonClickedArriba();
    void onButtonClickedAbajo();
    
    Gtk::Fixed fixed;
    Gtk::Label lblAerolineaInfo;
    Gtk::Label lblBienvenido;

    Gtk::Button btnDer;
    Gtk::Button btnIzq;
    Gtk::Button btnEscoger;
    Aerolinea* aerolineaActual;
    
    Gtk::Label lblNombre;
    Gtk::Entry etNombre;

    Gtk::Button btnIngresar;
    AerolineaData* aerolineaData;
};

#endif /* VENTANAACTUALIZARAEROLINEA_H */

