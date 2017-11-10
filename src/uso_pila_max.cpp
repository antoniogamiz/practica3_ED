#include <iostream>
#include "pila_max_cola.h"

using namespace std;

int main(){
  Pila_max p;
  
  int i;
  for(i=10; i>=0; i--)
    p.poner(i);

  // while(!p.datos.vacia()){
  //   cout << p.datos.frente().ele << endl;
  //   p.datos.quitar();
  // }


  while(!p.vacia()){
    elemento x= p.tope();
    cout << x.ele << endl;
    p.quitar();
  }
  return 0;
}
