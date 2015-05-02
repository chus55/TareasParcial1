#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMainWindow>
#include "tarea1.h"
#include "tarea2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_T1_clicked();

    void on_T2_clicked();

private:
    Ui::MainWindow *ui;
    Tarea1* Tar1;
    tarea2* Tar2;
};

#endif // MAINWINDOW_H
