
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include <iostream>
#define TAMANHO 10

using namespace std;

Roteador::Roteador (int endereco) {
    this -> endereco = endereco;
    tabela = new TabelaDeRepasse(TAMANHO);
    fila = new Fila (TAMANHO);

}

Roteador::~Roteador () {
    delete tabela;
    delete fila;
}

void Roteador::receber(Datagrama *d) {
    if (fila->enqueue (d) == false) {
        cout << "\tFila em " << endereco << " estorou" << endl;
        return;
    }

    cout << "Oi" << endl;
    fila->enqueue(d);
}

Evento* Roteador::processar (int instante) {
    Datagrama *d = fila->dequeue ();
    if (d != NULL) { /*verifica se fila nao esta vazia, pois fila vazia retorna NULL*/
        cout << "Roteador " << endereco << endl;
        if (d->getDestino() == endereco){
            cout << "\tRecebido :" << d->getDado() << endl;
            delete d;
            return NULL;
        }else{
            if(tabela->getProximoSalto(d->getDestino(), atraso)==NULL){
                cout << "\tSem proximo: Origem: " << d->getOrigem() << ", Destino: "
                << d->getDestino() << ", " << d->getDado() << endl;
                delete d;
                return NULL;
            }else{
                cout << "\t Repassado para " << endereco << " (instante " << instante << "): Origem: "
                << d->getOrigem() << ", Destino: "
                << d->getDestino() << ", " << d->getDado() << endl;
                Evento *e=new Evento(instante+atraso,tabela->getProximoSalto(d->getDestino(), atraso), d);
                return e;
            }
        }
    }else{
        return NULL;
    }
}

void Roteador::setPadrao(Roteador *padrao, int atraso){
    this->padrao = padrao;
    this->atraso = atraso;
}

int Roteador::getEndereco(){
    return endereco;
}

bool Roteador::mapear(int endereco, Roteador *adjacente, int atraso){
    return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::imprimir(){
    cout << "Roteador: " << endereco << endl;
}
