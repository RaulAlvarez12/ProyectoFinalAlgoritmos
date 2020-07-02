/* 
 * File:   VentanaPrincipalAdmin.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 10:06 AM
 */

#ifndef VENTANAPRINCIPALADMIN_H
#define VENTANAPRINCIPALADMIN_H
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

#include "VentanaAgregarAvion.h"
#include "VentanaAgregarAerolinea.h"
#include "VentanaAgregarCiudad.h"
#include "VentanaAgregarHorario.h"
#include "VentanaAgregarVuelo.h"
#include "VentanaEliminarAvion.h"
#include "VentanaEliminarAerolinea.h"
#include "VentanaEliminarCiudad.h"
#include "VentanaEliminarVuelo.h"
#include "VentanaEliminarHorario.h"
#include "VentanaBuscarAvion.h"
#include "VentanaBuscarHorario.h"
#include "VentanaBuscarAerolinea.h"
#include "VentanaBuscarCiudad.h"
#include "VentanaBuscarVuelo.h"
#include "VentanaActualizarAerolinea.h"
#include "VentanaActualizarAvionLista.h"
#include "VentanaActualizarAvionVuelo.h"
#include "VentanaActualizarCiudad.h"
#include "VentanaActualizarVuelo.h"
#include "VentanaActualizarHorario.h"

class VentanaPrincipalAdmin : public Gtk::Window{
public:
    VentanaPrincipalAdmin();
    VentanaPrincipalAdmin(const VentanaPrincipalAdmin& orig);
    virtual ~VentanaPrincipalAdmin();
private:
void init();
    
    void aboutWinClose();
    
    void abrirVentanaAgregarAvion();
    void abrirVentanaEliminarAvion();
    void abrirVentanaActualizarAvionLista();
//    void abrirVEntanaActualizarAvionVuelo();
    void abrirVentanaBuscarAvion();

    void abrirVentanaAgregarAerolinea();
    void abrirVentanaEliminarAerolinea();
    void abrirVentanaActualizarAerolinea();
    void abrirVentanaBuscarAerolinea();
    
    void abrirVentanaAgregarCiudad();
    void abrirVentanaEliminarCiudad();
    void abrirVentanaActualizarCiudad();
    void abrirVentanaBuscarCiudad();
    
    void abrirVentanaAgregarHorario();
    void abrirVentanaEliminarHorario();
    void abrirVentanaActualizarHorario();
    void abrirVentanaBuscarHorario();
    
    void abrirVentanaAgregarVuelo();
    void abrirVentanaEliminarVuelo();
    void abrirVentanaActualizarVuelo();
    void abrirVentanaBuscarVuelo();
    //Atributos
    Gtk::MenuBar menuBar;
    
    Gtk::MenuItem menuAvion;
    Gtk::MenuItem menuAerolinea;//item del menu bar
    Gtk::MenuItem menuCiudad;
    Gtk::MenuItem menuHorario;
    Gtk::MenuItem menuVuelo;
    
    Gtk::Menu subMenuAvion; //abre el contenedor submenu
    Gtk::Menu subMenuAerolinea;
    Gtk::Menu subMenuCiudad;//Contiene opciones del modulo administrativo
    Gtk::Menu subMenuHorario;
    Gtk::Menu subMenuVuelo;
    
    //menus avion
    Gtk::ImageMenuItem menuAgregarAvion;
    Gtk::ImageMenuItem menuElmininarAvion;
    Gtk::ImageMenuItem menuActualizarAvionLista;
    Gtk::ImageMenuItem menuActualizarAvionAerolinea;
    Gtk::ImageMenuItem menuBuscarAvion;
    
    //menus aerolinea
    Gtk::ImageMenuItem menuAgregarAerolinea;
    Gtk::ImageMenuItem menuElmininarAerolinea;
    Gtk::ImageMenuItem menuActualizarAerolinea;
    Gtk::ImageMenuItem menuBuscarAerolinea;
    
    //menus ciudad
    Gtk::ImageMenuItem menuAgregarCiudad;
    Gtk::ImageMenuItem menuElmininarCiudad;
    Gtk::ImageMenuItem menuActualizarCiudad;
    Gtk::ImageMenuItem menuBuscarCiudad;
    
    //menus horarioa un vuelo
    Gtk::ImageMenuItem menuAgregarHorario;
    Gtk::ImageMenuItem menuElmininarHorario;
    Gtk::ImageMenuItem menuActualizarHorario;
    Gtk::ImageMenuItem menuBuscarHorario;
    
    //menu Vuelo
    Gtk::ImageMenuItem menuAgregarVuelo;
    Gtk::ImageMenuItem menuElmininarVuelo;
    Gtk::ImageMenuItem menuActualizarVuelo;
    Gtk::ImageMenuItem menuBuscarVuelo;
    
    Gtk::ImageMenuItem menuIAerolinea;
    Gtk::ImageMenuItem menuICiudad;
    Gtk::ImageMenuItem menuIHorario;
    Gtk::ImageMenuItem menuIVuelo;

    Gtk::Fixed fixed; // contenedor

    
    //ventanas
    VentanaAgregarAvion * vagregarAvion;
    VentanaAgregarAerolinea* vagregarAerolinea;
    VentanaAgregarCiudad* vagregarCiudad;
    VentanaAgregarHorario* vagregarHorario;
    VentanaAgregarVuelo* vagregarVuelo;
    
    VentanaEliminarAvion* veleminarAvion;
    VentanaEliminarAerolinea* veleminarAerolinea;
    VentanaEliminarCiudad* veleminarCiudad;
    VentanaEliminarHorario* veleminarHorario;
    VentanaEliminarVuelo* veliminarVuelo;
    
    VentanaBuscarAvion* vBuscarAvion;
    VentanaBuscarAerolinea* vBuscarAerolinea;
    VentanaBuscarCiudad* vBuscarCiudad;
    VentanaBuscarHorario* vBuscarHorario;
    VentanaBuscarVuelo* vBuscarVuelo;
    
    VentanaActualizarAerolinea* vActualizarAerolinea;
    VentanaActualizarAvionLista* vActualizarAvionLista;
//    VentanaActualizarAvionVuelo* vActualizarAvionVuelo;
    VentanaActualizarCiudad* vActualizarCiudad;
    VentanaActualizarHorario* vActualizarHorario;
    VentanaActualizarVuelo* vActualizarVuelo;
    
    
};

#endif /* VENTANAPRINCIPALADMIN_H */

