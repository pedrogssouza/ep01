#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila{
    public:
        Fila(int tamanho);
        ~Fila();

        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();
        int getSize();

        void imprimir();
    private:
        Datagrama** datagramas;
        int tamanho;
        int quantidade = 0;
        int inicio = 0;
        int fim = 0;
};

#endif // FILA_H
