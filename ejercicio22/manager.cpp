#include "manager.h"

#include "logger.h"

Manager * Manager::instancia = NULL;

Manager::Manager( QObject * parent ) : QObject( parent )
{

    connect( Login::getInstancia(), SIGNAL( signal_usuarioValidado( bool, QStringList ) ),
             this, SLOT( slot_ingreso( bool, QStringList ) ) );

    connect( Formulario::getInstancia(), SIGNAL(signal_agregarUsuario(QVector<QStringList>)),
             this, SLOT(slot_agregar_usuario(QVector<QStringList>)));

    QVector< QStringList > nuevosUsuarios;

    QStringList usuario1;  usuario1 << "carlos" << "123";
    QStringList usuario2;  usuario2 << "miguel" << "1234";
    QStringList usuario3;  usuario3 << "julio" << "12345";

    nuevosUsuarios << usuario1 << usuario2 << usuario3;

    Login::getInstancia()->setBaseUsuarios( nuevosUsuarios );
}


Manager * Manager::getInstancia()
{
    if( instancia == NULL )
    {
        instancia = new Manager();
    }
    return instancia;
}

Manager::~Manager()
{
    if( instancia != NULL )
    {
        Logger::getInstancia()->registrarEvento("Cerrando aplicacion");
        delete instancia;
    }
}

void Manager::iniciar()
{
    Logger::getInstancia()->registrarEvento("Iniciando aplicacion");
    Login::getInstancia()->show();
}

void Manager::slot_ingreso( bool valido, QStringList usuario )
{
    if ( valido )  {
        Logger::getInstancia()->registrarEvento("Usuario logeado correctamente");
        Login::getInstancia()->hide();
        Formulario::getInstancia()->show();
        Formulario::getInstancia()->setWindowTitle( "Bienvenido: " + usuario.at( 0 ) );
    }
    else  {
        Logger::getInstancia()->registrarEvento("Usuario logeado incorrectamente");
        Login::getInstancia()->close();
        Logger::getInstancia()->registrarEvento("Cerrando aplicacion");
    }
}

void Manager::slot_agregar_usuario(QVector< QStringList > usuarios )
{
    Login::getInstancia()->setBaseUsuarios(usuarios);
    Formulario::getInstancia()->hide();
    Login::getInstancia()->show();
    Logger::getInstancia()->registrarEvento("Usuario agregado");
}
