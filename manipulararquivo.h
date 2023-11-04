#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H
#include <QString>
#include <QStringList>
#include <fstream>
#include <piloto.h>
#include <lista.h>

namespace bry
{
    class manipulararquivo
    {
    private:
        QString nomeDoArquivo; //Diretorio
        bry::Lista colecaoPilotos;
    public:
        manipulararquivo(QString nomeDoArquivo);

        void buscarDados();
        const bry::Lista &getColecaoPilotos() const;
    };
}



#endif // MANIPULARARQUIVO_H
