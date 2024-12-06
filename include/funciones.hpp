#pragma once
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "interaccion.hpp"
#include "fecha.hpp"
#include "lista.hpp"
#include "arbol.hpp"
#include <ctime>
#include <typeinfo>

using namespace std;

void buscarParticipacion(arbol<Interaccion> *miArbol);
void UsuariosEnUnPost(arbol<Interaccion> *miArbol, int numero);
void responderComentario(arbol<Interaccion> *miArbol, int numero, int comentario);
void menuComentario(arbol<Interaccion> *miArbol, int numero);
void opciones();
Interaccion crearPost();
void menuPost(arbol<Interaccion> *miArbol);
void explorarPost(arbol<Interaccion> *miArbol);
void menu(arbol<Interaccion> *miArbol);
void eliminarPost(arbol<Interaccion> *miArbol);
void comentarPost(arbol<Interaccion> *miArbol, int numero, int j);

#endif
