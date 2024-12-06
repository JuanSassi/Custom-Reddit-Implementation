#pragma once
#ifndef COMENTARIO_H_
#define COMENTARIO_H_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>
#include "fecha.hpp"
#include <ctime>

using namespace std;

class Interaccion {
private:
	Fecha fecha;
	string usuario;
	string contenido;
	int valoracion;
	int nivel;
	string titulo;
	
public:
	Interaccion();
	~Interaccion();
	
	void getFecha();
	string getUsuario();
	string getContenido();
	int getValoracion();
	int getNivel();
	Fecha gFecha();
	
	void setNivel(int level);
	void setUsuario(string u);
	void valorar(int v);
	void setContenido(string c);
	void setFecha();
	
	string getTitulo();
	void setTitulo(string t);
};

#endif
