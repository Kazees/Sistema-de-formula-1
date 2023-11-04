#include "manipulararquivo.h"

namespace bry
{
    manipulararquivo::manipulararquivo(QString nomeDoArquivo):nomeDoArquivo(nomeDoArquivo),colecaoPilotos()
    {
    }

    void manipulararquivo::buscarDados()
    {
        try
        {
            std::ifstream arquivo;
            arquivo.open(nomeDoArquivo.toStdString().c_str());

            if(!arquivo.is_open())
            {
                throw QString("Não foi possível abrir o arquivo.");
            }

            std::string linha;
            QString qlinha;

            while(std::getline(arquivo,linha))
            {
                qlinha=QString::fromStdString(linha);

                QStringList strLista=qlinha.split(';');
                int codigo=strLista[0].toInt();
                QString nome=strLista[1];
                QString pais=strLista[2];
                int idade=strLista[3].toInt();
                QString time=strLista[4];
                QString motor=strLista[5];

                piloto p1(codigo,nome,pais,idade,time,motor);
                colecaoPilotos.inserirFinal(p1);
            }

            arquivo.close();
        }

        catch (QString &erro)
        {
            throw erro;
        }
    }

    const bry::Lista &manipulararquivo::getColecaoPilotos() const
    {
        return colecaoPilotos;
    }
}
