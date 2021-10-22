#include "Agendador.h"



Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho){
    this->instante=instanteInicial;
    this->rede=rede;
    this->tamanho=tamanho;
    eventos = new Evento*[tamanho];
}

Agendador::~Agendador(){
    for(int i=0;i<quantidade;i++){
        delete eventos[i];
    }
    delete[] eventos;
}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d){
    if(quantidade>=tamanho){
        return false;
    }

    Evento *evento = new Evento(instante, r, d);
    eventos[quantidade++]=evento;
    return true;
}

void Agendador::processar(){
    for(int i = 0; i < quantidade; i++){
        if(instante == eventos[i]->getInstante()){
            Evento* eventoTemporario = eventos[i];
            delete eventos[i];
            (eventoTemporario->getDestino())->receber(eventoTemporario->getDatagrama());

        }
    }

    Roteador **roteadores = rede->getRoteadores();
    for(int j = 0; j < (rede->getQuantidade())-1; j++){
            eventos[quantidade++] = roteadores[j]->processar(instante);

    }

    instante++;
}


int Agendador::getInstante(){
    return instante;
}
