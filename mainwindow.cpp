#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxOrdem->setEnabled(false);
    ui->pushButtonMostrardados->setEnabled(false);
    ui->pushButtonLimpar->setEnabled(false);
    ui->tableWidgetPiloto->setRowCount(11);
    //ui->tableWidgetPiloto->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try
    {
        nomeDoArquivo=QFileDialog::getOpenFileName(this,"Abrir arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty())
        {
            throw QString("Arquivo não selecionado.");
        }

        ui->lineEditNomedoArquivo->setText(nomeDoArquivo);
        ui->comboBoxOrdem->setEnabled(true);
        ui->pushButtonMostrardados->setEnabled(true);
        ui->pushButtonLimpar->setEnabled(true);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
    }
}


void MainWindow::on_pushButtonMostrardados_clicked()
{
    try
    {
        bry::manipulararquivo dados(nomeDoArquivo);
        dados.buscarDados();
        bry::Lista listaPilotos;
        ui->tableWidgetPiloto->setRowCount(dados.getColecaoPilotos().getQuantidadeElementos());

        if(ui->comboBoxOrdem->currentIndex()==0)
        {
            for(int i=0;i<dados.getColecaoPilotos().getQuantidadeElementos();i++)
            {
                int cod=dados.getColecaoPilotos().acessarPosicao(i).getCodigo();
                QString nome=dados.getColecaoPilotos().acessarPosicao(i).getNome();
                QString pais=dados.getColecaoPilotos().acessarPosicao(i).getPais();
                int idade=dados.getColecaoPilotos().acessarPosicao(i).getIdade();
                QString time=dados.getColecaoPilotos().acessarPosicao(i).getTime();
                QString motor=dados.getColecaoPilotos().acessarPosicao(i).getMotor();

                bry::piloto p1(cod,nome,pais,idade,time,motor);

                listaPilotos.OrdenadoCrescente(p1);
            }

            for(int i=0;i<listaPilotos.getQuantidadeElementos();i++)
            {
                ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getCodigo()))); //Cod
                ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getNome())); //Nome
                ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getPais())); //Pais
                ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getIdade()))); //Idade
                ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getTime())); //Time
                ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getMotor())); //Motor
            }

        }

        else if(ui->comboBoxOrdem->currentIndex()==1)
        {
            for(int i=0;i<dados.getColecaoPilotos().getQuantidadeElementos();i++)
            {
                int cod=dados.getColecaoPilotos().acessarPosicao(i).getCodigo();
                QString nome=dados.getColecaoPilotos().acessarPosicao(i).getNome();
                QString pais=dados.getColecaoPilotos().acessarPosicao(i).getPais();
                int idade=dados.getColecaoPilotos().acessarPosicao(i).getIdade();
                QString time=dados.getColecaoPilotos().acessarPosicao(i).getTime();
                QString motor=dados.getColecaoPilotos().acessarPosicao(i).getMotor();

                bry::piloto p1(cod,nome,pais,idade,time,motor);

                listaPilotos.OrdenadoDescrescente(p1);
            }

            for(int i=0;i<listaPilotos.getQuantidadeElementos();i++)
            {
                ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getCodigo()))); //Cod
                ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getNome())); //Nome
                ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getPais())); //Pais
                ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getIdade()))); //Idade
                ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getTime())); //Time
                ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getMotor())); //Motor
            }
        }

        ui->pushButtonLimpar->setEnabled(true);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
    }
}


void MainWindow::on_pushButtonLimpar_clicked()
{
    for(int i=0;i<11;i++)
    {
        ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(0)); //Cod
        ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(0)); //Nome
        ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(0)); //Pais
        ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(0)); //Idade
        ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(0)); //Time
        ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(0)); //Motor
    }

     ui->pushButtonLimpar->setEnabled(false);
}

