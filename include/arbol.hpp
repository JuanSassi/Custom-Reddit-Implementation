#pragma once
#ifndef ARBOL_H_
#define ARBOL_H_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "interaccion.hpp"
#include "fecha.hpp"
#include "lista.hpp"
#include <ctime>
#include <typeinfo>

using namespace std;


template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};


template <class T> class arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo);
    void rid(nodo<T>* aux);
    void borrar(nodo<T>* &p, int i, int j);
    void imprimirTodo(nodo<T>* aux);
    void recorrerTitulos(nodo<T>* aux, int i);
    void like(nodo<T>* &p, int numero, int j);
	void dislike(nodo<T>* &p, int numero, int j);
	void insertar(nodo<T>* &p, T x, int numero, int j);
	void verValoracion(nodo<T>* &p, int numero,int j);
	void masVotado(nodo<T>* &p, int numero, int j, T comentario);
	void imprimirPost(nodo<T>* &p, int numero, int j);
	void recorrerComentarios(nodo<T>* &p, int numero, int j, int i);
	void colocarRespuesta(T x, nodo<T>*& nuevo, int numeroPost, int j, int numeroComentario, int i);
	void imprimirComentario(nodo<T>* &p, int numero, int j, int comentario, int i);
	void likeComentario(nodo<T>* &p, int numero, int j, int comentario, int i, int valoracion);
	void buscarUsuarios(nodo<T>* aux, Lista<string>* &l, string usuario);
	void imprimirParticipaciones(nodo<T>* aux, string usuario,Lista<T>*  participaciones);
	void buscarUsuariosEnUnPost(nodo<T>* aux, Lista<string>* &l, string usuario,int numero, int j);//en el post
	void imprimirParticipacionesEnUnPost(nodo<T>* aux, string usuario, Lista<T>* participaciones, int numero, int j);

public:
    arbol();
    ~arbol();
    void CreaArbolBus(T x);
    void RID();
    void Borrar(int i, int j);
	
    void IMPRIMIRTODO();
    void RECORRERTITULOS(int i);
    void LIKE(int numero, int j);
	void DISLIKE(int numero, int j);
	void INSERTAR(T x, int numero, int j);
	void VERVALORACION(int numero,int j);
	void MASVOTADO(int numero, int j, T comentario);
	void IMPRIMIRPOST(int numero, int j);
	void RECORRERCOMENTARIOS(int numero, int j, int i);
	void COLOCARRESPUESTA(T x, int numeroPost, int j, int numeroComentario, int i);
	void IMPRIMIRCOMENTARIO(int numero, int j, int comentario, int i);
	void LIKECOMENTARIO(int numero, int j, int comentario, int i, int valoracion);
	void BUSCARUSUARIOS(Lista<string>* &l, string usuario);
	void IMPRIMIRPARTICIPACIONES(string usuario,Lista<T>*  participaciones);
	void BUSCARUSUARIOSENUNPOST(Lista<string>* &l, string usuario,int numero, int j);//en el post
	void IMPRIMIRPARTICIPACIONESENUNPOST(string usuario, Lista<T>* participaciones, int numero, int j);

};

#endif
