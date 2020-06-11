/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: geraldi
 *
 * Created on 3 de junio de 2020, 04:49 PM
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include<sstream>
using namespace std;

class Usuario {
public:
    Usuario(string nombre,int edad,string genero,int numPasaporte, string nacionalidad);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    
    string getNombre();
    void setNombre(string nombre);
    int getEdad();
    void setEdad(int edad);
    string getGenero();
    void setGenero(string genero);
    int getNumeroPasaporte();
    void setNumeroPasaporte(int numeroPasaporte);
    string getNacionalidad();
    void setNacionalidad(string nacionalidad);
    string toString();
    
private:
    string nombre;
    int edad;
    string genero;
    int  numeroPasaporte;
    string nacionalidad;
};

#endif /* USUARIO_H */

