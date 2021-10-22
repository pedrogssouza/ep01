#include <iostream>
#include "Datagrama.h"

using namespace std;

int main(){
    Datagrama *d=new Datagrama(5,6,"roi");
    d->getOrigem();
    d->getDestino();
    d->getDado();
    d->imprimir();
    delete d;
    return 0;
}
