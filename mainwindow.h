#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulacja.h"
#include "lista.h"

#include "startowe.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setlabel(QString);

private slots:

   // void get_obj(string nazwa,int m, int r);
    void get_obj(QString nazwa,int m, int r);

    void on_start_clicked();



private:
    Ui::MainWindow *ui;
    symulacja world;
    friend class startowe;


};

#endif // MAINWINDOW_H
