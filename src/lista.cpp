#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bits/basic_string.h>
#include <sstream>

#include "lista.hpp"
using namespace std;
/*
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
};*/

    template <class T> Nodo<T>::Nodo() { next = NULL; }
    template <class T> Nodo<T>::Nodo(T a) { dato = a; next = NULL; }
    template <class T> void Nodo<T>::set_dato(T a) { dato = a; }
    template <class T> void Nodo<T>::set_next(Nodo* n) { next = n; }
    template <class T> T Nodo<T>::get_dato() { return dato; }
    template <class T> Nodo<T>* Nodo<T>::get_next() { return next; }
    template <class T> bool Nodo<T>::es_vacio() { return next == NULL; }
    
	//template <class T> bool Lista<T>::DMA(T d){dma(d);}
    template <class T> Lista<T>::Lista() { czo = new Nodo<T>(); }
    template <class T> Lista<T>::Lista(Nodo<T>* n) { czo = n; }
    template <class T> void Lista<T>::borrarDato(T d) { borrarD(d, NULL); }//borra el nodo que contiene d
    template <class T> void Lista<T>::addOrdenado(T d) { addO(d, NULL); }//sumar nodos a la lista Ordenados de menor a MAYOR
	template <class T> T Lista<T>::last()
		{
		    if (!this->esvacia()) {
		        if (this->resto()->esvacia())return this->cabeza();
		        return this->resto()->last();
		    }return 0;
		}

	template <class T> void Lista<T>::add(T d) //100
		{
		    Nodo<T>* nuevo = new Nodo<T>(d);
		    nuevo->set_next(czo);
		    czo = nuevo;
		}
	template <class T> bool Lista<T>::esvacia(void)
		{
		    return czo->es_vacio();
		}
	template <class T> T Lista<T>::cabeza(void)
		{
		    if (this->esvacia()) {
		        cout << " Error, Cabeza de lista vacia";
		        return NULL;
		    }
		    return czo->get_dato();
		}

	template <class T> Lista<T>* Lista<T>::resto(void)
		{
		    Lista* l = new Lista(czo->get_next());
		    return (l);
		}

	template <class T> string Lista<T>::toPrint(string p)
		{
		    if (this->esvacia()) {
		        return p;
		    }
		    else {
		        //std::ostringstream stm;
		        ostringstream stm;
		        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
		        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
		        return stm.str();
		    }
		}

	template <class T> T Lista<T>::suma(T i)
		{    //cout<<" i al entrar= "<<i<<endl;
		    if (this->esvacia()) {
		        return i;
		    }
		    else {
		
		        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
		        return this->resto()->suma(i + this->cabeza());
		    }
		}

	template <class T> int Lista<T>::size()
		{
		    if (this->esvacia()) return 0;
		    return 1 + this->resto()->size();
		}



	template <class T> void Lista<T>::borrar(void)
		{ //borra el nodo cabeza
		    if (!this->esvacia()) {
		        Nodo<T>* tmp = czo;
		        czo = czo->get_next();
		        delete tmp;
		    }
		}

	template <class T> void Lista<T>::borrar_last()
		{ // borra el ultimo nodo
		    if (!this->esvacia()) {
		        if ((czo->get_next())->get_next() == NULL) {
		            delete czo->get_next();
		            czo->set_next(NULL);
		        }
		        else this->resto()->borrar_last();
		    }
		}

	template <class T> void Lista<T>::concat(Lista<T>* l1)
		{// le transfiere los datos de l1 a this
		    if (!(l1->esvacia())) {
		        this->concat(l1->resto());
		        this->add(l1->cabeza());
		    }
		}

	template <class T> Lista<T>* Lista<T>::copy(void)
		{
		    Lista<T>* aux = new Lista();
		    aux->concat(this);
		    return aux;
		}

	template <class T> void Lista<T>::tomar(int n)
		{ //deja "vivos" los n primeros nodos y borra el resto
		    if (this->size() > n) {
		        this->borrar_last();
		        this->tomar(n);
		    }
		}

	template <class T> void Lista<T>::impre(void)
		{
		    Nodo<T>* aux;
		    aux = czo;
		    int i =1;
		    while (aux->get_next() != NULL) {
		        cout<<endl<<"Usuario Numero "<<i<<": "<< aux->get_dato();
		        aux = aux->get_next();
		        i++;
		    }
		}
		
template <class T> void Lista<T>::imp(void)
	{
		    Nodo<T>* aux;
		    aux = czo;
		    while (aux->get_next() != NULL) {
		    	// if nivel 0 imprimir como post
		    	if(aux->get_dato().getNivel()==0)
		    	{
		    		cout<<endl<<"Post --- Titulo: "<<aux->get_dato().getTitulo()<<" --- ";
		    		aux->get_dato().getFecha();
		    		cout<<endl<<aux->get_dato().getContenido()<<endl;
		    	}
		    	// if nivel 1 imprimir como comentario
		    	if(aux->get_dato().getNivel()==1)
		    	{
		    		cout<<endl<<"Comentario --- ";
		    		aux->get_dato().getFecha();
		    		cout<<endl<<aux->get_dato().getContenido()<<endl;
		    	}
		    	// if nivel 2 imprimir como respuesta
		    	if(aux->get_dato().getNivel()==2)
		    	{
		    		cout<<endl<<"Respuesta --- ";
		    		aux->get_dato().getFecha();
		    		cout<<endl<<aux->get_dato().getContenido()<<endl;
		    	}
		    			        
		        aux = aux->get_next();
		    }
		}
		
//este fecha es clase fecha no puntero fecha de tm *
template <class T> bool Lista<T>::dma(T d){
		if(d.gFecha().gf()->tm_year < czo->get_dato().gFecha().gf()->tm_year){
			return true;
		}else{if(d.gFecha().gf()->tm_year > czo->get_dato().gFecha().gf()->tm_year){
			return false;
			}else{if(d.gFecha().gf()->tm_mon<czo->get_dato().gFecha().gf()->tm_mon){
				return true;
			}else{if(d.gFecha().gf()->tm_mon>czo->get_dato().gFecha().gf()->tm_mon){
				return false;
					}else{if(d.gFecha().gf()->tm_mday<czo->get_dato().gFecha().gf()->tm_mday){
						return true;
					}else{if(d.gFecha().gf()->tm_mday>czo->get_dato().gFecha().gf()->tm_mday){
						return false;
						}else{if(d.gFecha().gf()->tm_hour<czo->get_dato().gFecha().gf()->tm_hour){
							return true;
						}else{if(d.gFecha().gf()->tm_hour>czo->get_dato().gFecha().gf()->tm_hour){
							return false;
							}else{if(d.gFecha().gf()->tm_min<czo->get_dato().gFecha().gf()->tm_min){
								return true;
							}else{if(d.gFecha().gf()->tm_min>czo->get_dato().gFecha().gf()->tm_min){
								return false;
								}else{if(d.gFecha().gf()->tm_sec<czo->get_dato().gFecha().gf()->tm_sec){
									return true;
								}else{if(d.gFecha().gf()->tm_sec>czo->get_dato().gFecha().gf()->tm_sec){
									return false;
										}
									}
								}
								}
					}
				}
			}
		}	
	}}}}}

	template <class T> void Lista<T>::addO(T d, Nodo<T>* ant)
		{
		    if (this->esvacia()) {//el primero
		        this->add(d);
		    }
		    else {
		        if (dma(d)) {
		            if (ant == NULL) {//al principio
		                this->add(d);
		            }
		            else {//entre medio
		                Nodo<T>* nuevo = new Nodo<T>(d);
		                nuevo->set_next(ant->get_next());
		                ant->set_next(nuevo);
		            }
		        }
		        else {
		            if ((czo->get_next())->get_next() == NULL) {//al final
		                Nodo<T>* nuevo = new Nodo<T>(d);
		                nuevo->set_next(czo->get_next());
		                czo->set_next(nuevo);
		
		            }
		            else this->resto()->addO(d, czo);
		
		        }
		    }
		}

	template <class T> bool Lista<T>::esta(T d)
		{// busca d en la lista
		    if (this->esvacia()) return false;
		    if (this->cabeza() == d) return true;
		
		    return this->resto()->esta(d);
		}

	template <class T> void Lista<T>::borrarD(T d, Nodo<T>* ant)
		{
		    if (!this->esvacia()) {
		        if (d == this->cabeza()) {
		            if (ant == NULL) {//al principio
		                this->borrar();
		            }
		            else {//entre medio
		                ant->set_next(czo->get_next());
		                delete czo;
		            }
		        }
		        else  this->resto()->borrarD(d, czo);
		
		    }
		}
		
template <class T> T Lista<T>::tomarK(int k){
	string usuario;
			Nodo<T>* aux;
		    aux = czo;
		    int i =1;
		    while (i<=k) {
				if(k == i){
					usuario = aux->get_dato();
				}
		        aux = aux->get_next();
		        i++;
		    }
	return usuario;
}

    template <class T> Pila<T>::Pila() { Lista<T>(); }
    template <class T> void Pila<T>::apilar(T d) { this->add(d); }
    template <class T> T Pila<T>::tope(void) { return this->cabeza(); }
    template <class T> void Pila<T>::desapilar(void) { this->borrar(); }
    template <class T> bool Pila<T>::pilavacia() { return this->esvacia(); }


    template <class T> Cola<T>::Cola(void) { Lista<T>(); }
    template <class T> T Cola<T>::tope() { return this->last(); }
    template <class T> bool Cola<T>::colavacia(void) { return this->esvacia(); }
    template <class T> void Cola<T>::encolar(T a) { this->add(a); }
    template <class T> void Cola<T>::desencolar(void) { this->borrar_last(); }
    template <class T> T Cola<T>::ultimo(void) { return this->cabeza(); }
    template <class T> string Cola<T>::imprimir(string s) { return this->toPrint(s); }
