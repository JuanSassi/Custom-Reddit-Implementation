#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "interaccion.hpp"
#include "fecha.hpp"
#include "arbol.hpp"
#include "lista.hpp"
#include <ctime>
#include <typeinfo>
using namespace std;


template <class T> arbol<T>::arbol() { raiz = NULL; };
template <class T> arbol<T>::~arbol() {};
template <class T> void arbol<T>::RID() { rid(raiz); }
template <class T> void arbol<T>::Borrar(int i, int j) { borrar(raiz, i, j); }

template <class T> void arbol<T>::IMPRIMIRTODO() {imprimirTodo(raiz);}
template <class T> void arbol<T>::RECORRERTITULOS(int i){recorrerTitulos(raiz,i);}
template <class T> void arbol<T>::LIKE(int numero, int j){like(raiz, numero, j);}
template <class T> void arbol<T>::DISLIKE(int numero, int j){dislike(raiz, numero, j);}
template <class T> void arbol<T>::INSERTAR(T x, int numero, int j){insertar(raiz, x, numero, j);}
template <class T> void arbol<T>::VERVALORACION(int numero,int j){verValoracion(raiz, numero, j);}
template <class T> void arbol<T>::MASVOTADO(int numero, int j, T comentario){masVotado(raiz, numero, j, comentario);}
template <class T> void arbol<T>::IMPRIMIRPOST(int numero, int j){imprimirPost(raiz, numero, j);}
template <class T> void arbol<T>::RECORRERCOMENTARIOS(int numero, int j, int i){recorrerComentarios(raiz, numero, j, i);}
template <class T> void arbol<T>::COLOCARRESPUESTA(T x, int numeroPost, int j, int numeroComentario, int i){colocarRespuesta(x, raiz, numeroPost, j, numeroComentario, i);}
template <class T> void arbol<T>::IMPRIMIRCOMENTARIO(int numero, int j, int comentario, int i){imprimirComentario(raiz, numero, j, comentario, i);}
template <class T> void arbol<T>::LIKECOMENTARIO(int numero, int j, int comentario, int i, int valoracion){likeComentario(raiz, numero, j, comentario, i, valoracion);}
template <class T> void arbol<T>::BUSCARUSUARIOS(Lista<string>* &l, string usuario){buscarUsuarios(raiz, l, usuario);}
template <class T> void arbol<T>::IMPRIMIRPARTICIPACIONES(string usuario,Lista<T>*  participaciones){imprimirParticipaciones(raiz, usuario, participaciones);}
template <class T> void arbol<T>::BUSCARUSUARIOSENUNPOST(Lista<string>* &l, string usuario,int numero, int j){buscarUsuariosEnUnPost(raiz, l, usuario, numero, j);}
template <class T> void arbol<T>::IMPRIMIRPARTICIPACIONESENUNPOST(string usuario, Lista<T>* participaciones, int numero, int j){imprimirParticipacionesEnUnPost(raiz, usuario, participaciones, numero, j);}


template <class T> void arbol<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}
template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo)
{
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    else{
    if (x.getNivel() == nuevo->info.getNivel()) ArbolBusq(x, nuevo->der); // preguntar por el nivel 
    if (x.getNivel() > nuevo->info.getNivel()) ArbolBusq(x, nuevo->izq);
	}
}

template <class T> void arbol<T>::rid(nodo<T>* aux)
{
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}

template <class T> void arbol<T>::borrar(nodo<T>* &p, int i, int j)
{
		if (p != NULL) {
			if(i==j){
				nodo<T>* c;
    			c = p->der;
				delete p;
				p = c;
			}
	        else{
				borrar(p->der, i, j+1);
				}
    	}
}

template <class T> void arbol<T>::imprimirTodo(nodo<T>* aux)
{
    if (aux != NULL) {
    	if(aux->info.getNivel()==0){
    			cout<<endl<<"Titulo: "<< aux->info.getTitulo()<<" --- Publicado por: ";
    			cout<<aux->info.getUsuario()<<" ";
				aux->info.getFecha();
        		cout<<endl<<aux->info.getContenido()<<endl;
    	}
        else{
        	if(aux->info.getNivel()==1){
        		cout<<endl<<"Comentario: ";
        		cout<<aux->info.getContenido();
        		cout<<" --- Publicado por: "<<aux->info.getUsuario()<<" ";
				aux->info.getFecha();
				cout<<endl;
        	}
        	else{
        		cout<<endl<<"Respuesta: ";
        		cout<<aux->info.getContenido();
        		cout<<" --- Publicado por: "<<aux->info.getUsuario()<<" ";
				aux->info.getFecha();
				cout<<endl;
        	}
        }
        
        
        imprimirTodo(aux->izq);
        imprimirTodo(aux->der);
    }
}

template <class T> void arbol<T>::recorrerTitulos(nodo<T>* aux, int i){
	if (aux != NULL) {
		cout<<endl<<"Posteo N° "<<i<<": --- "<<"Titulo: "<< aux->info.getTitulo()<<" --- Publicado por: "<<aux->info.getUsuario()<<" --- ";
		aux->info.getFecha();
        recorrerTitulos(aux->der, i+1);
    }
}

template <class T> void arbol<T>::like(nodo<T>* &p, int numero, int j){
	if (p != NULL) {
			if(numero==j){
				// like
				p->info.valorar(1);
				cout<<"El Post tiene: "<<p->info.getValoracion()<<" likes"<<endl;
			}
	        else{
				like(p->der, numero, j+1);
				}
    	}
}

template <class T> void arbol<T>::dislike(nodo<T>* &p, int numero, int j){
	if (p != NULL) {
			if(numero==j){
				// dislike
				p->info.valorar(-1);
				cout<<"El Post tiene: "<<p->info.getValoracion()<<" likes"<<endl;
			}
	        else{
				dislike(p->der, numero, j+1);
				}
    	}
}

template <class T> void arbol<T>::insertar(nodo<T>* &p, T x, int numero, int j){
	if (p != NULL) {
			if(numero==j){
				if(p->info.getNivel() < x.getNivel()){
					insertar(p->izq, x, numero, j);
				}
				else{
				insertar(p->der, x, numero, j);}
			}
	        else{
				insertar(p->der, x, numero, j+1);
			}
    	}
    	else{
			if(numero==j){
	        	p = new nodo<T>;
        		p->info = x; p->der = p->izq = NULL;
	        	}
    		}
}

template <class T> void arbol<T>::verValoracion(nodo<T>* &p, int numero,int j){
	if (p != NULL) {
			if(numero==j){
				cout<<endl<<"El Post tiene "<<p->info.getValoracion()<<" LIKES"<<endl;
			}
	        else{
				verValoracion(p->der, numero, j+1);
				}
    	}
}

template <class T> void arbol<T>::masVotado(nodo<T>* &p, int numero, int j, T comentario){
	//numero y j para encontrar post --- muevo a la izquierda y veo comentarios 
		if (p != NULL) {
			if(numero==j){
				if(p->info.getNivel() < comentario.getNivel()){
					masVotado(p->izq, numero, j, comentario);
				}
				else{
				if(comentario.getValoracion() < p->info.getValoracion()){
					comentario = p->info;
				}
				masVotado(p->der, numero, j, comentario);
				}
			}
	        else{
				masVotado(p->der, numero, j+1, comentario);
				}
    	}
    	else{
			if(numero==j){
				cout<<endl<<"El comentario mas votado es: "<<comentario.getContenido();
				cout<<endl<<"Usuario: "<<comentario. getUsuario()<<" --- Likes: "<<comentario.getValoracion()<<" --- ";
				comentario.getFecha();
	        	}
    		}
}

template <class T> void arbol<T>::imprimirPost(nodo<T>* &p, int numero, int j){
	if (p != NULL) {
			if(numero==j){
				//codigo
				if (p != NULL) {
					if(p->info.getNivel()==0){
							cout<<endl<<"Titulo: "<< p->info.getTitulo()<<" --- Publicado por: ";
					}
					else{
						if(p->info.getNivel()==1){
							cout<<endl<<"Comentario de ";
						}
						else{
							cout<<endl<<"Respuesta de ";
						}
					}
					cout<<p->info.getUsuario()<<" ";
					p->info.getFecha();
					cout<<endl<<p->info.getContenido()<<endl;
					if(p->info.getNivel()==0){
					imprimirTodo(p->izq);}
					if(p->info.getNivel()!=0){
					imprimirTodo(p->der);}
				}
			}
	        else{
				imprimirPost(p->der, numero, j+1);
				}
    	}
}

template <class T> void arbol<T>::recorrerComentarios(nodo<T>* &p, int numero, int j, int i){
	if (p != NULL) {
			if(numero==j){
				if(p->info.getNivel() ==0){
					recorrerComentarios(p->izq, numero, j, i);
				}
				else{
					cout<<endl<<"Comentario N° "<<i<<": "<< p->info.getContenido()<<" --- Publicado por: "<<p->info.getUsuario()<<" --- ";
					p->info.getFecha();
					recorrerComentarios(p->der, numero, j, i+1);
				}
			}
	        else{
				recorrerComentarios(p->der, numero, j+1, i);
				}
    	}
}

template <class T> void arbol<T>::colocarRespuesta(T x, nodo<T>*& nuevo, int numeroPost, int j, int numeroComentario, int i){// numero el del post, j el que controla hasta que llegue, numeroComentarioel del comentario, i controla hasta que llegue
		if(nuevo!=NULL){
			if(numeroPost==j){
				
				if(nuevo->info.getNivel()==0){
					colocarRespuesta( x, nuevo->izq, numeroPost,j,numeroComentario, i);
				}
				else{
				
				if(numeroComentario==i){
					if(nuevo->info.getNivel()==1){
						colocarRespuesta( x, nuevo->izq, numeroPost, j, numeroComentario, i);
					}
					else{
						colocarRespuesta( x, nuevo->der, numeroPost, j, numeroComentario, i);}
				}
				else{
				colocarRespuesta( x, nuevo->der, numeroPost,j,numeroComentario, i+1);
				}
			}
			}
	        else{
				colocarRespuesta( x, nuevo->der, numeroPost,j+1,numeroComentario,i);
				}
		}
		else{
			if(numeroPost==j && numeroComentario==i) {
					nuevo = new nodo<T>;
        			nuevo->info = x; nuevo->der = nuevo->izq = NULL;
		}
		}
}

template <class T> void arbol<T>::imprimirComentario(nodo<T>* &p, int numero, int j, int comentario, int i){
	if(p!=NULL){
			if(numero==j){
				
				if(p->info.getNivel()==0){
					imprimirComentario(p->izq, numero,j,comentario, i);
				}
				else{
				
				if(comentario==i){
					//imprimir comentario
					if(p->info.getNivel()==1){
					
					cout<<endl<<"Comentario de "<<p->info.getUsuario()<<" ";
					p->info.getFecha();
					cout<<endl<<p->info.getContenido();}
					
					if(p->info.getNivel()==1){
						imprimirComentario( p->izq, numero, j, comentario, i);
					}
					else{
						//imprimir respuesta
						if(p->info.getNivel()==2){
						
						cout<<endl<<"Respuesta de "<<p->info.getUsuario()<<" ";
						p->info.getFecha();
						cout<<endl<<p->info.getContenido();}
					
						imprimirComentario(p->der, numero, j, comentario, i);}
				}
				else{
				imprimirComentario(p->der, numero,j,comentario, i+1);
				}
			}
			}
	        else{
				imprimirComentario( p->der, numero,j+1,comentario,i);
				}
		}

}

template <class T> void arbol<T>::likeComentario(nodo<T>* &p, int numero, int j, int comentario, int i, int valoracion){
	
	if(p!=NULL){
			if(numero==j){
				
				if(p->info.getNivel()==0){
					likeComentario(p->izq, numero,j,comentario, i, valoracion);
				}
				else{
				
				if(comentario==i){
					p->info.valorar(valoracion);
					cout<<endl<<"El Comentario tiene "<<p->info.getValoracion()<<" LIKES";
				}
				else{
				likeComentario(p->der, numero,j,comentario, i+1, valoracion);
				}
			}
			}
	        else{
				likeComentario( p->der, numero,j+1,comentario,i, valoracion);
				}
		}
	
	
}

template <class T> void arbol<T>::buscarUsuarios(nodo<T>* aux, Lista<string>* &l, string usuario){
	if (aux != NULL) {
        
        if(!(l->esta(aux->info.getUsuario())))
		{
			l->add(aux->info.getUsuario());
		}        
        buscarUsuarios(aux->izq, l, usuario);
        buscarUsuarios(aux->der, l, usuario);
    }
}

template <class T> void arbol<T>::imprimirParticipaciones(nodo<T>* aux, string usuario, Lista<T>*  participaciones){
	if (aux != NULL) {
        
        if((aux->info.getUsuario()==usuario))
		{
			participaciones->addOrdenado(aux->info);
		}        
        imprimirParticipaciones(aux->izq, usuario,  participaciones);
        imprimirParticipaciones(aux->der, usuario,  participaciones);
    }
	}
	
template <class T> void arbol<T>::buscarUsuariosEnUnPost(nodo<T>* aux, Lista<string>* &l, string usuario,int numero, int j){
	if (aux != NULL) {
        if(numero == j){
        if(!(l->esta(aux->info.getUsuario())))
		{
			l->add(aux->info.getUsuario());
		}			
		buscarUsuariosEnUnPost(aux->izq, l, usuario, numero, j);
		if(aux->info.getNivel() != 0){
			buscarUsuariosEnUnPost(aux->der, l, usuario, numero, j);
		}        
        else{
        	buscarUsuariosEnUnPost(aux->der, l, usuario, numero, j+1);
    	}
    	
    }
	else{
    	buscarUsuariosEnUnPost(aux->der, l, usuario, numero, j+1);
    }
    }
}

template <class T> void arbol<T>::imprimirParticipacionesEnUnPost(nodo<T>* aux, string usuario, Lista<T>* participaciones, int numero, int j){
	if (aux != NULL) {
        if(numero == j){
        if((aux->info.getUsuario()==usuario))
		{
			participaciones->addOrdenado(aux->info);
		}   
		
		imprimirParticipacionesEnUnPost(aux->izq, usuario,  participaciones, numero, j);     
		if(aux->info.getNivel() != 0){
        imprimirParticipacionesEnUnPost(aux->der, usuario,  participaciones, numero, j);
        }        
        else{
        	imprimirParticipacionesEnUnPost(aux->der, usuario, participaciones, numero, j+1);
    	}
    }
    else{
    	imprimirParticipacionesEnUnPost(aux->der, usuario, participaciones, numero, j+1);
    }
    }
    
    }
