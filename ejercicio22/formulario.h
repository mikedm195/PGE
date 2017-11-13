#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>

namespace Ui {
    class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    static Formulario *getInstancia();
    explicit Formulario( QWidget * parent = 0 );
    ~Formulario();

private:
    static Formulario *instancia;
    Ui::Formulario *ui;

private slots:
    void slot_agregarUsuario();

signals:

    /**
     * @brief signal_usuarioValidado Se emite cuando un usuario intenta ingresar.
     * @param valido Si es true entonces el usuario es valido, sino devuelve false.
     * @param usuario Son las credenciales que el usuario ingresa.
     */
    void signal_agregarUsuario( QVector<QStringList> usuario );
};

#endif // FORMULARIO_H
