#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>
#include <cstdio>

#include "interaccion.hpp"
#include "fecha.hpp"
#include "lista.cpp"
#include "arbol.cpp"
#include <ctime>
#include "funciones.hpp"
#include <typeinfo>

using namespace std;

void opciones(){
	cout<<endl<<"Ingrese 1 para crear un Post";
	cout<<endl<<"Ingrese 2 para explorar los posteos";
	cout<<endl<<"Ingrese 3 para ver todos los Post con sus comentarios y respuestas";
	cout<<endl<<"Ingrese 4 para buscar las participaciones de los usuarios";
	cout<<endl<<"Ingrese 5 para salir"<<endl;
}

Interaccion crearPost() {
    Interaccion posteo;
    char titulo[2000];
    char usuario[2000];
    char contenido[2000];

    cin.ignore(); // Limpiar el buffer de entrada
    cout << endl << "Ingrese usuario: ";
    cin.getline(usuario, sizeof(usuario)); // Leer usuario de manera segura

    cout << endl << "Ingrese Titulo de su Post: ";
    cin.getline(titulo, sizeof(titulo)); // Leer título de manera segura

    cout << endl << "Ingrese contenido del Post: ";
    cin.getline(contenido, sizeof(contenido)); // Leer contenido de manera segura

    posteo.setUsuario(usuario);
    posteo.setTitulo(titulo);
    posteo.setContenido(contenido);
    posteo.setNivel(0);

    return posteo;
}

void eliminarPost(arbol<Interaccion> *miArbol){
			miArbol->RECORRERTITULOS(1);
			cout<<endl;
			cout<<"Ingrese el numero de Post que desea eliminar: ";
			int numero;
			cin>>numero;
			//funcion eliminar
			miArbol->Borrar(numero, 1);
			miArbol->RECORRERTITULOS(1);
			cout<<endl;
			}
			
void comentarPost(arbol<Interaccion> *miArbol, int numero, int j) {
    Interaccion comentario;
    char usuario[2000];
    char contenido[2000];
    
    cin.ignore(); // Limpiar el buffer de entrada
    cout << endl << "Ingrese Usuario: ";
    cin.getline(usuario, sizeof(usuario)); // Leer usuario de manera segura

    cout << endl << "Ingrese Comentario: ";
    cin.getline(contenido, sizeof(contenido)); // Leer contenido de manera segura

    comentario.setUsuario(usuario);
    comentario.setContenido(contenido);
    comentario.setNivel(1);
    
    miArbol->INSERTAR(comentario, numero, j);
    miArbol->IMPRIMIRPOST(numero, j);
}

void responderComentario(arbol<Interaccion> *miArbol, int numero, int comentario) {
    Interaccion respuesta;
    Fecha fecha;
    char usuario[2000];
    char contenido[2000];

    cin.ignore(); // Limpiar el buffer de entrada
    cout << endl << "Ingrese Usuario: ";
    cin.getline(usuario, sizeof(usuario)); // Leer usuario de manera segura

    cout << endl << "Ingrese Respuesta: ";
    cin.getline(contenido, sizeof(contenido)); // Leer contenido de manera segura

    respuesta.setUsuario(usuario);
    respuesta.setNivel(2);
    respuesta.setContenido(contenido);

    miArbol->COLOCARRESPUESTA(respuesta, numero, 1, comentario, 1);
    miArbol->IMPRIMIRCOMENTARIO(numero, 1, comentario, 1);
    cout << endl;
}

	void menuComentario(arbol<Interaccion> *miArbol, int numero){
	//recorrer comentarios
	miArbol->RECORRERCOMENTARIOS(numero, 1, 1);
	cout<<endl<<"Ingrese el Numero de Post que desea entrar: ";
	int comentario;
	cin>>comentario;
	cin.ignore();
	int opcion;
	do{
	cout<<endl<<"Ingrese 1 para Responder Comentario";
	cout<<endl<<"Ingrese 2 para dar LIKE";
	cout<<endl<<"Ingrese 3 para dar DISLIKE";
	cout<<endl<<"Ingrese 4 para volver atras"<<endl;
	cin>>opcion;
	switch(opcion){
		case 1: //responder comentario
		responderComentario(miArbol, numero, comentario);
		break;

		case 2: //dar like
		miArbol->LIKECOMENTARIO(numero, 1, comentario, 1, 1);
		break;

		case 3: //dar dislike
		miArbol->LIKECOMENTARIO(numero, 1, comentario, 1, -1);
		break;

		case 4: //volver atras 
		break;

		default:
		cout<<endl<<"Opcion invalida, intente nuevamente: "<<endl;
		break;
	}
	}while(opcion!=4);
}

void UsuariosEnUnPost(arbol<Interaccion> *miArbol, int numero){
				// lista de string
				string usuario;
				Lista<string>* l = new Lista<string>();
				miArbol->BUSCARUSUARIOSENUNPOST(l, usuario, numero, 1);//en el post
				l->impre();
				cout<<endl;
				int k;
				cin>>k;
				usuario = l->tomarK(k);
				Lista<Interaccion>* participaciones = new Lista<Interaccion>();
				miArbol->IMPRIMIRPARTICIPACIONESENUNPOST(usuario, participaciones,  numero, 1);//en el post
				participaciones->imp();
}

void menuPost(arbol<Interaccion> *miArbol){
			
			miArbol->RECORRERTITULOS(1);
			cout<<endl<<"Ingrese el Numero de Post que desea entrar: ";
			int numero;
			cin>>numero;	
			int opcion;
			do{
			Interaccion comentario;
			string usuario;
			cout<<endl<<"Ingrese 1 para Comentar Post";
			cout<<endl<<"Ingrese 2 para ingresar a un comentario del Post";
			cout<<endl<<"Ingrese 3 para ver cuantos LIKES tiene el Post";
			cout<<endl<<"Ingrese 4 para darle LIKE al Post";
			cout<<endl<<"Ingrese 5 para darle DISLIKE al Post";
			cout<<endl<<"Ingrese 6 para ver comentario mas votado";
			cout<<endl<<"Ingrese 7 para ver usuario que mas participo";
			cout<<endl<<"Ingrese 8 para volver atras"<<endl;
			cin>>opcion;
			switch(opcion){
				case 1: //comentar post
				comentarPost(miArbol, numero, 1);
				break; 
				
				case 2: //para ingresar a un comentario del Post
				menuComentario(miArbol, numero);
				break;
				
				case 3: //ver valoracion del post
				miArbol->VERVALORACION(numero,1);
				break;
				
				case 4: //like
				miArbol->LIKE(numero, 1);
				break;
				
				case 5: //dislike
				miArbol->DISLIKE(numero, 1);
				break;
				
				case 6: //ver comentario mas votado
				comentario.setNivel(1);
				miArbol->MASVOTADO(numero, 1, comentario);
				break;
				
				case 7: //ver usuario que mas participo
				UsuariosEnUnPost(miArbol, numero);
				break;
				
				case 8: //volver atras
				break;
				
				default:
				cout<<endl<<"Opcion invalida, intente nuevamente: "<<endl;
				break;	
			}
			}while(opcion!=8);
			}

void explorarPost(arbol<Interaccion> *miArbol){
	int opciones;
	do{
	cout<<endl<<"Ingrese 1 para entrar a un Post";
	cout<<endl<<"Ingrese 2 para eliminar un Post";
	cout<<endl<<"Ingrese 3 para volver atras"<<endl;
		cin>>opciones;		
		switch(opciones){
			case 1: //Ingresar a un Post
			menuPost(miArbol);
			break;
			
			case 2: //Eliminar un Post
			eliminarPost(miArbol);
			break;
			
			case 3: //volver atras
			break;
			
			default: //Ingrese de nuevo
			cout<<endl<<"Opcion invalida, intente nuevamente: "<<endl;
			break;
		}
	}while(opciones != 3);
}

void buscarParticipacion(arbol<Interaccion> *miArbol){
	// lista de string
	string usuario;
	Lista<string>* l = new Lista<string>();
	// mostrar usuarios<--&lista
	miArbol->BUSCARUSUARIOS(l, usuario);
	l->impre();
	cout<<endl;
	int k;
	cin>>k;
	usuario = l->tomarK(k);
	
	Lista<Interaccion>* participaciones = new Lista<Interaccion>();
	miArbol->IMPRIMIRPARTICIPACIONES(usuario, participaciones);
	participaciones->imp();
}

void menu(arbol<Interaccion> *miArbol){
	int opcion;
	Interaccion posteo;
	
	cout<<endl<<"Bienvenido a Reddit Trucho!"<<endl;
	do{
		opciones();
		cin>> opcion;
		switch(opcion){
			case 1: //Crear Post
			posteo = crearPost();
			miArbol->CreaArbolBus(posteo);
			break;
			
			case 2: //Explorar Posteos
			explorarPost(miArbol);
			break;
			
			case 3: //Imprimir Todo
			miArbol->IMPRIMIRTODO();
			break;
			
			case 4: //Buscar las participaciones de un usuario
			buscarParticipacion(miArbol);
			break;
			
			case 5: //Salir
			break;
			
			default: //Ingrese de nuevo
			cout<<endl<<"Opcion invalida, intente nuevamente: "<<endl;
			break;
		}
	}while(opcion != 5);
}


