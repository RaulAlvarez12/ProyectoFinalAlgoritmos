/* 
 * File:   GrafoListaEnlazada.h
 * Author: alsov
 *
 * Created on 22 de junio de 2020, 10:20 PM
 */

#ifndef GRAFOLISTAENLAZADA_H
#define GRAFOLISTAENLAZADA_H

#include "Vertice.h"
#include "ListaEnlazada.h"
#include "Arista.h"
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

class GrafoListaEnlazada {
public:
    GrafoListaEnlazada();
    // GrafoListaEnlazada(vector<Vertice>* vertices, ListaEnlazada<Arista>* listaArista);
    virtual ~GrafoListaEnlazada();

    //metodos propios del grafo
    //////////////////////////////////////////////
    void agregarArista(Vertice* v1, Vertice* v2); //*************
    void agregarVertice(Vertice* v1); //**********
    void anular();
    bool existeVertice(Vertice* vertice);
    bool existeArista(Arista* arista);
    void borrarArista(Arista* arista);
    void borrarVertice(Vertice* vertice);
    bool isEmpty();
    int getPosicion(Vertice* vertice);
    string toString();
    int getSize();

    //////////////////////////////////////////////

    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    vector<Vertice*> getVertices();
    void setVertices(vector<Vertice*> vertices);
    ListaEnlazada<Arista>* getAristas();
    void setAristas(ListaEnlazada<Arista>* listaAristas);

private:

    vector<Vertice*> vertices;
    //ListaEnlazada<Arista>* listaAristas = new ListaEnlazada<Arista>;
    int x;
    int y;
    int contador;

};

#endif /* GRAFOLISTAENLAZADA_H */