/* 
 * File:   VentanaPrincipalAdmin.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 10:06 AM
 */

#include "VentanaPrincipalAdmin.h"

VentanaPrincipalAdmin::VentanaPrincipalAdmin() {
    this->set_size_request(400, 300);
    init();
    this->set_title("Administracion");
    this->vagregarAvion = 0;
    this->vagregarAerolinea = 0;
    this->vagregarCiudad = 0;
    this->vagregarHorario = 0;
    this->vagregarVuelo = 0;

    this->veleminarAvion = 0;
    this->veleminarAerolinea = 0;
    this->veleminarCiudad = 0;
    this->veleminarHorario = 0;
    this->veliminarVuelo = 0;

    this->vBuscarAvion = 0;
    this->vBuscarAerolinea = 0;
    this->vBuscarCiudad = 0;
    this->vBuscarHorario = 0;
    this->vBuscarVuelo = 0;

    this->vActualizarAerolinea = 0;
    this->vActualizarAvionLista = 0;
//    this->vActualizarAvionVuelo = 0;
    this->vActualizarCiudad = 0;
    this->vActualizarHorario = 0;
    this->vActualizarVuelo = 0;
    //this->show_all_children();
}

VentanaPrincipalAdmin::VentanaPrincipalAdmin(const VentanaPrincipalAdmin& orig) {
}

VentanaPrincipalAdmin::~VentanaPrincipalAdmin() {
}

void VentanaPrincipalAdmin::init() {
    this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
    this->menuAvion.set_label("Avion");
    this->menuAerolinea.set_label("Aerolinea");
    this->menuCiudad.set_label("Ciudad");
    this->menuHorario.set_label("Horario");
    this->menuVuelo.set_label("Vuelo");


    this->menuBar.append(this->menuAvion);
    this->menuBar.append(this->menuAerolinea);
    this->menuBar.append(this->menuCiudad);
    this->menuBar.append(this->menuHorario);
    this->menuBar.append(this->menuVuelo);

    this->menuAvion.set_submenu(this->subMenuAvion);
    this->menuAerolinea.set_submenu(this->subMenuAerolinea);
    this->menuCiudad.set_submenu(this->subMenuCiudad);
    this->menuHorario.set_submenu(this->subMenuHorario);
    this->menuVuelo.set_submenu(this->subMenuVuelo);

    //agrega submenu a la barra y le asigna una accion
    this->menuAgregarAvion.set_label("Agregar");
    this->menuAgregarAvion.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaAgregarAvion));
    this->subMenuAvion.append(this->menuAgregarAvion);

    this->menuElmininarAvion.set_label("Eliminar");
    this->menuElmininarAvion.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaEliminarAvion));
    this->subMenuAvion.append(this->menuElmininarAvion);

    this->menuActualizarAvionLista.set_label("Actualizar");
    this->menuActualizarAvionLista.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaActualizarAvionLista));
    this->subMenuAvion.append(this->menuActualizarAvionLista);

//    this->menuActualizarAvionAerolinea.set_label("Actualizar En vuelo");
//    this->menuActualizarAvionAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVEntanaActualizarAvionVuelo));
//    this->subMenuAvion.append(this->menuActualizarAvionAerolinea);

    this->menuBuscarAvion.set_label("Buscar");
    this->menuBuscarAvion.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaBuscarAvion));
    this->subMenuAvion.append(this->menuBuscarAvion);

    this->menuAgregarAerolinea.set_label("Agregar");
    this->menuAgregarAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaAgregarAerolinea));
    this->subMenuAerolinea.append(this->menuAgregarAerolinea);

    this->menuElmininarAerolinea.set_label("Eliminar");
    this->menuElmininarAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaEliminarAerolinea));
    this->subMenuAerolinea.append(this->menuElmininarAerolinea);

    this->menuActualizarAerolinea.set_label("Actualizar");
    this->menuActualizarAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaActualizarAerolinea));
    this->subMenuAerolinea.append(this->menuActualizarAerolinea);

    this->menuBuscarAerolinea.set_label("Buscar");
    this->menuBuscarAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaBuscarAerolinea));
    this->subMenuAerolinea.append(this->menuBuscarAerolinea);


    this->menuAgregarCiudad.set_label("Agregar");
    this->menuAgregarCiudad.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaAgregarCiudad));
    this->subMenuCiudad.append(this->menuAgregarCiudad);

    this->menuElmininarCiudad.set_label("Eliminar");
    this->menuElmininarCiudad.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaEliminarCiudad));
    this->subMenuCiudad.append(this->menuElmininarCiudad);

    this->menuActualizarCiudad.set_label("Actualizar");
    this->menuActualizarCiudad.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaActualizarCiudad));
    this->subMenuCiudad.append(this->menuActualizarCiudad);

    this->menuBuscarCiudad.set_label("Buscar");
    this->menuBuscarCiudad.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaBuscarCiudad));
    this->subMenuCiudad.append(this->menuBuscarCiudad);


    this->menuAgregarHorario.set_label("Agregar");
    this->menuAgregarHorario.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaAgregarHorario));
    this->subMenuHorario.append(this->menuAgregarHorario);

    this->menuElmininarHorario.set_label("Eliminar");
    this->menuElmininarHorario.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaEliminarHorario));
    this->subMenuHorario.append(this->menuElmininarHorario);

    this->menuActualizarHorario.set_label("Actualizar");
    this->menuActualizarHorario.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaActualizarHorario));
    this->subMenuHorario.append(this->menuActualizarHorario);

    this->menuBuscarHorario.set_label("Buscar");
    this->menuBuscarHorario.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaBuscarHorario));
    this->subMenuHorario.append(this->menuBuscarHorario);


    this->menuAgregarVuelo.set_label("Agregar");
    this->menuAgregarVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaAgregarVuelo));
    this->subMenuVuelo.append(this->menuAgregarVuelo);

    this->menuElmininarVuelo.set_label("Eliminar");
    this->menuElmininarVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaEliminarVuelo));
    this->subMenuVuelo.append(this->menuElmininarVuelo);

    this->menuActualizarVuelo.set_label("Actualizar");
    this->menuActualizarVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaActualizarVuelo));
    this->subMenuVuelo.append(this->menuActualizarVuelo);

    this->menuBuscarVuelo.set_label("Buscar");
    this->menuBuscarVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::abrirVentanaBuscarVuelo));
    this->subMenuVuelo.append(this->menuBuscarVuelo);



    this->add(fixed);
    this->show_all_children();
}

void VentanaPrincipalAdmin::aboutWinClose() {

    this->vagregarAvion = 0;
    this->vagregarAerolinea = 0;
    this->vagregarCiudad = 0;
    this->vagregarHorario = 0;
    this->vagregarVuelo = 0;

    this->veleminarAvion = 0;
    this->veleminarAerolinea = 0;
    this->veleminarCiudad = 0;
    this->veleminarHorario = 0;
    this->veliminarVuelo = 0;

    this->vBuscarAvion = 0;
    this->vBuscarAerolinea = 0;
    this->vBuscarCiudad = 0;
    this->vBuscarHorario = 0;
    this->vBuscarVuelo = 0;

    this->vActualizarAerolinea = 0;
    this->vActualizarAvionLista = 0;
//    this->vActualizarAvionVuelo = 0;
    this->vActualizarCiudad = 0;
    this->vActualizarHorario = 0;
    this->vActualizarVuelo = 0;
}

//void VentanaPrincipalAdmin::abrirVEntanaActualizarAvionVuelo() {
//    if (this->vActualizarAvionVuelo != 0)
//        return;
//
//    this->vActualizarAvionVuelo = new VentanaActualizarAvionVuelo();
//    this->vActualizarAvionVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
//    this->vActualizarAvionVuelo->show();
//}

void VentanaPrincipalAdmin::abrirVentanaActualizarAerolinea() {
    if (this->vActualizarAerolinea != 0)
        return;

    this->vActualizarAerolinea = new VentanaActualizarAerolinea();
    this->vActualizarAerolinea->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vActualizarAerolinea->show();
}

void VentanaPrincipalAdmin::abrirVentanaActualizarAvionLista() {

    if (this->vActualizarAvionLista != 0)
        return;

    this->vActualizarAvionLista = new VentanaActualizarAvionLista();
    this->vActualizarAvionLista->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vActualizarAvionLista->show();
}

void VentanaPrincipalAdmin::abrirVentanaActualizarCiudad() {

    if (this->vActualizarCiudad != 0)
        return;

    this->vActualizarCiudad = new VentanaActualizarCiudad();
    this->vActualizarCiudad->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vActualizarCiudad->show();
}

void VentanaPrincipalAdmin::abrirVentanaActualizarHorario() {

    if (this->vActualizarHorario != 0)
        return;

    this->vActualizarHorario = new VentanaActualizarHorario();
    this->vActualizarHorario->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vActualizarHorario->show();
}

void VentanaPrincipalAdmin::abrirVentanaActualizarVuelo() {

    if (this->vActualizarVuelo != 0)
        return;

    this->vActualizarVuelo = new VentanaActualizarVuelo();
    this->vActualizarVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vActualizarVuelo->show();
}

void VentanaPrincipalAdmin::abrirVentanaAgregarAerolinea() {

    if (this->vagregarAerolinea!= 0)
        return;

    this->vagregarAerolinea = new VentanaAgregarAerolinea();
    this->vagregarAerolinea->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vagregarAerolinea->show();
}

void VentanaPrincipalAdmin::abrirVentanaAgregarAvion() {

    if (this->vagregarAvion != 0)
        return;

    this->vagregarAvion = new VentanaAgregarAvion();
    this->vagregarAvion->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vagregarAvion->show();
}

void VentanaPrincipalAdmin::abrirVentanaAgregarCiudad() {

    if (this->vagregarCiudad != 0)
        return;

    this->vagregarCiudad = new VentanaAgregarCiudad();
    this->vagregarCiudad->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vagregarCiudad->show();
}

void VentanaPrincipalAdmin::abrirVentanaAgregarHorario() {

    if (this->vagregarHorario != 0)
        return;

    this->vagregarHorario = new VentanaAgregarHorario();
    this->vagregarHorario->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vagregarHorario->show();
}

void VentanaPrincipalAdmin::abrirVentanaAgregarVuelo() {

    if (this->vagregarVuelo != 0)
        return;

    this->vagregarVuelo = new VentanaAgregarVuelo();
    this->vagregarVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vagregarVuelo->show();
}

void VentanaPrincipalAdmin::abrirVentanaBuscarAerolinea() {

    if (this->vBuscarAerolinea != 0)
        return;

    this->vBuscarAerolinea = new VentanaBuscarAerolinea();
    this->vBuscarAerolinea->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vBuscarAerolinea->show();
}

void VentanaPrincipalAdmin::abrirVentanaBuscarAvion() {

    if (this->vBuscarAvion != 0)
        return;

    this->vBuscarAvion = new VentanaBuscarAvion();
    this->vBuscarAvion->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vBuscarAvion->show();
}

void VentanaPrincipalAdmin::abrirVentanaBuscarCiudad() {

    if (this->vBuscarCiudad != 0)
        return;

    this->vBuscarCiudad = new VentanaBuscarCiudad();
    this->vBuscarCiudad->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vBuscarCiudad->show();
}

void VentanaPrincipalAdmin::abrirVentanaBuscarHorario() {

    if (this->vBuscarHorario != 0)
        return;

    this->vBuscarHorario = new VentanaBuscarHorario();
    this->vBuscarHorario->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vBuscarHorario->show();
}

void VentanaPrincipalAdmin::abrirVentanaBuscarVuelo() {

    if (this->vBuscarVuelo != 0)
        return;

    this->vBuscarVuelo = new VentanaBuscarVuelo();
    this->vBuscarVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->vBuscarVuelo->show();
}

void VentanaPrincipalAdmin::abrirVentanaEliminarAerolinea() {

    if (this->veleminarAerolinea != 0)
        return;

    this->veleminarAerolinea = new VentanaEliminarAerolinea();
    this->veleminarAerolinea->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->veleminarAerolinea->show();
}

void VentanaPrincipalAdmin::abrirVentanaEliminarAvion() {

    if (this->veleminarAvion != 0)
        return;

    this->veleminarAvion = new VentanaEliminarAvion();
    this->veleminarAvion->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->veleminarAvion->show();
}

void VentanaPrincipalAdmin::abrirVentanaEliminarCiudad() {

    if (this->veleminarCiudad != 0)
        return;

    this->veleminarCiudad = new VentanaEliminarCiudad();
    this->veleminarCiudad->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->veleminarCiudad->show();
}

void VentanaPrincipalAdmin::abrirVentanaEliminarHorario() {

    if (this->veleminarHorario != 0)
        return;

    this->veleminarHorario = new VentanaEliminarHorario();
    this->veleminarHorario->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->veleminarHorario->show();
}

void VentanaPrincipalAdmin::abrirVentanaEliminarVuelo() {

    if (this->veliminarVuelo != 0)
        return;

    this->veliminarVuelo = new VentanaEliminarVuelo();
    this->veliminarVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipalAdmin::aboutWinClose));
    this->veliminarVuelo->show();
}
