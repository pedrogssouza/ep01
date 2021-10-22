#include "Fila.h"
#include <iostream>

Fila::Fila(int tamanho){
    this->tamanho=tamanho;
    datagramas = new Datagrama*[tamanho];
}

Fila::~Fila(){
    cout << "Fila com " << this->getSize() << " datagrama(s) destruida" << endl;
    for(int i = 0; i < this->getSize(); i++) datagramas[i]->imprimir();
}

bool Fila::enqueue(Datagrama* d) {
    if (quantidade >= tamanho)
        return false;

    datagramas[quantidade++] = d;
    return true;
}

Datagrama* Fila::dequeue(){
    if(this->isEmpty()){
        return NULL;
    }

    Datagrama *primeiroDatagrama = datagramas[0];
}

int Fila::getSize(){
    return quantidade;
}

bool Fila::isEmpty(){
    return quantidade==0;
}

void Fila::imprimir(){
    cout << "Fila com " << this->getSize() << " datagrama(s)" << endl;
    for(int i = 0; i < this->getSize(); i++) delete datagramas[i];
}
