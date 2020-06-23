
/* 
 * File:   VentanaLoginAdmin.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 22 de junio de 2020, 05:51 PM
 */

#include <cstring>

#include "VentanaLoginAdmin.h"

VentanaLoginAdmin::VentanaLoginAdmin() {
    this->set_size_request(300, 300);
    this->set_title("Login modulo administrativo");
    init();
    this->show_all_children();
}

VentanaLoginAdmin::~VentanaLoginAdmin() {
}

void VentanaLoginAdmin::init() {


    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 20, 20);
    this->fixed.put(this->etNombre, 175, 20);
    
    this->lblContrasena.set_label("Contraseña:");
    this->etContrasena.set_visibility(false);
    this->fixed.put(this->lblContrasena, 20, 60);
    this->fixed.put(this->etContrasena, 175, 60);

    this->btnIngresar.set_label("Ingresar");
    this->btnIngresar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaLoginAdmin::onButtonClickedIngresar));
    this->fixed.put(this->btnIngresar, 20, 225);
    
    this->add(fixed);
    this->show_all_children();
}

void VentanaLoginAdmin::aboutWinClose() {
    vPrincipal=0;
}

void VentanaLoginAdmin::onButtonClickedIngresar() {
    
    if(strcmp(etNombre.get_text().c_str(), "admin") == 0 && strcmp(etContrasena.get_text().c_str(), "admin") == 0){
    vPrincipal = new VentanaPrincipalAdmin();
    this->vPrincipal->signal_hide().connect(sigc::mem_fun(*this, &VentanaLoginAdmin::aboutWinClose));
    vPrincipal->show();
    this->close();
    }
}
