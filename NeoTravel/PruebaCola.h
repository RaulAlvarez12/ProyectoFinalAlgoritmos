
/* 
 * File:   Prueba.h
 * Author: alsov
 *
 * Created on 11 de junio de 2020, 05:38 PM
 */

#ifndef PRUEBACOLA_H
#define PRUEBACOLA_H

#include "Cola.h"
#include "ItinerarioData.h"

class PruebaCola {
public:

    void test() {


        //        cola.encolar(22, 24);
        //        cola.encolar(8, 13);
        //        cola.encolar(13, 15);
        //        // cola.encolar(18, 21);
        //        //        cola.encolar(4, 7);
        //
        //        //        cola.encolar(1, 3);
        //
        //        cola.imprimir();
        //
        //        cout << "Definiendo Prioridad...." << endl;
        //
        //        cola.definePrioridad();
        //
        //        cout << "Mostrando las prioridades de los elementos: " << endl;
        //
        //        cola.imprimir();
        //
        //        cout << "Ordenando por prioridad..." << endl;
        //
        //        cola.ordenarPrioridad();
        //
        //        cola.imprimir();
        //
        //
        //        cout << "Mostrando valores de la cola de prioridad ordenada: " << endl;
        //        cout << cola.toString() << endl;


        // PROBANDO EL ITINERARIODATA....


        itinerarioData = new ItinerarioData();




        //        cout << "Mostrando horario de la Cola1 : " << itinerarioData.obtenerStringHorario(1) << endl;

        cout << "Mostrando horario de la Cola1 : " << endl;
        cout << itinerarioData->obtenerStringHorario(0) << endl;


        cout << "Mostrando horario de la Cola2: " << endl;
        cout << itinerarioData->obtenerStringHorario(1) << endl;


        cout << "Mostrando horario de la Cola3 : " << endl;
        cout << itinerarioData->obtenerStringHorario(2) << endl;





    }



private:

    Cola cola;
    ItinerarioData* itinerarioData;

};

#endif /* PRUEBA_H */

