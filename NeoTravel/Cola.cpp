/* 
 * File:   Cola.cpp
 * Author: alsov
 * 
 * Created on 14 de mayo de 2020, 04:54 PM
 */

#include "Cola.h"

Cola::Cola() {
    cola = NULL; //creamos la cola para poder manejarla
    this->contador = 0;
    anterior = posterior = NULL;

}

Cola::~Cola() {
}

int Cola::getSize() {

    ptrCola aux = anterior;

    if (isEmpty()) {
        cout << "La cola esta vacia." << endl;
    }

    int cont = 0;
    while (aux != NULL) {

        cont++;
        aux = aux->sgte;
    }
    return this->contador;
}//getSize

bool Cola::isEmpty() {
    return this->anterior == NULL;
}//isEmpty

void Cola::anular() {
    anterior = posterior = NULL;
    //delete cola;
}//anular

void Cola::encolar(Horario* horario) {

    ptrCola aux;
    aux = new (struct nodo);
    aux->horario = horario;
    aux->sgte = NULL;

    // ingreso del primer valor
    if (isEmpty()) {
        anterior = aux;
        posterior = aux;
    } else {
        posterior->sgte = aux;
        posterior = aux;
    }
    definePrioridad();
    ordenarPrioridad();
}//encolar

Horario* Cola::desencolar() {

    if (isEmpty()) {
        cout << "La cola esta vacia." << endl;
    }

    Horario* horarioDesencolar = anterior->horario;
    ptrCola borrar = anterior;

    if (anterior == posterior) {
        anterior = NULL;
        posterior = NULL;
    } else {
        anterior = anterior->sgte;
    }
    delete borrar;

    return horarioDesencolar;
}//desencolar

bool Cola::existe(Horario* horario) {

    if (isEmpty()) {
        cout << "La cola esta vacia." << endl;
    }

    ptrCola aux = anterior;
    while (aux != NULL) {
        if (aux->horario->getHoraLlegada() == horario->getHoraLlegada() && aux->horario->getHoraSalida() == horario->getHoraSalida()) {
            return true;
        } //fin if

        aux = aux->sgte;

    } //fin while

    return false;
}//existe

Horario* Cola::frente() {

    if (isEmpty()) {
        cout << "La cola esta vacia." << endl;
    }
    return anterior->horario;
}//frente

string Cola::toString() {
    ptrCola recorrido = anterior;
    stringstream s;
    while (recorrido != NULL) {
        s << recorrido->horario->toString() << "\n";
        recorrido = recorrido->sgte;
    }
    return s.str();
}//toString

void Cola::ordenarPrioridad() {

    ptrCola aux;
    ptrCola aux2;
    aux = new (struct nodo);
    aux2 = new (struct nodo);

    int auxSalidaVuelo;
    int auxPrioridad;
    int auxLegada;

    aux = anterior;

    while (aux->sgte != NULL) {

        aux2 = aux->sgte;

        while (aux2 != NULL) {

            if (aux->prioridad > aux2->prioridad) {

                auxPrioridad = aux->prioridad;
                auxSalidaVuelo = aux->horario->getHoraSalida();
                auxLegada = aux->horario->getHoraLlegada();

                aux->prioridad = aux2->prioridad;
                aux->horario->setHoraSalida(aux2->horario->getHoraSalida());
                aux->horario->setHoraLlegada(aux2->horario->getHoraLlegada());

                aux2->prioridad = auxPrioridad;
                aux2->horario->setHoraSalida(auxSalidaVuelo);
                aux2->horario->setHoraLlegada(auxLegada);
            }
            aux2 = aux2->sgte;
        }
        aux = aux->sgte;
    }
}//ordenarPrioridad

void Cola::definePrioridad() {

    ptrCola recorrido = anterior;

    while (recorrido != NULL) {

        switch (recorrido->horario->getHoraSalida()) {

            case 1:
                recorrido->prioridad = 1;
                break;

            case 2:
                recorrido->prioridad = 2;
                break;

            case 3:
                recorrido->prioridad = 3;
                break;

            case 4:
                recorrido->prioridad = 4;
                break;

            case 5:
                recorrido->prioridad = 5;
                break;

            case 6:
                recorrido->prioridad = 6;
                break;

            case 7:
                recorrido->prioridad = 7;
                break;

            case 8:
                recorrido->prioridad = 8;
                break;

            case 9:
                recorrido->prioridad = 9;
                break;

            case 10:
                recorrido->prioridad = 10;
                break;
            case 11:
                recorrido->prioridad = 11;
                break;

            case 12:
                recorrido->prioridad = 12;
                break;

            case 13:
                recorrido->prioridad = 13;
                break;

            case 14:
                recorrido->prioridad = 14;
                break;

            case 15:
                recorrido->prioridad = 15;
                break;

            case 16:
                recorrido->prioridad = 16;
                break;

            case 17:
                recorrido->prioridad = 17;
                break;

            case 18:
                recorrido->prioridad = 18;
                break;

            case 19:
                recorrido->prioridad = 19;
                break;

            case 20:
                recorrido->prioridad = 20;
                break;

            case 21:
                recorrido->prioridad = 21;
                break;

            case 22:
                recorrido->prioridad = 22;
                break;

            case 23:
                recorrido->prioridad = 23;
                break;

            case 24:
                recorrido->prioridad = 24;
                break;
        }
        recorrido = recorrido->sgte;
    }
}//definePrioridad

Horario* Cola::obtenerAnteriorHorario(Horario* horario) {
    if(horario==anterior->horario){
        return posterior->horario;
    }else {
        Horario* horarioAux;
        Cola* colaAux = new Cola();
        Horario* horarioAnterior = new Horario(0,0);
        while(!isEmpty()){
            horarioAux = desencolar();
            if(horario==horarioAux){
                horarioAnterior=colaAux->posterior->horario;
                
            }
            colaAux->encolar(horarioAux);
            
        }
        while(!colaAux->isEmpty()){
            encolar(colaAux->desencolar());
        }
        
        
        return horarioAnterior;
    }
}

Horario* Cola::obtenerSiguienteHorario(Horario* horario) {
   
    if(horario==posterior->horario){
        return anterior->horario;
    }else{
        Horario* horarioAux;
        Cola* colaAux = new Cola();
        Horario* horarioSiguiente = new Horario(0,0);
        while(!isEmpty()){
            horarioAux = desencolar();
            colaAux->encolar(horarioAux);
            if(horario==horarioAux){
                horarioSiguiente=desencolar();
                colaAux->encolar(horarioSiguiente);
            }
            
        }
        while(!colaAux->isEmpty()){
            encolar(colaAux->desencolar());
        }
        
        return horarioSiguiente;
    }
    
}

void Cola::eliminar(Horario* horario) {

        Horario* horarioAux;
        Cola* colaAux = new Cola();
        while(!isEmpty()){
            horarioAux = desencolar();
            if(horario!=horarioAux){
              colaAux->encolar(horarioAux);
            }
            
            
        }
        while(!colaAux->isEmpty()){
            encolar(colaAux->desencolar());
        }
        
    }

