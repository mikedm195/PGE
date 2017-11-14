#include "imagenes.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
Imagenes::Imagenes(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);
    actual = 0;
    QDir directory(QDir::currentPath());
    images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    qDebug() << images;

    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeOut()));
    timer->start(100);


}

void Imagenes::paintEvent(QPaintEvent *event)
{
    if(images.size() > 0){
        QPainter painter( this );

        QPixmap pic(images.at(actual));
        qDebug() << images.at(actual);
        actual++;
        if (actual >= images.size()){
            QDir directory(QDir::currentPath());
            images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
            actual = 0;
        }
        pic.scaled(1000,1000);
        painter.drawPixmap(0,0,100,100, pic);
    }else{
        QDir directory(QDir::currentPath());
        images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    }
}

void Imagenes::slot_timeOut()
{
    this->repaint();
}
