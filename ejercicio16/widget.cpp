#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDate>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),timer(new QTimer(this))
{
    ui->setupUi(this);

    encendida = true;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (int i=0 ; i<cameras.size() ; i++)
        qDebug() << cameras.at(i).description();

    QCameraInfo cameraInfo = cameras.at(0);
    camera = new QCamera(cameraInfo);

    camera->setViewfinder(ui->visor);
    camera->start();
    connect(ui->pb_encender,SIGNAL(clicked()),this,SLOT(slot_startCamera()));
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(slot_valueSlider(int)));
    if(encendida)
        connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeOut()));

    timer->start(ui->slider->value());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_startCamera()
{
    if(encendida){
        encendida = false;
        camera->stop();
    }else{
        encendida = true;
        camera->start();
    }
}

void Widget::slot_valueSlider(int valor)
{
    timer->start(valor);
}

void Widget::slot_timeOut()
{
    if(encendida){
        QString fecha = QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss");
//        ui->visor->grab().save(fecha+".jpg");
        QPixmap::grabWindow(ui->visor->winId(), 0, 0, -1, -1).save(fecha+".jpg");
    }
}
