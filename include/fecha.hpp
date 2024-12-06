#pragma once
#ifndef FECHA_H_
#define FECHA_H_

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>
#include <ctime>

using namespace std;

class Fecha {
private:
	time_t t;
	struct tm *fecha;
	int anio;
	int mes;
	int dia;
	int hora;
	int min;
	int seg;

public:
	Fecha();
	~Fecha();
	struct tm* gf();
	void imprimirFecha();
};

#endif
