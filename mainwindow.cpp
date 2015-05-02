#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tar1 = new Tarea1();
    Tar2 = new tarea2();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_T1_clicked()
{
    Tar1->show();
}

void MainWindow::on_T2_clicked()
{
    Tar2->show();
}
