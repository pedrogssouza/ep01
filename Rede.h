#ifndef REDE_H
#define REDE_H

#include "Roteador.h"

class Rede
{
    public:
        Rede(int tamanho);
        ~Rede();

        bool adicionar(Roteador* r);
        Roteador* getRoteador(int endereco);

        Roteador** getRoteadores();
        int getQuantidade();

        void imprimir();

    private:
        Roteador **roteadores;
        int tamanho;
        int quantidade=0;
};

#endif // REDE_H
