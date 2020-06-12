
/* 
 * File:   Cola.h
 * Author: alsov
 *
 * Created on 14 de mayo de 2020, 04:54 PM
 */

#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Cola {

    struct nodo {
        int salidaVuelo;
        int llegadaVuelo;
        int prioridad;
        struct nodo *sgte;
        struct nodo *anterior;

    };

    typedef nodo *ptrCola; // creando nodo tipo puntero (tipo de dato)


public:
    Cola();
    Cola(const Cola& orig);
    virtual ~Cola();

    int getSize();
    void anular();
    bool isEmpty();
    int frente();
    void encolar(int salida, int llegada);
    int desencolar();
    bool existe(int salida);
    void menu();
    void imprimir();
    void definePrioridad();
    void valoresPrioridad(ptrCola cola);
    void ordenarPrioridad();
    string toString();
    ptrCola cola;

private:

    int contador;
    nodo* anterior;
    nodo* posterior;


};

#endif /* COLA_H */

