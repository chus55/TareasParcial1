#include "tarea2.h"
#include "ui_tarea2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <QGraphicsTextItem>

using namespace std;

tarea2::tarea2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarea2)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,721,571);
    Tar22 = new tarea2_agregar();
}

tarea2::~tarea2()
{
    delete ui;
}

void tarea2::on_botonWrite_clicked()
{
    Tar22->show();
}

void tarea2::on_botonRead_clicked()
{
    scene->clear();
    string nameFile = "ArchivoBinario2";
    string nameFile2 = "IndiceBinario2";
            ifstream in(nameFile.c_str(),ios::binary);
            ifstream indice(nameFile2.c_str(),ios::ate | ios::binary);
            streampos fin = indice.tellg();
            in.seekg(0,ios::beg);
            indice.seekg(0,ios::beg);
            int posY = 0;
            int posX = 0;
                    while(indice.tellg()<fin)
                    {
                       int puntero;
                       int num;

                       indice.read((char*)&puntero,sizeof(puntero));
                       in.seekg(puntero);
                       in.read((char*)&num,sizeof(num));

                       indice.read((char*)&puntero,sizeof(puntero));
                       char name[puntero+1];
                       memset(name,'\0',puntero+1);
                       in.read(name,puntero);
                       indice.read((char*)&puntero,sizeof(puntero));
                       char car[puntero+1];
                       memset(car,'\0',puntero+1);
                       in.read(car,puntero);
                       indice.read((char*)&puntero,sizeof(puntero));
                       char fec[puntero+1];
                       memset(fec,'\0',puntero+1);
                       in.read(fec,puntero);
                       indice.read((char*)&puntero,sizeof(puntero));
                       char uni[puntero+1];
                       memset(uni,'\0',puntero+1);
                       in.read(uni,puntero);

                       string nombre(name);
                       string carrera(car);
                       string fecha(fec);
                       string universidad(uni);

//                       cout<<num<<endl;
//                       cout<<nombre<<endl;
//                       cout<<carrera<<endl;
//                       cout<<fecha<<endl;
//                       cout<<universidad<<endl;

                       scene->addText(QString::number(num))->setPos(posX,posY);
                       posY+=25;
                       scene->addText(nombre.c_str())->setPos(posX,posY);
                       posY+=25;
                       scene->addText(carrera.c_str())->setPos(posX,posY);
                       posY+=25;
                       scene->addText(fecha.c_str())->setPos(posX,posY);
                       posY+=25;
                       scene->addText(universidad.c_str())->setPos(posX,posY);
                       posY+=50;
                    }
                    in.close();
                    indice.close();
}

void tarea2::on_botonBuscar_clicked()
{
    scene->clear();
    int ncuenta = ui->NumeroDeCuenta->text().toInt();
    string nameFile = "ArchivoBinario2";
    string nameFile2 = "IndiceBinario2";
            ifstream in(nameFile.c_str(),ios::binary);
            ifstream indice(nameFile2.c_str(),ios::ate | ios::binary);
            streampos fin = indice.tellg();
            in.seekg(0,ios::beg);
            indice.seekg(0,ios::beg);
            int posY = 0;
            int posX = 0;
                    while(indice.tellg()<fin)
                    {
                       int puntero;
                       int num;

                       indice.read((char*)&puntero,sizeof(puntero));
                       in.seekg(puntero);
                       in.read((char*)&num,sizeof(num));


                           indice.read((char*)&puntero,sizeof(puntero));
                           char name[puntero+1];
                           memset(name,'\0',puntero+1);
                           in.read(name,puntero);
                           indice.read((char*)&puntero,sizeof(puntero));
                           char car[puntero+1];
                           memset(car,'\0',puntero+1);
                           in.read(car,puntero);
                           indice.read((char*)&puntero,sizeof(puntero));
                           char fec[puntero+1];
                           memset(fec,'\0',puntero+1);
                           in.read(fec,puntero);
                           indice.read((char*)&puntero,sizeof(puntero));
                           char uni[puntero+1];
                           memset(uni,'\0',puntero+1);
                           in.read(uni,puntero);

                           if(num==ncuenta)
                           {
                           string nombre(name);
                           string carrera(car);
                           string fecha(fec);
                           string universidad(uni);

                           scene->addText(QString::number(num))->setPos(posX,posY);
                           posY+=25;
                           scene->addText(nombre.c_str())->setPos(posX,posY);
                           posY+=25;
                           scene->addText(carrera.c_str())->setPos(posX,posY);
                           posY+=25;
                           scene->addText(fecha.c_str())->setPos(posX,posY);
                           posY+=25;
                           scene->addText(universidad.c_str())->setPos(posX,posY);
                           posY+=50;
                       }
                    }
                    in.close();
                    indice.close();
}
