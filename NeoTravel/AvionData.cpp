/* 
 * File:   AvionData.cpp
 * Author: Raul Alvarez Fernandez
 * 
 * Created on 22 de junio de 2020, 05:32 PM
 */

#include "AvionData.h"

AvionData* AvionData::instance=NULL;

AvionData::AvionData() {
}

AvionData* AvionData::getInstance() {
    if (instance == NULL) {
        instance = new AvionData();
    }
    return instance;
}

void AvionData::agregarAvion(Avion* avion) {
    ListaAviones->insertar(avion);
}

void AvionData::eliminarAvion(Avion* avion) {
    ListaAviones->borrar(avion);
}

ListaEnlazadaCircularDoble<Avion>* AvionData::obtenerListaDeAviones() {
    return ListaAviones;
}

Avion* AvionData::obtenerAnteriorAvion(Avion* avion) {
    return ListaAviones->obtenerAnterior(avion);
}

Avion* AvionData::obtenerSiguienteAvion(Avion* avion) {
    return ListaAviones->obtenerSiguiente(avion);
}

Avion* AvionData::firstInList() {
    return ListaAviones->firstInlist();
}

Avion* AvionData::buscarAvion(string avion) {

    Avion* aux = ListaAviones->firstInlist();
    if(aux->getNombreAvion().compare(avion)==0){
        return aux;
    }else{
        while(aux!=ListaAviones->firstInlist()){
            aux=ListaAviones->obtenerSiguiente(aux);
            if(aux->getNombreAvion().compare(avion)==0){
                return aux;
            }
        }
    }
    

}
