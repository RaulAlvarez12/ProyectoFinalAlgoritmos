/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEnlazadaCircularDoble.cpp
 * Author: geral
 * 
 * Created on 20 de mayo de 2020, 03:34 PM
 */

#include "ListaEnlazadaCircularDoble.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

ListaEnlazadaCircularDoble::ListaEnlazadaCircularDoble() {
    inicio = ultimo = NULL;
}

ListaEnlazadaCircularDoble::ListaEnlazadaCircularDoble(const ListaEnlazadaCircularDoble& orig) {
}

ListaEnlazadaCircularDoble::~ListaEnlazadaCircularDoble() {
}

int ListaEnlazadaCircularDoble::getSize() {
    if (!isEmpty()) {
        ptrLista aux;
        aux = inicio;
        int con = 1;
        if (!isEmpty()) {
            while (aux->sgte != inicio) {
                con++;
                aux = aux->sgte;


            }
            return con;
        } else {
            return -1;
        }
    }//fin if isEmpty

}

void ListaEnlazadaCircularDoble::anular() {
    inicio = ultimo = NULL;
}//**

bool ListaEnlazadaCircularDoble::isEmpty() {
    return inicio == NULL;
}//**

void ListaEnlazadaCircularDoble::insertar(Aerolinea* valor) {
    ptrLista aux, nuevoNodo; //manipula la pila
    aux = inicio;
    nuevoNodo = new(struct nodo); //apuntamos al nuevo nodo creado
    nuevoNodo->elemento = valor;
    if (isEmpty()) {
        aux = nuevoNodo;
        ultimo = nuevoNodo;
        ultimo->sgte = inicio;
        nuevoNodo->sgte = ultimo;
        inicio = aux;
        inicio->ant = ultimo;
    } else {
        nuevoNodo->sgte = aux;
        inicio = nuevoNodo;
        ultimo->sgte = inicio;
        inicio->sgte->ant = inicio;
        inicio->ant = ultimo;
    }
}//**

int ListaEnlazadaCircularDoble::getPosicion(Aerolinea* valor) {
    if (exist(valor)) {
        ptrLista aux = inicio;
        int cont = 1;
        while (aux->elemento != valor) {
            cont++;
            aux = aux->sgte;
        }
        return cont;
    }
    return -1;
}//**

void ListaEnlazadaCircularDoble::borrar(Aerolinea* valor) {
    if (!isEmpty() && exist(valor)) {
        if (inicio == ultimo && inicio->elemento == valor) {//si solo ese elemento existe
            anular();
        } else {

            ptrLista aux;
            aux = inicio;
            ptrLista nuevaLista, nodoSinBorrar, ultimoTemporal;
            nuevaLista = new (struct nodo);
            nuevaLista = NULL;
            if (aux->elemento == valor) {//si está al inicio
                inicio = aux->sgte;
                inicio->ant = ultimo;
                ultimo->sgte = inicio;
                inicio->sgte->ant = ultimo;
            } else {
                nodoSinBorrar = new (struct nodo);
                nodoSinBorrar->elemento = aux->elemento;
                nodoSinBorrar->sgte = nuevaLista;
                nuevaLista = nodoSinBorrar;
                ultimoTemporal = nuevaLista;
                nuevaLista->sgte = ultimoTemporal;
                ultimoTemporal->sgte = nuevaLista;
                nuevaLista->ant = ultimoTemporal;
                ultimoTemporal->ant = nuevaLista;
                aux = aux->sgte;

                while (aux != inicio) {
                    if (aux->elemento != valor) {//lo guarda mientras no coincidan sus valores
                        nodoSinBorrar = new (struct nodo);
                        nodoSinBorrar->elemento = aux->elemento;
                        nodoSinBorrar->sgte = nuevaLista;
                        nuevaLista = nodoSinBorrar;
                        nuevaLista->sgte->ant = nuevaLista;
                        ultimoTemporal->sgte = nuevaLista;
                        nuevaLista->ant = ultimoTemporal;
                    }
                    aux = aux->sgte;
                }
                inicio = nuevaLista;
                ultimo = ultimoTemporal;
                inicio->ant = ultimo;
                invertirLista();
            }

        }
    }//is empty
}//**

bool ListaEnlazadaCircularDoble::exist(Aerolinea* valor) {
    ptrLista aux;
    aux = inicio;
    while (aux->sgte != inicio) {
        if (aux->elemento == valor) return true;
        aux = aux->sgte;
    }
    if (aux->elemento == valor) return true;
    return false;
}//**

Aerolinea* ListaEnlazadaCircularDoble::obtenerAnterior(Aerolinea* aerolinea) {
    if (!isEmpty()) {
        ptrLista aux;
        aux = inicio;
        if (aux->elemento == aerolinea) return aux->ant->elemento;

        aux = aux->sgte;
        while (aux != inicio) {
            if (aux->elemento == aerolinea) return aux->ant->elemento;
            aux = aux->sgte;
        }
    }
}

Aerolinea* ListaEnlazadaCircularDoble::obtenerSiguiente(Aerolinea* aerolinea) {
    if (!isEmpty()) {
        ptrLista aux;
        aux = inicio;
        if (aux->elemento == aerolinea) return aux->sgte->elemento;

        aux = aux->sgte;
        while (aux != inicio) {
            if (aux->elemento == aerolinea) return aux->sgte->elemento;
            aux = aux->sgte;
        }
    }
}

Aerolinea* ListaEnlazadaCircularDoble::firstInlist() {
    return inicio->elemento;
}//**

Aerolinea* ListaEnlazadaCircularDoble::lastInList() {
    return ultimo->elemento;
}//**

void ListaEnlazadaCircularDoble::mostrarValoresLista() {
    if (!isEmpty()) {
        ptrLista aux;
        aux = inicio;

        cout << " <-> [" << aux->elemento->getNombre() << "]";
        aux = aux->sgte;
        while (aux != inicio) {
            cout << " <-> [" << aux->elemento->getNombre() << "]";
            if (aux == ultimo) cout << "<->";
            aux = aux->sgte;
        }
    }
}//**

void ListaEnlazadaCircularDoble::invertirLista() {
    ptrLista aux;
    aux = inicio; //esté fragmento deja la lista de la forma en la cual la encontro y no invertida
    ListaEnlazadaCircularDoble* laux = new ListaEnlazadaCircularDoble();
    laux->insertar(aux->elemento);
    aux = aux->sgte;
    while (aux != inicio) {
        laux->insertar(aux->elemento);
        aux = aux->sgte;
    }
    inicio = laux->inicio;
    ultimo = laux->ultimo;
}