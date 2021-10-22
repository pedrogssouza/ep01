#include "TabelaDeRepasse.h"
#include <iostream>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    this->tamanho = tamanho;
    enderecos = new int[tamanho];
    adjacentes = new Roteador*[tamanho];
    atrasos = new int[tamanho];
    setPadrao(NULL, 0);
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] enderecos;
    delete[] adjacentes;
    delete[] atrasos;
}

int TabelaDeRepasse::buscaEndereco(int endereco){
    for (int i = 0; i < quantidadeDeAdjacentes; i++){
        if (enderecos[i] == endereco){
            return i;
        }
    }
    return -1; /*roteador com endereco passado como parametro nao esta na tabela, retornando -1 (posicao invalida)*/

}
bool TabelaDeRepasse::mapear(int endereco, Roteador *adjacente, int atraso){
    if (quantidadeDeAdjacentes >= tamanho){ /*overflow*/
        return false;
    }
    int posicao = buscaEndereco(endereco);
    if (posicao == -1){  /*endereco ainda nao se encontra na tabela*/
        enderecos[quantidadeDeAdjacentes] = endereco;
        adjacentes[quantidadeDeAdjacentes] = adjacente;
        atrasos[quantidadeDeAdjacentes] = atraso;
        quantidadeDeAdjacentes++;
    }else{    /*endereco ja esta na tabela*/
        return false;
    }
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidadeDeAdjacentes;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso){
    this->padrao = padrao;
    atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    int posicao = buscaEndereco(endereco);
    if (posicao == -1){    /* não existe um roteador com endereco fornecido na tabela de adjacentes, portanto,
                             o datagrama sera repassado ao roteador padrao*/
        atraso = atrasoPadrao;
        return padrao;
    }
    atraso = atrasos[posicao];
    return adjacentes[posicao];
}

void TabelaDeRepasse::imprimir(){
    cout << "Tabela de repasse de tamanho " << tamanho << " e " << getQuantidadeDeAdjacentes() <<
    " roteador(es), a seguir: " << endl;
    cout << "       Roteador padrao com endereco ";
    if (padrao == NULL){
        cout << "NULL e 0 de atraso" << endl;
    }else{
        cout << padrao->getEndereco() << " e " << atrasoPadrao << " de atraso" << endl;
    }
    cout << "       Roteador(es) associados a um endereco de destino: " << endl;
    for (int i = 0; i < quantidadeDeAdjacentes; i++){
        cout << "           Repassar o datagrama com endereço de destino " << enderecos[i] <<
        " para o roteador associado com endereco " << adjacentes[i]->getEndereco()
        << ", cujo atraso relacionado é " << atrasos[i] << endl;
    }
}
