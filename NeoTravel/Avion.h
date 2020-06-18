/* 
 * File:   Avion.h
 * Author: geraldi
 *
 * Created on 3 de junio de 2020, 04:50 PM
 */

#ifndef AVION_H
#define AVION_H
#include <string>
#include<sstream>

using namespace std;

class Avion {
public:
    Avion(string nombreAvion, int cantidadEspacios, int cantidadVuelos, int horasVuelo);
    Avion();
    virtual ~Avion();
    string getNombreAvion();
    void setNombre(string nombre);
    int getCantidadVuelos();
    void setCantidadVuelos(int vuelos);
    int getHorasVuelo();
    void setHorasVuelo(int horas);
    int getCantidadEspacios();
    void setCantidadEspacios(int espacios);

private:
    string nombreAvion;
    int cantidadEspacios;
    int cantidadVuelos;
    int horasVuelo;
};

#endif /* AVION_H */