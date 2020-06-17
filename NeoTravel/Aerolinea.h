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

#include "Vuelo.h"

using namespace std;
class Aerolinea {
public:
    Aerolinea(string nombre);
    Aerolinea(const Aerolinea& orig);
    virtual ~Aerolinea();
    string getNombre();
    vector<Vuelo*> getVuelos();
    void setVuelo(Vuelo* vuelo);
    string toString();
private:
    string nombreAerolinea;
    
    vector<Vuelo*> vuelos;

};

#endif /* AEROLINEA_H */