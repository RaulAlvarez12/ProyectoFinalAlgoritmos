/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Horario.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 02:00 PM
 */

#ifndef HORARIO_H
#define HORARIO_H

#include "Avion.h"


class Horario {
public:
    Horario(Avion* avion,int espacios);
    Horario(const Horario& orig);
    virtual ~Horario();
    Avion* getAvion();
    void setAvion(Avion* avion);
    int getEspacios();
    void setEspacios(int espacios);
    
private:
    Avion* avion;
    int espacios;
};

#endif /* HORARIO_H */

