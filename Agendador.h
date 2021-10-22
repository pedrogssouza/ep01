#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Rede.h"

class Agendador
{
    public:
        Agendador(int instanteInicial, Rede* rede, int tamanho);
        ~Agendador();

        bool agendar(int instante, Roteador* r, Datagrama* d);
        void processar();
        int getInstante();
    protected:

    private:
        Evento **eventos;
        int quantidade=0;
        int tamanho;

        int instante;
        Rede *rede;
};

#endif // AGENDADOR_H
