/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

using namespace std;
class Aerolinea {
public:
    Aerolinea(string nombre);
    Aerolinea(const Aerolinea& orig);
    virtual ~Aerolinea();
    
    string getNombre();
private:
    string nombreCiudad;

};

#endif /* AEROLINEA_H */

