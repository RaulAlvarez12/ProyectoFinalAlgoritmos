
/* 
 * File:   ItinerarioData.cpp
 * Author: alsov
 * 
 * Created on 11 de junio de 2020, 09:03 PM
 */

#include "ItinerarioData.h"
#include "Itinerario.h"
#include "Cola.h"

ItinerarioData::ItinerarioData() {


    cola1 = new Cola();
    cola2 = new Cola();
    cola3 = new Cola();
    
    itinerario = new Itinerario();


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

    itinerario->agregaCola(cola1);
    itinerario->agregaCola(cola2);
    itinerario->agregaCola(cola3);


}

//void ItinerarioData::agregarHorario(int salida, int llegada) {
//
//
//    //   cola->encolar(salida, llegada);
//
//
//}

void ItinerarioData::agregarItinerario() {


//    itinerario->agregaCola(cola1);
//    itinerario->agregaCola(cola2);
//    itinerario->agregaCola(cola3);



}

vector<Cola*> ItinerarioData::obtenerItinerario() {

    itinerario->GetColas();

}

//Cola* ItinerarioData::obtenerCola(int indice){
//    
//    Cola* auxCola;
//    
//    for (int i =0; i<itinerario->colasPrioridad.size();i++){
//        
//        if(i == indice){
//            
//            auxCola = itinerario->colasPrioridad.
//            
//        }
//        
//        
//    }
//    
//    
//    
//    
//}

//void ItinerarioData::mostrarOrdenado() {
//
//    //    cola->ordenarPrioridad();
//
//    //   cola->imprimir();
//
//
//}

string ItinerarioData::obtenerStringHorario(int indice) {

    //cola->ordenarPrioridad();

    //   return cola->toString();

    for (int i = 0; i < itinerario->colasPrioridad.size(); i++) {

        if (i == indice) {

            itinerario->colasPrioridad[i]->ordenarPrioridad();

            return itinerario->colasPrioridad[i]->toString();

        }

    }

}

ItinerarioData::~ItinerarioData() {
}

