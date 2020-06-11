/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vuelo.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 01:50 PM
 */

#ifndef VUELO_H
#define VUELO_H

#include "Itinerario.h"
#include "Ciudad.h"


class Vuelo {
public:
    Vuelo(Itinerario* itinerario,Ciudad* ciudadOrigen,Ciudad* ciudadDestino);
    Vuelo(const Vuelo& orig);
    virtual ~Vuelo();
    Itinerario* getItinerario();
    void setItinerario( Itinerario* itinerario);
    Ciudad* getCiudadOrigen();
    void setCiudadOrigen(Ciudad* ciudadOrigen);
    Ciudad* getciudadDestino();
    void setciudadDestino(Ciudad* ciudadDestino);
    
    
    
private:
    Itinerario* itinerario;
    Ciudad* ciudadOrigen;
    Ciudad* ciudadDestino;
    
};

#endif /* VUELO_H */

