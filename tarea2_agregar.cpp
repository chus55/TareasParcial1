#include "tarea2_agregar.h"
#include "ui_tarea2_agregar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <QGraphicsTextItem>

using namespace std;

tarea2_agregar::tarea2_agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarea2_agregar)
{
    ui->setupUi(this);
}

tarea2_agregar::~tarea2_agregar()
{
    delete ui;
}

void tarea2_agregar::on_pushButton_clicked()
{
    if(ui->NumeroDeCuenta->text()!="" && ui->NombreEdit->text()!="" && ui->CarreraEdit->text()!="" && ui->FechaEdit->text()!="" && ui->UniversidadEdit->text()!="")
    {
        string nameFile = "ArchivoBinario2";
        ofstream out(nameFile.c_str(),ios::ate | ios::binary | ios::app);
        if(!out.is_open())
        {
            out.open(nameFile.c_str());
        }
        streampos fin = out.tellp();

        string nameFile2 = "IndiceBinario2";
        ofstream indice(nameFile2.c_str(),ios::app | ios::binary);
        if(!indice.is_open())
        {
            indice.open(nameFile2.c_str());
        }

        int ncuenta = ui->NumeroDeCuenta->text().toInt();
        string name = ui->NombreEdit->text().toStdString();
        string car = ui->CarreraEdit->text().toStdString();
        string date = ui->FechaEdit->text().toStdString();
        string uni = ui->UniversidadEdit->text().toStdString();

        out.write((char*)&ncuenta,sizeof(ncuenta));

        int tamNombre = name.length();
        cout<<tamNombre<<endl;
        char nombre[50];
        strcpy(nombre,name.c_str());
        for(int y=0; y<tamNombre; y++)
        {
            out.write((char*)&nombre[y], sizeof(char));
        }

        int tamCar = car.length();
        cout<<tamCar<<endl;
        char carrera[50];
        strcpy(carrera,car.c_str());
        for(int y=0; y<tamCar; y++)
        {
            out.write((char*)&carrera[y], sizeof(char));
        }

        int tamDate = date.length();
        cout<<tamDate<<endl;
        char fecha[50];
        strcpy(fecha,date.c_str());
        for(int y=0; y<tamDate; y++)
        {
            out.write((char*)&fecha[y], sizeof(char));
        }

        int tamUni = uni.length();
        cout<<tamUni<<endl;
        char universidad[50];
        strcpy(universidad,uni.c_str());
        for(int y=0; y<tamUni; y++)
        {
            out.write((char*)&universidad[y], sizeof(char));
        }

        indice.write((char*)&fin,sizeof(int));
        indice.write((char*)&tamNombre,sizeof(tamNombre));
        indice.write((char*)&tamCar,sizeof(tamCar));
        indice.write((char*)&tamDate,sizeof(tamDate));
        indice.write((char*)&tamUni,sizeof(tamUni));

//        int actual = fin;
//        indice.write((char*)&actual,sizeof(actual));
//        actual+= sizeof(ncuenta);
//        indice.write((char*)&actual,sizeof(actual));
//        actual+= tamNombre;
//        indice.write((char*)&actual,sizeof(actual));
//        actual+= tamCar;
//        indice.write((char*)&actual,sizeof(actual));
//        actual+= tamDate;
//        indice.write((char*)&actual,sizeof(actual));

        out.close();
        indice.close();

        ui->NumeroDeCuenta->setText("");
        ui->NombreEdit->setText("");
        ui->CarreraEdit->setText("");
        ui->FechaEdit->setText("");
        ui->UniversidadEdit->setText("");
        this->hide();
    }
}

void tarea2_agregar::on_pushButton_2_clicked()
{
    ui->NumeroDeCuenta->setText("");
    ui->NombreEdit->setText("");
    ui->CarreraEdit->setText("");
    ui->FechaEdit->setText("");
    ui->UniversidadEdit->setText("");
    this->hide();
}
