#include "widget.h"
#include <QApplication>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>

#include "imagenes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Imagenes im;
    im.show();

    Widget w;
    w.show();

    return a.exec();
}
