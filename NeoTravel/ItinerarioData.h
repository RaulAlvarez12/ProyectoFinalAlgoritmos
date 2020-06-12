/* 
 * File:   ItinerarioData.h
 * Author: alsov
 *
 * Created on 11 de junio de 2020, 09:03 PM
 */

#ifndef ITINERARIODATA_H
#define ITINERARIODATA_H

#include "Cola.h"
#include "string.h"
#include "Itinerario.h"

using namespace std;

class ItinerarioData {
public:

    ItinerarioData();
    virtual ~ItinerarioData();
    // void agregarHorario(int salida, int llegada);
    void agregarItinerario();
    vector<Cola*> obtenerItinerario();
   // void mostrarOrdenado();
    string obtenerStringHorario(int indice); // muestra el string ordenado de la cola en el indice que le indique 
    //Cola* obtenerCola(int indice);

protected:

    Cola* cola1;
    Cola* cola2;
    Cola* cola3;
    Cola* cola4;
    Cola* cola5;

    Itinerario* itinerario;

};

#endif /* ITINERARIODATA_H */