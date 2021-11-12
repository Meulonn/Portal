#include "connection.h"

Connection::Connection(){}
bool Connection::createconnection()
{
   db=QSqlDatabase::addDatabase("QODBC");
   bool test=false;
   db.setDatabaseName("test");
   db.setUserName("khalil");
   db.setPassword("khalil");

if (db.open()) test=true;
return test;
}

