#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "Fila.h"
#include "Roteador.h"

class Roteador;

class TabelaDeRepasse {
private:
    int tamanho;
    int *enderecos;
    Roteador** adjacentes;
    int *atrasos;

    Roteador* padrao;
    int atrasoPadrao;

    int quantidadeDeAdjacentes = 0;
    int buscaEndereco (int endereco); /*metodo em que é passado como parâmetro um endereço e ele retorna a posicao em que se encontra
                                       esse endereco no vetor enderecos, ou retorna -1 caso nao exista tal endereco no vetor*/

public:
    TabelaDeRepasse(int tamanho);
    ~TabelaDeRepasse();

    bool mapear(int endereco, Roteador *adjacente, int atraso);
    Roteador** getAdjacentes();
    int getQuantidadeDeAdjacentes();

    void setPadrao(Roteador* padrao, int atraso);

    Roteador* getProximoSalto(int endereco, int& atraso);

    void imprimir();
};

#endif /* TABELADEREPASSE_H */
