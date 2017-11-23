/**
  * @file pila_max_cola.cpp
  * @brief Implementación del TDA Pila
  *
  */
#include <cassert>
#include<pila_max_cola.h>
#include<iostream>

using namespace std;

/* _________________________________________________________________________ */

void Pila_max::push(int num){
    elemento aux;
    aux.element=num;
    if(empty()){
        aux.maximo=num;
        queue.poner(aux);
    }
    else{
        if(queue.frente().maximo < num)
            aux.maximo=num;
        else
            aux.maximo=queue.frente().maximo;

        Cola<elemento> aux_;
        aux_.poner(aux);
        int n=queue.num_elementos();
        for(int i=0; i<n; ++i){
            aux_.poner(queue.frente());
            queue.quitar();
        }
        queue=aux_;
    }
}

//Devuelve una referencia al tope de la pila
struct elemento& Pila_max::top(){
 return queue.frente();
}

//Devuelve una referencia constante al tope de la pila
const struct elemento& Pila_max::top() const {
 return queue.frente();
}

//Elimina el elemento en el tope de la pila
void Pila_max::pop(){
 return queue.quitar();
}
