/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaData.h
 * Author: geraldi
 *
 * Created on 7 de junio de 2020, 04:53 PM
 */

#ifndef AEROLINEADATA_H
#define AEROLINEADATA_H
#include <vector>
#include <iostream>

#include "Aerolinea.h"
#include "ListaEnlazadaCircularDoble.h"


class AerolineaData {
public:
   static AerolineaData* getInstance();
   void agregarAerolinea(Aerolinea* aerolinea);
   ListaEnlazadaCircularDoble* obtenerListaDeAerolineas();
   void mostrar();
    virtual ~AerolineaData();
    AerolineaData();
    Aerolinea* obtenerSiguiente(Aerolinea* aerolinea);
    Aerolinea* obtenerAnterior(Aerolinea* aerolinea);
    Aerolinea* firstInList();
private:
     
    static AerolineaData* instance;
    ListaEnlazadaCircularDoble* ListaAerolineas;
    
protected:
 
};

//AerolineaData* AerolineaData::instance=0;

#endif /* AEROLINEADATA_H */

