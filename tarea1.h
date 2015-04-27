#ifndef TAREA1_H
#define TAREA1_H
#include <QGraphicsScene>
#include <QDialog>

namespace Ui {
class Tarea1;
}

class Tarea1 : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea1(QWidget *parent = 0);
    ~Tarea1();

private slots:
    void on_botonWrite_clicked();

    void on_botonRead_clicked();

private:
    Ui::Tarea1 *ui;
    QGraphicsScene *scene;
};

#endif // TAREA1_H
