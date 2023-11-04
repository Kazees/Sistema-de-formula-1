#ifndef LISTALLSE_H
#define LISTALLSE_H
#include <no.h>
#include <piloto.h>

namespace bry
{
    class Lista
    {
    private:
        No *inicio;
        int quantidadeElementos;

    public:
        Lista();

        int getQuantidadeElementos()const {return quantidadeElementos;}
        bool estaVazia()const {return quantidadeElementos==0;} //ou inicio==0

        void inserirInicio(piloto dado);
        void inserirFinal(piloto dado);
        void inserirPosicao(piloto dado,int posicao);

        piloto acessarInicio()const;
        piloto acessarFinal()const;
        piloto acessarPosicao(int posicao)const;

        void retirarInicio();
        void retirarFinal();
        void retirarPosicao(int posicao);

        void OrdenadoCrescente(piloto dados);
        void OrdenadoDescrescente(piloto dados);

        QString toString()const;
    };
}

#endif // LISTALLSE_H
