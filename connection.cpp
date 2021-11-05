#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Sourrce_Projet2A");
db.setUserName("hajer");//inserer nom de l'utilisateur
db.setPassword("esprit2020");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
