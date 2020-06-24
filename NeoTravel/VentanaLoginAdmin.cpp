
/* 
 * File:   VentanaLoginAdmin.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 22 de junio de 2020, 05:51 PM
 */

#include <cstring>
#include <cairomm-1.0/cairomm/enums.h>

#include "VentanaLoginAdmin.h"

VentanaLoginAdmin::VentanaLoginAdmin() {
    this->set_size_request(300, 175);
    this->set_title("Login modulo administrativo");
    init();
    this->show_all_children();
}

VentanaLoginAdmin::~VentanaLoginAdmin() {
}

void VentanaLoginAdmin::init() {


    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 20, 22);
    this->fixed.put(this->etNombre, 110, 18);

    this->lblContrasena.set_label("Contraseña:");
    this->etContrasena.set_visibility(false);
    this->fixed.put(this->lblContrasena, 20, 62);
    this->fixed.put(this->etContrasena, 110, 58);

    this->btnIngresar.set_label("Ingresar");
    this->btnIngresar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaLoginAdmin::onButtonClickedIngresar));
    this->fixed.put(this->btnIngresar, 20, 120);
    this->add(fixed);
    this->show_all_children();
}

void VentanaLoginAdmin::aboutWinClose() {
    vPrincipal = 0;
}

void VentanaLoginAdmin::onButtonClickedIngresar() {

    if (strcmp(etNombre.get_text().c_str(), "admin") == 0 && strcmp(etContrasena.get_text().c_str(), "admin") == 0) {
        vPrincipal = new VentanaPrincipalAdmin();
        this->vPrincipal->signal_hide().connect(sigc::mem_fun(*this, &VentanaLoginAdmin::aboutWinClose));
        vPrincipal->show();
        this->close();
    }
}

//bool VentanaLoginAdmin::on_key_press_event(GdkEventKey* event) {
//    if (event->keyval == GDK_KEY_) {
//        onButtonClickedIngresar();
//    }
//}