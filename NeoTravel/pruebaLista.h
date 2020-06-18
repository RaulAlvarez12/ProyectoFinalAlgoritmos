/* 
 * File:   prueba.h
 * Author: geraldi
 *
 * Created on 7 de junio de 2020, 05:51 PM
 */

#ifndef PRUEBALISTA_H
#define PRUEBALISTA_H

#include "AerolineaData.h"
#include <iostream>

using namespace std;

class pruebaLista {
public:

    prueba() {

        //    Aerolinea* a1 = new Aerolinea("nombre");
        //    ad->getInstance()->agregarAerolinea(a1);

        //         ad = new AerolineaData();
        ad->mostrar();
        ListaEnlazadaCircularDoble* test = ad->obtenerListaDeAerolineas();
        cout << "\n\n está vacia:" << test->isEmpty() << endl;
        //    cout<<"\n Elemento:"<<test->inicio->elemento->getNombre()<<endl;
        //    cout<<"\n Elemento:"<<test->inicio->sgte->elemento->getNombre()<<endl;
        //    cout<<"\n Elemento:"<<test->inicio->sgte->sgte->elemento->getNombre()<<endl;
        //    cout<<"\n Elemento:"<<test->inicio->sgte->sgte->sgte->elemento->getNombre()<<endl;
        //    cout<<"\n Elemento:"<<test->inicio->sgte->sgte->sgte->sgte->elemento->getNombre()<<endl;
        //    cout<<"\n Elemento:"<<test->inicio->sgte->sgte->sgte->sgte->sgte->elemento->getNombre()<<endl;
    }//prueba
    AerolineaData* ad;
};

#endif /* PRUEBA_H */