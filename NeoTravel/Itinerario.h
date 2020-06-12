/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.h
 * Author: alsov
 *
 * Created on 11 de junio de 2020, 01:51 PM
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H

#include <vector>
#include "Cola.h"

class Itinerario {
public:
    Itinerario();
    // Itinerario(int salida, int llegada);
  //  Itinerario(const Itinerario& orig);
    virtual ~Itinerario();

    //  int GetSalida();
    // void SetSalida(int salida);
    //  int GetLlegada();
    //  void SetLlegada(int llegada);
    vector<Cola*> GetColas();
    //void SetCola(Cola* cola);
    void agregaCola(Cola* cola); // agrega una nueva cola al vector

    vector<Cola*> colasPrioridad;
    
private:

    //    int salida;
    //    int llegada;
protected:



};

#endif /* ITINERARIO_H */

