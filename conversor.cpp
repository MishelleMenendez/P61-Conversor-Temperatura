#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectarel dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2cent(int)));
    connect(ui->inKelv, SIGNAL(valueChanged(int)),
            this, SLOT(Kelv2cent(int)));
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Kelv(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2Kelv(int)));
    connect(ui->inKelv, SIGNAL(valueChanged(int)),
            this, SLOT (Kelv2fahr(int)));

}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32;
        ui->inFahr->setValue(f);
    }

}

void Conversor::fahr2cent(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9;
        ui->inCent->setValue(c);
    }
}

void Conversor::cent2Kelv(int grados)
{
    if (ui->inCent->hasFocus()){
        int k = (grados + 273.15) ;
        ui->inKelv->setValue(k);
    }
}

void Conversor::Kelv2cent(int grados)
{
    if (ui->inKelv->hasFocus()){
        int c = (grados - 273.15) ;
        ui->inCent->setValue(c);
    }
}

void Conversor::fahr2Kelv(int grados)
{
    if (ui->inFahr->hasFocus()){
        int k = ((grados - 32) * 5.0/9.0)+273.15;
        ui->inKelv->setValue(k);
    }
}

void Conversor::Kelv2fahr(int grados)
{
    if (ui->inKelv->hasFocus()){
        int f = ((grados - 273.15) * 9.0/5.0)+32;
        ui->inFahr->setValue(f);
    }
}



