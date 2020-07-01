/* 
 * File:   CiudadData.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 03:08 PM
 */

#include "CiudadData.h"
#include "ListaEnlazadaCircularDoble.h"
CiudadData* CiudadData::instance = NULL;

CiudadData::CiudadData() {
}

void CiudadData::agregarCiudad(Ciudad* ciudad) {
    this->ListaCiudad->insertar(ciudad);
}

void CiudadData::eliminarCiudad(Ciudad* ciudad) {
    this->ListaCiudad->borrar(ciudad);
}

Ciudad* CiudadData::firstInList() {
    return this->ListaCiudad->firstInlist();
}

CiudadData* CiudadData::getInstance() {
    if (instance == NULL) {
        instance = new CiudadData();
    }
    return instance;
}

Ciudad* CiudadData::obtenerAnteriorCiudad(Ciudad* ciudad) {
    return this->ListaCiudad->obtenerAnterior(ciudad);
}

ListaEnlazadaCircularDoble<Ciudad>* CiudadData::obtenerListaDeCiudades() {
    return this->ListaCiudad;
}

Ciudad* CiudadData::obtenerSiguienteCiudad(Ciudad* ciudad) {
    return this->ListaCiudad->obtenerSiguiente(ciudad);
}

Ciudad* CiudadData::buscarCiudad(string ciudad) {
    Ciudad* aux = this->ListaCiudad->firstInlist();
    if (aux->getNombre().compare(ciudad) == 0) {
        return aux;
    } else {
        aux = obtenerSiguienteCiudad(aux);
        while (aux != this->ListaCiudad->firstInlist()) {
            aux = this->ListaCiudad->obtenerSiguiente(aux);
            if (aux->getNombre().compare(ciudad) == 0) {
                return aux;
            }
        }
    }
}