
/* 
 * File:   Arista.cpp
 * Author: alsov
 * 
 * Created on 22 de junio de 2020, 10:20 PM
 */

#include "Arista.h"

Arista::Arista(string nombre, int posX1, int posY1, int posX2, int posY2) {

    this->nombre = nombre;
    this->posX1 = posX1;
    this->posX2 = posX2;
    this->posY1 = posY1;
    this->posY2 = posY2;

}

Arista::Arista() {

    this->nombre = "";
    this->posX1 = 0;
    this->posX2 = 0;
    this->posY1 = 0;
    this->posY2 = 0;

}

Arista::~Arista() {
}

string Arista::getNombre() {
    return nombre;
}

void Arista::setNombre(string nombre) {
    this->nombre = nombre;
}

int Arista::getPosX1() {
    return posX1;
}

void Arista::setPosX1(int posX1) {
    this->posX1 = posX1;
}

int Arista::getPosX2() {
    return posX2;
}

void Arista::setPosX2(int posX2) {
    this->posX2 = posX2;
}

int Arista::getPosY1() {
    return posY1;
}

void Arista::setPosY1(int posY1) {
    this->posY1 = posY1;
}

int Arista::getPosY2() {
    return posY2;
}

void Arista::setPosY2(int posY2) {
    this->posY2 = posY2;
}

string Arista::toString() {

    stringstream s;

    s << this->nombre;

    return s.str();

}

void Arista::draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    cr->set_line_width(5.0);

    cr->line_to(this->posY1 + 25, this->posX2 + 25);
    cr->stroke();


}