#include "piloto.h"

namespace bry {

    piloto::piloto():codigo(0),nome(""),pais(""),idade(0),time(""),motor("")
    {
    }

    piloto::piloto(int codigo,QString nome,QString pais,int idade,QString time,QString motor):codigo(codigo),nome(nome),pais(pais),idade(idade),time(time),motor(motor)
    {
    }

    QString piloto::getNome() const
    {
        return nome;
    }

    void piloto::setNome(const QString &newNome)
    {
        nome = newNome;
    }

    QString piloto::getPais() const
    {
        return pais;
    }

    void piloto::setPais(const QString &newPais)
    {
        pais = newPais;
    }

    int piloto::getIdade() const
    {
        return idade;
    }

    void piloto::setIdade(int newIdade)
    {
        idade = newIdade;
    }

    QString piloto::getTime() const
    {
        return time;
    }

    void piloto::setTime(const QString &newTime)
    {
        time = newTime;
    }

    QString piloto::getMotor() const
    {
        return motor;
    }

    void piloto::setMotor(const QString &newMotor)
    {
        motor = newMotor;
    }

    int piloto::getCodigo() const
    {
        return codigo;
    }

    void piloto::setCodigo(int newCodigo)
    {
        codigo = newCodigo;
    }

    QString piloto::toString()const
    {
        QString saida="{ ";

        saida+="Codigo: "+QString::number(codigo)+'\n';
        saida+="Nome: "+nome+'\n';
        saida+="País: "+pais+'\n';
        saida+="Idade: "+QString::number(idade)+'\n';
        saida+="Time: "+time+'\n';
        saida+="Motor: "+motor+'\n';

        return saida;
    }
}
