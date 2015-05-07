#ifndef TAREA3_H
#define TAREA3_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QDialog>
#include <bitset>

namespace Ui {
class tarea3;
}

class tarea3 : public QDialog
{
    Q_OBJECT

public:
    explicit tarea3(QWidget *parent = 0);
    ~tarea3();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_boton_clicked();

private:
    Ui::tarea3 *ui;
    QGraphicsScene* scene1;
    QGraphicsScene* scene2;
    int arr[3] = {0,1,2};
};

#endif // TAREA3_H
