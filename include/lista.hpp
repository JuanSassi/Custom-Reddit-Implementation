#pragma once
#ifndef LISTA_H_
#define LISTA_H_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo();
    Nodo(T a);
    void set_dato(T a);
    void set_next(Nodo* n);
    T get_dato();
    Nodo* get_next();
    bool es_vacio();
};

template <class T> class Lista {
private: Nodo<T>* czo;
       void addO(T d, Nodo<T>* ant);
       void borrarD(T d, Nodo<T>* ant);
       //bool dma(T d, Nodo<T>* ant);

public:
    Lista();
    Lista(Nodo<T>* n);
    void add(T d); 
    bool esvacia(void);
    T cabeza(void); 
    Lista* resto(void);
    string toPrint(string p);
    void impre(void);
    T suma(T i);
    int  size();
    bool esta(T d);
    void borrarDato(T d);
    void borrar(void); 
    void borrar_last();
    void concat(Lista<T>* l1);
    Lista<T>* copy(void);
    void tomar(int n);
    void addOrdenado(T d); 
    T last();
    T tomarK(int k);
    //bool DMA(T d);
    bool dma(T d);
    void imp(void);

};

template <class T> class Pila :public Lista<T> {
public:
    Pila();
    void apilar(T d);
    T tope(void);
    void desapilar(void);
    bool pilavacia();
};

template <class T> class Cola :public Lista<T> {
public:
    Cola(void);
    T tope();
    bool colavacia(void);
    void encolar(T a);
    void desencolar(void);
    T ultimo(void);
    string imprimir(string s);
};
#endif
