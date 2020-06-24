
/* 
 * File:   VentanaAgregarAerolinea.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:17 AM
 */

#ifndef VENTANAAGREGARAEROLINEA_H
#define VENTANAAGREGARAEROLINEA_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>
#include "Aerolinea.h"
#include "AerolineaData.h"

class VentanaAgregarAerolinea : public Gtk::Window{
public:
    VentanaAgregarAerolinea();
    VentanaAgregarAerolinea(const VentanaAgregarAerolinea& orig);
    virtual ~VentanaAgregarAerolinea();
private:
    
    void init();
    void onButtonClickedIngresar();
    void aboutWinClose();
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblNombre;
    Gtk::Entry etNombre;

    Gtk::Button btnIngresar;
    AerolineaData* aerolineaData;
    
};

#endif /* VENTANAAGREGARAEROLINEA_H */

