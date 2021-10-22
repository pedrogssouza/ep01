#include "Datagrama.h"
#include <iostream>

using namespace std;

Datagrama::Datagrama(int origem, int destino, string dado){
    this->origem=origem;
    this->destino=destino;
    this->dado=dado;
}

Datagrama::~Datagrama(){
    cout << "O datagrama de dado '" << dado << "' foi destruido" << endl;
}

int Datagrama::getOrigem(){
    return origem;
}

int Datagrama::getDestino(){
    return destino;
}

string Datagrama::getDado(){
    return dado;
}

void Datagrama::imprimir(){
    cout << "O datagrama de dado '" << dado << "' tem como origem e destino: " << origem << " "
    << destino << ", respectivamente" << endl;
}
