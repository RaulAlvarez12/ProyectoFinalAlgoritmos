/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEnlazadaCircularDoble.h
 * Author: geral
 *
 * Created on 20 de mayo de 2020, 03:34 PM
 */

#ifndef LISTAENLAZADACIRCULARDOBLE_H
#define LISTAENLAZADACIRCULARDOBLE_H

#include "Aerolinea.h"

class ListaEnlazadaCircularDoble {

    struct nodo {
        Aerolinea* elemento;
        struct nodo *sgte; //apuntador al nodo SIGUIENTE
        struct nodo *ant; //apuntador al nodo Anterior
    };
    typedef nodo *ptrLista; //creando nodo tipo puntero(tipo de dato)
public:
    ListaEnlazadaCircularDoble();
    ListaEnlazadaCircularDoble(const ListaEnlazadaCircularDoble& orig);
    virtual ~ListaEnlazadaCircularDoble();


    int getSize();
    void anular();
    bool isEmpty();

    void insertar(Aerolinea* valor);
    int getPosicion(Aerolinea* valor);
    void borrar(Aerolinea* valor);
    bool exist(Aerolinea* valor);
    //    void insertarOrdenado(Aerolinea valor);

    Aerolinea* firstInlist();
    Aerolinea* lastInList();
    Aerolinea* obtenerSiguiente(Aerolinea* aerolinea);
    Aerolinea* obtenerAnterior(Aerolinea* aerolinea);

    void mostrarValoresLista();
    void invertirLista();
    ptrLista inicio;
    ptrLista ultimo;
private:

};

#endif /* LISTAENLAZADACIRCULARDOBLE_H */

