/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaData.cpp
 * Author: geraldi
 * 
 * Created on 7 de junio de 2020, 04:53 PM
 */

#include "AerolineaData.h"

AerolineaData::AerolineaData() {
    ListaAerolineas = new ListaEnlazadaCircularDoble<Aerolinea>;
    Aerolinea *a1 = new Aerolinea("Copa");
    ListaAerolineas->insertar(a1);
    Aerolinea *a2 = new Aerolinea("Emirates");
    ListaAerolineas->insertar(a2);
    Aerolinea *a4 = new Aerolinea("American");
    ListaAerolineas->insertar(a4);
    Aerolinea *a5 = new Aerolinea("Qatar");
    ListaAerolineas->insertar(a5);

    Aerolinea *a3 = new Aerolinea("Avianca");
    ListaAerolineas->insertar(a3);

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




//AerolineaData* AerolineaData::getInstance(){
//    
//        if(instance==0){
//            instance=new AerolineaData();
//        }
//        
//        return instance;
//    
//}

void AerolineaData::agregarAerolinea(Aerolinea* aerolinea) {
    ListaAerolineas->insertar(aerolinea);
}

ListaEnlazadaCircularDoble<Aerolinea>* AerolineaData::obtenerListaDeAerolineas() {
    return ListaAerolineas;
}

Aerolinea* AerolineaData::firstInList() {
    return ListaAerolineas->firstInlist();
}

AerolineaData::~AerolineaData() {
}

