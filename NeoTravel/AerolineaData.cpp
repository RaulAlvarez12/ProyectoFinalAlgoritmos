/* 
 * File:   AerolineaData.cpp
 * Author: geraldi
 * 
 * Created on 7 de junio de 2020, 04:53 PM
 */

#include "AerolineaData.h"

AerolineaData* AerolineaData::instance = NULL;

AerolineaData::AerolineaData() {
    ListaAerolineas = new ListaEnlazadaCircularDoble<Aerolinea>;
    grafo = new GrafoListaEnlazada();
}

AerolineaData* AerolineaData::getInstance() {

    if (instance == NULL) {
        instance = new AerolineaData();
    }
    return instance;
}//getInstance

void AerolineaData::agregarAerolinea(Aerolinea* aerolinea) {
    ListaAerolineas->insertar(aerolinea);
}

void AerolineaData::eliminarAerolinea(Aerolinea* aerolinea) {
    ListaAerolineas->borrar(aerolinea);
}

Aerolinea* AerolineaData::obtenerSiguiente(Aerolinea* aerolinea) {
    return ListaAerolineas->obtenerSiguiente(aerolinea);
}

Aerolinea* AerolineaData::obtenerAnterior(Aerolinea* aerolinea) {
    return ListaAerolineas->obtenerAnterior(aerolinea);
}

void AerolineaData::mostrar() {
    this->ListaAerolineas->mostrarValoresLista();
}

ListaEnlazadaCircularDoble<Aerolinea>* AerolineaData::obtenerListaDeAerolineas() {
    return ListaAerolineas;
}

Aerolinea* AerolineaData::firstInList() {
    return ListaAerolineas->firstInlist();
}

Aerolinea* AerolineaData::buscarAerolinea(string aerolinea) {
    Aerolinea* aux = ListaAerolineas->firstInlist();
    if (aux->getNombre().compare(aerolinea) == 0) {
        return aux;
    } else {
        while (aux != ListaAerolineas->firstInlist()) {
            aux = ListaAerolineas->obtenerSiguiente(aux);
            if (aux->getNombre().compare(aerolinea) == 0) {
                return aux;
            }
        }
    }
}
