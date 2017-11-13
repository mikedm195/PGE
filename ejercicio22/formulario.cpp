#include "formulario.h"
#include "ui_formulario.h"

Formulario * Formulario::instancia = NULL;

Formulario *Formulario::getInstancia()
{
    if( instancia == NULL )
    {
        instancia = new Formulario();
    }
    return instancia;
}

Formulario::Formulario( QWidget * parent ) : QWidget( parent ),
                                             ui( new Ui::Formulario )
{
    ui->setupUi( this );

    connect( ui->pbAgregar, SIGNAL( pressed() ), this, SLOT( slot_agregarUsuario() ) );
}

Formulario::~Formulario()
{

    delete ui;
}

void Formulario::slot_agregarUsuario()
{
    QStringList usuarioIngresado;
    usuarioIngresado << ui->leUsuario->text() << ui->leClave->text();

    QVector<QStringList>  usuarios;
    usuarios << usuarioIngresado;
    if(!ui->leUsuario->text().isEmpty() && !ui->leClave->text().isEmpty()){
        emit signal_agregarUsuario( usuarios );
        ui->leUsuario->clear();
        ui->leClave->clear();
    }

}
