/* 
 * File:   Vuelo.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 01:50 PM
 */

#ifndef VUELO_H
#define VUELO_H

#include <string.h>
#include "Itinerario.h"
#include "Ciudad.h"

using namespace std;

class Vuelo {
public:
    Vuelo(Itinerario* itinerario, Ciudad* ciudadOrigen, Ciudad* ciudadDestino);
    Vuelo();
    virtual ~Vuelo();
    Itinerario* getItinerario();
    void setItinerario(Itinerario* itinerario);
    Ciudad* getCiudadOrigen();
    void setCiudadOrigen(Ciudad* ciudadOrigen);
    Ciudad* getciudadDestino();
    void setciudadDestino(Ciudad* ciudadDestino);
    string toString();

private:
    Itinerario* itinerario;
    Ciudad* ciudadOrigen;
    Ciudad* ciudadDestino;
};

#endif /* VUELO_H */