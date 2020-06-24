/* 
 * File:   Aerolinea.h
 * Author: geraldi
 *
 * Created on 3 de junio de 2020, 04:50 PM
 */

#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <string>
#include <sstream>
#include <vector>

#include "Vuelo.h"
#include "VueloData.h"

using namespace std;

class Aerolinea {
public:
    Aerolinea(string nombre);
    Aerolinea();
    virtual ~Aerolinea();
    string getNombre();
    string toString();
    VueloData* vueloData;
    void setNombre(string nombre);
private:
    string nombreAerolinea;
    //vector<Vuelo*> vuelos;
    
    
};

#endif /* AEROLINEA_H */