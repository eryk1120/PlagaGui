#include "startowe.h"
#include "ui_startowe.h"
#include <QMessageBox>

startowe::startowe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startowe)
{
    ui->setupUi(this);
    for(int i=0; i<54; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }

}

startowe::~startowe()
{
    delete ui;
}
void startowe::on_butt1_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=0; i<54; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}
void startowe::on_butt2_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=54; i<89; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}
void startowe::on_butt3_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=180; i<194; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}
void startowe::on_butt4_clicked()
{
    ui->KrajeCombo->clear();
    for(int i=89; i<180; i++)
    {
        ui->KrajeCombo->addItem(QString::fromStdString( world1->dej_nazwe(i)) );
    }
}




void startowe::on_OKEJKA_accepted()
{
    QString text = "pandemia rozpocznie się w " + (ui->KrajeCombo->currentText()) +
    "z datą " + QString::number(ui->spinBoxMiesiac->value()) + "."
            + QString::number(ui->spinBoxRok->value());

    startowe * ptr= this;

    int x = QMessageBox::question(this,"THE FINAL PYTANKO",text);

    if(!x)
    {

    }
}

void startowe::on_try_2_clicked()
{
    QString text = "pandemia rozpocznie się w " + (ui->KrajeCombo->currentText()) +
    "z datą " + QString::number(ui->spinBoxMiesiac->value()) + "."
            + QString::number(ui->spinBoxRok->value());

    startowe * ptr= this;

    int x = QMessageBox::question(this,"THE FINAL PYTANKO",text);

    if(!x)
    {
        emit get_obj(ui->KrajeCombo->currentText(),ui->spinBoxMiesiac->value(),ui->spinBoxRok->value());

    }
}
