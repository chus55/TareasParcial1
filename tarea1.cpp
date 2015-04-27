#include "tarea1.h"
#include "ui_tarea1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <QGraphicsTextItem>

using namespace std;

Tarea1::Tarea1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea1)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,721,571);
}

Tarea1::~Tarea1()
{
    delete ui;
}

void Tarea1::on_botonWrite_clicked()
{
            string nameFile = "ArchivoAutomatico";
            ofstream out(nameFile.c_str(), ios::binary);
            if(!out.is_open())
            {
                out.open(nameFile.c_str());
            }
            out.seekp(0);
            for(int x=0; x<10; x++)
            {
                out.write((char*)&x,sizeof(x));
                QString number = QString::number(x);
                string numero = number.toStdString();
                char nombre[8] = "Alumno";
                nombre[6] = numero.at(0);
                for(int y=0; y<sizeof(nombre); y++)
                {
                    out.write((char*)&nombre[y], sizeof(char));
                }
                char carrera[9] = "Carrera";
                carrera[7] = numero.at(0);
                for(int u=0; u<sizeof(carrera); u++)
                {
                    out.write((char*)&carrera[u], sizeof(char));
                }
                char fecha[7] = "Fecha";
                fecha[5] = numero.at(0);
                for(int j=0; j<sizeof(fecha); j++)
                {
                    out.write((char*)&fecha[j], sizeof(char));
                }
                char universidad[13] = "Universidad";
                universidad[11] = numero.at(0);
                for(int q=0; q<sizeof(universidad); q++)
                {
                    out.write((char*)&universidad[q], sizeof(char));
                }
                //cout<<nombre<<endl;
                //out.write((char*)&nombre,nombre.size());
                //out.write((char*)&x,4);
            }
            out.close();
}

void Tarea1::on_botonRead_clicked()
{
    scene->clear();
    string nameFile = "ArchivoAutomatico";
            ifstream in(nameFile.c_str(),ios::ate | ios::binary);
            streampos fin = in.tellg();
            in.seekg(0,ios::beg);
            int posY = 0;
            int posX = 0;
                    while(in.tellg()<fin)
                    {
                       int num;
                       char name[8];
                       char car[9];
                       char fec[7];
                       char uni[13];
                       in.read((char*)&num,sizeof(num));
                       in.read(name,sizeof(name));
                       in.read(car,sizeof(car));
                       in.read(fec,sizeof(fec));
                       in.read(uni,sizeof(uni));
                       string nombre(name);
                       string carrera(car);
                       string fecha(fec);
                       string universidad(uni);
                       scene->addText(QString::number(num))->setPos(posX,posY);
                       posX+=50;
                       scene->addText(nombre.c_str())->setPos(posX,posY);
                       posX+=100;
                       scene->addText(carrera.c_str())->setPos(posX,posY);
                       posX+=100;
                       scene->addText(fecha.c_str())->setPos(posX,posY);
                       posX+=100;
                       scene->addText(universidad.c_str())->setPos(posX,posY);
                       posY+=25;
                       posX=0;
                       //cout<<nombre<<num<<endl;
                    }
}
