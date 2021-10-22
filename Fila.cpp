#include "Fila.h"
#include <iostream>
#include <vector>

Fila::Fila(int tamanho){
    this->tamanho = tamanho;
    datagramas = new Datagrama*[tamanho];
}

Fila::~Fila(){
    cout << "Fila com " << quantidade << " datagrama(s) destruida" << endl;
    for(int i = 0; i < this->getSize(); i++){
            delete datagramas[i];
    }
    delete[] datagramas;
}

bool Fila::enqueue (Datagrama *d) {
    if (fim == inicio - 1 || (fim == tamanho && inicio == 0)) { /*condicao do overflow */
        return false;
    }
    datagramas[fim] = d;
    fim++;
    if (fim == tamanho + 1) { /*vetor circular*/
        fim = 0;
    }
    quantidade++;
    return true;
}

Datagrama* Fila::dequeue(){
    if(this->isEmpty()){
        return NULL;
    }

    Datagrama* datagramaDeletado = datagramas[inicio];
    inicio++;
    if (inicio == tamanho + 1) {
        inicio = 0;
    }
    quantidade--;
    return datagramaDeletado;
}


int Fila::getSize(){
    return quantidade;
}

bool Fila::isEmpty(){
    return quantidade == 0;
}

void Fila::imprimir(){
    cout << "Fila com " << quantidade << " datagrama(s)" << endl;
}
