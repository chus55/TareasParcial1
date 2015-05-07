#include "tarea3.h"
#include "ui_tarea3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <QGraphicsTextItem>
#define CLEARBIT(a, pos) (a ^(1 << pos) )

using namespace std;

tarea3::tarea3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarea3)
{
    ui->setupUi(this);
    scene1 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(0,0,461,111);

    scene2 = new QGraphicsScene(this);
    ui->graphicsView2->setScene(scene2);
    scene1->setSceneRect(0,0,101,91);

    for(int y=0; y<3; y++)
     ui->comboBox->addItem(QString::number(arr[y]));

    ui->comboBox->setCurrentIndex(-1);
}

tarea3::~tarea3()
{
    delete ui;
}

void tarea3::on_comboBox_activated(const QString &arg1)
{
    scene1->clear();
    scene2->clear();
    int n = arg1.toInt();
    bitset<32> numero(n);
    //QString bits(QString::number(n,2));
    //string numeroString = numero.to_string();
    scene1->addText(numero.to_string().c_str())->setPos(-50,0);
    scene2->addText(QString::number(n))->setPos(0,0);
}

void tarea3::on_boton_clicked()
{
    scene1->clear();
    scene2->clear();
    int bit = ui->BitSelect->text().toInt();
    //bitset<32> cons(1);
    int n = ui->comboBox->currentText().toInt();
    int nb = CLEARBIT(n,bit);
    bitset<32> numero(nb);
    int index = ui->comboBox->findText(QString::number(n));
    arr[index] = nb;
    ui->comboBox->clear();
    for(int y=0; y<3; y++)
        ui->comboBox->addItem(QString::number(arr[y]));
    ui->comboBox->setCurrentIndex(index);
    scene1->addText(numero.to_string().c_str())->setPos(-50,0);
    scene2->addText(QString::number(nb))->setPos(0,0);
    //for(int y=0; y<3; y++)
    //cout<<arr[y]<<endl;
}
