/* 
 * File:   VueloData.h
 * Author: Raul Alvarez Fernandez
 *
 * Created on 18 de junio de 2020, 04:18 PM
 */

#ifndef VUELODATA_H
#define VUELODATA_H
#include <iostream>
#include <string.h>
#include <sstream>

#include "Vuelo.h"
#include "ListaEnlazadaCircularDoble.h"

using namespace std;
//using namespace ListaEnlazadaCircularDoble<Vuelo>;

class VueloData {
public:
    VueloData();
    virtual ~VueloData();
    void insertarVuelo(Vuelo* vuelo);
    void borrarVuelo(Vuelo* vuelo);
    ListaEnlazadaCircularDoble<Vuelo>* obtenerListaVuelos();
    Vuelo* obtenerSiguienteVuelo(Vuelo* vuelo);
    Vuelo* obtenerAnteriorVuelo(Vuelo* vuelo);
    Vuelo* firstInList();
    Vuelo* buscarVuelo(string cOrigen,string cDestino);
    string toString();
    string mostrarVuelosActivos();

private:

    ListaEnlazadaCircularDoble<Vuelo>*listaVuelos = new ListaEnlazadaCircularDoble<Vuelo>;
};

#endif /* VUELODATA_H */