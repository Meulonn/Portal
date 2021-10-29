#include "agent.h"

agent::agent()
{
 name="";
 surname="";
 cin="";
 admission_date="";
 number_of_absences="";
 adress="";
 position="";
 salary="";
 email="";

}
void agent::setname(QString n){name=n;}
void agent::setsurname(QString n){surname=n;}
void agent::setcin(QString n){cin=n;}
void agent::setadmissiondate(QString n){admission_date=n;}
void agent::setnumberofabsences(QString n){number_of_absences=n;}
void agent::setadress(QString n){adress=n;}
void agent::setposition(QString n){position=n;}
void agent::setsalary(QString n){salary=n;}
void agent::setemail(QString n){email=n;}

QString agent::get_name(){return name;}
QString agent::get_surname(){return surname;}
QString agent::get_cin(){return cin;}
QString agent::get_admissiondate(){return admission_date;}
QString agent::get_numberofabsences(){return number_of_absences;}
QString agent::get_adress(){return adress;}
QString agent::get_position(){return position;}
QString agent::get_salary(){return salary;}
QString agent::get_email(){return email;}





