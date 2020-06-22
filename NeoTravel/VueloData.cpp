/* 
 * File:   VueloData.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 18 de junio de 2020, 04:18 PM
 */

#include "VueloData.h"

VueloData::VueloData() {
    this->listaVuelos = new ListaEnlazadaCircularDoble<Vuelo>;

    Ciudad* cOrigen = new Ciudad("San Jose");
    Ciudad* cDestino = new Ciudad("Estados Unidos");
    Avion* avion = new Avion("Boeing", 80, 20, 60);
    Horario* horario1 = new Horario(1, 3);
    Horario* horario2 = new Horario(4, 6);
    Cola* cola = new Cola();
    cola->encolar(horario1);
    cola->encolar(horario2);

    Itinerario* itinerario = new Itinerario(avion, cola);

    Vuelo* v1 = new Vuelo(itinerario, cOrigen, cDestino);

    this->listaVuelos->insertar(v1);

    Ciudad* c2Origen = new Ciudad("New York");
    Ciudad* c2Destino = new Ciudad("Wuhan");
    Avion* avion2 = new Avion("AvionetaMieo", 20, 10, 30);
    Horario* horario3 = new Horario(3, 5);
    Horario* horario4 = new Horario(6, 7);
    Horario* horario5 = new Horario(8, 10);
    Cola* cola2 = new Cola();
    cola2->encolar(horario3);
    cola2->encolar(horario4);
    cola2->encolar(horario5);

    Itinerario* itinerario2 = new Itinerario(avion2, cola2);

    Vuelo* v2 = new Vuelo(itinerario2, c2Origen, c2Destino);
    listaVuelos->insertar(v2);
}

VueloData::~VueloData() {
}

Vuelo* VueloData::obtenerAnteriorVuelo(Vuelo* vuelo) {
    return this->listaVuelos->obtenerAnterior(vuelo);
}

Vuelo* VueloData::obtenerSiguienteVuelo(Vuelo* vuelo) {
    return this->listaVuelos->obtenerSiguiente(vuelo);
}

Vuelo* VueloData::firstInList() {
    return this->listaVuelos->firstInlist();
}

void VueloData::insertarVuelo(Vuelo* vuelo) {
    this->listaVuelos->insertar(vuelo);
}

void VueloData::borrarVuelo(Vuelo* vuelo) {
    this->listaVuelos->borrar(vuelo);
}

/*################PENDIENTE DE HACER#####################*/
Vuelo* VueloData::buscarVuelo(Vuelo* vuelo) {

}

void VueloData::actualizarVuelo(Vuelo* vuelo) {

}

ListaEnlazadaCircularDoble<Vuelo>* VueloData::obtenerListaVuelos() {

}

string VueloData::toString() {
    stringstream s;
    s << this->listaVuelos->toString();
    return s.str();
}