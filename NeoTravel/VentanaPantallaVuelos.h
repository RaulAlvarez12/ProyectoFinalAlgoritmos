/* 
 * File:   VentanaPantallaVuelos.h
 * Author: alsov
 *
 * Created on 1 de julio de 2020, 07:19 PM
 */

#ifndef VENTANAPANTALLAVUELOS_H
#define VENTANAPANTALLAVUELOS_H

#include <gtkmm.h>

#include "AerolineaData.h"

using namespace std;

class VentanaPantallaVuelos : public Gtk::Window{
public:
    VentanaPantallaVuelos();
    virtual ~VentanaPantallaVuelos();
    
private:

    void init();
    
    //Atributos
    Gtk::Fixed fixed;
    Gtk::Label lblTitulo;
    Gtk::Label lblVuelos;
    
    AerolineaData* aerolineaData;
    Aerolinea* aerolineaActual;
};

#endif /* VENTANAPANTALLAVUELOS_H */

