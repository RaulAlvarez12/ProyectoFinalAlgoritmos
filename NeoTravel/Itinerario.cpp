/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.cpp
 * Author: alsov
 * 
 * Created on 11 de junio de 2020, 01:51 PM
 */

#include "Itinerario.h"

Itinerario::Itinerario() {
}

Itinerario::~Itinerario() {
}

vector<Cola*> Itinerario::GetColas() {

    return this->colasPrioridad;

}

void Itinerario::agregaCola(Cola* cola) {

    this->colasPrioridad.push_back(cola);

}