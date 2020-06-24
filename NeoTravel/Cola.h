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

#include "Horario.h"

using namespace std;

class Cola {

    struct nodo {
        Horario *horario;
        int prioridad;
        struct nodo *sgte;
        struct nodo *anterior;
    };

    typedef nodo *ptrCola; // creando nodo tipo puntero (tipo de dato)

public:
    Cola();
    virtual ~Cola();
    int getSize();
    void anular();
    bool isEmpty();
    Horario* frente();
    void encolar(Horario* horario);
    Horario* desencolar();
    bool existe(Horario* horario);
    void definePrioridad();
    void valoresPrioridad(ptrCola cola);
    void ordenarPrioridad();
    string toString();
    ptrCola cola;
    Horario* obtenerSiguienteHorario(Horario* horario);
    Horario* obtenerAnteriorHorario(Horario* horario);
    void eliminar(Horario* horario);
    

private:

    int contador;
    nodo* anterior;
    nodo* posterior;
};

#endif /* COLA_H */