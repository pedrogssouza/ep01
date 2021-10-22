#include "Evento.h"
#include <iostream>
#include <vector>

Evento::Evento(int instante, Roteador* destino, Datagrama* d){
    this->instante = instante;
    this->destino = destino;
    datagrama = d;
}

Evento::~Evento(){
    cout << "Evento que representa o recebimento do Datagrama " << datagrama <<
    " pelo roteador com endereço " << destino->getEndereco() << " destruido." << endl;
}

int Evento::getInstante(){
    return instante;
}

Roteador* Evento::getDestino(){
    return destino;
}

Datagrama* Evento::getDatagrama(){
    return datagrama;
}


void Evento::imprimir(){
    cout << "Evento que representa o recebimento do Datagrama " << datagrama <<
    " pelo roteador com endereço " << (destino)->getEndereco() << endl;
}
