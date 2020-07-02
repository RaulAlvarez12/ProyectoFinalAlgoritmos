
/* 
 * File:   ListaEnlazada.h
 * Author: alsov
 *
 * Created on 21 de mayo de 2020, 02:50 PM
 */

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

using namespace std;

template <typename T>
class ListaEnlazada {

    struct nodo {
        T* dato;
        struct nodo *sgte; //apuntador al siguiente nodo
    };

    typedef nodo *ptrLista; //creando nodo tipo puntero(tipo de dato)

public:

    ListaEnlazada() {
        // TODO Auto-generated constructor stub
        lista = NULL; //creamos la lista para trabajar
        //numeroNodos = 0;
    }

    int getSize() {

        ptrLista aux = lista;
        int cont = 0;

        while (aux != NULL) {
            cont++;
            aux = aux->sgte;
        }
        return cont;

    }

    bool isEmpty() {

        return lista == NULL;
    }

    void insertar(T* valor) {

        ptrLista aux, nuevoNodo;
        aux = lista;

        nuevoNodo = new(struct nodo); // apuntamos al nuevo nodo creado
        nuevoNodo->dato = valor;

        if (aux == NULL) {
            aux = nuevoNodo;
            lista = aux;
            //  numeroNodos++;
            cout << "Se ingreso primer valor a la lista..!" << endl;
        } else {
            /*
             * while(aux->sgte != NULL){
                    aux = aux->sgte;
            }//FinWhile
            aux->sgte = nuevoNodo;
            l = aux;
             */

            nuevoNodo->sgte = aux;
            lista = nuevoNodo;
            //   nuevoNodo.ant = aux; doblementeEnlazada
            // numeroNodos++;
            cout << "Se ingreso nuevo valor a la lista: " << valor << endl;
        }//FinElse

    }

    void borrarValor(T* valor) {

        if (isEmpty()) {
        }
        // Nodo<T>* aux = inicio; // para movernos en la lista
        //  Nodo<T>* nodoAnterior = NULL;
        ptrLista aux = lista;
        ptrLista nodoAnterior = NULL;

        //caso1:cuando el elemento  borrar es el primero
        if (lista->dato == valor) {// es el primer elemento a borrar
            lista = lista->sgte;
            //numNodos--;
        } else {

            while (aux->sgte != NULL && aux->dato != valor) {
                nodoAnterior = aux; //dejar rastro
                aux = aux->sgte;

            }
            if (aux->dato == valor) {//ya lo encontro

                nodoAnterior->sgte = aux->sgte; //saltamos el nodo
                //numNodos--;
                cout << "Eliminamos el elemento:" << valor << endl;
            }

            // inicio = nodoAnterior;

        }//end else



    }

    void borrar(T* valor) {

        ptrLista aux = lista;
        //ptrLista nodoAnterior = NULL;
        ptrLista nuevaLista, nodoSinBorrar;
        nuevaLista = new(struct nodo); // apuntamos al nuevo nodo creado

        /*
         *
         * aux = l = [7] [10] [3] [5] [9] [2] [14]
         *                        aux
         *
         * nuevaLista [] -->
         * nodoSinBorrar = [10]
         * [7] --> nuevaLista
         * nodoSinBorrar = [10]--> [7]
         * nuevaLista = [7] --> [10]  --> [5] --> [9] --> [2] --> [14]
         * Borrar el 3
         *
         * l = nuevaLista
         *
         * */

        //Caso 1: Cuando el elemento a suprimir es el primero de la lista
        if (aux->dato == valor) {
            aux = aux->sgte;
            lista = aux;
            //  numeroNodos--;
        }//Caso 2, no es el primero que ocupamos borrar
        else {
            while (aux != NULL/*&& (!aux->numero)==valor*/) {
                //nodoAnterior = aux;
                if (aux->dato != valor) {
                    nodoSinBorrar = new(struct nodo); // apuntamos al nuevo nodo creado
                    nodoSinBorrar->dato = aux->dato;
                    nodoSinBorrar->sgte = nuevaLista;
                    nuevaLista = nodoSinBorrar;
                }
                aux = aux->sgte;
                //   numeroNodos--;
            }//finWhile
            //if(aux->numero == valor){//ya lo encontro, debo eliminarlo
            //nodoAnterior->sgte = aux->sgte;//se salta al nodo apuntado por aux
            lista = nuevaLista;

        }//finElse
        cout << "Se elimino valor de la lista : " << valor << endl;
    }

    void mostrarValoresLista(/*ptrPila p*/) {

        ptrLista aux;
        aux = lista; //apunta al inicio de la lista

        cout << "\n\n MOSTRANDO LISTA\n\n";
        if (aux != NULL)
            while (aux != NULL) {
                if (aux->dato != 0) {
                    cout << "\t Valor en lista: " << aux->dato << endl;
                }
                aux = aux->sgte;
            } else
            cout << "\n\n\tLista vacia..!" << endl;

    }

    void print() {
        // Nodo<T>* temp = inicio;
        cout << "MOSTRANDO LISTA: " << endl;
        ptrLista temp = lista;
        while (temp != NULL) {

            cout << "[" << temp->dato << "]---->";
            temp = temp->sgte;
        }

    }

    void anular() {

        //  lista = NULL;
        //    if (lista != NULL) {
        //        ptrLista recorido = lista->sgte;
        //        ptrLista borrar;
        //        while (recorido != lista) {
        //            borrar = recorido;
        //            recorido = recorido->sgte;
        //            delete borrar;
        //        }
        //        delete lista;
        //    }
        // delete lista;
        this->lista = NULL;
        // numeroNodos = 0;

        /*
        ptrPila aux;

        while(p != NULL){
                aux = p;
                p = aux->sgte;
                delete(aux);
        }//while
         */
    }

    T* primeroLista() {

        if (!isEmpty()) {

            return lista->dato;

        }


    }

    T* ultimoLista() {

        ptrLista aux;

        if (!isEmpty()) {

            aux = lista;

            while (aux->sgte != NULL) {
                aux = aux->sgte;

            }

            return aux->dato;
        }


    }

    int getPosicion(T* valor) {
        ptrLista temp = lista;

        for (int i = 1; i < getSize(); i++) {

            if (temp->dato == valor) {
                return i;
            } else {
                temp = temp->sgte;
            }
        }
        return -1;

    }

    void insertarOrdenado(T* data_) {

        ptrLista temp, nodoAnterior, temp2;

        //  nuevoNodo->dato = valor;
        int ordenado = 0, contador = 0;

        if (isEmpty()) {
            insertarD(data_);

        } else {
            // Nodo<T>* temp = inicio;
            // Nodo<T>* nodoAnterior = NULL;
            temp = lista;
            nodoAnterior = NULL;

            bool continuar = true;
            while (temp != NULL) {
                if (lista->dato > data_) {
                    // Nodo<T>* temp2 = new Nodo<T>(data_);
                    temp2 = new (struct nodo);
                    temp2->dato = data_;
                    temp2->sgte = lista;
                    lista = temp2;
                    continuar = false;
                    //numNodos++;
                    break;
                } else {
                    if (temp->dato > data_) {
                        //Nodo<T>* temp2 = new Nodo<T>(data_);
                        temp2 = new (struct nodo);
                        temp2->dato = data_;
                        temp2->sgte = temp;
                        nodoAnterior->sgte = temp2;
                        continuar = false;
                        // numNodos++;
                        break;
                    }
                }
                nodoAnterior = temp;
                temp = temp->sgte;
            }
            if (continuar) {
                insertarD(data_);

            }
        }
        // return data_;

    }

    void insertarD(T* valor) {

        ptrLista nuevoNodo, temp;
        nuevoNodo = new(struct nodo);
        nuevoNodo->dato = valor;
        temp = lista;

        // Nodo<T>* nuevoNodo = new Nodo<T>(data_);
        //  Nodo<T>* temp = inicio;
        if (isEmpty()) {
            lista = nuevoNodo;
            cout << "Se ingreso el primer valor de la lista: " << valor << endl;
        } else {
            while (temp->sgte != NULL) {
                temp = temp->sgte;

            }
            temp->sgte = nuevoNodo;
            cout << "Se ingreso nuevo valor a la lista: " << valor << endl;

        }

        //    if (isEmpty()) {
        //        lista = nuevoNodo;
        //        cout << "Agregando primero valor de la lista: " << valor << endl;
        //    } else {
        //        cout << "entra al else" << endl;
        //        while (temp->sgte != NULL) {
        //            cout << "entra al while" << endl;
        //            temp = temp->sgte;
        //            cout << "Agregando nuevo valor: " << valor << endl;
        //        }
        //        temp->sgte = nuevoNodo;
        //    }
        // numNodos++;
        //  return data_;



    }
    
//
//    void insertarPrimero(T* valor) {
//
//
//
//
//
//
//
//    }
//
//    void insertarUltimo(T* valor) {
//
//
//
//
//    }

    bool existe(T* element) {

        if (isEmpty()) {

            cout << "La lista esta vacia" << endl;

        }

        ptrLista aux = lista;
        while (aux != NULL) {

            if (aux->dato == element) {

                return true;

            }
            aux = aux->sgte;

        }

        return false;

    }

private:

    ptrLista lista;
    int numeroNodos;

};


#endif /* LISTAENLAZADA_H */

