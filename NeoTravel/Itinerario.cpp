/* 
 * File:   Itinerario.cpp
 * Author: alsov
 * 
 * Created on 11 de junio de 2020, 01:51 PM
 */

#include "Itinerario.h"

Itinerario::Itinerario() {
    cola1 = new Cola();
    cola2 = new Cola();
    cola3 = new Cola();

    cola1->encolar(8, 13);
    cola1->encolar(22, 24);
    cola1->encolar(18, 21);

    cola2->encolar(4, 7);
    cola2->encolar(13, 15);
    cola2->encolar(1, 3);

    cola3->encolar(5, 8);
    cola3->encolar(12, 14);
    cola3->encolar(19, 22);

    //    cola1->definePrioridad();
    //    cola2->definePrioridad();
    //    cola3->definePrioridad();
    //  cola4->definePrioridad();
//
//          itinerario->colasPrioridad.push_back(cola1);
//         itinerario->colasPrioridad.push_back(cola2);
//         itinerario->colasPrioridad.push_back(cola3);

    this->agregaCola(cola1);
    this->agregaCola(cola2);
    this->agregaCola(cola3);
}

Itinerario::~Itinerario() {
}

vector<Cola*> Itinerario::GetColas() {

    return this->colasPrioridad;

}

void Itinerario::agregaCola(Cola* cola) {

    this->colasPrioridad.push_back(cola);

}

//*******************Metodos del Data*****************************
vector<Cola*> Itinerario::obtenerItinerario() {

    this->GetColas();

}

string Itinerario::obtenerStringHorario(int indice) {

    //cola->ordenarPrioridad();

    //   return cola->toString();
    for (int i = 0; i < this->colasPrioridad.size(); i++) {

        if (i == indice) {

            this->colasPrioridad[i]->ordenarPrioridad();

            return this->colasPrioridad[i]->toString();

        }

    }

}

