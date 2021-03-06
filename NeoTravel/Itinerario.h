/* 
 * File:   Itinerario.h
 * Author: alsov
 *
 * Created on 11 de junio de 2020, 01:51 PM
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H

#include <string.h>
#include <sstream>

#include "Cola.h"
#include "Avion.h"
#include "Horario.h"

using namespace std;

class Itinerario {
public:
    Itinerario();
    Itinerario(Avion* avion, Cola* colaPrioridad);
    virtual ~Itinerario();
    Cola* getColaPrioridad();
    void setColaPrioridad(Cola* cola);
    Avion* getAvion();
    void setAvion(Avion* avion);
    string toString();
private:
    Avion* avion;
    Cola* colaPrioridad;
};

#endif /* ITINERARIO_H */