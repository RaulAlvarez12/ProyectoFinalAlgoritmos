/* 
 * File:   ListaEnlazadaCircularDoble.h
 * Author: geral
 *
 * Created on 20 de mayo de 2020, 03:34 PM
 */

#ifndef LISTAENLAZADACIRCULARDOBLE_H
#define LISTAENLAZADACIRCULARDOBLE_H

#include <string.h>

using namespace std;

template <typename T>
class ListaEnlazadaCircularDoble {
    
    struct nodo {
        T* elemento;
        struct nodo *sgte; //apuntador al nodo SIGUIENTE
        struct nodo *ant; //apuntador al nodo Anterior
    };
    typedef nodo *ptrLista; //creando nodo tipo puntero(tipo de dato)
public:

    ListaEnlazadaCircularDoble() {
        this->inicio = this->ultimo = NULL;
    }

    ~ListaEnlazadaCircularDoble() {
    }

    int getSize() {
        if (!isEmpty()) {
            ptrLista aux;
            aux = inicio;
            int con = 1;
            if (!isEmpty()) {
                while (aux->sgte != inicio) {
                    con++;
                    aux = aux->sgte;


                }
                return con;
            } else {
                return -1;
            }
        }//fin if isEmpty

    }

    void anular() {
        inicio = ultimo = NULL;
    }//**

    bool isEmpty() {
        return inicio == NULL;
    }//**

    void insertar(T* valor) {
        ptrLista aux, nuevoNodo; //manipula la pila
        aux = inicio;
        nuevoNodo = new(struct nodo); //apuntamos al nuevo nodo creado
        nuevoNodo->elemento = valor;
        if (isEmpty()) {
            aux = nuevoNodo;
            ultimo = nuevoNodo;
            ultimo->sgte = inicio;
            nuevoNodo->sgte = ultimo;
            inicio = aux;
            inicio->ant = ultimo;
        } else {
            nuevoNodo->sgte = aux;
            inicio = nuevoNodo;
            ultimo->sgte = inicio;
            inicio->sgte->ant = inicio;
            inicio->ant = ultimo;
        }
    }//**

    int getPosicion(T* valor) {
        if (exist(valor)) {
            ptrLista aux = inicio;
            int cont = 1;
            while (aux->elemento != valor) {
                cont++;
                aux = aux->sgte;
            }
            return cont;
        }
        return -1;
    }//**

    void borrar(T* valor) {
        if (!isEmpty() && exist(valor)) {
            if (inicio == ultimo && inicio->elemento == valor) {//si solo ese elemento existe
                anular();
            } else {

                ptrLista aux;
                aux = inicio;
                ptrLista nuevaLista, nodoSinBorrar, ultimoTemporal;
                nuevaLista = new (struct nodo);
                nuevaLista = NULL;
                if (aux->elemento == valor) {//si está al inicio
                    inicio = aux->sgte;
                    inicio->ant = ultimo;
                    ultimo->sgte = inicio;
                    inicio->sgte->ant = ultimo;
                } else {
                    nodoSinBorrar = new (struct nodo);
                    nodoSinBorrar->elemento = aux->elemento;
                    nodoSinBorrar->sgte = nuevaLista;
                    nuevaLista = nodoSinBorrar;
                    ultimoTemporal = nuevaLista;
                    nuevaLista->sgte = ultimoTemporal;
                    ultimoTemporal->sgte = nuevaLista;
                    nuevaLista->ant = ultimoTemporal;
                    ultimoTemporal->ant = nuevaLista;
                    aux = aux->sgte;

                    while (aux != inicio) {
                        if (aux->elemento != valor) {//lo guarda mientras no coincidan sus valores
                            nodoSinBorrar = new (struct nodo);
                            nodoSinBorrar->elemento = aux->elemento;
                            nodoSinBorrar->sgte = nuevaLista;
                            nuevaLista = nodoSinBorrar;
                            nuevaLista->sgte->ant = nuevaLista;
                            ultimoTemporal->sgte = nuevaLista;
                            nuevaLista->ant = ultimoTemporal;
                        }
                        aux = aux->sgte;
                    }
                    inicio = nuevaLista;
                    ultimo = ultimoTemporal;
                    inicio->ant = ultimo;
                    invertirLista();
                }

            }
        }//is empty
    }//**

    bool exist(T* valor) {
        ptrLista aux;
        aux = inicio;
        while (aux->sgte != inicio) {
            if (aux->elemento == valor) return true;
            aux = aux->sgte;
        }
        if (aux->elemento == valor) return true;
        return false;
    }//**

    T* obtenerAnterior(T* aerolinea) {
        if (!isEmpty()) {
            ptrLista aux;
            aux = inicio;
            if (aux->elemento == aerolinea) return aux->ant->elemento;

            aux = aux->sgte;
            while (aux != inicio) {
                if (aux->elemento == aerolinea) return aux->ant->elemento;
                aux = aux->sgte;
            }
        }
    }

    T* obtenerSiguiente(T* aerolinea) {
        if (!isEmpty()) {
            ptrLista aux;
            aux = inicio;
            if (aux->elemento == aerolinea) return aux->sgte->elemento;

            aux = aux->sgte;
            while (aux != inicio) {
                if (aux->elemento == aerolinea) return aux->sgte->elemento;
                aux = aux->sgte;
            }
        }
    }
    
    T* buscarObjeto(T* objeto){
        if(!isEmpty()){
            ptrLista aux;
            aux = inicio;
            if(aux->elemento == objeto) return aux->elemento;
            
            aux = aux->sgte;
            while (aux != inicio) {
                if (aux->elemento == objeto) return aux->elemento;
                aux = aux->sgte;
            }
        }
    }//buscarObjeto

    T* firstInlist() {
        return inicio->elemento;
    }//**

    T* lastInList() {
        return ultimo->elemento;
    }//**

    void mostrarValoresLista() {
        if (!isEmpty()) {
            ptrLista aux;
            aux = inicio;

            cout << " <-> [" << aux->elemento->toString() << "]";
            aux = aux->sgte;
            while (aux != inicio) {
                cout << " <-> [" << aux->elemento->toString() << "]";
                if (aux == ultimo) cout << "<->";
                aux = aux->sgte;
            }
        }
    }//**

    string toString() {
        stringstream s;
        if (!isEmpty()) {
            ptrLista aux;
            aux = inicio;

            s << " <-> [" << aux->elemento->toString() << "]";
            aux = aux->sgte;
            while (aux != inicio) {
                s << " <-> [" << aux->elemento->toString() << "]";
                if (aux == ultimo)
                    s << "<->";
                aux = aux->sgte;
            }
        }
        return s.str();
    }//toString

    void invertirLista() {
        ptrLista aux;
        aux = inicio; //esté fragmento deja la lista de la forma en la cual la encontro y no invertida
        ListaEnlazadaCircularDoble* laux = new ListaEnlazadaCircularDoble();
        laux->insertar(aux->elemento);
        aux = aux->sgte;
        while (aux != inicio) {
            laux->insertar(aux->elemento);
            aux = aux->sgte;
        }
        inicio = laux->inicio;
        ultimo = laux->ultimo;
    }

private:
    ptrLista inicio;
    ptrLista ultimo;

};

#endif /* LISTAENLAZADACIRCULARDOBLE_H */