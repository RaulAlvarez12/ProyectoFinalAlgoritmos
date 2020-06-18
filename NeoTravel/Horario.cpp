/* 
 * File:   Horario.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 02:00 PM
 */

#include "Horario.h"

Horario::Horario(int horaSalida, int horaLlegada) {
    this->horaSalida = horaSalida;
    this->horaLlegada = horaLlegada;
}

Horario::~Horario() {
}

int Horario::getHoraLlegada() {
    return this->horaLlegada;
}

void Horario::setHoraLlegada(int llegada) {
    this->horaLlegada = llegada;
}

int Horario::getHoraSalida() {
    return this->horaSalida;
}

void Horario::setHoraSalida(int salida) {
    this->horaSalida = salida;
}

string Horario::toString() {
    stringstream s;
    s << "Salida: " << this->horaSalida << ", Llegada: " << this->horaLlegada;
    return s.str();
}