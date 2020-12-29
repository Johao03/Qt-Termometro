#include "termometro.h"
#include "ui_termometro.h"
#include <QDebug>

Termometro::Termometro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);

    connect(ui->dialC, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    connect(ui->dialC, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Kel(int)));
    connect(ui->dialF, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));
    connect(ui->dialF, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Kel(int)));
    connect(ui->dialK, SIGNAL(valueChanged(int)),
            this, SLOT(kel2Cent(int)));
    connect(ui->dialK, SIGNAL(valueChanged(int)),
            this, SLOT(kel2Fahr(int)));


    connect(ui->dialC, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialF, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialK, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));


    connect(ui->dialC, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    connect(ui->dialF, SIGNAL(sliderReleased()),
             this, SLOT(dialRelajado()));
    connect(ui->dialK, SIGNAL(sliderReleased()),
             this, SLOT(dialRelajado()));


    ui->dialF->setValue(32);
    ui->dialK->setValue(255);
}

Termometro::~Termometro()
{
    delete ui;
}

float Termometro::cent2Fahr(int valor)
{
    if(ui->dialC->hasFocus()){
        float f = valor  * 9.0/5 + 32;
        ui->dialF->setValue(f);
        return f;
    }
    return 0;
}

float Termometro::cent2Kel(int valor)
{
    if(ui->dialC->hasFocus()){
        float k = valor + 273.15 ;
        ui->dialK->setValue(k);
        return k;
    }
    return 0;
}

float Termometro::fahr2Cent(int valor)
{
    if (ui->dialF->hasFocus()){
        float c = (valor-32) * 5/9;
        ui->dialC->setValue(c);
        return c;
    }
    return 0;
}

float Termometro::fahr2Kel(int valor)
{
    if (ui->dialF->hasFocus()){
        float k = (valor-32) * 5/9 + 273.15;
        ui->dialK->setValue(k);
        return k;
    }
    return 0;
}

float Termometro::kel2Cent(int valor)
{
    if(ui->dialK->hasFocus()){
        float c = valor - 273.15;
        ui->dialC->setValue(c);
        return c;
    }
    return 0;
}

float Termometro::kel2Fahr(int valor)
{
    if(ui->dialK->hasFocus()){
        float f = (valor - 273.15) * 9.0/5 + 32;
        ui->dialF->setValue(f);
        return f;
    }
    return 0;
}

void Termometro::dialPresionado()
{
    if(ui->dialC->hasFocus()){
        ui->dialF->setCursor(Qt::ClosedHandCursor);
    }else if(ui->dialF->hasFocus()){
        ui->dialK->setCursor(Qt::ClosedHandCursor);
    }
}

void Termometro::dialRelajado()
{
    if(ui->dialC->hasFocus()){
        ui->dialF   ->setCursor(Qt::OpenHandCursor);
    }else if(ui->dialF->hasFocus()){
        ui->dialK->setCursor(Qt::OpenHandCursor);
    }

}

