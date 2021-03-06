/* 
 * File:   AerolineaData.h
 * Author: geraldi
 *
 * Created on 7 de junio de 2020, 04:53 PM
 */

#ifndef AEROLINEADATA_H
#define AEROLINEADATA_H
#include <iostream>
#include <string.h>
#include <sstream>
#include <ctime>

#include "Aerolinea.h"
#include "ListaEnlazadaCircularDoble.h"
#include "GrafoListaEnlazada.h"

using namespace std;

class AerolineaData {
public:
    static AerolineaData* getInstance();
    void agregarAerolinea(Aerolinea* aerolinea);
    ListaEnlazadaCircularDoble<Aerolinea>* obtenerListaDeAerolineas();
    void eliminarAerolinea(Aerolinea* aerolinea);
    Aerolinea* obtenerSiguiente(Aerolinea* aerolinea);
    Aerolinea* obtenerAnterior(Aerolinea* aerolinea);
    Aerolinea* firstInList();
    Aerolinea* buscarAerolinea(string aerolinea);
    void mostrar();
    string mostrarVuelosActivos();
    
    GrafoListaEnlazada* grafo;
    
protected:
    AerolineaData();
    
private:
    static AerolineaData* instance;
    ListaEnlazadaCircularDoble<Aerolinea>* ListaAerolineas = new ListaEnlazadaCircularDoble<Aerolinea>;
    
};

#endif /* AEROLINEADATA_H */