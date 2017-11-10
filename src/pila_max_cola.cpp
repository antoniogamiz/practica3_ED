/**
  * @file pila.cpp
  * @brief Implementaci�n del TDA Pila
  *
  */
#include <cassert>
#include<pila_max_cola.h>
#include<iostream>

using namespace std;

/* _________________________________________________________________________ */

Pila_max::Pila_max(const Pila_max & otra){
    *this=otra; //Usamos el operador de asignación.
}

Pila_max::~Pila_max(){
    if(primera!=0)  //Si la pila no está vacía.
        delete primera; //Borramos el nodo de la lista.
}

Pila_max& Pila_max::operator=(const Pila_max& otra){
    if(this!=&otra){    //Comprobación de rigor. Si son diferentes objetos.
        if(primera!=0)  //Borramos la lista de nodos de la pila *this.
            delete primera;
        if(otra.primera!=0){    //Si la pila original no está vacía.
            Celda *p = otra.primera;    //Copio el puntero al primer nodo.
            primera = new Celda(p->elem.ele, p->elem.maximo, p->siguiente); //Creamos el primer nodo.
            datos = otra.datos;
        }
        else    //Si la pila original está vacía.
            primera=0;
        num_elem=otra.num_elem; //En cualquier caso, copiamos num_elem.
    }
    return *this;   //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

void Pila_max::poner(const int elem){
    
    elemento aux;
    if(primera!=0){
        aux.ele = elem;
        aux.maximo=primera->elem.maximo;
        primera->elem=aux;
    } 
    else{
        aux.ele=elem;
        aux.maximo=elem;
        primera = new Celda;
        primera->elem=aux;
    }
    datos.poner(aux);
    num_elem++;
}

void Pila_max::quitar(){
    assert(primera!=0);
    Cola<elemento> aux;
    int n=datos.num_elementos()-1;
    for(int i=0; i<n; i++){
        aux.poner(datos.frente());
        primera->elem=datos.frente();
        datos.quitar();
    }
    datos=aux;
    if(datos.num_elementos()==0)
        primera=0;
}