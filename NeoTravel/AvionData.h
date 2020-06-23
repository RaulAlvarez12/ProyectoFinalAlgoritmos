/* 
 * File:   AvionData.h
 * Author: Raul Alvarez Fernandez
 *
 * Created on 22 de junio de 2020, 05:32 PM
 */

#ifndef AVIONDATA_H
#define AVIONDATA_H

#include <iostream>

#include "Avion.h"
#include "ListaEnlazadaCircularDoble.h"

using namespace std;

class AvionData {
public:
    static AvionData* getInstance();
    void agregarAvion(Avion* avion);
    ListaEnlazadaCircularDoble<Avion>* obtenerListaDeAviones();
    void eliminarAvion(Avion* avion);
    Avion* obtenerSiguienteAvion(Avion* avion);
    Avion* obtenerAnteriorAvion(Avion* avion);
    Avion* firstInList();
    
    
protected:
    AvionData();
    
private:
    static AvionData* instance;
    ListaEnlazadaCircularDoble<Avion>* ListaAviones = new ListaEnlazadaCircularDoble<Avion>;
};

#endif /* AVIONDATA_H */