/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila_Max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_H__
#define __Pila_H__

#include <cassert>
#include <cola.h>
#include <iostream>

/**
 *  @brief T.D.A. Pila_Max
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila sobre el tipo @c T es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserci�n y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posici�n i-�sima.

 * En esta pila, tendremos acceso �nicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento ser� sobre  @e an, y la
 * inserci�n de un nuevo elemento se har� sobre �ste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila est� vac�a.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el n�mero de
 * elementos de la Pila.
 *
 * @author Elena Merelo Molina y Antonio Gámiz Delgado.
 * @date Noviembre 2017
 */

        struct elemento{
            int ele;    ///< Elemento.
            int maximo; ///< Máximo asociado a @e ele
            /**
             * @brief Constructor por defecto
             */
            elemento() : ele(0), maximo(0){}
            /**
             * @brief Constructor con parámetros.
             * @param ele_ int asociado a elemento.
             * @param max Maximo asociado a elemento.
             */
            elemento(const int ele_, const int max): ele(ele_), maximo(max){}
        };

class Pila_max{
    private:


        struct Celda{
            struct elemento elem;    ///< Elemento de información.
            Celda * siguiente;  ///< Puntero al siguiente nodo.

            /**
             * @brief Constructor por defecto
             */
            Celda() : siguiente(0){}
            /**
             * @brief Constructor con parámetros.
             * @param elem Int de la celda.
             * @param sig Puntero al siguiente nodo.
             */
            Celda(const int elem_, const int max, Celda * sig) : elem(elem_,max), siguiente(sig){}

        };
        Celda * primera;
        int num_elem;

    public:
        Cola<elemento> datos; ///< Cola que almacenará los elementos.
        // ---------------  Constructores ----------------
        /**
         * @brief Constructor por defecto
         */
        Pila_max(): primera(0), num_elem(0){
        }
        /**
         * @brief Constructor de copias
         * @param otra La pila de la que se har� la copia.
         */
        Pila_max(const Pila_max & otra);
        // ------------------ Destructor ------------------
        /**
         * @brief Destructor
         */
        ~Pila_max();
        // --------------- Otras funciones ---------------
        /**
         * @brief Operador de asignaci�n
         * @param otra La pila que se va a asignar.
         */
        Pila_max& operator= (const Pila_max& otra);
        /**
         * @brief Comprueba si la pila est� vac�a
         */
        bool vacia() const{
        return (primera==0);
        }
        /**
         * @brief Devuelve el elemento del tope de la pila
         */
        elemento& tope (){
        assert(primera!=0);       //Si la pila est� vac�a, abortar
        return primera->elem; //Devuelve el elemento del tope de la pila
        }
        /**
         * @brief Devuelve el elemento del tope de una pila constante
         */
        const elemento & tope () const{
        assert(primera!=0);       //Si la pila est� vac�a, abortar
        return primera->elem; //Devuelve el elemento del tope de la pila
        }
        /**
         * @brief A�ade un elemento "encima" del tope de la pila
         * @param elem Elemento que se va a a�adir.
         */
        void poner(const int elem);
        /**
         * @brief Quita el elemento del tope de la pila
         */
        void quitar();
        /**
         * @brief Devuelve el n�mero de elementos de la pila
         */
        int num_elementos() const{
        return num_elem;
        }
};

#endif // __Pila_H__