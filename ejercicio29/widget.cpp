#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), thread( new Thread ),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString texto = ui->comboBox->currentText();
    if(texto == "Sin hilos"){
        qDebug() << "Sin hilos";
        sinHilos();
    }else{
        qDebug() << "Con hilos";
        conHilos();
    }
}

void Widget::sinHilos()
{
    std::ofstream fs("qThread.txt",std::ios::app);
    for(int j = 0;j<999;j++)
        for(int i = 0;i<999999;i++)
            fs << (char)i%255;
}

void Widget::conHilos()
{
//    QObject::connect(&t, SIGNAL(finished()), &t, SLOT(deleteLater()));

    thread->start();
}
