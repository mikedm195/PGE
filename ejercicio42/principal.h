#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QImage>
#include <QDebug>

#include "computadora.h"
#include "router.h"
#include "tabla.h"
#include "rutas.h"


namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:    
    explicit Principal(QWidget *parent = 0);
    ~Principal();

protected:
    void paintEvent( QPaintEvent * );

private:
    Ui::Principal *ui;
    QImage im;

    Computadora pc_sola;
    Computadora pc_1;
    Computadora pc_2;
    Router red_2pc;
    Router red_pcsola;

private slots:
    void slot_chequear();
};

#endif // PRINCIPAL_H
