#ifndef IMAGENES_H
#define IMAGENES_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QStringList>
#include <QDir>

class QTimer;

class Imagenes : public QWidget
{
    Q_OBJECT
public:
    QTimer *timer;
    explicit Imagenes(QWidget *parent = 0);
    QLabel* imageLabel;
    QStringList images;
    int actual;

protected:
    void paintEvent(QPaintEvent *event);
signals:

private slots:
    void slot_timeOut();
};

#endif // IMAGENES_H
