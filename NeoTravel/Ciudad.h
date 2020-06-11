/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ciudad.h
 * Author: geraldi
 *
 * Created on 3 de junio de 2020, 04:50 PM
 */

#ifndef CIUDAD_H
#define CIUDAD_H
#include <string>
#include <sstream>

using namespace std;
class Ciudad {
public:
    Ciudad(string nombre);
    Ciudad(const Ciudad& orig);
    virtual ~Ciudad();
    
    
    string getNombre();
    void setNombre(string nombre);
    string toString();
private:
    string nombre;
};

#endif /* CIUDAD_H */

