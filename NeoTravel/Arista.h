
/* 
 * File:   Arista.h
 * Author: alsov
 *
 * Created on 22 de junio de 2020, 10:20 PM
 */

#ifndef ARISTA_H
#define ARISTA_H

#include <unistd.h>
#include <cairomm-1.0/cairomm/refptr.h>
#include <cairomm-1.0/cairomm/context.h>

#include <string.h>
#include <sstream>

using namespace std;

class Arista {
public:

    Arista();
    Arista(string nombre, int posX1, int posY1, int posX2, int posY2);
    virtual ~Arista();
    string getNombre();
    void setNombre(string nombre);
    int getPosX1();
    void setPosX1(int posX1);
    int getPosX2();
    void setPosX2(int posX2);
    int getPosY1();
    void setPosY1(int posY1);
    int getPosY2();
    void setPosY2(int posY2);
    string toString();
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);


private:

    string nombre;

    // se necesitan las coordenadas X Y de los vertices para conectarlos
    int posX1;
    int posX2;
    int posY1;
    int posY2;



};

#endif /* ARISTA_H */

