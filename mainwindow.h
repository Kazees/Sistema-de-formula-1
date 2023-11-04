#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <piloto.h>
#include <manipulararquivo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonBuscar_clicked();

    void on_pushButtonMostrardados_clicked();

    void on_pushButtonLimpar_clicked();

private:
    Ui::MainWindow *ui;
    QString nomeDoArquivo;
};
#endif // MAINWINDOW_H
