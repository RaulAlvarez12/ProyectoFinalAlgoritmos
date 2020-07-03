/* 
 * File:   GrafoListaEnlazada.cpp
 * Author: alsov
 * 
 * Created on 22 de junio de 2020, 10:20 PM
 */

#include "GrafoListaEnlazada.h"

GrafoListaEnlazada::GrafoListaEnlazada() {

    this->vertices = vertices;
    //this->listaAristas = listaAristas;
    this->contador = 0;

}

//GrafoListaEnlazada::GrafoListaEnlazada(vector<Vertice>* vertices, ListaEnlazada<Arista>* listaArista) {
//    this->vertices = vertices;
//    //this->listaAristas = listaArista;
//    this->contador = 0;
//
//}

GrafoListaEnlazada::~GrafoListaEnlazada() {
}

int GrafoListaEnlazada::getSize() {

    return contador;

}

bool GrafoListaEnlazada::isEmpty() {

    if (contador == 0) {

        return true;

    } else {


        return false;
    }

}

void GrafoListaEnlazada::agregarArista(Vertice* v1, Vertice* v2) {

    if (!existeVertice(v1) || !existeVertice(v2)) {
        cout << "No existe algun vertice" << endl;
    } else {

        Arista* a1 = new Arista(v1->getElemento()->getNombre() + " --- " + v2->getElemento()->getNombre(), v1->getPosX(), v1->getPosY(), v2->getPosX(), v2->getPosY());

        vertices[getPosicion(v1)]->listaAristas->insertar(a1);
        // vertices[getPosicion(c2)].listaAristas.insertar(c1);
    }
}

int GrafoListaEnlazada::getPosicion(Vertice* vertice) {

    for (int i = 0; i < this->vertices.size(); i++) {
        if (strcmp(vertices[i]->getElemento()->getNombre().c_str(), vertice->getElemento()->getNombre().c_str()) == 0) { //  comparar los elementos del vector con el que se busca
            return i;
        }
    }
    return -1;

}

void GrafoListaEnlazada::agregarVertice(Vertice* v1) {


    this->vertices.push_back(v1);
    contador++;

}

void GrafoListaEnlazada::anular() {

}

void GrafoListaEnlazada::borrarArista(Arista* arista) {

    //this->listaAristas->borrarValor(arista);

}

bool GrafoListaEnlazada::existeArista(Arista* arista) {






}

bool GrafoListaEnlazada::existeVertice(Vertice* vertice) {

    //  if (isEmpty()) {
    //     throw new GrafoException("No existe grafo en el cual buscar");
    // }


    for (int i = 0; i < this->vertices.size(); i++) {
        if (strcmp(vertices[i]->getElemento()->getNombre().c_str(), vertice->getElemento()->getNombre().c_str()) == 0) { //  comparar los elementos del vector con el que se busca
            return true;
        }
    }


    return false;
}

int GrafoListaEnlazada::getX() {
    return this->x;
}

int GrafoListaEnlazada::getY() {
    return this->y;
}

void GrafoListaEnlazada::setX(int x) {
    this->x = x;
}

void GrafoListaEnlazada::setY(int y) {
    this->y = y;
}

ListaEnlazada<Arista>* GrafoListaEnlazada::getAristas() {

    //  return this->listaAristas;

}

void GrafoListaEnlazada::setAristas(ListaEnlazada<Arista>* listaAristas) {

    //->listaAristas = listaAristas;

}

vector<Vertice*> GrafoListaEnlazada::getVertices() {

    return this->vertices;

}

void GrafoListaEnlazada::setVertices(vector<Vertice*> vertices) {

    this->vertices = vertices;

}

void GrafoListaEnlazada::borrarVertice(Vertice* vertice) {
    vector<Vertice*> aux;
    while (!this->vertices.empty()) {
        if (strcmp(this->vertices.back()->getElemento()->getNombre().c_str(), vertice->getElemento()->getNombre().c_str()) == 0) {
            cout << "Elemento por BORRAR DEL VECTOR ORIGINAL: " << this->vertices.back()->toString() << endl;
            this->vertices.pop_back();
        } else {
            cout << "Elemento por guardar en el aux: " << this->vertices.back()->toString() << endl;
            aux.push_back((Vertice*)this->vertices.back());
            this->vertices.pop_back();
        }
    }
    while (!aux.empty()) {
        this->vertices.push_back((Vertice*)aux.back());
        aux.pop_back();
    }
}

string GrafoListaEnlazada::toString() {

    stringstream salida;
    salida << "INFORMACION DEL GRAFO \n ";
    salida << "con lista de adyacencia \n";
    salida << "------------------------\n";

    for (int i = 0; i < vertices.size(); i++)
        salida << "el vertice en la pocicion " << i << " es: " << vertices[i]->getElemento()->toString() << "\n";

    salida << "aristas del grafo\n\n";
    for (int i = 0; i < vertices.size(); i++) {
        salida << "Vertice: " << vertices[i]->getElemento()->toString() << "\n";
        salida << "-----Aristas: " << vertices[i]->listaAristas->toString() << "\n";
        //          if(vertices[i].listaAristas.getNodo(1).elemento!=vertices[i].listaPesos.getNodo(1).elemento)
        salida << "--------------------------------\n\n";
    }//for


    salida << "\n";
    return salida.str();

}//fin to String