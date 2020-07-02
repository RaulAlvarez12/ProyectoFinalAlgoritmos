
/* 
 * File:   Vertice.h
 * Author: alsov
 *
 * Created on 22 de junio de 2020, 10:20 PM
 */

#ifndef VERTICE_H
#define VERTICE_H

#include <unistd.h>
#include <cairomm-1.0/cairomm/refptr.h>
#include <cairomm-1.0/cairomm/context.h>

#include "Ciudad.h"
#include "ListaEnlazadaCircularDoble.h"
#include "Arista.h"


using namespace std;

//template <typename T>

class Vertice {
public:
    Vertice(Ciudad* ciudad);
    Vertice(Ciudad* ciudad, int posX, int posY);
    virtual ~Vertice();
    Ciudad* getElemento();
    void setElemento(Ciudad* ciudad);
    int getPosX();
    void setPosX(int posX);
    int getPosY();
    void setPosY(int posY);
    bool isVisitado();
    void setVisitado(bool visitado);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    string toString();

    ListaEnlazadaCircularDoble<Arista>* listaAristas = new ListaEnlazadaCircularDoble<Arista>;

private:

    Ciudad* ciudad;
    int posX;
    int posY;
    bool visitado;


};

#endif /* VERTICE_H */

