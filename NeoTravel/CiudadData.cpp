
/* 
 * File:   CiudadData.cpp
 * Author: geraldi
 * 
 * Created on 23 de junio de 2020, 03:08 PM
 */

#include "CiudadData.h"
#include "ListaEnlazadaCircularDoble.h"
CiudadData* CiudadData::instance=NULL;

CiudadData::CiudadData() {
}



void CiudadData::agregarCiudad(Ciudad* ciudad) {
    ListaCiudad->insertar(ciudad);
}

void CiudadData::eliminarCiudad(Ciudad* ciudad) {
    ListaCiudad->borrar(ciudad);
}

Ciudad* CiudadData::firstInList() {
    return ListaCiudad->firstInlist();
}

CiudadData* CiudadData::getInstance() {
if (instance == NULL) {
        instance = new CiudadData();
    }
    return instance;
}

Ciudad* CiudadData::obtenerAnteriorCiudad(Ciudad* ciudad) {
    return ListaCiudad->obtenerAnterior(ciudad);
}

ListaEnlazadaCircularDoble<Ciudad>* CiudadData::obtenerListaDeCiudades() {
    return ListaCiudad;
}

Ciudad* CiudadData::obtenerSiguienteCiudad(Ciudad* ciudad) {
    return ListaCiudad->obtenerSiguiente(ciudad);
}

Ciudad* CiudadData::buscarCiudad(string ciudad) {
    Ciudad* aux = ListaCiudad->firstInlist();
    if(aux->getNombre().compare(ciudad)==0){
        return aux;
    }else{
        while(aux!=ListaCiudad->firstInlist()){
            aux=ListaCiudad->obtenerSiguiente(aux);
            if(aux->getNombre().compare(ciudad)==0){
                return aux;
            }
        }
    }
    
}
