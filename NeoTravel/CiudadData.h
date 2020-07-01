/* 
 * File:   CiudadData.h
 * Author: geraldi
 *
 * Created on 23 de junio de 2020, 03:08 PM
 */

#ifndef CIUDADDATA_H
#define CIUDADDATA_H
#include <iostream>
#include "ListaEnlazadaCircularDoble.h"
#include "Ciudad.h"

class CiudadData {
public:
    static CiudadData* getInstance();
    void agregarCiudad(Ciudad* ciudad);
    ListaEnlazadaCircularDoble<Ciudad>* obtenerListaDeCiudades();
    void eliminarCiudad(Ciudad* ciudad);
    Ciudad* obtenerSiguienteCiudad(Ciudad* ciudad);
    Ciudad* obtenerAnteriorCiudad(Ciudad* ciudad);
    Ciudad* firstInList();
    Ciudad* buscarCiudad(string ciudad);


protected:
    CiudadData();

private:
    static CiudadData* instance;
    ListaEnlazadaCircularDoble<Ciudad>* ListaCiudad = new ListaEnlazadaCircularDoble<Ciudad>;
};

#endif /* CIUDADDATA_H */