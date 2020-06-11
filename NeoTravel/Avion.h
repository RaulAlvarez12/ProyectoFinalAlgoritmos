/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    Avion(string nombreAvion,int cantVuelos,float horasVuelo);
    Avion(const Avion& orig);
    virtual ~Avion();
    string getNombreAvion();
    void setNombre(string nombre);
    int getCantVuelos();
    void setCantVuelos(int vuelos);
    float getHorasVuelo();
    void setHorasVuelo(float horas);
    
private:
    string nombreAvion;
    int cantVuelos;
    float horasVuelo;
};

#endif /* AVION_H */

