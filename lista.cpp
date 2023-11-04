#include "lista.h"

namespace bry
{
    Lista::Lista():inicio(0),quantidadeElementos(0)
    {
    }

    void Lista::inserirInicio(piloto dado)
    {
        try
        {
            No *novoNo=new No(dado);

            novoNo->setProximo(inicio);
            inicio=novoNo;
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void Lista::inserirFinal(piloto dado)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dado);
                return;
            }

            No *novoNo=new No(dado);

            /*if(estaVazia())
            {
                inicio=novoNo;
                quantidadeElementos++;
                return;
            }*/

            No *atual=inicio;

            while(atual->getProximo()!=0)
            {
                atual=atual->getProximo();
            }

            atual->setProximo(novoNo);
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void Lista::inserirPosicao(piloto dado,int posicao)
    {
        try
        {
            if(posicao<0||posicao>quantidadeElementos)
            {
                throw QString("Posição inválida.");
            }

            if(posicao==0)
            {
                inserirInicio(dado);
                return;
            }

            if(posicao==quantidadeElementos-1)
            {
                inserirFinal(dado);
                return;
            }

            No *novoNo=new No(dado);
            No *atual=inicio;

            for(int i=0;i<posicao-1;i++)
            {
                atual=atual->getProximo();
            }

            novoNo->setProximo(atual->getProximo());
            atual->setProximo(novoNo);
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    piloto Lista::acessarInicio()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        return inicio->getDados();
    }

    piloto Lista::acessarFinal()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        No *atual=inicio;

        while(atual->getProximo()!=0)
        {
            atual=atual->getProximo();
        }

        return atual->getDados();
    }

    piloto Lista::acessarPosicao(int posicao)const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        No *atual=inicio;

        for(int i=0;i<posicao;i++)
        {
            atual=atual->getProximo();
        }

        return atual->getDados();
    }

    void Lista::retirarInicio()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        No *pAux=inicio;

        inicio=inicio->getProximo(); //ou inicio->setProximo(pAux->getProximo());
        quantidadeElementos--;

        delete pAux;
    }

    void Lista::retirarFinal()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(quantidadeElementos==1)
        {
            delete inicio;
            inicio=0;
            quantidadeElementos=0;
            return;
        }

        No *final=inicio;
        No *penultimo=0;

        while(final->getProximo()!=0)
        {
            penultimo=final;
            final=final->getProximo();
        }

        penultimo->setProximo(0);
        quantidadeElementos--;

        delete final;
    }

    void Lista::retirarPosicao(int posicao)
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        if(posicao==0)
        {
            retirarInicio();
            return;
        }

        if(posicao==quantidadeElementos-1)
        {
            retirarFinal();
            return;
        }

        No *final=inicio;
        No *penultimo=0;
        int cont=0;

        while(cont<posicao)
        {
            penultimo=final;
            final=final->getProximo();
            cont++;
        }

        penultimo->setProximo(final->getProximo());
        quantidadeElementos--;

        delete final;
    }

    void Lista::OrdenadoCrescente(piloto dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *atual=inicio;
            No *novoNo=new No(dados);

            if(novoNo->getDados().getCodigo()<=atual->getDados().getCodigo())
            {
                novoNo->setProximo(inicio);
                inicio=novoNo;
            }

            else
            {
                atual=inicio;

                while(atual->getProximo() && novoNo->getDados().getCodigo()>atual->getProximo()->getDados().getCodigo())
                {
                    atual=atual->getProximo();
                }

                novoNo->setProximo(atual->getProximo());
                atual->setProximo(novoNo);
            }

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void Lista::OrdenadoDescrescente(piloto dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *atual=inicio;
            No *novoNo=new No(dados);

            if(novoNo->getDados().getNome()>atual->getDados().getNome())
            {
                novoNo->setProximo(inicio);
                inicio=novoNo;
            }

            else
            {
                atual=inicio;

                while(atual->getProximo() && novoNo->getDados().getNome()<atual->getProximo()->getDados().getNome())
                {
                    atual=atual->getProximo();
                }

                novoNo->setProximo(atual->getProximo());
                atual->setProximo(novoNo);
            }

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    QString Lista::toString()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        bry::No *pAux=inicio;
        QString saida="Dados da lista: ";

        for(int i=0;i<quantidadeElementos;i++)
        {
            saida+=pAux->toString();
            pAux=pAux->getProximo();
        }

        return saida;
    }
}
