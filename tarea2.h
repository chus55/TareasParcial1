#ifndef TAREA2_H
#define TAREA2_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMainWindow>
#include "tarea2_agregar.h"

#include <QDialog>

namespace Ui {
class tarea2;
}

class tarea2 : public QDialog
{
    Q_OBJECT

public:
    explicit tarea2(QWidget *parent = 0);
    ~tarea2();

private slots:
    void on_botonWrite_clicked();

    void on_botonRead_clicked();

    void on_botonBuscar_clicked();

private:
    Ui::tarea2 *ui;
    QGraphicsScene* scene;
    tarea2_agregar* Tar22;
};

#endif // TAREA2_H
