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

using namespace std;

class AerolineaData {
public:
    static AerolineaData* getInstance();
    void agregarAerolinea(Aerolinea* aerolinea);
    ListaEnlazadaCircularDoble<Aerolinea>* obtenerListaDeAerolineas();
    void mostrar();
    virtual ~AerolineaData();
    AerolineaData();
    Aerolinea* obtenerSiguiente(Aerolinea* aerolinea);
    Aerolinea* obtenerAnterior(Aerolinea* aerolinea);
    Aerolinea* firstInList();
private:

    static AerolineaData* instance;
    ListaEnlazadaCircularDoble<Aerolinea>* ListaAerolineas = new ListaEnlazadaCircularDoble<Aerolinea>;

};

//AerolineaData* AerolineaData::instance=0;

#endif /* AEROLINEADATA_H */