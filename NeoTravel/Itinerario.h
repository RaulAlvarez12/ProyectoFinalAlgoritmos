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

using namespace std;

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

    vector<Cola*> colasPrioridad; //Tiene todos los horarios, en otras palabras es el itinerario del vuelo
    
    //Metodos del Data
    string obtenerStringHorario(int indice); // muestra el string ordenado de la cola en el indice que le indique 
    vector<Cola*> obtenerItinerario();
    void agregarItinerario();
    
private:

    //    int salida;
    //    int llegada;
    
protected:
    
    Cola* cola1;
    Cola* cola2;
    Cola* cola3;
    Cola* cola4;
    Cola* cola5;
};

#endif /* ITINERARIO_H */