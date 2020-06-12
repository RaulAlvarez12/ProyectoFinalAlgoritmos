
/* 
 * File:   ColaException.h
 * Author: alsov
 *
 * Created on 14 de mayo de 2020, 04:54 PM
 */

#ifndef COLAEXCEPTION_H
#define COLAEXCEPTION_H

#include <iostream>
#include <string>


using namespace std;

class ColaException {
public:
    ColaException();
    ColaException(const string& error);
    virtual ~ColaException();
private:
    string mensajes;
};

#endif /* COLAEXCEPTION_H */

