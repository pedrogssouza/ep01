#include <iostream>
#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"
#include "Agendador.h"

using namespace std;

int main(){
    Rede* r = new Rede(10);

    Roteador* r1 = new Roteador(1);
    Roteador* r2 = new Roteador(2);
    Roteador* r3 = new Roteador(3);
    Roteador* r4 = new Roteador(4);
    Roteador* r5 = new Roteador(5);
    Roteador* r6 = new Roteador(6);
    r->adicionar(r1);
    r->adicionar(r2);
    r->adicionar(r3);
    r->adicionar(r4);
    r->adicionar(r5);
    r->adicionar(r6);

    Agendador* a = new Agendador(1, r, 10);

    r1->setPadrao(r3, 1);
    r2->setPadrao(r4, 1);
    r3->setPadrao(r4, 1);
    r4->setPadrao(r3, 1);
    r5->setPadrao(r3, 2);
    r6->setPadrao(r4, 1);

    r1->mapear(2, r2, 2);
    r2->mapear(1, r1, 2);
    r3->mapear(1, r1, 1);
    r3->mapear(5, r5, 2);
    r4->mapear(2, r2, 1);
    r4->mapear(6, r6, 1);
    r5->mapear(6, r6, 2);
    r6->mapear(5, r5, 2);

    int opcao;
    do{
        cout << "Simulador de Rede" << endl;
        cout << "---" << endl;
        cout << "1) Enviar um datagrama" << endl;
        cout << "2) Passar tempo" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1){
            int origem;
            int instante;
            int destino;
            string  mensagem;

            cout << "Endereço do roteador de origem: ";
            cin >> origem ;
            cout << endl;
            cout << "Instante: " << endl;
            cin >> instante;
            cout << "Endereço de destino: " << endl;
            cin >> destino;
            cout << "Mensagem: " << endl;
            cin >> mensagem;

            Datagrama *d = new Datagrama(origem, destino, mensagem);

            Roteador *roteadorDestino= new Roteador(destino);

            if(destino!=1&&destino!=2&&destino!=3&&destino!=4&&destino!=5&&destino!=6){
                cout << "Erro: origem desconhecida" << endl;
            }else if(!a->agendar(instante,roteadorDestino,d)){
                cout << "Erro: Sem espaco para agendar o evento" << endl;
            }else{
                a->agendar(instante,roteadorDestino,d);
            }

        }else if(opcao==2){
            int quantidadeTempo;

        }

    }while(opcao!=0);


    return 0;
}
