/* 
 * File:   Horario.h
 * Author: geraldi
 *
 * Created on 11 de junio de 2020, 02:00 PM
 */

#ifndef HORARIO_H
#define HORARIO_H

#include <string.h>
#include "Avion.h"

using namespace std;

class Horario {
public:
    Horario(int horaSalida, int horaLlegada);
    virtual ~Horario();
    int getHoraSalida();
    void setHoraSalida(int salida);
    int getHoraLlegada();
    void setHoraLlegada(int llegada);
    string toString();

private:
    int horaSalida;
    int horaLlegada;
};

#endif /* HORARIO_H */