
#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO 10

#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"

class Evento;

class TabelaDeRepasse;

class Roteador{
    public:
        Roteador(int endereco);
        ~Roteador();

        bool mapear(int endereco, Roteador* adjacente, int atraso);
        void setPadrao(Roteador* padrao, int atraso);

        int getEndereco();
        void receber(Datagrama* d);
        Evento* processar(int instante);

        void imprimir();
    protected:

    private:
        TabelaDeRepasse *tabela;
        Fila *fila;
        int endereco;
        int atraso;
        Roteador *padrao;

};

#endif // ROTEADOR_H

