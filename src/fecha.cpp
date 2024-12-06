#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "fecha.hpp"
#include <ctime>

using namespace std;

Fecha::Fecha(){
	t = time(NULL);
	fecha = localtime(&t);
	anio=fecha->tm_year+1900;
	mes=fecha->tm_mon+1;
	dia=fecha->tm_mday;
	hora=fecha->tm_hour;
	min=fecha->tm_min;
	seg=fecha->tm_sec;
}

Fecha::~Fecha(){
}

struct tm* Fecha::gf() {
    return fecha;
}

void Fecha::imprimirFecha(){
	//cout<<fecha->tm_mday<<"/"<<fecha->tm_mon+1<<"/"<<fecha->tm_year+1900;
	//cout<<" "<<fecha->tm_hour<< ":"<<fecha->tm_min<<":"<<fecha->tm_sec;
	cout<<dia<<"/"<<mes<<"/"<<anio;
	cout<<" "<<hora<< ":"<<min<<":"<<seg;
}

