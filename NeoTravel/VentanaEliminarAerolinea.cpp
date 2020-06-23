
/* 
 * File:   VentanaEliminarAerolinea.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 11:20 AM
 */

#include "VentanaEliminarAerolinea.h"

VentanaEliminarAerolinea::VentanaEliminarAerolinea() {
        this->set_size_request(300, 300);
    this->set_title("Eliminar Aerolinea");
//    init();
    this->show_all_children();
}

VentanaEliminarAerolinea::VentanaEliminarAerolinea(const VentanaEliminarAerolinea& orig) {
}

VentanaEliminarAerolinea::~VentanaEliminarAerolinea() {
}

