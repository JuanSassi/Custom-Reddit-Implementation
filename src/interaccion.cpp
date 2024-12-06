#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "interaccion.hpp"
#include "fecha.hpp"
#include <ctime>

using namespace std;

	
	Interaccion::Interaccion(){
		Fecha miFecha;
		fecha = miFecha;
		usuario = "";
		contenido = "";
		valoracion = 0;
		nivel = 0;
		titulo = "";
	}
	Interaccion::~Interaccion(){
	}
	void Interaccion::getFecha(){
	gFecha().imprimirFecha();
	//cout<<gFecha().gf()->tm_mday<<"/"<<gFecha().gf()->tm_mon+1<<"/"<<gFecha().gf()->tm_year+1900;
	//cout<<" "<<gFecha().gf()->tm_hour<< ":"<<gFecha().gf()->tm_min<<":"<<gFecha().gf()->tm_sec;
	}
	string Interaccion::getUsuario(){
		return usuario;
	}
	string Interaccion::getContenido(){
		return contenido;
	}
	int Interaccion::getValoracion(){
		return valoracion;
	}
	void Interaccion::valorar(int v){
		valoracion = valoracion + v;
	}
	
	int Interaccion::getNivel(){
		return nivel;
	}
	Fecha Interaccion::gFecha(){
		return fecha;
	}

	string Interaccion::getTitulo(){
		return titulo;
	}
	
	void Interaccion::setNivel(int level){
		nivel = level;
	}

	void Interaccion::setUsuario(string u){
		usuario = u;
	}
	
	void Interaccion::setContenido(string c){
		contenido = c;
	}
	
	void Interaccion::setTitulo(string t){
		titulo = t;
	}
	
	void Interaccion::setFecha(){
		Fecha miFecha;
		fecha = miFecha;
	}
