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
    virtual ~Ciudad();
    string getNombre();
    void setNombre(string nombre);
    string toString();

private:
    string nombre;
};

#endif /* CIUDAD_H */