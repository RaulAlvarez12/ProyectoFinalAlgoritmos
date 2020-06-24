/* 
 * File:   VentanaPrincipal.cpp
 * Author: geraldi
 * 
 * Created on 8 de junio de 2020, 02:36 PM
 */

#include "VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal() {
    this->set_size_request(400, 300);
    init();
    this->ventanaescoger = 0;
    this->ventanaItinerario = 0;
    this->ventanaLogin = 0;
}//constructor

VentanaPrincipal::~VentanaPrincipal() {
}

void VentanaPrincipal::init() {

    ciudadData->getInstance()->agregarCiudad(new Ciudad("okland"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("newPort"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("Estados Unidos"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("Costa Rica"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("Mexico"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("China"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("España"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("Colombia"));
    ciudadData->getInstance()->agregarCiudad(new Ciudad("San Jose"));

    avionData->getInstance()->agregarAvion(new Avion("Boeing 777", 120, 27, 722));
    avionData->getInstance()->agregarAvion(new Avion("Boeing 767", 300, 74, 172));
    avionData->getInstance()->agregarAvion(new Avion("Boeing 539", 200, 37, 782));
    avionData->getInstance()->agregarAvion(new Avion("Cessna", 20, 97, 729));

    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea("Copa"));
    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea("Emirates"));
    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea("American"));
    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea("Qatar"));
    aerolineaData->getInstance()->agregarAerolinea(new Aerolinea("Avianca"));


            this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
    this->menuArchivo.set_label("Usuario");
    this->menuItinerario.set_label("Itinerarios");
    this->menuAdministrativo.set_label("Administracion");

    this->menuBar.append(this->menuArchivo);
    this->menuBar.append(this->menuItinerario);
    this->menuBar.append(this->menuAdministrativo);

    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->menuItinerario.set_submenu(this->subMenuItinerario);
    this->menuAdministrativo.set_submenu(this->subMenuAdministrativo);

    //agrega submenu a la barra y le asigna una accion
    this->menuEscogerAerolinea.set_label("Comprar Tiquete");
    this->menuEscogerAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaEscogerAerolinea));
    this->subMenuArchivo.append(this->menuEscogerAerolinea);

    this->menuItinerarios.set_label("Itinerarios de vuelos");
    this->menuItinerarios.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaItinerario));
    this->subMenuItinerario.append(this->menuItinerarios);

    this->menuItemAvion.set_label("Modulo Admin");
    this->menuItemAvion.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaLogin));
    this->subMenuAdministrativo.append(this->menuItemAvion);

    this->add(fixed);
    this->show_all_children();
}//init

void VentanaPrincipal::aboutWinClose() {
    this->ventanaescoger = 0;
}

void VentanaPrincipal::aboutWinCloseVentanaItinerarios() {
    this->ventanaItinerario = 0;
}//aboutWinCloseVentanaItinerarios

void VentanaPrincipal::aboutWinCloseVentanaLogin() {
    this->ventanaLogin = 0;
}

void VentanaPrincipal::abrirVentanaLogin() {
    if (this->ventanaLogin != 0)
        return;

    this->ventanaLogin = new VentanaLoginAdmin();
    this->ventanaLogin->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinCloseVentanaLogin));
    this->ventanaLogin->show();
}

void VentanaPrincipal::abrirVentanaEscogerAerolinea() {
    if (this->ventanaescoger != 0)
        return;

    this->ventanaescoger = new VentanaEscogerAerolinea();
    this->ventanaescoger->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaescoger->show();
}

void VentanaPrincipal::abrirVentanaItinerario() {
    if (this->ventanaItinerario != 0)
        return;

    this->ventanaItinerario = new VentanaItinerario();
    this->ventanaItinerario->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinCloseVentanaItinerarios));
    this->ventanaItinerario->show();
}//abrirVentanaItinerario