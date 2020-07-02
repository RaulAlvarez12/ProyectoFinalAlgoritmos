
/* 
 * File:   Vertice.cpp
 * Author: alsov
 * 
 * Created on 22 de junio de 2020, 10:20 PM
 */

#include "Vertice.h"

//template <typename T>

Vertice::Vertice(Ciudad* ciudad) {

    this->ciudad = ciudad;
    this->posX = 0;
    this->posY = 0;
    this->visitado = false;

}

//template <typename T>

Vertice::Vertice(Ciudad* ciudad, int posX, int posY) {

    this->ciudad = ciudad;
    this->posX = posX;
    this->posY = posY;
    this->visitado = false;

}

//template <typename T>

Vertice::~Vertice() {
}

//template <typename T>

void Vertice::setElemento(Ciudad* ciudad) {
    this->ciudad = ciudad;
}

Ciudad* Vertice::getElemento() {

    return this->ciudad;
}


//template <typename T>

int Vertice::getPosX() {
    return posX;
}

//template <typename T>

void Vertice::setPosX(int posX) {
    this->posX = posX;
}

//template <typename T>

int Vertice::getPosY() {
    return posY;
}

//template <typename T>

void Vertice::setPosY(int posY) {
    this->posY = posY;
}

//template <typename T>

bool Vertice::isVisitado() {
    return visitado;
}

//template <typename T>

void Vertice::setVisitado(bool visitado) {
    this->visitado = visitado;
}

//template <typename T>

void Vertice::draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    cr->arc(this->posX, this->posY, 12.0, 0.0, 5 * M_PI);
    cr->stroke();

}