#ifndef NO_H
#define NO_H
#include <QString>
#include <piloto.h>

namespace bry
{
    class No
    {
    private:
        piloto dados;
        No *proximo;

    public:
        No();
        No(piloto dados);

        piloto getDados() const {return dados;}
        No *getProximo() const {return proximo;}

        void setDados(piloto newDados);
        void setProximo(No *newProximo);

        QString toString()const;
    };
}



#endif // NO_H
