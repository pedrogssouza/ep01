#ifndef EVENTO_H
#define EVENTO_H

#include "Datagrama.h"
#include "Roteador.h"

class Roteador;

class Evento{
public:
    Evento(int instante, Roteador* destino, Datagrama* d);
    ~Evento();
    int getInstante();
    Roteador* getDestino();
    Datagrama* getDatagrama();
    void imprimir();

private:
    int instante;
    Roteador* destino;
    Datagrama* datagrama;

};

#endif // EVENTO_H
