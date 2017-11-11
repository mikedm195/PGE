#ifndef VISTA_H
#define VISTA_H

#include <QWidget>
#include <QTreeWidget>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class Vista;
}

class Vista : public QWidget  {
        Q_OBJECT

public:
        explicit Vista(QWidget *parent = 0);
        ~Vista();

private:
        Ui::Vista *ui;
        QTreeWidget* popup;
        QTimer* timer;
        QStringList lista;  // La base de datos

        void crearPopup();
        bool eventFilter(QObject *obj, QEvent *ev);  // Método virtual de QObject
        void completarPopup(QVector<QStringList> vector);

private slots:
        void slot_sugerencia();
        void slot_completarLineEdit();
};

#endif // VISTA_H
