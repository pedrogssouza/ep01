#include "Rede.h"
#include <iostream>

using namespace std;

Rede::Rede(int tamanho){
    this->tamanho = tamanho;
    roteadores = new Roteador*[tamanho];
}

Rede::~Rede(){
    for(int i=0;i<quantidade;i++){
        delete roteadores[i];
    }
    delete[] roteadores;
}

bool Rede::adicionar(Roteador* r){
    if (quantidade >= tamanho)
        return false;

    if(getRoteador(r->getEndereco())!=NULL){
        return false;
    }

    roteadores[quantidade++] = r;
    return true;
}

Roteador* Rede::getRoteador(int endereco){
    for(int i=0;i<quantidade;i++){
        if(roteadores[i]->getEndereco()==endereco){
            return roteadores[i];
        }
    }
    return NULL;
}

Roteador** Rede::getRoteadores(){
    return roteadores;
}

int Rede::getQuantidade(){
    return quantidade;
}

void Rede::imprimir () {
    cout << "Rede com " << quantidade << " roteadores, a seguir: " << endl;
    cout << endl;
    for (int i = 0; i < quantidade; i++) {
        roteadores[i]->imprimir ();
    }
}
