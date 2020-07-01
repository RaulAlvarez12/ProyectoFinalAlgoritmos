/* 
 * File:   VentanaAgregarCiudad.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 11:18 AM
 */

#ifndef VENTANAAGREGARCIUDAD_H
#define VENTANAAGREGARCIUDAD_H
#include <gtkmm.h>

#include "Ciudad.h"
#include "CiudadData.h"

class VentanaAgregarCiudad : public Gtk::Window{
public:
    VentanaAgregarCiudad();
    VentanaAgregarCiudad(const VentanaAgregarCiudad& orig);
    virtual ~VentanaAgregarCiudad();
    
private:
    
    void init();
    void onButtonClickedGuardar();
    
    //Atributos
    Gtk::Fixed fixed;
    
    Gtk::Label lblNombreCiudad;
    
    Gtk::Entry etNombreCiudad;

    Gtk::Button btnGuardar;
    
    CiudadData* ciudadData;
};

#endif /* VENTANAAGREGARCIUDAD_H */