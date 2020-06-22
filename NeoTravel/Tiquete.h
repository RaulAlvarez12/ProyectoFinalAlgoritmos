/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tiquete.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 01:42 PM
 */

#ifndef TIQUETE_H
#define TIQUETE_H

#include "Usuario.h"
#include "Aerolinea.h"
#include "Vuelo.h"
#include "Horario.h"
#include <string>
#include <sstream>

class Tiquete {
public:
    Tiquete(Usuario* usuario, Aerolinea* aerolinea, Vuelo* vuelo,Horario* horario);
    Tiquete(const Tiquete& orig);
    virtual ~Tiquete();
    Usuario* getUsuario();
    void setUsuario( Usuario* usuario);
    Aerolinea* getAerolinea();
    void setAerolinea(Aerolinea* Aerolinea);
    Vuelo* getVuelo();
    void setVuelo(Vuelo* vuelo);
    string toString();
private:
    Usuario* usuario;
    Aerolinea* aerolinea;
    Vuelo* vuelo;
    Horario* horario;

};

#endif /* TIQUETE_H */

