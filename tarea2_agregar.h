#ifndef TAREA2_AGREGAR_H
#define TAREA2_AGREGAR_H

#include <QDialog>

namespace Ui {
class tarea2_agregar;
}

class tarea2_agregar : public QDialog
{
    Q_OBJECT

public:
    explicit tarea2_agregar(QWidget *parent = 0);
    ~tarea2_agregar();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tarea2_agregar *ui;
};

#endif // TAREA2_AGREGAR_H
