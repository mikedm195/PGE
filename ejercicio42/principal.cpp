#include "principal.h"
#include "ui_principal.h"
#include <QPainter>


Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    im.load("../redes/topologia.png");

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slot_chequear()));

    // Aca armar la topologia
    // Notar que en el .h ya estan creados los:
    Computadora pc_sola;
    pc_sola.setIP("172.17.0.10");
    pc_sola.setHostName("PC-PT-PC4");
    pc_sola.setGateway("10.0.0.2");
////    Computadora pc_1;
    pc_1.setIP("192.168.0.10");
    pc_1.setHostName("PC-PT-PC0");
    pc_1.setGateway("10.0.0.1");
//    Computadora pc_2;
    pc_2.setIP("192.168.0.11");
    pc_2.setHostName("PC-PT-PC5");
    pc_2.setGateway("10.0.0.1");
////    Router red_2pc;
    red_2pc.setHostName("Router0");
    red_2pc.setIPs("10.0.0.1","192.168.0.1");
////    Router red_pcsola;
//    red_pcsola.setHostName("Router1");
//    red_pcsola.setIPs("10.0.0.2","172.17.0.1");


}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QImage im = this->im.scaledToHeight( this->height() - ui->label->height() - ui->pushButton->height() );

    painter.drawImage(0, ui->label->height() + ui->pushButton->height(), im);
}

void Principal::slot_chequear()
{    
    QList<QStringList> (Rutas::*puntero)() = &Rutas::genera1;
    red_2pc.setTabla(puntero);
    puntero = &Rutas::genera2;
    red_2pc.setTabla(puntero);
    puntero = &Rutas::genera3;
    red_2pc.setTabla(puntero);
    // usar Qdebug para imprimir aca la tabla de ruteo de los dos routers

    // usar Qdebug para imprimir también los gateways de las computadoras
}



