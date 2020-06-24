
/* 
 * File:   VentanaEliminarAerolinea.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:20 AM
 */

#ifndef VENTANAELIMINARAEROLINEA_H
#define VENTANAELIMINARAEROLINEA_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"
class VentanaEliminarAerolinea: public Gtk::Window {
public:
    VentanaEliminarAerolinea();
    VentanaEliminarAerolinea(const VentanaEliminarAerolinea& orig);
    virtual ~VentanaEliminarAerolinea();
private:
    void init();
    void onButtonClickedArriba();
    void onButtonClickedAbajo();
    void onButtonClickedEscoger();
    void aboutWinClose();
    
    Gtk::Fixed fixed;
    Gtk::Label lblAerolineaInfo;
    Gtk::Label lblBienvenido;

    Gtk::Button btnDer;
    Gtk::Button btnIzq;
    Gtk::Button btnEscoger;
    Aerolinea* aerolineaActual;
    AerolineaData* aerolineaData;
};

#endif /* VENTANAELIMINARAEROLINEA_H */

