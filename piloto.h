#ifndef PILOTO_H
#define PILOTO_H
#include <QString>


namespace bry
{
    class piloto
    {
    private:
        int codigo;
        QString nome;
        QString pais;
        int idade;
        QString time;
        QString motor;

    public:
        piloto();
        piloto(int codigo,QString nome,QString pais,int idade,QString time,QString motor);

        int getCodigo()const;
        QString getNome()const;
        QString getPais()const;
        int getIdade()const;
        QString getTime()const;
        QString getMotor()const;

        void setCodigo(int newCodigo);
        void setNome(const QString &newNome);
        void setPais(const QString &newPais);
        void setIdade(int newIdade);
        void setTime(const QString &newTime);
        void setMotor(const QString &newMotor);

        QString toString()const;
    };
}



#endif // PILOTO_H
