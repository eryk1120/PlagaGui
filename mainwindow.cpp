#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "symulacja.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    QGraphicsScene * scena = new QGraphicsScene;
    scena->addPixmap(QPixmap(":/IMG/Mapa.png"));
    ui->Mapka->setScene(scena);

    ui->test_label->setText(QString::number(world.size()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_start_clicked()
{
    startowe start;
    start.setModal(true);
    start.exec();

    connect(
                &start,SIGNAL(get_obj(QString nazwa,int m,int r)),
                this,SLOT(get_obj(QString nazwa, int m, int r)));


}

void MainWindow::setlabel(QString x)
{
    ui->test_label->setText(x);
}

void MainWindow::get_obj(QString nazwa, int m, int r)
{
    world.infect(world.szukaj_indeks(nazwa),10);
    world.set_data(m,r);
    ui->test_label->setText("done");
}
