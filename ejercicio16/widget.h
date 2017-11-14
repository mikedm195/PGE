#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>

class QTimer;

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
    Ui::Widget *ui;
    QCamera * camera;
    bool encendida;
    QTimer *timer;

private slots:
    void slot_startCamera();
    void slot_valueSlider(int valor);
    void slot_timeOut();
};

#endif // WIDGET_H
