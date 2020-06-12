
/* 
 * File:   Cola.cpp
 * Author: alsov
 * 
 * Created on 14 de mayo de 2020, 04:54 PM
 */

#include "Cola.h"
#include "ColaException.h"

Cola::Cola() {
    cola = NULL; //creamos la cola para poder manejarla
    this->contador = 0;
    anterior = posterior = NULL;

}

Cola::Cola(const Cola& orig) {
}

Cola::~Cola() {
}

void Cola::menu() {

    std::cout << "Menu de la Cola" << endl;

    cout << "1. Encolar  " << endl;
    cout << "2. Desencolar " << endl;
    cout << "3. Existe  " << endl;
    cout << "4. Frente " << endl;
    cout << "5. Anular  " << endl;
    cout << "6. Salir  " << endl;

    cout << "Ingrese cualquier opcion: ";
    cout << " " << endl;

}

int Cola::getSize() {


    ptrCola aux = anterior;

    if (isEmpty()) {

        throw new ColaException("Cola vacia");

    }

    int cont = 0;

    while (aux != NULL) {


        cont++;
        aux = aux->sgte;
    }

    return this->contador;



}

bool Cola::isEmpty() {


    return this->anterior == NULL;

}

void Cola::anular() {

    anterior = posterior = NULL;
    //delete cola;

    cout << "La cola no existe" << endl;

}

void Cola::encolar(int salida, int llegada) {

    ptrCola aux;

    aux = new (struct nodo);

    aux->salidaVuelo = salida;
    aux->llegadaVuelo = llegada;

    aux->sgte = NULL;

    // ingreso del primer valor
    if (isEmpty()) {

        //cola->sgte = aux;
        //  anterior = aux;

        anterior = aux;
        posterior = aux;

    } else {

        // posterior->sgte = new (struct nodo);
        //        aux->element = elemento;
        //        aux = aux->sgte;
        //cola->anterior->sgte = aux;

        posterior->sgte = aux;
        posterior = aux;

    }

}

int Cola::desencolar() {


    if (isEmpty()) {

        throw new ColaException("Cola vacia");
        return -1;

    }


    int elementoDesencolar = anterior->salidaVuelo;

    ptrCola borrar = anterior;

    if (anterior == posterior) {

        anterior = NULL;
        posterior = NULL;


    } else {

        anterior = anterior->sgte;


    }

    delete borrar;


    //     elementoDesencolar = anterior->element;
    //    anterior = anterior->sgte;
    //
    //    return elementoADesencolar;
    return elementoDesencolar;
}

bool Cola::existe(int elemento) {

    if (isEmpty()) {

        throw new ColaException("Cola vacia");

    }

    ptrCola aux = anterior;

    while (aux != NULL) {

        if (aux->salidaVuelo == elemento) {

            return true;

        } //fin if

        aux = aux->sgte;

    } //fin while

    return false;

}

int Cola::frente() {

    if (isEmpty()) {

        throw new ColaException("Cola vacia");

    }

    return anterior->salidaVuelo;


}

string Cola::toString() {
    ptrCola recorrido = anterior;
    stringstream s;
    //  cout << "Listado de todos los elementos de la cola.\n";
    while (recorrido != NULL) {
        s << "Salida: " << recorrido->salidaVuelo << " Llegada: " << recorrido->llegadaVuelo << endl;
        recorrido = recorrido->sgte;
    }
    // s << "\n";
    return s.str();
}

void Cola::imprimir() {
    ptrCola recorrido = anterior;
    cout << "Listado de todos los elementos de la cola.\n";
    while (recorrido != NULL) {
        cout << "Salida: " << recorrido->salidaVuelo << " Llegada: " << recorrido->llegadaVuelo << ". Prioridad: " << recorrido->prioridad << endl;
        recorrido = recorrido->sgte;
    }
    cout << "\n";
}

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
                auxSalidaVuelo = aux->salidaVuelo;
                auxLegada = aux->llegadaVuelo;

                aux->prioridad = aux2->prioridad;
                aux->salidaVuelo = aux2->salidaVuelo;
                aux->llegadaVuelo = aux2->llegadaVuelo;

                aux2->prioridad = auxPrioridad;
                aux2->salidaVuelo = auxSalidaVuelo;
                aux2->llegadaVuelo = auxLegada;

            }
            aux2 = aux2->sgte;
        }
        aux = aux->sgte;
    }
}

void Cola::definePrioridad() {

    ptrCola recorrido = anterior;
    cout << "Entra al metodo" << endl;

    while (recorrido != NULL) {

        cout << "entra al while" << endl;
        cout << recorrido->salidaVuelo << endl;

        switch (recorrido->salidaVuelo) {

                cout << "entra al switch" << endl;

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

}