#include"connexion.h"
Connection::Connection()
{

}

bool Connection::createconnection()
{ db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;

db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("dali123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return test;
}
