#include "no.h"

namespace bry
{

    No::No():dados(),proximo(0)
    {
    }

    No::No(piloto dados):dados(dados),proximo(0)
    {
    }

    void No::setDados(piloto newDados)
    {
        dados = newDados;
    }

    void No::setProximo(No *newProximo)
    {
        proximo = newProximo;
    }

    QString No::toString()const
    {
        return dados.toString();
    }
}

