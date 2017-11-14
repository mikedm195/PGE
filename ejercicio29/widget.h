#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"
#include <QDebug>
#include <fstream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Thread * thread;

private slots:
    void on_pushButton_clicked();

private:
    void sinHilos();
    void conHilos();
    Ui::Widget *ui;
};

#endif // WIDGET_H
