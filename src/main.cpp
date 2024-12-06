#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "interaccion.hpp"
#include "fecha.hpp"
#include "lista.hpp"
#include "arbol.cpp"
#include <ctime>
#include "funciones.hpp"
#include <typeinfo>

using namespace std;

int main() {
    arbol<Interaccion> miArbol;    
	menu(&miArbol);	
	return 0;
}
